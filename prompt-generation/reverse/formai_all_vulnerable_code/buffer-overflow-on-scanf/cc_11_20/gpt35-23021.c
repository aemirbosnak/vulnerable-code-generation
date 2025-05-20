//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[20];
    int atomic_number;
    float atomic_weight;
} Element;

Element elements[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.01},
    {"N", "Nitrogen", 7, 14.01},
    {"O", "Oxygen", 8, 16.00},
    {"F", "Fluorine", 9, 19.00},
    {"Ne", "Neon", 10, 20.18},
    {"Na", "Sodium", 11, 22.99},
    {"Mg", "Magnesium", 12, 24.31},
    {"Al", "Aluminum", 13, 26.98},
    {"Si", "Silicon", 14, 28.09},
    {"P", "Phosphorus", 15, 30.97},
    {"S", "Sulfur", 16, 32.07},
    {"Cl", "Chlorine", 17, 35.45},
    {"K", "Potassium", 19, 39.10},
    {"Ar", "Argon", 18, 39.95},
    {"Ca", "Calcium", 20, 40.08},
    {"Sc", "Scandium", 21, 44.96},
    {"Ti", "Titanium", 22, 47.87},
    {"V", "Vanadium", 23, 50.94},
    {"Cr", "Chromium", 24, 52.00},
    {"Mn", "Manganese", 25, 54.94},
    {"Fe", "Iron", 26, 55.85},
    {"Ni", "Nickel", 28, 58.69},
    {"Co", "Cobalt", 27, 58.93},
    {"Cu", "Copper", 29, 63.55},
    {"Zn", "Zinc", 30, 65.39},
    {"Ga", "Gallium", 31, 69.72},
    {"Ge", "Germanium", 32, 72.63},
    {"As", "Arsenic", 33, 74.92},
    {"Se", "Selenium", 34, 78.96},
    {"Br", "Bromine", 35, 79.90},
    {"Kr", "Krypton", 36, 83.80},
    {"Rb", "Rubidium", 37, 85.47},
    {"Sr", "Strontium", 38, 87.62},
    {"Y", "Yttrium", 39, 88.91},
    {"Zr", "Zirconium", 40, 91.22},
    {"Nb", "Niobium", 41, 92.91},
    {"Mo", "Molybdenum", 42, 95.94},
    {"Tc", "Technetium", 43, 98.00},
    {"Ru", "Ruthenium", 44, 101.07},
    {"Rh", "Rhodium", 45, 102.91},
    {"Pd", "Palladium", 46, 106.42},
    {"Ag", "Silver", 47, 107.87},
    {"Cd", "Cadmium", 48, 112.41},
    {"In", "Indium", 49, 114.82},
    {"Sn", "Tin", 50, 118.71},
    {"Sb", "Antimony", 51, 121.76},
    {"Te", "Tellurium", 52, 127.60},
    {"I", "Iodine", 53, 126.90},
    {"Xe", "Xenon", 54, 131.29},
    {"Cs", "Cesium", 55, 132.91},
    {"Ba", "Barium", 56, 137.33},
    {"La", "Lanthanum", 57, 138.91},
    {"Ce", "Cerium", 58, 140.12},
    {"Pr", "Praseodymium", 59, 140.91},
    {"Nd", "Neodymium", 60, 144.24},
    {"Pm", "Promethium", 61, 145.00},
    {"Sm", "Samarium", 62, 150.36},
    {"Eu", "Europium", 63, 151.96},
    {"Gd", "Gadolinium", 64, 157.25},
    {"Tb", "Terbium", 65, 158.93},
    {"Dy", "Dysprosium", 66, 162.50},
    {"Ho", "Holmium", 67, 164.93},
    {"Er", "Erbium", 68, 167.26},
    {"Tm", "Thulium", 69, 168.93},
    {"Yb", "Ytterbium", 70, 173.05},
    {"Lu", "Lutetium", 71, 174.97},
    {"Hf", "Hafnium", 72, 178.49},
    {"Ta", "Tantalum", 73, 180.95},
    {"W", "Tungsten", 74, 183.84},
    {"Re", "Rhenium", 75, 186.21},
    {"Os", "Osmium", 76, 190.23},
    {"Ir", "Iridium", 77, 192.22},
    {"Pt", "Platinum", 78, 195.08},
    {"Au", "Gold", 79, 196.97},
    {"Hg", "Mercury", 80, 200.59},
    {"Tl", "Thallium", 81, 204.38},
    {"Pb", "Lead", 82, 207.2},
    {"Bi", "Bismuth", 83, 208.98},
    {"Po", "Polonium", 84, 209.00},
    {"At", "Astatine", 85, 210.00},
    {"Rn", "Radon", 86, 222.02},
    {"Fr", "Francium", 87, 223.02},
    {"Ra", "Radium", 88, 226.03},
    {"Ac", "Actinium", 89, 227.03},
    {"Pa", "Protactinium", 91, 231.04},
    {"Th", "Thorium", 90, 232.04},
    {"Np", "Neptunium", 93, 237.05},
    {"U", "Uranium", 92, 238.03},
    {"Am", "Americium", 95, 243.06},
    {"Pu", "Plutonium", 94, 244.06},
    {"Cm", "Curium", 96, 247.07},
    {"Bk", "Berkelium", 97, 247.07},
    {"Cf", "Californium", 98, 251.08},
    {"Es", "Einsteinium", 99, 252.08},
    {"Fm", "Fermium", 100, 257.10},
    {"Md", "Mendelevium", 101, 258.10},
    {"No", "Nobelium", 102, 259.10},
    {"Lr", "Lawrencium", 103, 262.11},
    {"Rf", "Rutherfordium", 104, 261.11},
    {"Db", "Dubnium", 105, 262.11},
    {"Sg", "Seaborgium", 106, 266.12},
    {"Bh", "Bohrium", 107, 264.12},
    {"Hs", "Hassium", 108, 267.13},
    {"Mt", "Meitnerium", 109, 266.13},
    {"Ds", "Darmstadtium", 110, 271.14},
    {"Rg", "Roentgenium", 111, 272.14},
    {"Cn", "Copernicium", 112, 277.15},
    {"Nh", "Nihonium", 113, 284.18},
    {"Fl", "Flerovium", 114, 289.19},
    {"Mc", "Moscovium", 115, 288.19},
    {"Lv", "Livermorium", 116, 293.20},
    {"Ts", "Tennessine", 117, 294.21},
    {"Og", "Oganesson", 118, 294.21},
};

