//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of elements in the Periodic Table
#define NUM_ELEMENTS 118

// Define the maximum number of questions
#define MAX_QUESTIONS 20

// Define the maximum number of choices per question
#define MAX_CHOICES 6

// Define the maximum length of an element symbol or name
#define MAX_ELEMENT_NAME 20


// Define the structure for a single element

typedef struct Element Element;

struct Element {
    char symbol[MAX_ELEMENT_NAME];
    char name[MAX_ELEMENT_NAME];
    int atomic_number;
};

// Define the global array for the periodic table

Element periodic_table[NUM_ELEMENTS] = {
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
    {"Og", "Oganesson", 118}
};

int main() {
    srand(time(NULL)); // Initialize random number generator

    int num_questions, num_choices;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want? (maximum is %d) ", MAX_QUESTIONS);
    scanf("%d", &num_questions);
    printf("How many choices per question do you want? (maximum is %d) ", MAX_CHOICES);
    scanf("%d", &num_choices);

    if (num_questions > MAX_QUESTIONS) {
        printf("Sorry, the maximum number of questions is %d.\n", MAX_QUESTIONS);
        return 1;
    }

    if (num_choices > MAX_CHOICES) {
        printf("Sorry, the maximum number of choices per question is %d.\n", MAX_CHOICES);
        return 1;
    }

    int choices[num_choices];

    for (int i = 0; i < num_questions; i++) {
        // Choose a random atomic number as the correct answer
        int correct_answer = rand() % NUM_ELEMENTS;
        printf("Question %d:\n", i + 1);
        printf("What is the symbol for element number %d?\n", periodic_table[correct_answer].atomic_number);

        // Generate random choices
        for (int j = 0; j < num_choices - 1; j++) {
            int choice = rand() % NUM_ELEMENTS;
            while (choice == correct_answer) {
                choice = rand() % NUM_ELEMENTS;
            }
            choices[j] = choice;
        }

        // Replace one of the random choices with the correct answer
        int correct_choice = rand() % num_choices;
        choices[correct_choice] = correct_answer;

        // Shuffle the choices
        for (int j = num_choices - 1; j >= 0; j--) {
            int k = rand() % (j + 1);
            int temp = choices[j];
            choices[j] = choices[k];
            choices[k] = temp;
        }

        // Print the choices
        for (int j = 0; j < num_choices; j++) {
            printf("%d) %s\n", j + 1, periodic_table[choices[j]].symbol);
        }

        // Get user input
        int user_choice;
        printf("Enter your answer: ");
        scanf("%d", &user_choice);

        // Check the answer
        if (user_choice == correct_choice + 1) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[correct_answer].symbol);
        }
        printf("\n");
    }

    printf("Thanks for playing!\n");

    return 0;
}