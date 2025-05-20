//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initPeriodicTable() {
    // Sample data for the periodic table, for demonstration purposes
    strcpy(periodicTable[0].symbol, "H");
    strcpy(periodicTable[0].name, "Hydrogen");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;

    strcpy(periodicTable[1].symbol, "He");
    strcpy(periodicTable[1].name, "Helium");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.0026;

    // More elements can be added here...

    strcpy(periodicTable[2].symbol, "Li");
    strcpy(periodicTable[2].name, "Lithium");
    periodicTable[2].atomicNumber = 3;
    periodicTable[2].atomicWeight = 6.94;

    strcpy(periodicTable[3].symbol, "Be");
    strcpy(periodicTable[3].name, "Beryllium");
    periodicTable[3].atomicNumber = 4;
    periodicTable[3].atomicWeight = 9.0122;

    // More elements can go up until 118...
}

void printElementInfo(Element e) {
    printf("Element: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Atomic Weight: %.4f\n", e.atomicWeight);
}

int getRandomElementIndex() {
    return rand() % MAX_ELEMENTS;  // Random index for periodic table
}

void quizUser() {
    int score = 0;
    int totalQuestions = 5;  // Number of questions for the quiz

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", totalQuestions);
    printf("For each correct answer, you will receive 1 point.\n\n");

    for(int i = 0; i < totalQuestions; i++) {
        int index = getRandomElementIndex();
        Element e = periodicTable[index];
        
        printf("Question %d: What is the symbol of %s?\n", i + 1, e.name);
        char userAnswer[3];
        printf("Your answer: ");
        scanf("%s", userAnswer);
        
        if (strcasecmp(userAnswer, e.symbol) == 0) { // Case insensitive comparison
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is: %s\n\n", e.symbol);
        }
    }

    printf("You scored %d out of %d.\n", score, totalQuestions);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    initPeriodicTable();
    quizUser();
    
    return 0;
}