//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 118

/* Structure to hold information about an element */
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

/* Function to generate a random number within a range */
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Function to shuffle an array of elements */
void shuffle(Element *elements, int num_elements) {
    int i, j;
    Element temp;

    for (i = num_elements - 1; i > 0; i--) {
        j = rand_range(0, i);
        temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

/* Function to ask a question about an element */
void ask_question(Element *element, int question_num) {
    char answer[20];

    printf("Question %d: What is the symbol for %s?\n", question_num, element->name);
    printf("> ");
    scanf("%s", answer);

    if (strcmp(answer, element->symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct symbol for %s is %s.\n", element->name, element->symbol);
    }
}

int main() {
    srand(time(NULL));

    Element elements[MAX_ELEMENTS] = {
        {"H", "Hydrogen", 1},
        {"He", "Helium", 2},
        {"Li", "Lithium", 3},
        {"Be", "Beryllium", 4},
        {"B", "Boron", 5},
        {"C", "Carbon", 6},
        {"N", "Nitrogen", 7},
        {"O", "Oxygen", 8},
        {"F", "Fluorine", 9},
        {"Ne", "Neon", 10},
        {"Na", "Sodium", 11},
        {"Mg", "Magnesium", 12},
        {"Al", "Aluminum", 13},
        {"Si", "Silicon", 14},
        {"P", "Phosphorus", 15},
        {"S", "Sulfur", 16},
        {"Cl", "Chlorine", 17},
        {"Ar", "Argon", 18},
        {"K", "Potassium", 19},
        {"Ca", "Calcium", 20},
        {"Sc", "Scandium", 21},
        {"Ti", "Titanium", 22},
        {"V", "Vanadium", 23},
        {"Cr", "Chromium", 24},
        {"Mn", "Manganese", 25},
        {"Fe", "Iron", 26},
        {"Co", "Cobalt", 27},
        {"Ni", "Nickel", 28},
        {"Cu", "Copper", 29},
        {"Zn", "Zinc", 30},
        {"Ga", "Gallium", 31},
        {"Ge", "Germanium", 32},
        {"As", "Arsenic", 33},
        {"Se", "Selenium", 34},
        {"Br", "Bromine", 35},
        {"Kr", "Krypton", 36},
        {"Rb", "Rubidium", 37},
        {"Sr", "Strontium", 38},
        {"Y", "Yttrium", 39},
        {"Zr", "Zirconium", 40},
        {"Nb", "Niobium", 41},
        {"Mo", "Molybdenum", 42},
        {"Tc", "Technetium", 43},
        {"Ru", "Ruthenium", 44},
        {"Rh", "Rhodium", 45},
        {"Pd", "Palladium", 46},
        {"Ag", "Silver", 47},
        {"Cd", "Cadmium", 48},
        {"In", "Indium", 49},
        {"Sn", "Tin", 50},
        {"Sb", "Antimony", 51},
        {"Te", "Tellurium", 52},
        {"I", "Iodine", 53},
        {"Xe", "Xenon", 54},
        {"Cs", "Cesium", 55},
        {"Ba", "Barium", 56},
        {"La", "Lanthanum", 57},
        {"Ce", "Cerium", 58},
        {"Pr", "Praseodymium", 59},
        {"Nd", "Neodymium", 60},
        {"Pm", "Promethium", 61},
        {"Sm", "Samarium", 62},
        {"Eu", "Europium", 63},
        {"Gd", "Gadolinium", 64},
        {"Tb", "Terbium", 65},
        {"Dy", "Dysprosium", 66},
        {"Ho", "Holmium", 67},
        {"Er", "Erbium", 68},
        {"Tm", "Thulium", 69},
        {"Yb", "Ytterbium", 70},
        {"Lu", "Lutetium", 71},
        {"Hf", "Hafnium", 72},
        {"Ta", "Tantalum", 73},
        {"W", "Tungsten", 74},
        {"Re", "Rhenium", 75},
        {"Os", "Osmium", 76},
        {"Ir", "Iridium", 77},
        {"Pt", "Platinum", 78},
        {"Au", "Gold", 79},
        {"Hg", "Mercury", 80},
        {"Tl", "Thallium", 81},
        {"Pb", "Lead", 82},
        {"Bi", "Bismuth", 83},
        {"Po", "Polonium", 84},
        {"At", "Astatine", 85},
        {"Rn", "Radon", 86},
        {"Fr", "Francium", 87},
        {"Ra", "Radium", 88},
        {"Ac", "Actinium", 89},
        {"Th", "Thorium", 90},
        {"Pa", "Protactinium", 91},
        {"U", "Uranium", 92},
        {"Np", "Neptunium", 93},
        {"Pu", "Plutonium", 94},
        {"Am", "Americium", 95},
        {"Cm", "Curium", 96},
        {"Bk", "Berkelium", 97},
        {"Cf", "Californium", 98},
        {"Es", "Einsteinium", 99},
        {"Fm", "Fermium", 100},
        {"Md", "Mendelevium", 101},
        {"No", "Nobelium", 102},
        {"Lr", "Lawrencium", 103},
        {"Rf", "Rutherfordium", 104},
        {"Db", "Dubnium", 105},
        {"Sg", "Seaborgium", 106},
        {"Bh", "Bohrium", 107},
        {"Hs", "Hassium", 108},
        {"Mt", "Meitnerium", 109},
        {"Ds", "Darmstadtium", 110},
        {"Rg", "Roentgenium", 111},
        {"Cn", "Copernicium", 112},
        {"Nh", "Nihonium", 113},
        {"Fl", "Flerovium", 114},
        {"Mc", "Moscovium", 115},
        {"Lv", "Livermorium", 116},
        {"Ts", "Tennessine", 117},
        {"Og", "Oganesson", 118},
    };

    int num_questions;
    printf("Welcome to the Periodic Table quiz!\n");
    printf("How many questions would you like to answer? (1-%d)\n", MAX_ELEMENTS);
    printf("> ");
    scanf("%d", &num_questions);

    if (num_questions < 1 || num_questions > MAX_ELEMENTS) {
        printf("Invalid number of questions.\n");
        return 1;
    }

    /* Shuffle the elements array to randomize the questions */
    shuffle(elements, MAX_ELEMENTS);

    int i;
    for (i = 0; i < num_questions; i++) {
        ask_question(&elements[i], i+1);
    }

    printf("Thanks for playing!\n");

    return 0;
}