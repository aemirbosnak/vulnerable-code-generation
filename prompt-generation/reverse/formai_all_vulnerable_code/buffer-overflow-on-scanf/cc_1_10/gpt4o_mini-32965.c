//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
} Element;

Element periodicTable[MAX_ELEMENTS] = {
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
    {13, "Al", "Aluminum"},
    {14, "Si", "Silicon"},
    {15, "P", "Phosphorus"},
    {16, "S", "Sulfur"},
    {17, "Cl", "Chlorine"},
    {18, "Ar", "Argon"},
    {19, "K", "Potassium"},
    {20, "Ca", "Calcium"},
    // Add other elements...
    {118, "Og", "Oganesson"}
};

void printInstructions() {
    printf("\n=== Periodic Table Quiz ===\n");
    printf("1. Guess the Element: Based on atomic number.\n");
    printf("2. Points will be awarded for correct answers.\n");
    printf("3. The quiz ends when you type 'exit'. Good luck!\n");
}

void startQuiz() {
    char input[50];
    int score = 0;
    srand(time(NULL));

    while (1) {
        int randomIndex = rand() % MAX_ELEMENTS;
        Element element = periodicTable[randomIndex];

        printf("\nWhat is the element with atomic number %d? (or type 'exit' to quit): ", element.atomicNumber);
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Thanks for playing! Your final score is: %d\n", score);
            return;
        }

        if (strcmp(input, element.name) == 0) {
            score++;
            printf("Correct! Your score is now: %d\n", score);
        } else {
            printf("Incorrect! The correct answer is: %s\n", element.name);
        }
    }
}

int main() {
    printInstructions();
    startQuiz();
    return 0;
}