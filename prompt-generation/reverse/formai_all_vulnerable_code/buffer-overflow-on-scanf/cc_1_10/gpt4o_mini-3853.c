//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

void initializeElements(Element elements[]) {
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomicNumber = 3;

    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomicNumber = 4;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomicNumber = 5;

    strcpy(elements[5].name, "Carbon");
    strcpy(elements[5].symbol, "C");
    elements[5].atomicNumber = 6;

    strcpy(elements[6].name, "Nitrogen");
    strcpy(elements[6].symbol, "N");
    elements[6].atomicNumber = 7;

    strcpy(elements[7].name, "Oxygen");
    strcpy(elements[7].symbol, "O");
    elements[7].atomicNumber = 8;

    strcpy(elements[8].name, "Fluorine");
    strcpy(elements[8].symbol, "F");
    elements[8].atomicNumber = 9;

    strcpy(elements[9].name, "Neon");
    strcpy(elements[9].symbol, "Ne");
    elements[9].atomicNumber = 10;
}

void startQuiz(Element elements[], int numberOfQuestions) {
    int correctAnswers = 0;
    int totalQuestions = 0;
    char userAnswer[3];

    for (int i = 0; i < numberOfQuestions; i++) {
        int randomIndex = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol of %s? ", i + 1, elements[randomIndex].name);
        
        fgets(userAnswer, sizeof(userAnswer), stdin);
        userAnswer[strcspn(userAnswer, "\n")] = 0; // Remove newline character
        
        if (strcasecmp(userAnswer, elements[randomIndex].symbol) == 0) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", elements[randomIndex].symbol);
        }
        totalQuestions++;
    }

    // Print the score
    printf("Quiz finished. You answered %d out of %d correctly.\n", correctAnswers, totalQuestions);
}

int main() {
    srand(time(0)); // Seed the random number generator

    Element elements[MAX_ELEMENTS];
    initializeElements(elements);

    int numberOfQuestions;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &numberOfQuestions);
    getchar(); // Consume newline character left in the buffer after scanf

    // Start the quiz
    startQuiz(elements, numberOfQuestions);

    printf("Thank you for playing!\n");
    return 0;
}