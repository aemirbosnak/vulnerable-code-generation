//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct Element {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomicMass;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    { 1, "Hydrogen", "H", 1.01 },
    { 2, "Helium", "He", 4.00 },
    { 3, "Lithium", "Li", 6.94 },
    { 4, "Beryllium", "Be", 9.01 },
    { 5, "Boron", "B", 10.81 },
    { 6, "Carbon", "C", 12.01 },
    { 7, "Nitrogen", "N", 14.01 },
    { 8, "Oxygen", "O", 16.00 },
    { 9, "Fluorine", "F", 19.00 },
    { 10, "Neon", "Ne", 20.18 },
    { 11, "Sodium", "Na", 22.99 },
    { 12, "Magnesium", "Mg", 24.31 },
    { 13, "Aluminum", "Al", 26.98 },
    { 14, "Silicon", "Si", 28.09 },
    { 15, "Phosphorus", "P", 30.97 },
    { 16, "Sulfur", "S", 32.06 },
    { 17, "Chlorine", "Cl", 35.45 },
    { 18, "Argon", "Ar", 39.95 },
    { 19, "Potassium", "K", 39.10 },
    { 20, "Calcium", "Ca", 40.08 },
    { 21, "Scandium", "Sc", 44.96 },
    { 22, "Titanium", "Ti", 47.87 },
    { 23, "Vanadium", "V", 50.94 },
    { 24, "Chromium", "Cr", 52.00 },
    { 25, "Manganese", "Mn", 54.94 },
    { 26, "Iron", "Fe", 55.85 },
    { 27, "Cobalt", "Co", 58.93 },
    { 28, "Nickel", "Ni", 58.69 },
    { 29, "Copper", "Cu", 63.55 },
    { 30, "Zinc", "Zn", 65.38 },
    { 31, "Gallium", "Ga", 69.72 },
    { 32, "Germanium", "Ge", 72.63 },
    { 33, "Arsenic", "As", 74.92 },
    { 34, "Selenium", "Se", 78.96 },
    { 35, "Bromine", "Br", 79.90 },
    { 36, "Krypton", "Kr", 83.80 },
    { 37, "Rubidium", "Rb", 85.47 },
    { 38, "Strontium", "Sr", 87.62 },
    { 39, "Yttrium", "Y", 88.91 },
    { 40, "Zirconium", "Zr", 91.22 },
    { 41, "Niobium", "Nb", 92.91 },
    { 42, "Molybdenum", "Mo", 95.94 },
    { 43, "Technetium", "Tc", 98.00 },
    { 44, "Ruthenium", "Ru", 101.07 },
    { 45, "Rhodium", "Rh", 102.91 },
    { 46, "Palladium", "Pd", 106.42 },
    { 47, "Silver", "Ag", 107.87 },
    { 48, "Cadmium", "Cd", 112.41 },
    { 49, "Indium", "In", 114.82 },
    { 50, "Tin", "Sn", 118.71 },
    { 51, "Antimony", "Sb", 121.76 },
    { 52, "Tellurium", "Te", 127.60 },
    { 53, "Iodine", "I", 126.90 },
    { 54, "Xenon", "Xe", 131.29 },
    { 55, "Cesium", "Cs", 132.91 },
    { 56, "Barium", "Ba", 137.33 },
    { 57, "Lanthanum", "La", 138.91 },
    { 58, "Cerium", "Ce", 140.12 },
    { 59, "Praseodymium", "Pr", 140.91 },
    { 60, "Neodymium", "Nd", 144.24 },
    { 61, "Promethium", "Pm", 145.00 },
    { 62, "Samarium", "Sm", 150.36 },
    { 63, "Europium", "Eu", 151.96 },
    { 64, "Gadolinium", "Gd", 157.25 },
    { 65, "Terbium", "Tb", 158.93 },
    { 66, "Dysprosium", "Dy", 162.50 },
    { 67, "Holmium", "Ho", 164.93 },
    { 68, "Erbium", "Er", 167.26 },
    { 69, "Thulium", "Tm", 168.93 },
    { 70, "Ytterbium", "Yb", 173.05 },
    { 71, "Lutetium", "Lu", 175.00 },
    { 72, "Hafnium", "Hf", 178.49 },
    { 73, "Tantalum", "Ta", 180.95 },
    { 74, "Tungsten", "W", 183.84 },
    { 75, "Rhenium", "Re", 186.21 },
    { 76, "Osmium", "Os", 190.23 },
    { 77, "Iridium", "Ir", 192.22 },
    { 78, "Platinum", "Pt", 195.08 },
    { 79, "Gold", "Au", 196.97 },
    { 80, "Mercury", "Hg", 200.59 },
    { 81, "Thallium", "Tl", 204.38 },
    { 82, "Lead", "Pb", 207.2 },
    { 83, "Bismuth", "Bi", 208.98 },
    { 84, "Polonium", "Po", 209.00 },
    { 85, "Astatine", "At", 210.00 },
    { 86, "Radon", "Rn", 222.00 },
    { 87, "Francium", "Fr", 223.00 },
    { 88, "Radium", "Ra", 226.03 },
    { 89, "Actinium", "Ac", 227.03 },
    { 90, "Thorium", "Th", 232.04 },
    { 91, "Protactinium", "Pa", 231.04 },
    { 92, "Uranium", "U", 238.03 },
    { 93, "Neptunium", "Np", 237.05 },
    { 94, "Plutonium", "Pu", 244.06 },
    { 95, "Americium", "Am", 243.06 },
    { 96, "Curium", "Cm", 247.07 },
    { 97, "Berkelium", "Bk", 247.07 },
    { 98, "Californium", "Cf", 251.08 },
    { 99, "Einsteinium", "Es", 252.08 },
    { 100, "Fermium", "Fm", 257.10 },
    { 101, "Mendelevium", "Md", 258.10 },
    { 102, "Nobelium", "No", 259.10 },
    { 103, "Lawrencium", "Lr", 262.11 },
    { 104, "Rutherfordium", "Rf", 267.12 },
    { 105, "Dubnium", "Db", 270.13 },
    { 106, "Seaborgium", "Sg", 271.13 },
    { 107, "Bohrium", "Bh", 270.13 },
    { 108, "Hassium", "Hs", 277.15 },
    { 109, "Meitnerium", "Mt", 276.15 },
    { 110, "Darmstadtium", "Ds", 281.17 },
    { 111, "Roentgenium", "Rg", 280.17 },
    { 112, "Copernicium", "Cn", 285.18 },
    { 113, "Nihonium", "Nh", 284.18 },
    { 114, "Flerovium", "Fl", 289.19 },
    { 115, "Moscovium", "Mc", 288.19 },
    { 116, "Livermorium", "Lv", 293.21 },
    { 117, "Tennessine", "Ts", 294.21 },
    { 118, "Oganesson", "Og", 294.21 }
};

