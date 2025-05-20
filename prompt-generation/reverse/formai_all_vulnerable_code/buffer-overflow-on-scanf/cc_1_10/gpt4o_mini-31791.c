//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 5

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H"},
    {"Helium", "He"},
    {"Lithium", "Li"},
    {"Beryllium", "Be"},
    {"Boron", "B"},
    {"Carbon", "C"},
    {"Nitrogen", "N"},
    {"Oxygen", "O"},
    {"Fluorine", "F"},
    {"Neon", "Ne"}
};

void clearScreen() {
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about the elements.\n");
    printf("Type 'exit' at any time to end the quiz.\n\n");
    printf("Let’s test your knowledge!\n\n");
}

int quiz() {
    int score = 0;
    char answer[MAX_SYMBOL_LEN];
    int idx;

    srand(time(NULL));

    for(int i = 0; i < 5; i++) {
        idx = rand() % MAX_ELEMENTS; // Get a random element
        printf("What is the symbol for %s? ", elements[idx].name);
        scanf("%s", answer);

        // Check for exit command
        if (strcmp(answer, "exit") == 0) {
            printf("Thanks for playing! Your score: %d\n", score);
            return -1;
        }

        if (strcmp(answer, elements[idx].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", elements[idx].symbol);
        }
        printf("Current Score: %d\n", score);
    }

    return score;
}

void finalOutput(int score) {
    // Dynamic coloring based on the score
    if (score >= 4) {
        printf("\033[32mCongratulations! You scored %d out of 5!\033[0m\n", score); // Green
    } else if (score == 3) {
        printf("\033[33mGood job! You scored %d out of 5!\033[0m\n", score); // Yellow
    } else {
        printf("\033[31mYou scored %d out of 5. Better luck next time!\033[0m\n", score); // Red
    }
}

int main() {
    int score;

    clearScreen();
    displayInstructions();

    score = quiz();
    if (score != -1) {
        finalOutput(score);
    }

    return 0;
}