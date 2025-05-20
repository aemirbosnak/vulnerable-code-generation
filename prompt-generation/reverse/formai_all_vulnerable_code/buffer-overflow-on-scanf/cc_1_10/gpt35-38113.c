//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of questions and choices per question
#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

// Define the maximum length of the element symbol and name
#define MAX_SYMBOL_LENGTH 3
#define MAX_NAME_LENGTH 25

// Define the structure for a periodic table element
struct element {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    int atomic_number;
    float atomic_weight;
};

// Define an array of elements
struct element elements[] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.811},
    {"C", "Carbon", 6, 12.011},
    {"N", "Nitrogen", 7, 14.007},
    {"O", "Oxygen", 8, 15.999},
    {"F", "Fluorine", 9, 18.998},
    {"Ne", "Neon", 10, 20.180},
    {"Na", "Sodium", 11, 22.990},
    {"Mg", "Magnesium", 12, 24.305},
    {"Al", "Aluminium", 13, 26.982},
    {"Si", "Silicon", 14, 28.086},
    {"P", "Phosphorus", 15, 30.974},
    {"S", "Sulfur", 16, 32.066},
    {"Cl", "Chlorine", 17, 35.453},
    {"Ar", "Argon", 18, 39.948},
    {"K", "Potassium", 19, 39.098},
    {"Ca", "Calcium", 20, 40.078},
    {"Sc", "Scandium", 21, 44.956},
    {"Ti", "Titanium", 22, 47.867},
    {"V", "Vanadium", 23, 50.942},
    {"Cr", "Chromium", 24, 52.000},
    {"Mn", "Manganese", 25, 54.938},
    {"Fe", "Iron", 26, 55.845},
    {"Co", "Cobalt", 27, 58.933},
    {"Ni", "Nickel", 28, 58.693},
    {"Cu", "Copper", 29, 63.546},
    {"Zn", "Zinc", 30, 65.380},
    {"Ga", "Gallium", 31, 69.723},
    {"Ge", "Germanium", 32, 72.630},
    {"As", "Arsenic", 33, 74.922},
    {"Se", "Selenium", 34, 78.960},
    {"Br", "Bromine", 35, 79.904},
    {"Kr", "Krypton", 36, 83.798},
    {"Rb", "Rubidium", 37, 85.468},
    {"Sr", "Strontium", 38, 87.620},
    {"Y", "Yttrium", 39, 88.906},
    {"Zr", "Zirconium", 40, 91.224},
    {"Nb", "Niobium", 41, 92.906},
    {"Mo", "Molybdenum", 42, 95.940},
    {"Tc", "Technetium", 43, 98.000},
    {"Ru", "Ruthenium", 44, 101.070},
    {"Rh", "Rhodium", 45, 102.905},
    {"Pd", "Palladium", 46, 106.420},
    {"Ag", "Silver", 47, 107.868},
    {"Cd", "Cadmium", 48, 112.411},
    {"In", "Indium", 49, 114.818},
    {"Sn", "Tin", 50, 118.710},
    {"Sb", "Antimony", 51, 121.760},
    {"Te", "Tellurium", 52, 127.600},
    {"I", "Iodine", 53, 126.905},
    {"Xe", "Xenon", 54, 131.293},
    {"Cs", "Caesium", 55, 132.905},
    {"Ba", "Barium", 56, 137.327},
    {"La", "Lanthanum", 57, 138.905},
    {"Ce", "Cerium", 58, 140.116},
    {"Pr", "Praseodymium", 59, 140.908},
    {"Nd", "Neodymium", 60, 144.242},
    {"Pm", "Promethium", 61, 145.000},
    {"Sm", "Samarium", 62, 150.360},
    {"Eu", "Europium", 63, 151.964},
    {"Gd", "Gadolinium", 64, 157.250},
    {"Tb", "Terbium", 65, 158.925},
    {"Dy", "Dysprosium", 66, 162.500},
    {"Ho", "Holmium", 67, 164.930},
    {"Er", "Erbium", 68, 167.259},
    {"Tm", "Thulium", 69, 168.934},
    {"Yb", "Ytterbium", 70, 173.054},
    {"Lu", "Lutetium", 71, 174.967},
    {"Hf", "Hafnium", 72, 178.490},
    {"Ta", "Tantalum", 73, 180.948},
    {"W", "Tungsten", 74, 183.840},
    {"Re", "Rhenium", 75, 186.207},
    {"Os", "Osmium", 76, 190.230},
    {"Ir", "Iridium", 77, 192.217},
    {"Pt", "Platinum", 78, 195.084},
    {"Au", "Gold", 79, 196.967},
    {"Hg", "Mercury", 80, 200.592},
    {"Tl", "Thallium", 81, 204.383},
    {"Pb", "Lead", 82, 207.200},
    {"Bi", "Bismuth", 83, 208.980},
    {"Po", "Polonium", 84, 209.000},
    {"At", "Astatine", 85, 210.000},
    {"Rn", "Radon", 86, 222.000},
    {"Fr", "Francium", 87, 223.000},
    {"Ra", "Radium", 88, 226.000},
    {"Ac", "Actinium", 89, 227.028},
    {"Th", "Thorium", 90, 232.038},
    {"Pa", "Protactinium", 91, 231.036},
    {"U", "Uranium", 92, 238.029},
    {"Np", "Neptunium", 93, 237.000},
    {"Pu", "Plutonium", 94, 244.000},
    {"Am", "Americium", 95, 243.000},
    {"Cm", "Curium", 96, 247.000},
    {"Bk", "Berkelium", 97, 247.000},
    {"Cf", "Californium", 98, 251.000},
    {"Es", "Einsteinium", 99, 252.000},
    {"Fm", "Fermium", 100, 257.000},
    {"Md", "Mendelevium", 101, 258.000},
    {"No", "Nobelium", 102, 259.000},
    {"Lr", "Lawrencium", 103, 262.000},
    {"Rf", "Rutherfordium", 104, 261.000},
    {"Db", "Dubnium", 105, 262.000},
    {"Sg", "Seaborgium", 106, 266.000},
    {"Bh", "Bohrium", 107, 264.000},
    {"Hs", "Hassium", 108, 267.000},
    {"Mt", "Meitnerium", 109, 268.000},
    {"Ds", "Darmstadtium", 110, 271.000},
    {"Rg", "Roentgenium", 111, 272.000},
    {"Cn", "Copernicium", 112, 277.000},
    {"Nh", "Nihonium", 113, 284.000},
    {"Fl", "Flerovium", 114, 289.000},
    {"Mc", "Moscovium", 115, 288.000},
    {"Lv", "Livermorium", 116, 293.000},
    {"Ts", "Tennessine", 117, 294.000},
    {"Og", "Oganesson", 118, 294.000},
};

