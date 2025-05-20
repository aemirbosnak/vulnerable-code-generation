//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define a struct to store information about each element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_num;
} Element;

// Define an array to store information about each element
Element table[MAX_ELEMENTS] = {
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

// Function to generate a random integer between the given min and max values (inclusive)
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked to enter the name or symbol of a random element from the periodic table.\n");
    printf("You can type 'exit' at any time to quit the quiz.\n\n");

    int num_correct = 0; // Initialize the number of correct answers to 0
    int num_wrong = 0; // Initialize the number of wrong answers to 0

    while (1) {
        // Generate a random index between 0 and MAX_ELEMENTS-1
        int index = random_int(0, MAX_ELEMENTS-1);

        // Print the question
        printf("What is the symbol or name of element #%d in the periodic table?\n", table[index].atomic_num);

        // Get the user's answer
        char answer[20];
        scanf("%s", answer);

        // Convert the answer to uppercase for comparison
        for (int i = 0; i < strlen(answer); i++) {
            answer[i] = toupper(answer[i]);
        }

        // Check if the user wants to exit
        if (strcmp(answer, "EXIT") == 0) {
            break;
        }

        // Check the user's answer
        if (strcmp(answer, table[index].symbol) == 0 || strcmp(answer, table[index].name) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Wrong! The correct answer is %s (%s).\n", table[index].symbol, table[index].name);
            num_wrong++;
        }

        // Print the user's score
        printf("Score: %d correct, %d wrong\n\n", num_correct, num_wrong);
    }

    printf("Thanks for playing the C Periodic Table Quiz!\n");
    printf("Your final score is: %d correct, %d wrong\n", num_correct, num_wrong);

    return 0;
}