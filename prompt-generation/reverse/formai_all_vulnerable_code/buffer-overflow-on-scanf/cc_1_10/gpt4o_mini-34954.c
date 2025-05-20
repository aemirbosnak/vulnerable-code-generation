//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the console
}

void displayTitle() {
    clearScreen();
    printf("**********************************\n");
    printf("*   Welcome to the Periodic Table Quiz   *\n");
    printf("**********************************\n");
}

void playQuiz() {
    int score = 0;
    int totalQuestions = 3; // We will ask 3 questions
    int askedQuestions[totalQuestions];
    int index;
    char userAnswer[3];

    printf("\nGet ready to test your knowledge of the periodic table!\n");
    printf("For each question, type the symbol of the element or its name.\n");

    srand(time(NULL));

    for (int i = 0; i < totalQuestions; i++) {
        index = rand() % MAX_ELEMENTS;
        askedQuestions[i] = index;

        printf("\nQuestion %d: What is the symbol for %s?\n", i + 1, periodicTable[index].name);
        printf("Your answer: ");
        scanf("%s", userAnswer);

        // Check the answer ignoring case
        if (strcasecmp(userAnswer, periodicTable[index].symbol) == 0) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Wrong! The correct symbol is %s.\n", periodicTable[index].symbol);
        }
    }

    printf("\nYour total score: %d out of %d\n", score, totalQuestions);
    printf("Thank you for playing!\n");
}

void displayInstructions() {
    clearScreen();
    printf("**********************************\n");
    printf("*   Instructions for the Quiz    *\n");
    printf("**********************************\n");
    printf("- You will be asked questions about the periodic table.\n");
    printf("- Type the symbol (or the name) of the element for your answer.\n");
    printf("- Every correct answer earns you a point.\n");
    printf("- Try to answer as many questions correctly as possible!\n");
    printf("- Let's get started!\n");
    printf("\nPress Enter to continue...");
    getchar();
}

int main() {
    displayTitle();
    displayInstructions();
    playQuiz();

    return 0;
}