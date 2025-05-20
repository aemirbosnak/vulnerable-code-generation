//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 118
#define MAX_QUESTIONS 10

typedef struct Element {
    char name[30];
    char symbol[3];
    int atomic_number;
} Element;

Element periodic_table[SIZE] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10},
    {"Sodium", "Na", 11},
    {"Magnesium", "Mg", 12},
    {"Aluminum", "Al", 13},
    {"Silicon", "Si", 14},
    {"Phosphorus", "P", 15},
    {"Sulfur", "S", 16},
    {"Chlorine", "Cl", 17},
    {"Argon", "Ar", 18},
    {"Potassium", "K", 19},
    {"Calcium", "Ca", 20},
    {"Scandium", "Sc", 21},
    {"Titanium", "Ti", 22},
    {"Vanadium", "V", 23},
    {"Chromium", "Cr", 24},
    {"Manganese", "Mn", 25},
    {"Iron", "Fe", 26},
    {"Cobalt", "Co", 27},
    {"Nickel", "Ni", 28},
    {"Copper", "Cu", 29},
    {"Zinc", "Zn", 30},
    {"Gallium", "Ga", 31},
    {"Germanium", "Ge", 32},
    {"Arsenic", "As", 33},
    {"Selenium", "Se", 34},
    {"Bromine", "Br", 35},
    {"Krypton", "Kr", 36},
    {"Rubidium", "Rb", 37},
    {"Strontium", "Sr", 38},
    {"Yttrium", "Y", 39},
    {"Zirconium", "Zr", 40},
    {"Niobium", "Nb", 41},
    {"Molybdenum", "Mo", 42},
    {"Technetium", "Tc", 43},
    {"Ruthenium", "Ru", 44},
    {"Rhodium", "Rh", 45},
    {"Palladium", "Pd", 46},
    {"Silver", "Ag", 47},
    {"Cadmium", "Cd", 48},
    {"Indium", "In", 49},
    {"Tin", "Sn", 50},
    {"Antimony", "Sb", 51},
    {"Tellurium", "Te", 52},
    {"Iodine", "I", 53},
    {"Xenon", "Xe", 54},
    {"Cesium", "Cs", 55},
    {"Barium", "Ba", 56},
    {"Lanthanum", "La", 57},
    {"Cerium", "Ce", 58},
    {"Praseodymium", "Pr", 59},
    {"Neodymium", "Nd", 60},
    {"Promethium", "Pm", 61},
    {"Samarium", "Sm", 62},
    {"Europium", "Eu", 63},
    {"Gadolinium", "Gd", 64},
    {"Terbium", "Tb", 65},
    {"Dysprosium", "Dy", 66},
    {"Holmium", "Ho", 67},
    {"Erbium", "Er", 68},
    {"Thulium", "Tm", 69},
    {"Ytterbium", "Yb", 70},
    {"Lutetium", "Lu", 71},
    {"Hafnium", "Hf", 72},
    {"Tantalum", "Ta", 73},
    {"Tungsten", "W", 74},
    {"Rhenium", "Re", 75},
    {"Osmium", "Os", 76},
    {"Iridium", "Ir", 77},
    {"Platinum", "Pt", 78},
    {"Gold", "Au", 79},
    {"Mercury", "Hg", 80},
    {"Thallium", "Tl", 81},
    {"Lead", "Pb", 82},
    {"Bismuth", "Bi", 83},
    {"Polonium", "Po", 84},
    {"Astatine", "At", 85},
    {"Radon", "Rn", 86},
    {"Francium", "Fr", 87},
    {"Radium", "Ra", 88},
    {"Actinium", "Ac", 89},
    {"Thorium", "Th", 90},
    {"Protactinium", "Pa", 91},
    {"Uranium", "U", 92},
    {"Neptunium", "Np", 93},
    {"Plutonium", "Pu", 94},
    {"Americium", "Am", 95},
    {"Curium", "Cm", 96},
    {"Berkelium", "Bk", 97},
    {"Californium", "Cf", 98},
    {"Einsteinium", "Es", 99},
    {"Fermium", "Fm", 100},
    {"Mendelevium", "Md", 101},
    {"Nobelium", "No", 102},
    {"Lawrencium", "Lr", 103},
    {"Rutherfordium", "Rf", 104},
    {"Dubnium", "Db", 105},
    {"Seaborgium", "Sg", 106},
    {"Bohrium", "Bh", 107},
    {"Hassium", "Hs", 108},
    {"Meitnerium", "Mt", 109},
    {"Darmstadtium", "Ds", 110},
    {"Roentgenium", "Rg", 111},
    {"Copernicium", "Cn", 112},
    {"Nihonium", "Nh", 113},
    {"Flerovium", "Fl", 114},
    {"Moscovium", "Mc", 115},
    {"Livermorium", "Lv", 116},
    {"Tennessine", "Ts", 117},
    {"Oganesson", "Og", 118}
};

// shuffle array
void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// print question and options
void print_question(Element elem, int options[]) {
    printf("What is the atomic number of %s?\n", elem.name);
    for (int i = 0; i < 4; i++) {
        printf("%d. %d\n", i + 1, periodic_table[options[i]].atomic_number);
    }
}

// check answer
int check_answer(Element elem, int answer) {
    return elem.atomic_number == answer;
}

int main() {
    int score = 0;
    int question_number = 1;
    int options[4];
    char choice;

    printf("Welcome to the futuristic Periodic Table Quiz!\n\n");

    do {
        // generate random element
        int rand_index = rand() % SIZE;
        Element rand_elem = periodic_table[rand_index];

        // generate random options
        options[0] = rand_index;
        for (int i = 1; i < 4; i++) {
            options[i] = rand() % SIZE;
        }
        shuffle(options, 4);

        // print question and options
        printf("Question %d:\n", question_number);
        print_question(rand_elem, options);

        // get user answer
        int answer;
        printf("\nEnter your answer (1-4): ");
        scanf("%d", &answer);

        // check answer
        if (check_answer(rand_elem, periodic_table[options[answer - 1]].atomic_number)) {
            printf("\nCorrect!\n\n");
            score++;
        } else {
            printf("\nIncorrect! The correct answer is %d.\n\n", rand_elem.atomic_number);
        }

        question_number++;
    } while(question_number <= MAX_QUESTIONS);

    // print final score
    printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}