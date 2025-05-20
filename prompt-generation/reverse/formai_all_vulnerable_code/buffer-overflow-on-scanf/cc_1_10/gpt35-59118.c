//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the periodic table as a constant.
#define TABLE_SIZE 118

// Define the maximum number of attempts per question.
#define MAX_ATTEMPTS 3

// Define a struct for atomic elements.
struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

int main() {
    // Initialize the periodic table.
    struct Element table[TABLE_SIZE] = {
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
    
    // Seed the random number generator.
    srand(time(NULL));
    
    // Create an array to hold the indices of the elements asked in the quiz.
    int quiz_indices[TABLE_SIZE] = {0};
    int num_quizzes = 0;
    
    // Print a welcome message and instructions.
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements.\n", TABLE_SIZE);
    printf("You have %d attempts per question.\n", MAX_ATTEMPTS);
    printf("Good luck!\n\n");
    
    // Loop until all elements have been asked in the quiz.
    while (num_quizzes < TABLE_SIZE) {
        // Generate a random index for the element to ask.
        int index = rand() % TABLE_SIZE;
        
        // Check if this element has already been asked in the quiz.
        int already_asked = 0;
        for (int i = 0; i < num_quizzes; i++) {
            if (quiz_indices[i] == index) {
                already_asked = 1;
                break;
            }
        }
        
        // If the element has already been asked, continue to the next iteration.
        if (already_asked) {
            continue;
        }
        
        // Add the index to the quiz indices array.
        quiz_indices[num_quizzes] = index;
        num_quizzes++;
        
        // Get a pointer to the element.
        struct Element *element = &table[index];
        
        // Print the question.
        printf("What is the symbol for %s? ", element->name);
        
        // Loop until the user either gets the correct answer or runs out of attempts.
        int attempts = 0;
        while (attempts < MAX_ATTEMPTS) {
            char answer[3];
            scanf("%s", answer);
            
            // Convert the answer to uppercase.
            for (int i = 0; answer[i] != '\0'; i++) {
                answer[i] = toupper(answer[i]);
            }
            
            if (strcmp(answer, element->symbol) == 0) {
                // The user got the correct answer.
                printf("Correct!\n\n");
                break;
            } else {
                // The user got the incorrect answer.
                printf("Incorrect. ");
                
                if (attempts == MAX_ATTEMPTS - 1) {
                    // This is the last attempt, so reveal the correct answer.
                    printf("The correct answer is %s.\n\n", element->symbol);
                } else {
                    // Ask the user to try again and increment the number of attempts.
                    printf("Try again. ");
                    attempts++;
                }
            }
        }
    }
    
    // Print a congratulatory message.
    printf("Congratulations! You have completed the Periodic Table Quiz.\n");
    
    return 0;
}