//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants for the size of the periodic table and maximum number of attempts
#define TABLESIZE 118
#define MAX_ATTEMPTS 3

// Define a structure for a single element on the periodic table
struct Element {
    int atomic_num;
    char symbol[3];
    char name[25];
    double atomic_mass;
};

int main() {
    // Declare an array of elements and initialize each element
    struct Element table[TABLESIZE] = {
        {1, "H", "Hydrogen", 1.008},
        {2, "He", "Helium", 4.003},
        {3, "Li", "Lithium", 6.941},
        {4, "Be", "Beryllium", 9.012},
        {5, "B", "Boron", 10.81},
        {6, "C", "Carbon", 12.01},
        {7, "N", "Nitrogen", 14.01},
        {8, "O", "Oxygen", 16.00},
        {9, "F", "Fluorine", 19.00},
        {10, "Ne", "Neon", 20.18},
        {11, "Na", "Sodium", 22.99},
        {12, "Mg", "Magnesium", 24.31},
        {13, "Al", "Aluminum", 26.98},
        {14, "Si", "Silicon", 28.08},
        {15, "P", "Phosphorus", 30.97},
        {16, "S", "Sulfur", 32.06},
        {17, "Cl", "Chlorine", 35.45},
        {18, "Ar", "Argon", 39.95},
        {19, "K", "Potassium", 39.10},
        {20, "Ca", "Calcium", 40.08},
        {21, "Sc", "Scandium", 44.96},
        {22, "Ti", "Titanium", 47.87},
        {23, "V", "Vanadium", 50.94},
        {24, "Cr", "Chromium", 52.00},
        {25, "Mn", "Manganese", 54.94},
        {26, "Fe", "Iron", 55.85},
        {27, "Co", "Cobalt", 58.93},
        {28, "Ni", "Nickel", 58.69},
        {29, "Cu", "Copper", 63.55},
        {30, "Zn", "Zinc", 65.38},
        {31, "Ga", "Gallium", 69.72},
        {32, "Ge", "Germanium", 72.63},
        {33, "As", "Arsenic", 74.92},
        {34, "Se", "Selenium", 78.96},
        {35, "Br", "Bromine", 79.90},
        {36, "Kr", "Krypton", 83.80},
        {37, "Rb", "Rubidium", 85.47},
        {38, "Sr", "Strontium", 87.62},
        {39, "Y", "Yttrium", 88.91},
        {40, "Zr", "Zirconium", 91.22},
        {41, "Nb", "Niobium", 92.91},
        {42, "Mo", "Molybdenum", 95.94},
        {43, "Tc", "Technetium", 98.00},
        {44, "Ru", "Ruthenium", 101.07},
        {45, "Rh", "Rhodium", 102.91},
        {46, "Pd", "Palladium", 106.42},
        {47, "Ag", "Silver", 107.87},
        {48, "Cd", "Cadmium", 112.41},
        {49, "In", "Indium", 114.82},
        {50, "Sn", "Tin", 118.71},
        {51, "Sb", "Antimony", 121.76},
        {52, "Te", "Tellurium", 127.60},
        {53, "I", "Iodine", 126.90},
        {54, "Xe", "Xenon", 131.29},
        {55, "Cs", "Cesium", 132.91},
        {56, "Ba", "Barium", 137.33},
        {57, "La", "Lanthanum", 138.91},
        {58, "Ce", "Cerium", 140.12},
        {59, "Pr", "Praseodymium", 140.91},
        {60, "Nd", "Neodymium", 144.24},
        {61, "Pm", "Promethium", 145.00},
        {62, "Sm", "Samarium", 150.36},
        {63, "Eu", "Europium", 151.96},
        {64, "Gd", "Gadolinium", 157.25},
        {65, "Tb", "Terbium", 158.93},
        {66, "Dy", "Dysprosium", 162.50},
        {67, "Ho", "Holmium", 164.93},
        {68, "Er", "Erbium", 167.26},
        {69, "Tm", "Thulium", 168.93},
        {70, "Yb", "Ytterbium", 173.05},
        {71, "Lu", "Lutetium", 174.97},
        {72, "Hf", "Hafnium", 178.49},
        {73, "Ta", "Tantalum", 180.95},
        {74, "W", "Tungsten", 183.84},
        {75, "Re", "Rhenium", 186.21},
        {76, "Os", "Osmium", 190.23},
        {77, "Ir", "Iridium", 192.22},
        {78, "Pt", "Platinum", 195.08},
        {79, "Au", "Gold", 196.97},
        {80, "Hg", "Mercury", 200.59},
        {81, "Tl", "Thallium", 204.38},
        {82, "Pb", "Lead", 207.2},
        {83, "Bi", "Bismuth", 208.98},
        {84, "Po", "Polonium", 209.00},
        {85, "At", "Astatine", 210.00},
        {86, "Rn", "Radon", 222.02},
        {87, "Fr", "Francium", 223.02},
        {88, "Ra", "Radium", 226.03},
//      Unstable elements with no reliable atomic mass information
        {89, "Ac", "Actinium", -1},
        {90, "Th", "Thorium", -1},
        {91, "Pa", "Protactinium", -1},
        {92, "U", "Uranium", -1},
        {93, "Np", "Neptunium", -1},
        {94, "Pu", "Plutonium", -1},
        {95, "Am", "Americium", -1},
        {96, "Cm", "Curium", -1},
        {97, "Bk", "Berkelium", -1},
        {98, "Cf", "Californium", -1},
        {99, "Es", "Einsteinium", -1},
        {100, "Fm", "Fermium", -1},
        {101, "Md", "Mendelevium", -1},
        {102, "No", "Nobelium", -1},
        {103, "Lr", "Lawrencium", -1},
        {104, "Rf", "Rutherfordium", -1},
        {105, "Db", "Dubnium", -1},
        {106, "Sg", "Seaborgium", -1},
        {107, "Bh", "Bohrium", -1},
        {108, "Hs", "Hassium", -1},
        {109, "Mt", "Meitnerium", -1},
        {110, "Ds", "Darmstadtium", -1},
        {111, "Rg", "Roentgenium", -1},
        {112, "Cn", "Copernicium", -1},
        {113, "Nh", "Nihonium", -1},
        {114, "Fl", "Flerovium", -1},
        {115, "Mc", "Moscovium", -1},
        {116, "Lv", "Livermorium", -1},
        {117, "Ts", "Tennessine", -1},
        {118, "Og", "Oganesson", -1}
    };

    // Prompt the user for their name
    printf("Welcome to the Periodic Table Quiz! Please enter your name: ");
    char name[25];
    scanf("%s", name);

    // Wait a second before continuing
    printf("Preparing game...\n");
    sleep(1);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Select a random element from the table
    int index = rand() % TABLESIZE;
    struct Element element = table[index];

    // Initialize variables for tracking user's attempts and whether they are correct
    int attempt = 1;
    int correct = 0;

    // Loop while the user has not exceeded the maximum number of attempts and has not answered correctly
    while (attempt <= MAX_ATTEMPTS && !correct) {
        // Print the prompt and read the user's answer
        printf("\n%s, what is the symbol for %s (atomic number %d)? ", name, element.name, element.atomic_num);
        char guess[3];
        scanf("%s", guess);

        // Convert the answer to uppercase for easier comparison
        for (int i = 0; i < strlen(guess); i++) {
            guess[i] = toupper(guess[i]);
        }

        // Compare the answer to the correct symbol and output feedback
        if (strcmp(guess, element.symbol) == 0) {
            printf("Correct! Congratulations, %s!\n", name);
            correct = 1;
        } else {
            printf("Incorrect. You have %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempt);
            attempt++;
        }
    }

    // If the user did not guess correctly after all attempts, reveal the answer
    if (!correct) {
        printf("\nSorry, %s! The correct answer was %s.\n", name, element.symbol);
    }

    return 0;
}