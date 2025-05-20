//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_QUESTIONS 5

typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
} Element;

Element periodicTable[] = {
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

void askQuestion(int index) {
    printf("Question %d: What is the symbol of %s? ", index + 1, periodicTable[index].name);
}

int validateAnswer(int index, char *userAnswer) {
    if (strcasecmp(userAnswer, periodicTable[index].symbol) == 0) {
        return 1; // Correct
    }
    return 0; // Incorrect
}

void displayScore(int score) {
    printf("\nYour total score: %d out of %d\n", score, TOTAL_QUESTIONS);
    if (score == TOTAL_QUESTIONS) {
        printf("Excellent! You're a chemistry whiz!\n");
    } else if (score >= TOTAL_QUESTIONS / 2) {
        printf("Good job! Keep studying!\n");
    } else {
        printf("Don't worry, keep practicing!\n");
    }
}

int main() {
    char userAnswer[3];
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a total of %d questions.\n", TOTAL_QUESTIONS);

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        askQuestion(i);
        scanf("%s", userAnswer);
        if (validateAnswer(i, userAnswer)) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer is: %s\n", periodicTable[i].symbol);
        }
    }

    displayScore(score);
    
    return 0;
}