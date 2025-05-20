//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

Element elements[] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10},
    {"Sodium", "Na", 11},
    {"Magnesium", "Mg", 12},
    {"Aluminum", "Al", 13},
    {"Silicon", "Si", 14},
    {"Phosphorus", "P", 15},
    {"Sulfur", "S", 16},
    {"Chlorine", "Cl", 17},
    {"Argon", "Ar", 18},
    {"Potassium", "K", 19},
    {"Calcium", "Ca", 20}
};

void displayWelcomeMessage() {
    printf("\n==============================================\n");
    printf("          WELCOME TO THE ELEMENT QUIZ!     \n");
    printf("==============================================\n");
    printf("Let's see how well you know the Periodic Table!\n\n");
}

int getRandomQuestionIndex() {
    return rand() % (sizeof(elements) / sizeof(elements[0]));
}

void askQuestion(int index) {
    printf("What is the symbol of %s? ", elements[index].name);
}

void askAtomicNumberQuestion(int index) {
    printf("What is the atomic number of %s? ", elements[index].name);
}

int getAnswer() {
    char answer[3];
    scanf("%s", answer);
    return atoi(answer);
}

int main() {
    srand(time(NULL));
    int score = 0; 
    int numQuestions = 0; 

    displayWelcomeMessage();

    while (numQuestions < MAX_QUESTIONS) {
        int randIndex = getRandomQuestionIndex();
        int choice;
        
        printf("Choose a question type: (1) Symbol (2) Atomic Number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                askQuestion(randIndex);
                char userSymbol[3];
                scanf("%s", userSymbol);
                if (strcmp(userSymbol, elements[randIndex].symbol) == 0) {
                    printf("🎉 Correct! The symbol for %s is indeed %s!\n", elements[randIndex].name, elements[randIndex].symbol);
                    score++;
                } else {
                    printf("❌ Incorrect! The correct symbol is %s.\n", elements[randIndex].symbol);
                }
                break;
            case 2:
                askAtomicNumberQuestion(randIndex);
                int userAtomicNumber = getAnswer();
                if (userAtomicNumber == elements[randIndex].atomicNumber) {
                    printf("🎉 Correct! The atomic number of %s is indeed %d!\n", elements[randIndex].name, elements[randIndex].atomicNumber);
                    score++;
                } else {
                    printf("❌ Incorrect! The correct atomic number is %d.\n", elements[randIndex].atomicNumber);
                }
                break;
            default:
                printf("Invalid choice! Please select (1) or (2).\n");
                continue;
        }

        numQuestions++;
        printf("Current Score: %d/%d\n\n", score, numQuestions);
    }

    printf("==============================================\n");
    printf("              QUIZ OVER!                     \n");
    printf("Your final score is: %d/%d\n", score, MAX_QUESTIONS);
    printf("Thank you for playing! Keep exploring the wonders of Chemistry! 🧪\n");
    printf("==============================================\n");
    
    return 0;
}