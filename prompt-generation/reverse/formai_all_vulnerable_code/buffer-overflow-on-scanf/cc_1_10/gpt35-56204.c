//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[20];
    float atomicMass;
    char state[10];
} Element;

void printTable(Element elements[118], int size) {
    printf("Atomic No. | Symbol | Name | Atomic Mass | State \n");
    for (int i=0; i<size; i++) {
        printf("%d \t\t %s \t %s \t %.2f \t %s \n", elements[i].atomicNumber, elements[i].symbol, elements[i].name, elements[i].atomicMass, elements[i].state);
    }
}

void quiz(Element elements[118], int size) {
    int score = 0;
    int questionNumber = 1;
    char answer[20];
    for (int i=0; i<size; i++) {
        printf("\nQuestion %d: What is the symbol for %s?\n", questionNumber, elements[i].name);
        scanf("%s", answer);
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct! The symbol for %s is %s.\n", elements[i].name, elements[i].symbol);
            score++;
        } else {
            printf("Incorrect. The symbol for %s is %s.\n", elements[i].name, elements[i].symbol);
        }
        questionNumber++;
    }
    printf("\nFinal score: %d/%d. Well done!\n", score, size);
}

int main() {
    Element elements[118] = {
        {1, "H", "Hydrogen", 1.008, "Gas"},
        {2, "He", "Helium", 4.003, "Gas"},
        {3, "Li", "Lithium", 6.941, "Solid"},
        {4, "Be", "Beryllium", 9.012, "Solid"},
        {5, "B", "Boron", 10.81, "Solid"},
        {6, "C", "Carbon", 12.01, "Solid"},
        {7, "N", "Nitrogen", 14.01, "Gas"},
        {8, "O", "Oxygen", 16.00, "Gas"},
        {9, "F", "Fluorine", 19.00, "Gas"},
        {10, "Ne", "Neon", 20.18, "Gas"},
        {11, "Na", "Sodium", 22.99, "Solid"},
        {12, "Mg", "Magnesium", 24.31, "Solid"},
        {13, "Al", "Aluminium", 26.98, "Solid"},
        {14, "Si", "Silicon", 28.09, "Solid"},
        {15, "P", "Phosphorus", 30.97, "Solid"},
        {16, "S", "Sulfur", 32.07, "Solid"},
        {17, "Cl", "Chlorine", 35.45, "Gas"},
        {18, "Ar", "Argon", 39.95, "Gas"},
        {19, "K", "Potassium", 39.10, "Solid"},
        {20, "Ca", "Calcium", 40.08, "Solid"},
        {21, "Sc", "Scandium", 44.96, "Solid"},
        {22, "Ti", "Titanium", 47.87, "Solid"},
        {23, "V", "Vanadium", 50.94, "Solid"},
        {24, "Cr", "Chromium", 52.00, "Solid"},
        {25, "Mn", "Manganese", 54.94, "Solid"},
        {26, "Fe", "Iron", 55.85, "Solid"},
        {27, "Co", "Cobalt", 58.93, "Solid"},
        {28, "Ni", "Nickel", 58.69, "Solid"},
        {29, "Cu", "Copper", 63.55, "Solid"},
        {30, "Zn", "Zinc", 65.38, "Solid"},
        {31, "Ga", "Gallium", 69.72, "Solid"},
        {32, "Ge", "Germanium", 72.63, "Solid"},
        {33, "As", "Arsenic", 74.92, "Solid"},
        {34, "Se", "Selenium", 78.96, "Solid"},
        {35, "Br", "Bromine", 79.90, "Liquid"},
        {36, "Kr", "Krypton", 83.80, "Gas"},
        {37, "Rb", "Rubidium", 85.47, "Solid"},
        {38, "Sr", "Strontium", 87.62, "Solid"},
        {39, "Y", "Yttrium", 88.91, "Solid"},
        {40, "Zr", "Zirconium", 91.22, "Solid"},
        {41, "Nb", "Niobium", 92.91, "Solid"},
        {42, "Mo", "Molybdenum", 95.94, "Solid"},
        {43, "Tc", "Technetium", 98.00, "Solid"},
        {44, "Ru", "Ruthenium", 101.07, "Solid"},
        {45, "Rh", "Rhodium", 102.91, "Solid"},
        {46, "Pd", "Palladium", 106.42, "Solid"},
        {47, "Ag", "Silver", 107.87, "Solid"},
        {48, "Cd", "Cadmium", 112.41, "Solid"},
        {49, "In", "Indium", 114.82, "Solid"},
        {50, "Sn", "Tin", 118.71, "Solid"},
        {51, "Sb", "Antimony", 121.76, "Solid"},
        {52, "Te", "Tellurium", 127.60, "Solid"},
        {53, "I", "Iodine", 126.90, "Solid"},
        {54, "Xe", "Xenon", 131.29, "Gas"},
        {55, "Cs", "Caesium", 132.91, "Solid"},
        {56, "Ba", "Barium", 137.33, "Solid"},
        {57, "La", "Lanthanum", 138.91, "Solid"},
        {58, "Ce", "Cerium", 140.12, "Solid"},
        {59, "Pr", "Praseodymium", 140.91, "Solid"},
        {60, "Nd", "Neodymium", 144.24, "Solid"},
        {61, "Pm", "Promethium", 145.00, "Solid"},
        {62, "Sm", "Samarium", 150.40, "Solid"},
        {63, "Eu", "Europium", 151.96, "Solid"},
        {64, "Gd", "Gadolinium", 157.25, "Solid"},
        {65, "Tb", "Terbium", 158.93, "Solid"},
        {66, "Dy", "Dysprosium", 162.50, "Solid"},
        {67, "Ho", "Holmium", 164.93, "Solid"},
        {68, "Er", "Erbium", 167.26, "Solid"},
        {69, "Tm", "Thulium", 168.93, "Solid"},
        {70, "Yb", "Ytterbium", 173.05, "Solid"},
        {71, "Lu", "Lutetium", 174.97, "Solid"},
        {72, "Hf", "Hafnium", 178.49, "Solid"},
        {73, "Ta", "Tantalum", 180.95, "Solid"},
        {74, "W", "Tungsten", 183.84, "Solid"},
        {75, "Re", "Rhenium", 186.21, "Solid"},
        {76, "Os", "Osmium", 190.23, "Solid"},
        {77, "Ir", "Iridium", 192.22, "Solid"},
        {78, "Pt", "Platinum", 195.08, "Solid"},
        {79, "Au", "Gold", 196.97, "Solid"},
        {80, "Hg", "Mercury", 200.59, "Liquid"},
        {81, "Tl", "Thallium", 204.38, "Solid"},
        {82, "Pb", "Lead", 207.2, "Solid"},
        {83, "Bi", "Bismuth", 208.98, "Solid"},
        {84, "Po", "Polonium", 209.00, "Solid"},
        {85, "At", "Astatine", 210.00, "Solid"},
        {86, "Rn", "Radon", 222.00, "Gas"},
        {87, "Fr", "Francium", 223.00, "Solid"},
        {88, "Ra", "Radium", 226.03, "Solid"},
        {89, "Ac", "Actinium", 227.03, "Solid"},
        {90, "Th", "Thorium", 232.04, "Solid"},
        {91, "Pa", "Protactinium", 231.04, "Solid"},
        {92, "U", "Uranium", 238.03, "Solid"},
        {93, "Np", "Neptunium", 237.05, "Solid"},
        {94, "Pu", "Plutonium", 244.06, "Solid"},
        {95, "Am", "Americium", 243.06, "Solid"},
        {96, "Cm", "Curium", 247.07, "Solid"},
        {97, "Bk", "Berkelium", 247.07, "Solid"},
        {98, "Cf", "Californium", 251.08, "Solid"},
        {99, "Es", "Einsteinium", 252.08, "Solid"},
        {100, "Fm", "Fermium", 257.10, "Solid"},
        {101, "Md", "Mendelevium", 258.10, "Solid"},
        {102, "No", "Nobelium", 259.10, "Solid"},
        {103, "Lr", "Lawrencium", 262.11, "Solid"},
        {104, "Rf", "Rutherfordium", 267.12, "Unknown"},
        {105, "Db", "Dubnium", 270.00, "Unknown"},
        {106, "Sg", "Seaborgium", 271.00, "Unknown"},
        {107, "Bh", "Bohrium", 270.00, "Unknown"},
        {108, "Hs", "Hassium", 277.00, "Unknown"},
        {109, "Mt", "Meitnerium", 276.00, "Unknown"},
        {110, "Ds", "Darmstadtium", 281.00, "Unknown"},
        {111, "Rg", "Roentgenium", 280.00, "Unknown"},
        {112, "Cn", "Copernicium", 285.00, "Unknown"},
        {113, "Nh", "Nihonium", 284.00, "Unknown"},
        {114, "Fl", "Flerovium", 289.00, "Unknown"},
        {115, "Mc", "Moscovium", 288.00, "Unknown"},
        {116, "Lv", "Livermorium", 293.00, "Unknown"},
        {117, "Ts", "Tennessine", 294.00, "Unknown"},
        {118, "Og", "Oganesson", 294.00, "Unknown"},
    };

    int tableSize = sizeof(elements)/sizeof(Element);
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There are %d elements in the table. \n", tableSize);
    printf("Press 1 to see the full table or 2 to continue to the quiz: ");

    int userChoice;
    scanf("%d", &userChoice);

    if (userChoice == 1) {
        printTable(elements, tableSize);
    } else if (userChoice == 2) {
        quiz(elements, tableSize);
    } else {
        printf("Invalid choice. \n");
    }

    return 0;
}