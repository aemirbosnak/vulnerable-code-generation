//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.0026},
    {3, "Lithium", "Li", 6.94},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.81},
    {6, "Carbon", "C", 12.011},
    {7, "Nitrogen", "N", 14.007},
    {8, "Oxygen", "O", 15.999},
    {9, "Fluorine", "F", 18.998},
    {10, "Neon", "Ne", 20.180},
    // ... (incomplete for brevity, fill in the rest up to element 118)
    {118, "Oganesson", "Og", 294}
};

void clearScreen() {
    printf("\033[H\033[J");
}

void displayWelcomeMessage() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Can you name the elements based on their atomic number?\n\n");
}

void displayElement(Element e) {
    printf("Element %d: %s (%s) - Atomic Weight: %.3f\n", e.atomicNumber, e.name, e.symbol, e.atomicWeight);
}

int askQuestion(int atomicNum) {
    char answer[MAX_NAME_LENGTH];
    printf("What is the name of the element with atomic number %d? ", atomicNum);
    scanf("%s", answer);
    answer[0] = toupper(answer[0]); // Capitalize the first letter to match correctly.

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (periodicTable[i].atomicNumber == atomicNum && strcmp(periodicTable[i].name, answer) == 0) {
            return 1; // Correct answer
        }
    }
    return 0; // Incorrect answer
}

void startQuiz() {
    int score = 0;
    int totalQuestions = 10;

    srand(time(NULL));

    for (int i = 0; i < totalQuestions; i++) {
        int atomicNum = (rand() % 118) + 1; // Random atomic number between 1 and 118
        if (askQuestion(atomicNum)) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is: ");
            displayElement(periodicTable[atomicNum - 1]);
            printf("\n");
        }
    }

    printf("You've completed the quiz! Your score: %d/%d\n", score, totalQuestions);
}

int main() {
    clearScreen();
    displayWelcomeMessage();
    startQuiz();
    printf("Thank you for playing!\n");
    return 0;
}