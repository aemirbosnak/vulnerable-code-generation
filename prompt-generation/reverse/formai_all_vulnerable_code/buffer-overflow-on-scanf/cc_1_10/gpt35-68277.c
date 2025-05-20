//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

struct Element {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char state[MAX_NAME_LENGTH];
};

void printElement(struct Element element) {
    printf("%d. %s (%s) is a(n) %s\n", element.atomicNumber, element.name, element.symbol, element.state);
}

void printTable(struct Element table[]) {
    int i;
    for(i = 0; i < MAX_ELEMENTS; i++) {
        printElement(table[i]);
    }
}

void quiz(struct Element table[]) {
    int score = 0;
    int answer;
    int i;
    struct Element currentElement;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a series of questions about the elements in the table.\n");

    for(i = 0; i < 10; i++) {
        currentElement = table[rand() % MAX_ELEMENTS];

        printf("Question %d:\n", i+1);
        printf("What is the atomic number of %s? ", currentElement.name);
        scanf("%d", &answer);

        if(answer == currentElement.atomicNumber) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer was %d.\n", currentElement.atomicNumber);
        }
    }

    printf("Quiz results: You scored %d out of 10.\n", score);
}

int main() {
    struct Element periodicTable[MAX_ELEMENTS] = {
        { 1, "Hydrogen", "H", "gas" },
        { 2, "Helium", "He", "gas" },
        { 3, "Lithium", "Li", "solid" },
        { 4, "Beryllium", "Be", "solid" },
        { 5, "Boron", "B", "solid" },
        { 6, "Carbon", "C", "solid" },
        { 7, "Nitrogen", "N", "gas" },
        { 8, "Oxygen", "O", "gas" },
        { 9, "Fluorine", "F", "gas" },
        { 10, "Neon", "Ne", "gas" },
        { 11, "Sodium", "Na", "solid" },
        { 12, "Magnesium", "Mg", "solid" },
        { 13, "Aluminum", "Al", "solid" },
        { 14, "Silicon", "Si", "solid" },
        { 15, "Phosphorus", "P", "solid" },
        { 16, "Sulfur", "S", "solid" },
        { 17, "Chlorine", "Cl", "gas" },
        { 18, "Argon", "Ar", "gas" },
        { 19, "Potassium", "K", "solid" },
        { 20, "Calcium", "Ca", "solid" },
        { 21, "Scandium", "Sc", "solid" },
        { 22, "Titanium", "Ti", "solid" },
        { 23, "Vanadium", "V", "solid" },
        { 24, "Chromium", "Cr", "solid" },
        { 25, "Manganese", "Mn", "solid" },
        { 26, "Iron", "Fe", "solid" },
        { 27, "Cobalt", "Co", "solid" },
        { 28, "Nickel", "Ni", "solid" },
        { 29, "Copper", "Cu", "solid" },
        { 30, "Zinc", "Zn", "solid" },
        { 31, "Gallium", "Ga", "solid" },
        { 32, "Germanium", "Ge", "solid" },
        { 33, "Arsenic", "As", "solid" },
        { 34, "Selenium", "Se", "solid" },
        { 35, "Bromine", "Br", "liquid" },
        { 36, "Krypton", "Kr", "gas" },
        { 37, "Rubidium", "Rb", "solid" },
        { 38, "Strontium", "Sr", "solid" },
        { 39, "Yttrium", "Y", "solid" },
        { 40, "Zirconium", "Zr", "solid" },
        { 41, "Niobium", "Nb", "solid" },
        { 42, "Molybdenum", "Mo", "solid" },
        { 43, "Technetium", "Tc", "solid" },
        { 44, "Ruthenium", "Ru", "solid" },
        { 45, "Rhodium", "Rh", "solid" },
        { 46, "Palladium", "Pd", "solid" },
        { 47, "Silver", "Ag", "solid" },
        { 48, "Cadmium", "Cd", "solid" },
        { 49, "Indium", "In", "solid" },
        { 50, "Tin", "Sn", "solid" },
        { 51, "Antimony", "Sb", "solid" },
        { 52, "Tellurium", "Te", "solid" },
        { 53, "Iodine", "I", "solid" },
        { 54, "Xenon", "Xe", "gas" },
        { 55, "Cesium", "Cs", "solid" },
        { 56, "Barium", "Ba", "solid" },
        { 57, "Lanthanum", "La", "solid" },
        { 58, "Cerium", "Ce", "solid" },
        { 59, "Praseodymium", "Pr", "solid" },
        { 60, "Neodymium", "Nd", "solid" },
        { 61, "Promethium", "Pm", "solid" },
        { 62, "Samarium", "Sm", "solid" },
        { 63, "Europium", "Eu", "solid" },
        { 64, "Gadolinium", "Gd", "solid" },
        { 65, "Terbium", "Tb", "solid" },
        { 66, "Dysprosium", "Dy", "solid" },
        { 67, "Holmium", "Ho", "solid" },
        { 68, "Erbium", "Er", "solid" },
        { 69, "Thulium", "Tm", "solid" },
        { 70, "Ytterbium", "Yb", "solid" },
        { 71, "Lutetium", "Lu", "solid" },
        { 72, "Hafnium", "Hf", "solid" },
        { 73, "Tantalum", "Ta", "solid" },
        { 74, "Tungsten", "W", "solid" },
        { 75, "Rhenium", "Re", "solid" },
        { 76, "Osmium", "Os", "solid" },
        { 77, "Iridium", "Ir", "solid" },
        { 78, "Platinum", "Pt", "solid" },
        { 79, "Gold", "Au", "solid" },
        { 80, "Mercury", "Hg", "liquid" },
        { 81, "Thallium", "Tl", "solid" },
        { 82, "Lead", "Pb", "solid" },
        { 83, "Bismuth", "Bi", "solid" },
        { 84, "Polonium", "Po", "solid" },
        { 85, "Astatine", "At", "solid" },
        { 86, "Radon", "Rn", "gas" },
        { 87, "Francium", "Fr", "solid" },
        { 88, "Radium", "Ra", "solid" },
        { 89, "Actinium", "Ac", "solid" },
        { 90, "Thorium", "Th", "solid" },
        { 91, "Protactinium", "Pa", "solid" },
        { 92, "Uranium", "U", "solid" },
        { 93, "Neptunium", "Np", "solid" },
        { 94, "Plutonium", "Pu", "solid" },
        { 95, "Americium", "Am", "solid" },
        { 96, "Curium", "Cm", "solid" },
        { 97, "Berkelium", "Bk", "solid" },
        { 98, "Californium", "Cf", "solid" },
        { 99, "Einsteinium", "Es", "solid" },
        { 100, "Fermium", "Fm", "solid" },
        { 101, "Mendelevium", "Md", "solid" },
        { 102, "Nobelium", "No", "solid" },
        { 103, "Lawrencium", "Lr", "solid" },
        { 104, "Rutherfordium", "Rf", "unknown" },
        { 105, "Dubnium", "Db", "unknown" },
        { 106, "Seaborgium", "Sg", "unknown" },
        { 107, "Bohrium", "Bh", "unknown" },
        { 108, "Hassium", "Hs", "unknown" },
        { 109, "Meitnerium", "Mt", "unknown" },
        { 110, "Darmstadtium", "Ds", "unknown" },
        { 111, "Roentgenium", "Rg", "unknown" },
        { 112, "Copernicium", "Cn", "unknown" },
        { 113, "Nihonium", "Nh", "unknown" },
        { 114, "Flerovium", "Fl", "unknown" },
        { 115, "Moscovium", "Mc", "unknown" },
        { 116, "Livermorium", "Lv", "unknown" },
        { 117, "Tennessine", "Ts", "unknown" },
        { 118, "Oganesson", "Og", "unknown" }
    };

    printf("Welcome to the Periodic Table Program!\n");
    printf("Please select an option:\n");
    printf("1. View the entire table\n");
    printf("2. Take the quiz\n");
    printf("Option: ");

    int option;
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nFull Periodic Table:\n");
            printTable(periodicTable);
            break;
        case 2:
            quiz(periodicTable);
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }

    return 0;
}