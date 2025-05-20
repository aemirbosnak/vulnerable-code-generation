//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the number of elements and length of symbols and names
#define NUM_ELEMENTS 118
#define SYMBOL_LEN 3
#define NAME_LEN 50

// Struct for elements
struct Element {
    int atomicNum;
    char symbol[SYMBOL_LEN];
    char name[NAME_LEN];
};

// Array of elements
struct Element elements[NUM_ELEMENTS] = {
    {1, "H", "Hydrogen"},
    {2, "He", "Helium"},
    {3, "Li", "Lithium"},
    {4, "Be", "Beryllium"},
    {5, "B", "Boron"},
    {6, "C", "Carbon"},
    {7, "N", "Nitrogen"},
    {8, "O", "Oxygen"},
    {9, "F", "Fluorine"},
    {10, "Ne", "Neon"},
    {11, "Na", "Sodium"},
    {12, "Mg", "Magnesium"},
    {13, "Al", "Aluminium"},
    {14, "Si", "Silicon"},
    {15, "P", "Phosphorus"},
    {16, "S", "Sulfur"},
    {17, "Cl", "Chlorine"},
    {18, "Ar", "Argon"},
    {19, "K", "Potassium"},
    {20, "Ca", "Calcium"},
    {21, "Sc", "Scandium"},
    {22, "Ti", "Titanium"},
    {23, "V", "Vanadium"},
    {24, "Cr", "Chromium"},
    {25, "Mn", "Manganese"},
    {26, "Fe", "Iron"},
    {27, "Co", "Cobalt"},
    {28, "Ni", "Nickel"},
    {29, "Cu", "Copper"},
    {30, "Zn", "Zinc"},
    {31, "Ga", "Gallium"},
    {32, "Ge", "Germanium"},
    {33, "As", "Arsenic"},
    {34, "Se", "Selenium"},
    {35, "Br", "Bromine"},
    {36, "Kr", "Krypton"},
    {37, "Rb", "Rubidium"},
    {38, "Sr", "Strontium"},
    {39, "Y", "Yttrium"},
    {40, "Zr", "Zirconium"},
    {41, "Nb", "Niobium"},
    {42, "Mo", "Molybdenum"},
    {43, "Tc", "Technetium"},
    {44, "Ru", "Ruthenium"},
    {45, "Rh", "Rhodium"},
    {46, "Pd", "Palladium"},
    {47, "Ag", "Silver"},
    {48, "Cd", "Cadmium"},
    {49, "In", "Indium"},
    {50, "Sn", "Tin"},
    {51, "Sb", "Antimony"},
    {52, "Te", "Tellurium"},
    {53, "I", "Iodine"},
    {54, "Xe", "Xenon"},
    {55, "Cs", "Caesium"},
    {56, "Ba", "Barium"},
    {57, "La", "Lanthanum"},
    {58, "Ce", "Cerium"},
    {59, "Pr", "Praseodymium"},
    {60, "Nd", "Neodymium"},
    {61, "Pm", "Promethium"},
    {62, "Sm", "Samarium"},
    {63, "Eu", "Europium"},
    {64, "Gd", "Gadolinium"},
    {65, "Tb", "Terbium"},
    {66, "Dy", "Dysprosium"},
    {67, "Ho", "Holmium"},
    {68, "Er", "Erbium"},
    {69, "Tm", "Thulium"},
    {70, "Yb", "Ytterbium"},
    {71, "Lu", "Lutetium"},
    {72, "Hf", "Hafnium"},
    {73, "Ta", "Tantalum"},
    {74, "W", "Tungsten"},
    {75, "Re", "Rhenium"},
    {76, "Os", "Osmium"},
    {77, "Ir", "Iridium"},
    {78, "Pt", "Platinum"},
    {79, "Au", "Gold"},
    {80, "Hg", "Mercury"},
    {81, "Tl", "Thallium"},
    {82, "Pb", "Lead"},
    {83, "Bi", "Bismuth"},
    {84, "Po", "Polonium"},
    {85, "At", "Astatine"},
    {86, "Rn", "Radon"},
    {87, "Fr", "Francium"},
    {88, "Ra", "Radium"},
    {89, "Ac", "Actinium"},
    {90, "Th", "Thorium"},
    {91, "Pa", "Protactinium"},
    {92, "U", "Uranium"},
    {93, "Np", "Neptunium"},
    {94, "Pu", "Plutonium"},
    {95, "Am", "Americium"},
    {96, "Cm", "Curium"},
    {97, "Bk", "Berkelium"},
    {98, "Cf", "Californium"},
    {99, "Es", "Einsteinium"},
    {100, "Fm", "Fermium"},
    {101, "Md", "Mendelevium"},
    {102, "No", "Nobelium"},
    {103, "Lr", "Lawrencium"},
    {104, "Rf", "Rutherfordium"},
    {105, "Db", "Dubnium"},
    {106, "Sg", "Seaborgium"},
    {107, "Bh", "Bohrium"},
    {108, "Hs", "Hassium"},
    {109, "Mt", "Meitnerium"},
    {110, "Ds", "Darmstadtium"},
    {111, "Rg", "Roentgenium"},
    {112, "Cn", "Copernicium"},
    {113, "Nh", "Nihonium"},
    {114, "Fl", "Flerovium"},
    {115, "Mc", "Moscovium"},
    {116, "Lv", "Livermorium"},
    {117, "Ts", "Tennessine"},
    {118, "Og", "Oganesson"}
};

// Function to quiz user
void quiz() {
    int score = 0;
    int numQs = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to match an element's symbol with its name.\n");
    printf("There will be ten questions total.\n");
    printf("Please enter your answer as the symbol.\n\n");
    
    // Loop through ten questions
    for (int i = 0; i < 10; i++) {
        // Randomly select an element
        int randIndex = rand() % NUM_ELEMENTS;
        struct Element e = elements[randIndex];
        
        // Print question and get user's answer
        printf("Question %d\n", i+1);
        printf("What is the chemical symbol for %s?\n", e.name);
        char answer[SYMBOL_LEN];
        scanf("%s", answer);
        
        // Check if answer is correct
        if (strcmp(answer, e.symbol) == 0) {
            printf("Correct!\n");
            score += 10;
        } else {
            printf("Incorrect. The correct answer is %s.\n", e.symbol); 
        }
        
        numQs++;
    }
    
    // Print final score and number of questions answered
    printf("\nQuiz complete. You answered %d out of 10 questions.\n", numQs);
    printf("Your final score is %d/100.", score);
}

int main() {
    quiz();
    return 0;
}