// Function prototypes
void displayMenu();
void displayAllElements();
void displayElementBySymbol();
void displayElementByName();
Element findElementBySymbol(char *symbol);
Element findElementByName(char *name);

int main() {
    int choice;

    do {
        // Display menu and read user's choice
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllElements();
                break;
            case 2:
                displayElementBySymbol();
                break;
            case 3:
                displayElementByName();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("=================\n");
    printf("PERIODIC TABLE\n");
    printf("=================\n");
    printf("1. Display all elements\n");
    printf("2. Display element by symbol\n");
    printf("3. Display element by name\n");
    printf("4. Quit program\n");
    printf("Enter your choice: ");
}

void displayAllElements() {
    printf("============================\n");
    printf("ATOMIC NUMBER     SYMBOL     NAME     ATOMIC MASS\n");
    printf("============================\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%-17d%-11s%-11s%.2f\n", periodicTable[i].atomicNumber, periodicTable[i].symbol, periodicTable[i].name, periodicTable[i].atomicMass);
    }
}

void displayElementBySymbol() {
    char symbol[MAX_SYMBOL_LENGTH];

    printf("Enter symbol: ");
    scanf("%s", symbol);

    Element foundElement = findElementBySymbol(symbol);

    if (foundElement.atomicNumber == 0) {
        printf("Element not found.\n");
    } else {
        printf("============================\n");
        printf("ATOMIC NUMBER     SYMBOL     NAME     ATOMIC MASS\n");
        printf("============================\n");
        printf("%-17d%-11s%-11s%.2f\n", foundElement.atomicNumber, foundElement.symbol, foundElement.name, foundElement.atomicMass);
    }
}

void displayElementByName() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    Element foundElement = findElementByName(name);

    if (foundElement.atomicNumber == 0) {
        printf("Element not found.\n");
    } else {
        printf("============================\n");
        printf("ATOMIC NUMBER     SYMBOL     NAME     ATOMIC MASS\n");
        printf("============================\n");
        printf("%-17d%-11s%-11s%.2f\n", foundElement.atomicNumber, foundElement.symbol, foundElement.name, foundElement.atomicMass);
    }
}

Element findElementBySymbol(char *symbol) {
    Element foundElement = {0, "", "", 0.0};

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(periodicTable[i].symbol, symbol) == 0) {
            foundElement = periodicTable[i];
            break;
        }
    }

    return foundElement;
}

Element findElementByName(char *name) {
    Element foundElement = {0, "", "", 0.0};

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(periodicTable[i].name, name) == 0) {
            foundElement = periodicTable[i];
            break;
        }
    }

    return foundElement;
}