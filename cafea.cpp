#include <iostream>
using namespace std;

class Cafea {
private:
    int totalCafele;        // cafelele ramase disponibile
    int totalCuburiZahar;   // cuburile de zahar ramase disponibile
    double sumaIncasari;    // suma incasata pana acum

    static const double PRET_INDULCITA;
    static const double PRET_NEINDULCITA;
    static const int ZAHAR_PER_CAFEA = 2;

public:
    // initializare: se specifica numarul de cafele si de cuburi de zahar disponibile
    void initializare(int nrCafele, int nrCuburiZahar) {
        totalCafele = nrCafele;
        totalCuburiZahar = nrCuburiZahar;
        sumaIncasari = 0;
    }

    // bea o cafea indulcita: se foloseste 1 cafea si 2 cuburi de zahar
    void beaCafeaIndulcita() {
        if (totalCafele < 1) {
            cout << "Nu mai este cafea!" << endl;
            return;
        }
        if (totalCuburiZahar < ZAHAR_PER_CAFEA) {
            cout << "Nu mai este zahar!" << endl;
            return;
        }
        totalCafele--;
        totalCuburiZahar -= ZAHAR_PER_CAFEA;
        sumaIncasari += PRET_INDULCITA;
        cout << "Ati baut o cafea indulcita. Pret: " << PRET_INDULCITA << " lei" << endl;
    }

    // bea o cafea neindulcita: se foloseste doar 1 cafea
    void beaCafeaNeindulcita() {
        if (totalCafele < 1) {
            cout << "Nu mai este cafea!" << endl;
            return;
        }
        totalCafele--;
        sumaIncasari += PRET_NEINDULCITA;
        cout << "Ati baut o cafea neindulcita. Pret: " << PRET_NEINDULCITA << " lei" << endl;
    }

    // afisare total incasari
    void afisareTotalIncasari() {
        cout << "Total incasari: " << sumaIncasari << " lei" << endl;
        cout << "Cafele ramase: " << totalCafele
             << ", cuburi de zahar ramase: " << totalCuburiZahar << endl;
    }
};

const double Cafea::PRET_INDULCITA = 3.5;
const double Cafea::PRET_NEINDULCITA = 3.0;

int main() {
    Cafea aparat;
    int nrCafele, nrZahar;

    cout << "Numar de cafele disponibile: ";
    cin >> nrCafele;
    cout << "Numar de cuburi de zahar disponibile: ";
    cin >> nrZahar;
    aparat.initializare(nrCafele, nrZahar);

    int optiune;
    do {
        cout << "\n===== MENIU =====" << endl;
        cout << "1. O cafea indulcita" << endl;
        cout << "2. O cafea neindulcita" << endl;
        cout << "3. Afisare total incasari" << endl;
        cout << "4. Iesire" << endl;
        cout << "Alegeti optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1: aparat.beaCafeaIndulcita(); break;
            case 2: aparat.beaCafeaNeindulcita(); break;
            case 3: aparat.afisareTotalIncasari(); break;
            case 4: cout << "La revedere!" << endl; break;
            default: cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 4);

    return 0;
}
