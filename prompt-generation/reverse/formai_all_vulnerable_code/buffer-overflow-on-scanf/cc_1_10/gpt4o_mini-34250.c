//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

void initializeElements(Element elements[]) {
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;
    elements[0].atomicWeight = 1.008;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;
    elements[1].atomicWeight = 4.0026;

    // ... Initialize other elements similarly

    strcpy(elements[117].name, "Oganesson");
    strcpy(elements[117].symbol, "Og");
    elements[117].atomicNumber = 118;
    elements[117].atomicWeight = 294;
}

void displayQuizMenu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

void askQuestion(Element element) {
    char userAnswer[3];
    printf("What is the symbol for %s? ", element.name);
    scanf("%s", userAnswer);

    if (strcmp(userAnswer, element.symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n", element.symbol);
    }
}

int main() {
    Element elements[MAX_ELEMENTS];
    initializeElements(elements);

    int choice;
    displayQuizMenu();
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Starting quiz...\n");
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            askQuestion(elements[i]);
            printf("\n");
        }
    } else {
        printf("Exiting the quiz. Goodbye!\n");
    }

    return 0;
}