//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5

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

void printInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about elements.\n", MAX_QUESTIONS);
    printf("For each question, type the answer (element name or symbol) and press Enter.\n");
    printf("Good luck!\n\n");
}

void generateQuestion(int *index) {
    srand(time(0));
    *index = rand() % (sizeof(periodicTable) / sizeof(periodicTable[0]));
}

void askQuestion(int index, int *score) {
    char answer[30];
    printf("What is the symbol for %s? ", periodicTable[index].name);
    scanf("%s", answer);

    if (strcasecmp(answer, periodicTable[index].symbol) == 0) {
        printf("Correct!\n\n");
        (*score)++;
    } else {
        printf("Incorrect! The correct symbol is %s.\n\n", periodicTable[index].symbol);
    }
}

void showFinalScore(int score) {
    printf("You scored %d out of %d.\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("Excellent! You're a chemistry whiz!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! You have a decent knowledge of the periodic table.\n");
    } else {
        printf("Keep studying! You'll do better next time!\n");
    }
}

int main() {
    int score = 0;
    int index;

    printInstructions();

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generateQuestion(&index);
        askQuestion(index, &score);
    }

    showFinalScore(score);
    return 0;
}