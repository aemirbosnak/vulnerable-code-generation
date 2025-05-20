//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    // A small subset of the periodic table for demonstration
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

    strcpy(periodicTable[3].name, "Beryllium");
    strcpy(periodicTable[3].symbol, "Be");
    periodicTable[3].atomicNumber = 4;
    periodicTable[3].atomicWeight = 9.0122;

    strcpy(periodicTable[4].name, "Boron");
    strcpy(periodicTable[4].symbol, "B");
    periodicTable[4].atomicNumber = 5;
    periodicTable[4].atomicWeight = 10.81;

    // ... More elements can be added for a complete table
}

void printElement(Element *elem) {
    printf("Atomic Number: %d\n", elem->atomicNumber);
    printf("Element: %s (%s)\n", elem->name, elem->symbol);
    printf("Atomic Weight: %.4f\n\n", elem->atomicWeight);
}

int findElementByAtomicNumber(int atomicNumber) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (periodicTable[i].atomicNumber == atomicNumber) {
            return i;
        }
    }
    return -1;
}

int findElementBySymbol(char *symbol) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(periodicTable[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1;
}

void quizUser() {
    int choice;
    char input[3];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Find by Atomic Number\n");
    printf("2. Find by Symbol\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int atomicNumber;
        printf("Enter the Atomic Number (1-118): ");
        scanf("%d", &atomicNumber);
        int index = findElementByAtomicNumber(atomicNumber);
        if (index < 0) {
            printf("Element not found.\n");
        } else {
            printElement(&periodicTable[index]);
        }
    } else if (choice == 2) {
        printf("Enter the Symbol (1 or 2 letters): ");
        scanf("%s", input);
        int index = findElementBySymbol(input);
        if (index < 0) {
            printf("Element not found.\n");
        } else {
            printElement(&periodicTable[index]);
        }
    } else {
        printf("Invalid option.\n");
    }
}

int main() {
    initializePeriodicTable();
    quizUser();
    return 0;
}