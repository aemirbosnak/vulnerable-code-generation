//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the element names and symbols
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define a structure to hold information about each element
typedef struct element_t {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    float atomic_weight;
} Element;

// Define an array to hold information about each element in the periodic table
Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.003},
    {"Lithium", "Li", 3, 6.941},
    {"Beryllium", "Be", 4, 9.012},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.01},
    {"Nitrogen", "N", 7, 14.01},
    {"Oxygen", "O", 8, 16.00},
    {"Fluorine", "F", 9, 19.00},
    {"Neon", "Ne", 10, 20.18},
    {"Sodium", "Na", 11, 22.99},
    {"Magnesium", "Mg", 12, 24.31},
    {"Aluminum", "Al", 13, 26.98},
    {"Silicon", "Si", 14, 28.09},
    {"Phosphorus", "P", 15, 30.97},
    {"Sulfur", "S", 16, 32.07},
    {"Chlorine", "Cl", 17, 35.45},
    {"Argon", "Ar", 18, 39.95},
    {"Potassium", "K", 19, 39.10},
    {"Calcium", "Ca", 20, 40.08},
    {"Scandium", "Sc", 21, 44.96},
    {"Titanium", "Ti", 22, 47.87},
    {"Vanadium", "V", 23, 50.94},
    {"Chromium", "Cr", 24, 52.00},
    {"Manganese", "Mn", 25, 54.94},
    {"Iron", "Fe", 26, 55.85},
    {"Cobalt", "Co", 27, 58.93},
    {"Nickel", "Ni", 28, 58.69},
    {"Copper", "Cu", 29, 63.55},
    {"Zinc", "Zn", 30, 65.39},
    {"Gallium", "Ga", 31, 69.72},
    {"Germanium", "Ge", 32, 72.63},
    {"Arsenic", "As", 33, 74.92},
    {"Selenium", "Se", 34, 78.96},
    {"Bromine", "Br", 35, 79.90},
    {"Krypton", "Kr", 36, 83.80},
    {"Rubidium", "Rb", 37, 85.47},
    {"Strontium", "Sr", 38, 87.62},
    {"Yttrium", "Y", 39, 88.91},
    {"Zirconium", "Zr", 40, 91.22},
    {"Niobium", "Nb", 41, 92.91},
    {"Molybdenum", "Mo", 42, 95.94},
    {"Technetium", "Tc", 43, 98.00},
    {"Ruthenium", "Ru", 44, 101.07},
    {"Rhodium", "Rh", 45, 102.91},
    {"Palladium", "Pd", 46, 106.42},
    {"Silver", "Ag", 47, 107.87},
    {"Cadmium", "Cd", 48, 112.41},
    {"Indium", "In", 49, 114.82},
    {"Tin", "Sn", 50, 118.71},
    {"Antimony", "Sb", 51, 121.76},
    {"Tellurium", "Te", 52, 127.60},
    {"Iodine", "I", 53, 126.90},
    {"Xenon", "Xe", 54, 131.29},
    {"Cesium", "Cs", 55, 132.91},
    {"Barium", "Ba", 56, 137.33},
    {"Lanthanum", "La", 57, 138.91},
    {"Cerium", "Ce", 58, 140.12},
    {"Praseodymium", "Pr", 59, 140.91},
    {"Neodymium", "Nd", 60, 144.24},
    {"Promethium", "Pm", 61, 145.00},
    {"Samarium", "Sm", 62, 150.36},
    {"Europium", "Eu", 63, 151.96},
    {"Gadolinium", "Gd", 64, 157.25},
    {"Terbium", "Tb", 65, 158.93},
    {"Dysprosium", "Dy", 66, 162.50},
    {"Holmium", "Ho", 67, 164.93},
    {"Erbium", "Er", 68, 167.26},
    {"Thulium", "Tm", 69, 168.93},
    {"Ytterbium", "Yb", 70, 173.05},
    {"Lutetium", "Lu", 71, 174.97},
    {"Hafnium", "Hf", 72, 178.49},
    {"Tantalum", "Ta", 73, 180.95},
    {"Tungsten", "W", 74, 183.84},
    {"Rhenium", "Re", 75, 186.21},
    {"Osmium", "Os", 76, 190.23},
    {"Iridium", "Ir", 77, 192.22},
    {"Platinum", "Pt", 78, 195.08},
    {"Gold", "Au", 79, 196.97},
    {"Mercury", "Hg", 80, 200.59},
    {"Thallium", "Tl", 81, 204.38},
    {"Lead", "Pb", 82, 207.2},
    {"Bismuth", "Bi", 83, 208.98},
    {"Polonium", "Po", 84, 208.98},
    {"Astatine", "At", 85, 209.99},
    {"Radon", "Rn", 86, 222.02},
    {"Francium", "Fr", 87, 223.02},
    {"Radium", "Ra", 88, 226.03},
    {"Actinium", "Ac", 89, 227.03},
    {"Thorium", "Th", 90, 232.04},
    {"Protactinium", "Pa", 91, 231.04},
    {"Uranium", "U", 92, 238.03},
    {"Neptunium", "Np", 93, 237.05},
    {"Plutonium", "Pu", 94, 244.06},
    {"Americium", "Am", 95, 243.06},
    {"Curium", "Cm", 96, 247.07},
    {"Berkelium", "Bk", 97, 247.07},
    {"Californium", "Cf", 98, 251.08},
    {"Einsteinium", "Es", 99, 252.08},
    {"Fermium", "Fm", 100, 257.10},
    {"Mendelevium", "Md", 101, 258.10},
    {"Nobelium", "No", 102, 259.10},
    {"Lawrencium", "Lr", 103, 262.11},
    {"Rutherfordium", "Rf", 104, 267.12},
    {"Dubnium", "Db", 105, 270.13},
    {"Seaborgium", "Sg", 106, 271.14},
    {"Bohrium", "Bh", 107, 270.15},
    {"Hassium", "Hs", 108, 277.16},
    {"Meitnerium", "Mt", 109, 276.17},
    {"Darmstadtium", "Ds", 110, 281.18},
    {"Roentgenium", "Rg", 111, 280.16},
    {"Copernicium", "Cn", 112, 285.18},
    {"Nihonium", "Nh", 113, 284.18},
    {"Flerovium", "Fl", 114, 289.19},
    {"Moscovium", "Mc", 115, 288.19},
    {"Livermorium", "Lv", 116, 293.20},
    {"Tennessine", "Ts", 117, 294.21},
    {"Oganesson", "Og", 118, 294.21},
};

// Define a function to quiz the user on their knowledge of the periodic table
void quiz() {
    int score = 0;
    int num_questions = 10;

    printf("Welcome to the Periodic Table Quiz! You will be given %d questions to answer.\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        // Randomly select an element from the periodic table to quiz the user on
        int index = rand() % MAX_ELEMENTS;
        Element e = elements[index];

        // Display the question
        printf("\nQuestion %d:\n" "What is the symbol for %s (atomic number %d)? ", (i + 1), e.name, e.atomic_number);

        // Read in the user's answer
        char answer[MAX_SYMBOL_LENGTH];
        scanf("%s", answer);

        // Check the user's answer
        if (strcmp(answer, e.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", e.symbol);
        }
    }

    // Display the user's score
    printf("\nQuiz complete! You got %d out of %d questions correct.\n", score, num_questions);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Display a welcome message to the user
    printf("Welcome to the Periodic Table Quiz!\n");

    // Prompt the user to start the quiz
    printf("Press enter to begin the quiz.");
    getchar();

    // Start the quiz
    quiz();

    // Exit the program
    return 0;
}