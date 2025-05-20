//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int number;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
    char group[20];
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008, "Non-metal"},
    {2, "Helium", "He", 4.0026, "Noble gas"},
    {3, "Lithium", "Li", 6.94, "Alkali metal"},
    {4, "Beryllium", "Be", 9.0122, "Alkaline earth metal"},
    {5, "Boron", "B", 10.81, "Metalloid"},
    // ... [Fill in the remaining elements] ...
    {118, "Oganesson", "Og", 294, "Noble gas"}
};

void displayMenu() {
    printf("\n*** Periodic Table Quiz ***\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    printf("Select an option (1 or 2): ");
}

void askQuestion(int index) {
    printf("\nQuestion: What is the symbol for %s? ", periodicTable[index].name);
    char inputSymbol[3];
    scanf("%s", inputSymbol);
    if (strcmp(inputSymbol, periodicTable[index].symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct symbol is %s.\n", periodicTable[index].symbol);
    }
}

int getRandomIndex() {
    return rand() % MAX_ELEMENTS;
}

int main() {
    int choice;

    printf("Welcome to the Periodic Table Quiz!\n");
    srand(time(NULL)); // Seed random number generator

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int totalQuestions = 5, i;
                for (i = 0; i < totalQuestions; i++) {
                    int randomIndex = getRandomIndex();
                    askQuestion(randomIndex);
                }
                break;
            }
            case 2:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid option. Please select again.\n");
        }
    } while (choice != 2);

    return 0;
}