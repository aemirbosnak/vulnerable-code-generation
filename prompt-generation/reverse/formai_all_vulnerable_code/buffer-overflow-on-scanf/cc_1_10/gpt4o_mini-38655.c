//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_QUESTIONS 5

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

void initializeElements(Element elements[]) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomicNumber = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomicNumber = 2;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomicNumber = 3;

    strcpy(elements[3].symbol, "Be");
    strcpy(elements[3].name, "Beryllium");
    elements[3].atomicNumber = 4;

    strcpy(elements[4].symbol, "B");
    strcpy(elements[4].name, "Boron");
    elements[4].atomicNumber = 5;

    strcpy(elements[5].symbol, "C");
    strcpy(elements[5].name, "Carbon");
    elements[5].atomicNumber = 6;

    strcpy(elements[6].symbol, "N");
    strcpy(elements[6].name, "Nitrogen");
    elements[6].atomicNumber = 7;

    strcpy(elements[7].symbol, "O");
    strcpy(elements[7].name, "Oxygen");
    elements[7].atomicNumber = 8;

    strcpy(elements[8].symbol, "F");
    strcpy(elements[8].name, "Fluorine");
    elements[8].atomicNumber = 9;

    strcpy(elements[9].symbol, "Ne");
    strcpy(elements[9].name, "Neon");
    elements[9].atomicNumber = 10;
}

void displayQuestion(int index, Element elements[]) {
    printf("Question %d: What is the name of the element with symbol '%s'?\n", index + 1, elements[index].symbol);
    printf("A) %s\n", elements[index].name);
    
    // Displaying some wrong options
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (i != index) {
            printf("%c) %s\n", 'B' + (i - (i > index)), elements[i].name);
        }
    }
}

int checkAnswer(int index, char answer, Element elements[]) {
    return (answer == 'A');
}

int main() {
    Element elements[MAX_ELEMENTS];
    initializeElements(elements);
    
    char answer;
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a series of questions about the first 10 elements.\n");
    printf("Type the letter corresponding to your answer (A, B, C, etc.).\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(i, elements);
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (checkAnswer(i, answer, elements)) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was: %s\n\n", elements[i].name);
        }
    }

    printf("You answered %d out of %d questions correctly.\n", score, MAX_QUESTIONS);
    printf("Thank you for participating in the quiz. Keep learning about the elements!\n");

    return 0;
}