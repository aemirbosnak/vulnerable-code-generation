//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ATOMIC_NUMBERS 118
#define MAX_QUESTION_NUM 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    int atomic_number;
    double atomic_weight;
} element;

element elements[ATOMIC_NUMBERS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.01},
    {"N", "Nitrogen", 7, 14.01},
    {"O", "Oxygen", 8, 16.00},
    {"F", "Fluorine", 9, 19.00},
    {"Ne", "Neon", 10, 20.18},
    {"Na", "Sodium", 11, 22.99},
    {"Mg", "Magnesium", 12, 24.31},
    {"Al", "Aluminum", 13, 26.98},
    {"Si", "Silicon", 14, 28.09},
    {"P", "Phosphorus", 15, 30.97},
    {"S", "Sulfur", 16, 32.06},
    {"Cl", "Chlorine", 17, 35.45},
    {"Ar", "Argon", 18, 39.95},
    {"K", "Potassium", 19, 39.10},
    {"Ca", "Calcium", 20, 40.08},
    {"Sc", "Scandium", 21, 44.96},
    {"Ti", "Titanium", 22, 47.87},
    {"V", "Vanadium", 23, 50.94},
    {"Cr", "Chromium", 24, 52.00},
    {"Mn", "Manganese", 25, 54.94},
    {"Fe", "Iron", 26, 55.85},
    {"Ni", "Nickel", 28, 58.69},
    {"Cu", "Copper", 29, 63.55},
    {"Zn", "Zinc", 30, 65.38},
    {"Ga", "Gallium", 31, 69.72},
    {"Ge", "Germanium", 32, 72.63},
    {"As", "Arsenic", 33, 74.92},
    {"Se", "Selenium", 34, 78.96},
    {"Br", "Bromine", 35, 79.90},
    {"Kr", "Krypton", 36, 83.80},
    {"Rb", "Rubidium", 37, 85.47},
    {"Sr", "Strontium", 38, 87.62},
    {"Y", "Yttrium", 39, 88.91},
    {"Zr", "Zirconium", 40, 91.22},
    {"Nb", "Niobium", 41, 92.91},
    {"Mo", "Molybdenum", 42, 95.94},
    {"Tc", "Technetium", 43, 98.00},
    {"Ru", "Ruthenium", 44, 101.07},
    {"Rh", "Rhodium", 45, 102.91},
    {"Pd", "Palladium", 46, 106.42},
    {"Ag", "Silver", 47, 107.87},
    {"Cd", "Cadmium", 48, 112.41},
    {"In", "Indium", 49, 114.82},
    {"Sn", "Tin", 50, 118.71},
    {"Sb", "Antimony", 51, 121.76},
    {"Te", "Tellurium", 52, 127.60},
    {"I", "Iodine", 53, 126.90},
    {"Xe", "Xenon", 54, 131.29},
    {"Cs", "Cesium", 55, 132.91},
    {"Ba", "Barium", 56, 137.33},
    {"La", "Lanthanum", 57, 138.91},
    {"Ce", "Cerium", 58, 140.12},
    {"Pr", "Praseodymium", 59, 140.91},
    {"Nd", "Neodymium", 60, 144.24},
    {"Pm", "Promethium", 61, 145.00},
    {"Sm", "Samarium", 62, 150.36},
    {"Eu", "Europium", 63, 151.96},
    {"Gd", "Gadolinium", 64, 157.25},
    {"Tb", "Terbium", 65, 158.93},
    {"Dy", "Dysprosium", 66, 162.50},
    {"Ho", "Holmium", 67, 164.93},
    {"Er", "Erbium", 68, 167.26},
    {"Tm", "Thulium", 69, 168.93},
    {"Yb", "Ytterbium", 70, 173.05},
    {"Lu", "Lutetium", 71, 174.97},
    {"Hf", "Hafnium", 72, 178.49},
    {"Ta", "Tantalum", 73, 180.95},
    {"W", "Tungsten", 74, 183.84},
    {"Re", "Rhenium", 75, 186.21},
    {"Os", "Osmium", 76, 190.23},
    {"Ir", "Iridium", 77, 192.22},
    {"Pt", "Platinum", 78, 195.08},
    {"Au", "Gold", 79, 196.97},
    {"Hg", "Mercury", 80, 200.59},
    {"Tl", "Thallium", 81, 204.38},
    {"Pb", "Lead", 82, 207.2},
    {"Bi", "Bismuth", 83, 208.98},
    {"Po", "Polonium", 84, 209.00},
    {"At", "Astatine", 85, 210.00},
    {"Rn", "Radon", 86, 222.00},
    {"Fr", "Francium", 87, 223.00},
    {"Ra", "Radium", 88, 226.03},
    {"Ac", "Actinium", 89, 227.03},
    {"Th", "Thorium", 90, 232.04},
    {"Pa", "Protactinium", 91, 231.04},
    {"U", "Uranium", 92, 238.03},
    {"Np", "Neptunium", 93, 237.05},
    {"Pu", "Plutonium", 94, 244.06},
    {"Am", "Americium", 95, 243.06},
    {"Cm", "Curium", 96, 247.07},
    {"Bk", "Berkelium", 97, 247.07},
    {"Cf", "Californium", 98, 251.08},
    {"Es", "Einsteinium", 99, 252.08},
    {"Fm", "Fermium", 100, 257.10},
    {"Md", "Mendelevium", 101, 258.10},
    {"No", "Nobelium", 102, 259.10},
    {"Lr", "Lawrencium", 103, 262.11},
    {"Rf", "Rutherfordium", 104, 267.12},
    {"Db", "Dubnium", 105, 270.13},
    {"Sg", "Seaborgium", 106, 271.13},
    {"Bh", "Bohrium", 107, 270.13},
    {"Hs", "Hassium", 108, 277.15},
    {"Mt", "Meitnerium", 109, 276.15},
    {"Ds", "Darmstadtium", 110, 281.16},
    {"Rg", "Roentgenium", 111, 280.16},
    {"Cn", "Copernicium", 112, 285.18},
    {"Nh", "Nihonium", 113, 284.18},
    {"Fl", "Flerovium", 114, 289.19},
    {"Mc", "Moscovium", 115, 288.19},
    {"Lv", "Livermorium", 116, 293.20},
    {"Ts", "Tennessine", 117, 294.21},
    {"Og", "Oganesson", 118, 294.21} 
};

