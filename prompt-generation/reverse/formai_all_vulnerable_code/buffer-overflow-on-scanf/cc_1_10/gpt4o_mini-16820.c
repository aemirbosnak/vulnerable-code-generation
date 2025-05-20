//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[50];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    strcpy(periodicTable[0].symbol, "H");
    strcpy(periodicTable[0].name, "Hydrogen");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;

    strcpy(periodicTable[1].symbol, "He");
    strcpy(periodicTable[1].name, "Helium");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.002602;

    // Add more elements here...
    
    strcpy(periodicTable[2].symbol, "Li");
    strcpy(periodicTable[2].name, "Lithium");
    periodicTable[2].atomicNumber = 3;
    periodicTable[2].atomicWeight = 6.94;

    strcpy(periodicTable[3].symbol, "Be");
    strcpy(periodicTable[3].name, "Beryllium");
    periodicTable[3].atomicNumber = 4;
    periodicTable[3].atomicWeight = 9.012183;

    // Initialize other elements as desired

}

void printElementDetails(int index) {
    printf("Element: %s\n", periodicTable[index].name);
    printf("Symbol: %s\n", periodicTable[index].symbol);
    printf("Atomic Number: %d\n", periodicTable[index].atomicNumber);
    printf("Atomic Weight: %.3f\n", periodicTable[index].atomicWeight);
}

int getRandomQuestionIndex() {
    return rand() % MAX_ELEMENTS;
}

void askQuizQuestion() {
    int index = getRandomQuestionIndex();
    printf("What is the symbol of the element with atomic number %d?\n", periodicTable[index].atomicNumber);
    printf("Your answer: ");
    
    char answer[3];
    scanf("%s", answer);
    
    if (strcmp(answer, periodicTable[index].symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", periodicTable[index].symbol);
    }
}

void startQuiz(int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        askQuizQuestion();
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int numQuestions;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &numQuestions);

    initializePeriodicTable();
    startQuiz(numQuestions);

    return 0;
}