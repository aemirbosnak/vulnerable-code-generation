//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <string.h>

// Define the struct for Peroidic Table Elements
typedef struct {
    char symbol[2];
    char name[20];
    int atomicNum;
    float atomicWeight;
} Element;

// Define the array for Peroidic Table Elements
Element elements[] = {
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
    {"S", "Sulfur", 16, 32.07},
    {"Cl", "Chlorine", 17, 35.45},
    {"K", "Potassium", 18, 39.10},
    {"Ar", "Argon", 19, 39.95},
    {"Ca", "Calcium", 20, 40.08},
    {"Sc", "Scandium", 21, 44.96},
    {"Ti", "Titanium", 22, 47.87},
    {"V", "Vanadium", 23, 50.94},
    {"Cr", "Chromium", 24, 52.00},
    {"Mn", "Manganese", 25, 54.94},
    {"Fe", "Iron", 26, 55.85},
    {"Ni", "Nickel", 27, 58.69},
    {"Cu", "Copper", 28, 63.55},
    {"Zn", "Zinc", 29, 65.38},
    {"Ga", "Gallium", 30, 69.72},
    {"Ge", "Germanium", 31, 72.63},
    {"As", "Arsenic", 32, 74.92},
    {"Se", "Selenium", 33, 78.96},
    {"Br", "Bromine", 34, 79.90},
    {"Kr", "Krypton", 35, 83.80},
    {"Rb", "Rubidium", 36, 85.47},
    {"Sr", "Strontium", 37, 87.62},
    {"Y", "Yttrium", 38, 88.91},
    {"Zr", "Zirconium", 39, 91.22},
    {"Nb", "Niobium", 40, 92.91},
    {"Mo", "Molybdenum", 41, 95.94},
    {"Tc", "Technetium", 42, 97.91},
    {"Ru", "Ruthenium", 43, 101.07},
    {"Rh", "Rhodium", 44, 102.91},
    {"Pd", "Palladium", 45, 106.42},
    {"Ag", "Silver", 46, 107.87},
    {"Cd", "Cadmium", 47, 112.41},
    {"In", "Indium", 48, 114.82},
    {"Sn", "Tin", 49, 118.71},
    {"Sb", "Antimony", 50, 121.76},
    {"Te", "Tellurium", 51, 127.60},
    {"I", "Iodine", 52, 126.90},
    {"Xe", "Xenon", 53, 131.29},
};

// Define the function to display the Quiz instructions to the User
void displayInstructions() {
    printf("\n*****************************************************\n");
    printf("**              Periodic Table Quiz                **\n");
    printf("**                                                 **\n");
    printf("** You will see the element's symbol or name, and   **\n");
    printf("** you should guess the element's name or symbol     **\n");
    printf("**                                                 **\n");
    printf("** Please enter your answer in all CAPS only        **\n");
    printf("** The Quiz consists of 20 questions                **\n");
    printf("**                                                 **\n");
    printf("*****************************************************\n\n");
}

// Define the function to shuffle the elements in the array before Quiz starts
void shuffleElements() {
    int i, j;
    Element temp;
    for(i = 0; i < 54; i++) {
        j = rand() % 54;
        temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Define the function to get user input with a prompt and return the user's input
char* getUserInput(char *prompt) {
    static char userInput[20];
    printf("%s ", prompt);
    scanf("%s", userInput);
    return userInput;
}

// Define the function to check if the user's input matches with the quiz answer
int checkQuizAnswer(char userInput[], char answer[]) {
    return strcmp(userInput, answer) == 0 ? 1 : 0;
}

// Define the main function for the Quiz
int main() {
    int i, correctCount = 0;
    char *quizOption;
    displayInstructions();
    shuffleElements();
    for(i = 0; i < 20; i++) {
        printf("Question %d: What is the %s of element %d? ", i+1, i%2==0?"symbol":"name", elements[i].atomicNum);
        quizOption = getUserInput("");
        if(i%2==0) {
            if(checkQuizAnswer(quizOption, elements[i].name)) {
                correctCount++;
                printf("Correct Answer!\n");
            } else {
                printf("Wrong Answer! The Correct Answer is %s\n", elements[i].name);
            }
        } else {
            if(checkQuizAnswer(quizOption, elements[i].symbol)) {
                correctCount++;
                printf("Correct Answer!\n");
            } else {
                printf("Wrong Answer! The Correct Answer is %s\n", elements[i].symbol);
            }
        }
    }
    printf("\nQuiz Completed!\nYou got %d out of 20 questions Correct.\n", correctCount);
    return 0;
}