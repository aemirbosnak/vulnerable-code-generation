//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

// define the maximum entries for the Periodic Table
#define MAX_ENTRIES 118

// define the maximum length of the element's name and symbol
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 5

// define the structure for an element
typedef struct {
    int atomic_number;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomic_weight;
} Element;

// initialize an array of elements
Element periodic_table[MAX_ENTRIES] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.003},
    {3, "Lithium", "Li", 6.941},
    {4, "Beryllium", "Be", 9.012},
    {5, "Boron", "B", 10.81},
    {6, "Carbon", "C", 12.01},
    {7, "Nitrogen", "N", 14.01},
    {8, "Oxygen", "O", 16.00},
    {9, "Fluorine", "F", 19.00},
    {10, "Neon", "Ne", 20.18},
    {11, "Sodium", "Na", 22.99},
    {12, "Magnesium", "Mg", 24.31},
    {13, "Aluminum", "Al", 26.98},
    {14, "Silicon", "Si", 28.09},
    {15, "Phosphorus", "P", 30.97},
    {16, "Sulfur", "S", 32.07},
    {17, "Chlorine", "Cl", 35.45},
    {18, "Argon", "Ar", 39.95},
    {19, "Potassium", "K", 39.10},
    {20, "Calcium", "Ca", 40.08},
    {21, "Scandium", "Sc", 44.96},
    {22, "Titanium", "Ti", 47.87},
    {23, "Vanadium", "V", 50.94},
    {24, "Chromium", "Cr", 52.00},
    {25, "Manganese", "Mn", 54.94},
    {26, "Iron", "Fe", 55.85},
    {27, "Cobalt", "Co", 58.93},
    {28, "Nickel", "Ni", 58.69},
    {29, "Copper", "Cu", 63.55},
    {30, "Zinc", "Zn", 65.38},
    {31, "Gallium", "Ga", 69.72},
    {32, "Germanium", "Ge", 72.63},
    {33, "Arsenic", "As", 74.92},
    {34, "Selenium", "Se", 78.96},
    {35, "Bromine", "Br", 79.90},
    {36, "Krypton", "Kr", 83.80},
    {37, "Rubidium", "Rb", 85.47},
    {38, "Strontium", "Sr", 87.62},
    {39, "Yttrium", "Y", 88.91},
    {40, "Zirconium", "Zr", 91.22},
    {41, "Niobium", "Nb", 92.91},
    {42, "Molybdenum", "Mo", 95.94},
    {43, "Technetium", "Tc", 98.00},
    {44, "Ruthenium", "Ru", 101.07},
    {45, "Rhodium", "Rh", 102.91},
    {46, "Palladium", "Pd", 106.42},
    {47, "Silver", "Ag", 107.87},
    {48, "Cadmium", "Cd", 112.41},
    {49, "Indium", "In", 114.82},
    {50, "Tin", "Sn", 118.71},
    {51, "Antimony", "Sb", 121.76},
    {52, "Tellurium", "Te", 127.60},
    {53, "Iodine", "I", 126.90},
    {54, "Xenon", "Xe", 131.29},
    {55, "Cesium", "Cs", 132.91},
    {56, "Barium", "Ba", 137.33},
    {57, "Lanthanum", "La", 138.91},
    {58, "Cerium", "Ce", 140.12},
    {59, "Praseodymium", "Pr", 140.91},
    {60, "Neodymium", "Nd", 144.24},
    {61, "Promethium", "Pm", 145.00},
    {62, "Samarium", "Sm", 150.36},
    {63, "Europium", "Eu", 151.96},
    {64, "Gadolinium", "Gd", 157.25},
    {65, "Terbium", "Tb", 158.93},
    {66, "Dysprosium", "Dy", 162.50},
    {67, "Holmium", "Ho", 164.93},
    {68, "Erbium", "Er", 167.26},
    {69, "Thulium", "Tm", 168.93},
    {70, "Ytterbium", "Yb", 173.05},
    {71, "Lutetium", "Lu", 174.97},
    {72, "Hafnium", "Hf", 178.49},
    {73, "Tantalum", "Ta", 180.95},
    {74, "Tungsten", "W", 183.84},
    {75, "Rhenium", "Re", 186.21},
    {76, "Osmium", "Os", 190.23},
    {77, "Iridium", "Ir", 192.22},
    {78, "Platinum", "Pt", 195.08},
    {79, "Gold", "Au", 196.97},
    {80, "Mercury", "Hg", 200.59},
    {81, "Thallium", "Tl", 204.38},
    {82, "Lead", "Pb", 207.2},
    {83, "Bismuth", "Bi", 208.98},
    {84, "Polonium", "Po", 209.00},
    {85, "Astatine", "At", 210.00},
    {86, "Radon", "Rn", 222.00},
    {87, "Francium", "Fr", 223.00},
    {88, "Radium", "Ra", 226.03},
    {89, "Actinium", "Ac", 227.03},
    {90, "Thorium", "Th", 232.04},
    {91, "Protactinium", "Pa", 231.04},
    {92, "Uranium", "U", 238.03},
    {93, "Neptunium", "Np", 237.05},
    {94, "Plutonium", "Pu", 244.06},
    {95, "Americium", "Am", 243.06},
    {96, "Curium", "Cm", 247.07},
    {97, "Berkelium", "Bk", 247.07},
    {98, "Californium", "Cf", 251.08},
    {99, "Einsteinium", "Es", 252.08},
    {100, "Fermium", "Fm", 257.10},
    {101, "Mendelevium", "Md", 258.10},
    {102, "Nobelium", "No", 259.10},
    {103, "Lawrencium", "Lr", 262.11},
    {104, "Rutherfordium", "Rf", 267.13},
    {105, "Dubnium", "Db", 270.13},
    {106, "Seaborgium", "Sg", 271.13},
    {107, "Bohrium", "Bh", 270.13},
    {108, "Hassium", "Hs", 277.15},
    {109, "Meitnerium", "Mt", 276.15},
    {110, "Darmstadtium", "Ds", 281.16},
    {111, "Roentgenium", "Rg", 280.16},
    {112, "Copernicium", "Cn", 285.18},
    {113, "Nihonium", "Nh", 284.18},
    {114, "Flerovium", "Fl", 289.19},
    {115, "Moscovium", "Mc", 288.19},
    {116, "Livermorium", "Lv", 293.20},
    {117, "Tennessine", "Ts", 293.20},
    {118, "Oganesson", "Og", 294.21}
};