// Define a structure for a multiple choice question
struct question {
    char prompt[MAX_NAME_LENGTH + 100];
    int answer_index;
    char choices[NUM_CHOICES][MAX_NAME_LENGTH + 1];
};

// Define an array of questions
struct question questions[] = {
    {"What is the symbol for Oxygen?", 1, {"A) H", "B) O", "C) N", "D) He"}},
    {"What is the atomic weight of Gold?", 3, {"A) 196.967", "B) 55.845", "C) 22.990", "D) 40.078"}},
    {"What is the atomic number of Carbon?", 2, {"A) 1", "B) 6", "C) 9", "D) 24"}},
    {"What is the symbol for Hydrogen?", 0, {"A) H", "B) O", "C) N", "D) He"}},
    {"What is the atomic number of Sodium?", 5, {"A) 7", "B) 16", "C) 35", "D) 56"}},
    {"What is the atomic weight of Chlorine?", 2, {"A) 1.008", "B) 14.007", "C) 35.453", "D) 55.845"}},
    {"What is the name of element 28?", 6, {"A) Nitrogen", "B) Oxygen", "C) Phosphorus", "D) Nickel"}},
    {"What is the symbol for Zinc?", 9, {"A) Zr", "B) Tb", "C) Si", "D) Ba"}},
    {"What is the atomic weight of Carbon?", 5, {"A) 1.008", "B) 14.007", "C) 12.011", "D) 35.453"}},
    {"What is the atomic number of Silicon?", 6, {"A) 13", "B) 14", "C) 15", "D) 16"}},
};

// Function to shuffle an array of integers
void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print the periodic table
void print_periodic_table() {
    printf("Periodic Table\n");
    printf("---------------\n");
    printf("  |");
    for (int i = 0; i < 18; i++) {
        printf("  %d |", i + 1);
    }
    printf("\n");
    printf("--|");
    for (int i = 0; i < 18; i++) {
        printf("-----|");
    }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 18; j++) {
            int index = i * 18 + j;
            if (index < 118) {
                printf(" %2s |", elements[index].symbol);
            } else {
                printf("     |");
            }
        }
        printf("\n");
        printf("--|");
        for (int i = 0; i < 18; i++) {
            printf("-----|");
        }
        printf("\n");
    }
}

// Function to run the quiz
void run_quiz() {
    // Shuffle the order of the questions
    int question_indices[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        question_indices[i] = i;
    }
    shuffle(question_indices, NUM_QUESTIONS);

    // Initialize the score
    int score = 0;

    // Loop through the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        struct question q = questions[question_indices[i]];

        // Print the question prompt and choices
        printf("Question %d:\n", i + 1);
        printf("%s\n", q.prompt);
        for (int j = 0; j < NUM_CHOICES; j++) {
            printf("%s\n", q.choices[j]);
        }
        printf("Enter your answer (A, B, C, or D): ");

        // Get the user's answer
        char answer[MAX_NAME_LENGTH + 1];
        scanf("%s", answer);

        // Convert the answer to uppercase
        if (answer[0] >= 'a' && answer[0] <= 'z') {
            answer[0] -= 32;
        }

        // Check if the answer is correct
        int answer_index = answer[0] - 'A';
        if (answer_index == q.answer_index) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", 'A' + q.answer_index);
        }
    }

    // Print the final score
    printf("Final score: %d/%d\n", score, NUM_QUESTIONS);
}

// Main function
int main() {
    // Print the periodic table and instructions
    print_periodic_table();
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d multiple choice questions.\n", NUM_QUESTIONS);
    printf("Please enter A, B, C, or D for your answer.\n\n");

    // Run the quiz
    run_quiz();

    return 0;
}