int main() {
    int selection;

    do {
        printf("\nWhat would you like to know about an element?\n");
        printf("1. Symbol\n");
        printf("2. Name\n");
        printf("3. Atomic Number\n");
        printf("4. Atomic Weight\n");
        printf("5. Exit\n");

        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printf("Enter an element symbol: ");
                char symbol[MAX_SYMBOL_LENGTH];
                scanf("%s", symbol);
                for (int i = 0; i < NUM_ELEMENTS; i++) {
                    if (strcmp(symbol, elements[i].symbol) == 0) {
                        printf("%s has symbol %s.\n", elements[i].name, elements[i].symbol);
                        break;
                    }
                    else if (i == NUM_ELEMENTS - 1) {
                        printf("Invalid element symbol.\n");
                    }
                }
                break;

            case 2:
                printf("Enter an element name: ");
                char name[20];
                scanf("%s", name);
                for (int i = 0; i < NUM_ELEMENTS; i++) {
                    if (strcmp(name, elements[i].name) == 0) {
                        printf("%s is element number %d.\n", elements[i].name, elements[i].atomic_number);
                        break;
                    }
                    else if (i == NUM_ELEMENTS - 1) {
                        printf("Invalid element name.\n");
                    }
                }
                break;

            case 3:
                printf("Enter an atomic number: ");
                int atomic_number;
                scanf("%d", &atomic_number);
                for (int i = 0; i < NUM_ELEMENTS; i++) {
                    if (atomic_number == elements[i].atomic_number) {
                        printf("Element %s has atomic number %d.\n", elements[i].name, elements[i].atomic_number);
                        break;
                    }
                    else if (i == NUM_ELEMENTS - 1) {
                        printf("Invalid atomic number.\n");
                    }
                }
                break;

            case 4:
                printf("Enter an element symbol: ");
                char symbol2[MAX_SYMBOL_LENGTH];
                scanf("%s", symbol2);
                for (int i = 0; i < NUM_ELEMENTS; i++) {
                    if (strcmp(symbol2, elements[i].symbol) == 0) {
                        printf("%s has an atomic weight of %.2f.\n", elements[i].name, elements[i].atomic_weight);
                        break;
                    }
                    else if (i == NUM_ELEMENTS - 1) {
                        printf("Invalid element symbol.\n");
                    }
                }
                break;

            case 5:
                break;

            default:
                printf("Invalid selection.\n");
                break;
        }

    } while (selection != 5);

    return 0;
}