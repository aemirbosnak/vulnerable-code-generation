//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the maximum number of guesses allowed in the quiz
#define MAX_GUESSES 3

// Define the structure for an element
struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

// Declare an array of element structures
struct Element periodic_table[NUM_ELEMENTS] = {
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

// Declare a function to choose a random element
int choose_random_element() {
    return rand() % NUM_ELEMENTS;
}

// Declare a function to initialize the quiz
void initialize_quiz() {
    // Print the title of the quiz
    printf("**** C Periodic Table Quiz ****\n\n");
    // Print the instructions for the quiz
    printf("For each element, you will be given its symbol and atomic number.\n"
           "You have to guess its name. You have %d guesses per element.\n"
           "You can enter 'quit' at any time to end the quiz.\n\n",
           MAX_GUESSES);
    // Seed the random number generator
    srand(time(NULL));
}

// Declare a function to prompt the user for a guess
void prompt_guess(char *guess) {
    printf("Enter your guess (or 'quit'): ");
    scanf("%s", guess);
}

// Declare a function to check the user's guess
int check_guess(char *guess, int element_idx) {
    // Convert the guess to lowercase
    int i;
    for (i = 0; guess[i] != '\0'; i++) {
        guess[i] = tolower(guess[i]);
    }
    // Compare the guess to the name of the element
    if (strcmp(guess, periodic_table[element_idx].name) == 0) {
        printf("\nCongratulations! You guessed the element correctly.\n\n");
        return 1;
    } else {
        printf("\nSorry, that's not correct.\n");
        return 0;
    }
}

// Declare a function to run the quiz
void run_quiz() {
    // Initialize the quiz
    initialize_quiz();
    // Loop through the elements of the periodic table
    int i, element_idx, num_guesses, correct_guesses = 0;
    char guess[20];
    for (i = 0; i < NUM_ELEMENTS; i++) {
        // Choose a random element
        element_idx = choose_random_element();
        // Print the symbol and atomic number of the element
        printf("Element %d: %s (%d)\n", i+1, periodic_table[element_idx].symbol,
               periodic_table[element_idx].atomic_number);
        // Loop through the guesses allowed
        for (num_guesses = 1; num_guesses <= MAX_GUESSES; num_guesses++) {
            // Prompt the user for a guess
            prompt_guess(guess);
            // Check if the user wants to quit
            if (strcmp(guess, "quit") == 0) {
                printf("\nQuitting the quiz...\n");
                return;
            }
            // Check the user's guess
            if (check_guess(guess, element_idx)) {
                correct_guesses++;
                break;
            } else {
                printf("You have %d guesses left.\n", MAX_GUESSES-num_guesses);
            }
        }
    }
    // Print the final score
    printf("Quiz completed.\n");
    printf("You guessed %d elements correctly out of %d.\n", correct_guesses, NUM_ELEMENTS);
}

// Declare the main function
int main() {
    // Run the quiz
    run_quiz();
    // Exit the program
    return 0;
}