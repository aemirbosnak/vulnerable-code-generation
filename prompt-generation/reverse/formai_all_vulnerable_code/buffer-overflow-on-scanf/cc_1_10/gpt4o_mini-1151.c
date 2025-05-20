//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
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

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    // Simple initialization of some elements; you can add more
    strcpy(periodicTable[0].name, "Hydrogen");
    strcpy(periodicTable[0].symbol, "H");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;

    strcpy(periodicTable[1].name, "Helium");
    strcpy(periodicTable[1].symbol, "He");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.0026;

    strcpy(periodicTable[2].name, "Lithium");
    strcpy(periodicTable[2].symbol, "Li");
    periodicTable[2].atomicNumber = 3;
    periodicTable[2].atomicWeight = 6.94;
    
    // Add more elements here...
}

void printElement(Element e) {
    printf("Element: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Atomic Weight: %.4f\n", e.atomicWeight);
    printf("-----------------------\n");
}

void quizUser() {
    char userResponse[5];
    int score = 0;

    printf("Periodic Table Quiz!\n");
    printf("Name the element with the atomic number 1:\n");
    printf("Your answer: ");
    scanf("%s", userResponse);
    if (strcasecmp(userResponse, "Hydrogen") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is Hydrogen.\n");
    }

    printf("Name the element with the chemical symbol 'He':\n");
    printf("Your answer: ");
    scanf("%s", userResponse);
    if (strcasecmp(userResponse, "Helium") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is Helium.\n");
    }

    printf("Name the element with the atomic number 3:\n");
    printf("Your answer: ");
    scanf("%s", userResponse);
    if (strcasecmp(userResponse, "Lithium") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is Lithium.\n");
    }

    printf("Your total score is: %d out of 3\n", score);
}

void listElements() {
    printf("Periodic Table Elements:\n");
    for (int i = 0; i < 3; i++) { // just the first three for this example
        printElement(periodicTable[i]);
    }
}

int main() {
    int choice;

    initializePeriodicTable();

    while (1) {
        printf("Welcome to the Periodic Table Program!\n");
        printf("1. List Elements\n");
        printf("2. Take a Quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listElements();
                break;
            case 2:
                quizUser();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}