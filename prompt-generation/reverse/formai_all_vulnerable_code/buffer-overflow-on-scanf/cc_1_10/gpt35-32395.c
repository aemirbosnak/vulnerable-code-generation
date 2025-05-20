//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

const Element periodic_table[] = {
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
    {"Al", "Aluminium", 13},
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
    int score = 0; // Variable for keeping track of the user's score
    int number_of_questions; // Variable for storing the number of questions the user wants to answer
    int question_count = 0; // Variable for keeping track of the number of questions answered
    char answer[3]; // Array for storing the user's answer
    int random_numbers[5]; // Array for storing the random numbers generated for selecting questions
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (Maximum 118)\n");
    scanf("%d", &number_of_questions);
    
    if(number_of_questions > 118) {
        printf("Sorry, the maximum number of questions is 118.\n");
        return 0;
    }
    
    // Generate random numbers for selecting questions
    for(int i = 0; i < 5; i++) {
        random_numbers[i] = rand() % 118;
    }
    
    while(question_count < number_of_questions) {
        printf("\nQuestion %d:\n", question_count + 1);
        int random_index = random_numbers[question_count % 5]; // Select a random index from the array
        printf("What is the atomic number of %s?\n", periodic_table[random_index].name);
        scanf("%s", answer);
        if(strcmp(answer, "exit") == 0) {
            printf("Exiting the quiz...\n");
            return 0;
        }
        if(strcmp(answer, "hint") == 0) {
            printf("The atomic number of %s is %d.\n", periodic_table[random_index].name, periodic_table[random_index].atomic_number);
            continue;
        }
        if(strcmp(answer, periodic_table[random_index].symbol) == 0) { // Check if the user's answer is correct
            printf("Congratulations, your answer is correct!\n");
            score++;
        } else {
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n", periodic_table[random_index].atomic_number);
        }
        question_count++;
    }
    printf("\nQuiz complete!\n");
    printf("You answered %d out of %d questions correctly.\n", score, number_of_questions);
    
    return 0;
}