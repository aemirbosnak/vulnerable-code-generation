//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10

typedef struct {
    int atomic_number;
    char symbol[3];
    char name[25];
    int period;
    int group;
    double atomic_mass;
} Element;

Element elements[MAX_ELEMENTS] = {
    {1, "H", "Hydrogen", 1, 1, 1.008},
    {2, "He", "Helium", 1, 18, 4.003},
    {3, "Li", "Lithium", 2, 1, 6.941},
    {4, "Be", "Beryllium", 2, 2, 9.012},
    {5, "B", "Boron", 2, 13, 10.81},
    {6, "C", "Carbon", 2, 14, 12.01},
    {7, "N", "Nitrogen", 2, 15, 14.01},
    {8, "O", "Oxygen", 2, 16, 16.00},
    {9, "F", "Fluorine", 2, 17, 19.00},
    {10, "Ne", "Neon", 2, 18, 20.18},
    {11, "Na", "Sodium", 3, 1, 22.99},
    {12, "Mg", "Magnesium", 3, 2, 24.31},
    {13, "Al", "Aluminum", 3, 13, 26.98},
    {14, "Si", "Silicon", 3, 14, 28.09},
    {15, "P", "Phosphorus", 3, 15, 30.97},
    {16, "S", "Sulfur", 3, 16, 32.07},
    {17, "Cl", "Chlorine", 3, 17, 35.45},
    {18, "Ar", "Argon", 3, 18, 39.95},
    {19, "K", "Potassium", 4, 1, 39.10},
    {20, "Ca", "Calcium", 4, 2, 40.08},
    {21, "Sc", "Scandium", 4, 3, 44.96},
    {22, "Ti", "Titanium", 4, 4, 47.87},
    {23, "V", "Vanadium", 4, 5, 50.94},
    {24, "Cr", "Chromium", 4, 6, 52.00},
    {25, "Mn", "Manganese", 4, 7, 54.94},
    {26, "Fe", "Iron", 4, 8, 55.85},
    {27, "Co", "Cobalt", 4, 9, 58.93},
    {28, "Ni", "Nickel", 4, 10, 58.69},
    {29, "Cu", "Copper", 4, 11, 63.55},
    {30, "Zn", "Zinc", 4, 12, 65.38},
    {31, "Ga", "Gallium", 4, 13, 69.72},
    {32, "Ge", "Germanium", 4, 14, 72.63},
    {33, "As", "Arsenic", 4, 15, 74.92},
    {34, "Se", "Selenium", 4, 16, 78.96},
    {35, "Br", "Bromine", 4, 17, 79.90},
    {36, "Kr", "Krypton", 4, 18, 83.80},
    {37, "Rb", "Rubidium", 5, 1, 85.47},
    {38, "Sr", "Strontium", 5, 2, 87.62},
    {39, "Y", "Yttrium", 5, 3, 88.91},
    {40, "Zr", "Zirconium", 5, 4, 91.22},
    {41, "Nb", "Niobium", 5, 5, 92.91},
    {42, "Mo", "Molybdenum", 5, 6, 95.94},
    {43, "Tc", "Technetium", 5, 7, 99.00},
    {44, "Ru", "Ruthenium", 5, 8, 101.1},
    {45, "Rh", "Rhodium", 5, 9, 102.9},
    {46, "Pd", "Palladium", 5, 10, 106.4},
    {47, "Ag", "Silver", 5, 11, 107.9},
    {48, "Cd", "Cadmium", 5, 12, 112.4},
    {49, "In", "Indium", 5, 13, 114.8},
    {50, "Sn", "Tin", 5, 14, 118.7},
    {51, "Sb", "Antimony", 5, 15, 121.8},
    {52, "Te", "Tellurium", 5, 16, 127.6},
    {53, "I", "Iodine", 5, 17, 126.9},
    {54, "Xe", "Xenon", 5, 18, 131.3},
    {55, "Cs", "Cesium", 6, 1, 132.9},
    {56, "Ba", "Barium", 6, 2, 137.3},
    {57, "La", "Lanthanum", 6, 3, 138.9},
    {58, "Ce", "Cerium", 6, 4, 140.1},
    {59, "Pr", "Praseodymium", 6, 5, 140.9},
    {60, "Nd", "Neodymium", 6, 6, 144.2},
    {61, "Pm", "Promethium", 6, 7, 145.0},
    {62, "Sm", "Samarium", 6, 8, 150.4},
    {63, "Eu", "Europium", 6, 9, 151.9},
    {64, "Gd", "Gadolinium", 6, 10, 157.3},
    {65, "Tb", "Terbium", 6, 11, 158.9},
    {66, "Dy", "Dysprosium", 6, 12, 162.5},
    {67, "Ho", "Holmium", 6, 13, 164.9},
    {68, "Er", "Erbium", 6, 14, 167.3},
    {69, "Tm", "Thulium", 6, 15, 168.9},
    {70, "Yb", "Ytterbium", 6, 16, 173.1},
    {71, "Lu", "Lutetium", 6, 17, 175.0},
    {72, "Hf", "Hafnium", 6, 4, 178.5},
    {73, "Ta", "Tantalum", 6, 5, 180.9},
    {74, "W", "Tungsten", 6, 6, 183.8},
    {75, "Re", "Rhenium", 6, 7, 186.2},
    {76, "Os", "Osmium", 6, 8, 190.2},
    {77, "Ir", "Iridium", 6, 9, 192.2},
    {78, "Pt", "Platinum", 6, 10, 195.1},
    {79, "Au", "Gold", 6, 11, 197.0},
    {80, "Hg", "Mercury", 6, 12, 200.6},
    {81, "Tl", "Thallium", 6, 13, 204.4},
    {82, "Pb", "Lead", 6, 14, 207.2},
    {83, "Bi", "Bismuth", 6, 15, 208.9},
    {84, "Po", "Polonium", 6, 16, 209.0},
    {85, "At", "Astatine", 6, 17, 210.0},
    {86, "Rn", "Radon", 6, 18, 222.0},
    {87, "Fr", "Francium", 7, 1, 223.0},
    {88, "Ra", "Radium", 7, 2, 226.0},
    {89, "Ac", "Actinium", 7, 3, 227.0},
    {90, "Th", "Thorium", 7, 4, 232.0},
    {91, "Pa", "Protactinium", 7, 5, 231.0},
    {92, "U", "Uranium", 7, 6, 238.0},
    {93, "Np", "Neptunium", 7, 7, 237.1},
    {94, "Pu", "Plutonium", 7, 8, 244.1},
    {95, "Am", "Americium", 7, 9, 243.1},
    {96, "Cm", "Curium", 7, 10, 247.1},
    {97, "Bk", "Berkelium", 7, 11, 247.1},
    {98, "Cf", "Californium", 7, 12, 251.1},
    {99, "Es", "Einsteinium", 7, 13, 252.1},
    {100, "Fm", "Fermium", 7, 14, 257.1},
    {101, "Md", "Mendelevium", 7, 15, 258.1},
    {102, "No", "Nobelium", 7, 16, 259.1},
    {103, "Lr", "Lawrencium", 7, 17, 262.1},
    {104, "Rf", "Rutherfordium", 7, 4, 267.1},
    {105, "Db", "Dubnium", 7, 5, 270.1},
    {106, "Sg", "Seaborgium", 7, 6, 271.1},
    {107, "Bh", "Bohrium", 7, 7, 270.1},
    {108, "Hs", "Hassium", 7, 8, 277.1},
    {109, "Mt", "Meitnerium", 7, 9, 276.1},
    {110, "Ds", "Darmstadtium", 7, 10, 281.1},
    {111, "Rg", "Roentgenium", 7, 11, 280.1},
    {112, "Cn", "Copernicium", 7, 12, 285.1},
    {113, "Nh", "Nihonium", 7, 13, 284.1},
    {114, "Fl", "Flerovium", 7, 14, 289.1},
    {115, "Mc", "Moscovium", 7, 15, 288.1},
    {116, "Lv", "Livermorium", 7, 16, 293.1},
    {117, "Ts", "Tennessine", 7, 17, 294.1},
    {118, "Og", "Oganesson", 7, 18, 294.2},
};