// define a function to display the periodic table
void display_periodic_table(void){
    printf("   Atomic Number |  Symbol  |   Name    | Atomic Weight\n");
    printf("========================================================\n");
    for(int i = 0; i < MAX_ENTRIES; i++){
        printf("%3d. %-12d | %-7s | %-10s | %3.5f\n", i+1, periodic_table[i].atomic_number, periodic_table[i].symbol, periodic_table[i].name, periodic_table[i].atomic_weight);
    }
}

int main(void)
{
    printf("Welcome to the Periodic Table Quiz program\n");
    printf("=========================================\n");
    
    // ask the user if they want to display the periodic table
    char input[5];
    printf("Do you want to display the periodic table? (y/n): ");
    scanf("%s", input);
    
    // display the periodic table if the user inputs "y" or "Y"
    if(strcmp(input, "y") == 0 || strcmp(input, "Y") == 0){
        display_periodic_table();
    }
    
    // start the quiz
    printf("Let's start the quiz!\n");
    printf("====================\n");
    
    // declare the variable to keep track of the number of correct answers
    int num_correct = 0;
    
    // ask the user for the number of questions
    int num_questions;
    printf("How many questions do you want to answer? (max %d): ", MAX_ENTRIES);
    scanf("%d", &num_questions);
    printf("\n");
    
    // declare an array to keep track of the questions asked
    int asked_questions[MAX_ENTRIES];
    memset(asked_questions, 0, sizeof(asked_questions));
    
    // loop through each question
    for(int i = 0; i < num_questions; i++){
        // generate a random atomic number that has not been asked before
        int atomic_number;
        do {
            atomic_number = rand() % MAX_ENTRIES + 1;
        } while(asked_questions[atomic_number-1] == 1);
        asked_questions[atomic_number-1] = 1;
        
        // ask the question and get the answer from the user
        char answer[MAX_NAME_LENGTH];
        printf("%d. What is the symbol and name of element with atomic number %d? ", i+1, atomic_number);
        scanf("%s", answer);
        
        // check if the answer is correct
        if(strcmp(answer, periodic_table[atomic_number-1].symbol) == 0 || strcmp(answer, periodic_table[atomic_number-1].name) == 0){
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s (%s).\n", periodic_table[atomic_number-1].symbol, periodic_table[atomic_number-1].name);
        }
    }
    
    // display the result of the quiz
    printf("\n");
    printf("You got %d out of %d questions correct!\n", num_correct, num_questions);
    
    printf("Thank you for using the Periodic Table Quiz program.\n");
    printf("==================================================\n");
    
    return 0;
}