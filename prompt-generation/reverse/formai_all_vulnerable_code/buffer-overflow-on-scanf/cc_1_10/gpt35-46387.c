//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of elements in the periodic table */
#define MAX_ELEMENTS 118

/* Define the maximum length of element name and symbol */
#define MAX_NAME_LEN 20
#define MAX_SYM_LEN 3

/* Define the element structure */
typedef struct element {
    int atomic_number;
    char symbol[MAX_SYM_LEN];
    char name[MAX_NAME_LEN];
    float atomic_mass;
} Element;

/* Define an array of all the elements in the periodic table */
Element elements[MAX_ELEMENTS] = {
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
    {14, "Si", "Silicon", 28.09},
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
    {84, "Po", "Polonium", 208.98},
    {85, "At", "Astatine", 209.99},
    {86, "Rn", "Radon", 222.02},
    {87, "Fr", "Francium", 223.02},
    {88, "Ra", "Radium", 226.03},
    {89, "Ac", "Actinium", 227.03},
    {90, "Th", "Thorium", 232.04},
    {91, "Pa", "Protactinium", 231.04},
    {92, "U", "Uranium", 238.03},
    {93, "Np", "Neptunium", 237.05},
    {94, "Pu", "Plutonium", 244.06},
    {95, "Am", "Americium", 243.06},
    {96, "Cm", "Curium", 247.07},
    {97, "Bk", "Berkelium", 247.07},
    {98, "Cf", "Californium", 251.08},
    {99, "Es", "Einsteinium", 252.08},
    {100, "Fm", "Fermium", 257.10},
    {101, "Md", "Mendelevium", 258.10},
    {102, "No", "Nobelium", 259.10},
    {103, "Lr", "Lawrencium", 262.11},
    {104, "Rf", "Rutherfordium", 267.12},
    {105, "Db", "Dubnium", 270.13},
    {106, "Sg", "Seaborgium", 269.13},
    {107, "Bh", "Bohrium", 270.13},
    {108, "Hs", "Hassium", 277.15},
    {109, "Mt", "Meitnerium", 276.15},
    {110, "Ds", "Darmstadtium", 281.16},
    {111, "Rg", "Roentgenium", 280.16},
    {112, "Cn", "Copernicium", 285.17},
    {113, "Nh", "Nihonium", 284.18},
    {114, "Fl", "Flerovium", 289.19},
    {115, "Mc", "Moscovium", 288.19},
    {116, "Lv", "Livermorium", 293},
    {117, "Ts", "Tennessine", 294},
    {118, "Og", "Oganesson", 294}
};

/* Define the main function */
int main() {
    int score = 0;
    char name[MAX_NAME_LEN];
    int num_questions = 5;

    /* Print the welcome message and instructions */
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the periodic table.\n", num_questions);
    printf("For each question, you will be given the symbol of an element,\n");
    printf("and you must enter the corresponding name of the element.\n");
    printf("Good luck!\n\n");

    /* Loop through the quiz questions */
    for (int i = 0; i < num_questions; i++) {
        /* Choose a random element from the periodic table */
        int random_index = rand() % MAX_ELEMENTS;
        Element current_element = elements[random_index];

        /* Print the question and prompt for an answer */
        printf("Question %d:\n", i+1);
        printf("What is the name of the element with the symbol \"%s\"? ", current_element.symbol);
        scanf("%s", name);

        /* Check the answer and update the score */
        if (strcmp(name, current_element.name) == 0)
            score++;
        else
            printf("Incorrect. The correct answer is \"%s\".\n", current_element.name);

        printf("\n");
    }

    /* Print the final score */
    printf("Quiz complete! You scored %d out of %d.\n", score, num_questions);

    return 0;
}