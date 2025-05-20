//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    periodicTable[0] = (Element){1, "Hydrogen", "H", 1.008};
    periodicTable[1] = (Element){2, "Helium", "He", 4.0026};
    periodicTable[2] = (Element){3, "Lithium", "Li", 6.94};
    periodicTable[3] = (Element){4, "Beryllium", "Be", 9.0122};
    periodicTable[4] = (Element){5, "Boron", "B", 10.81};
    periodicTable[5] = (Element){6, "Carbon", "C", 12.011};
    periodicTable[6] = (Element){7, "Nitrogen", "N", 14.007};
    periodicTable[7] = (Element){8, "Oxygen", "O", 15.999};
    periodicTable[8] = (Element){9, "Fluorine", "F", 18.998};
    periodicTable[9] = (Element){10, "Neon", "Ne", 20.180};
    // Additional elements would continue here...
    periodicTable[10] = (Element){11, "Sodium", "Na", 22.990};
    periodicTable[11] = (Element){12, "Magnesium", "Mg", 24.305};
    periodicTable[12] = (Element){13, "Aluminum", "Al", 26.982};
    periodicTable[13] = (Element){14, "Silicon", "Si", 28.085};
    periodicTable[14] = (Element){15, "Phosphorus", "P", 30.974};
    periodicTable[15] = (Element){16, "Sulfur", "S", 32.06};
    periodicTable[16] = (Element){17, "Chlorine", "Cl", 35.45};
    periodicTable[17] = (Element){18, "Argon", "Ar", 39.948};
    periodicTable[18] = (Element){19, "Potassium", "K", 39.098};
    periodicTable[19] = (Element){20, "Calcium", "Ca", 40.078};
    // Placeholder for 98 more elements.
}

void displayQuizInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about different elements.\n");
    printf("Enter the corresponding answer and hit ENTER.\n");
    printf("You can type 'exit' to quit the quiz at any time.\n");
}

void askQuizQuestion() {
    srand(time(NULL));
    int randomIndex = rand() % 20;  // Limiting to first 20 elements for quiz
    Element selectedElement = periodicTable[randomIndex];

    char userAnswer[MAX_NAME_LENGTH];
    printf("What is the name of the element with atomic number %d? ", selectedElement.atomicNumber);
    scanf("%s", userAnswer);
    
    if (strcmp(userAnswer, selectedElement.name) == 0) {
        printf("Correct! The element is %s.\n", selectedElement.name);
    } else {
        printf("Incorrect! The correct answer is %s.\n", selectedElement.name);
    }
}

void takeQuiz() {
    while (1) {
        askQuizQuestion();
        char continueQuizzing[5];
        printf("Do you want to continue the quiz? (yes/no): ");
        scanf("%s", continueQuizzing);
        if (strcmp(continueQuizzing, "no") == 0) {
            printf("Thanks for playing the quiz!\n");
            break;
        }
    }
}

int main() {
    initializePeriodicTable();
    displayQuizInstructions();
    takeQuiz();
    return 0;
}