void ask_question(Element element) {
    int num1, num2, answer;
    char operation;
    
    printf("What is the atomic number of the element %s? ", element.name);
    while (scanf("%d", &answer) == 0) {
        printf("Please enter an integer.\n");
        while (getchar() != '\n') {} // clear buffer
    }
    
    if (answer == element.atomic_number) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %d.\n", element.atomic_number);
    }

    // Generate and ask a bonus question
    printf("Here's a bonus question:\n");
    
    srand(time(NULL));
    num1 = rand() % 10;
    num2 = rand() % 10;
    operation = rand() % 3;
    
    switch (operation) {
        case 0: // addition
            printf("%d + %d = ", num1, num2);
            while (scanf("%d", &answer) == 0) {
                printf("Please enter an integer.\n");
                while (getchar() != '\n') {} // clear buffer
            }
            if (answer == num1 + num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 + num2);
            }
            break;
            
        case 1: // subtraction
            printf("%d - %d = ", num1, num2);
            while (scanf("%d", &answer) == 0) {
                printf("Please enter an integer.\n");
                while (getchar() != '\n') {} // clear buffer
            }
            if (answer == num1 - num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 - num2);
            }
            break;
            
        case 2: // multiplication
            printf("%d * %d = ", num1, num2);
            while (scanf("%d", &answer) == 0) {
                printf("Please enter an integer.\n");
                while (getchar() != '\n') {} // clear buffer
            }
            if (answer == num1 * num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 * num2);
            }
            break;
    }
}

int main() {
    int question_count = 0, i;
    
    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be asked %d questions about different elements.\n", MAX_QUESTIONS);
    printf("For each question, you'll be asked to enter the atomic number of the element.\n");
    printf("After each question, you'll get a bonus math question.\n\n");

    // Ask random questions
    srand(time(NULL));
    while (question_count < MAX_QUESTIONS) {
        i = rand() % MAX_ELEMENTS;
        ask_question(elements[i]);
        question_count++;
    }
    
    printf("\nCongratulations, you've completed the quiz!\n");
    
    return 0;
}