typedef struct {
    char question[MAX_NAME_LENGTH + 40];
    char correct_answer[3];
} quiz_question;

int get_random_number(int min, int max);
void generate_question(quiz_question* question);
int is_valid_answer(char answer[]);
int get_score(int correct_answers, int total_questions);

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will have to answer 10 random questions about elements from the periodic table.\n");
    printf("Good luck!\n");
    printf("==============================================\n");
    
    int correct_answers = 0;
    int total_questions = 0;
    quiz_question question;
    char answer[3];
    
    while(total_questions < MAX_QUESTION_NUM) {
        generate_question(&question);
        printf("%s\n", question.question);
        scanf("%s", answer);
        while(!is_valid_answer(answer)) {
            printf("Invalid answer! Please try again: ");
            scanf("%s", answer);
        }
        if(strcmp(answer, question.correct_answer) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Wrong! The correct answer was %s\n", question.correct_answer);
        }
        printf("==============================================\n");
        total_questions++;
    }
    int score = get_score(correct_answers, total_questions);
    printf("You have answered %d out of %d questions correctly.\n", correct_answers, total_questions);
    printf("Your score is %d%%\n", score);
    return 0;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_question(quiz_question* question) {
    int index = get_random_number(0, ATOMIC_NUMBERS - 1);
    element* element_data = &elements[index];
    question->correct_answer[0] = element_data->symbol[0];
    question->correct_answer[1] = element_data->symbol[1];
    question->correct_answer[2] = '\0';
    sprintf(question->question, "What is the symbol for %s?", element_data->name);
}

int is_valid_answer(char answer[]) {
    if(strlen(answer) != 1 && strlen(answer) != 2) {
        return 0;
    }
    for(int i = 0; i < strlen(answer); i++) {
        if(!isalpha(answer[i])) {
            return 0;
        }
    }
    return 1;
}

int get_score(int correct_answers, int total_questions) {
    return (double) correct_answers / (double) total_questions * 100;
}