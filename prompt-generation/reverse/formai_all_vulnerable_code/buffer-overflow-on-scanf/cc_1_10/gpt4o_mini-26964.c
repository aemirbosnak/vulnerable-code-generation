//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include <stdio.h>
#include <string.h>

#define ELEMENTS 10

struct Element {
    char name[20];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
};

struct Element periodicTable[ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.0026},
    {"Lithium", "Li", 3, 6.94},
    {"Beryllium", "Be", 4, 9.0122},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.011},
    {"Nitrogen", "N", 7, 14.007},
    {"Oxygen", "O", 8, 15.999},
    {"Fluorine", "F", 9, 18.998},
    {"Neon", "Ne", 10, 20.180}
};

void displayElement(struct Element e) {
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Element Name: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Weight: %.3f\n", e.atomicWeight);
}

void quiz() {
    int score = 0;
    char answer[3];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked the symbols for the following elements:\n");

    for (int i = 0; i < ELEMENTS; i++) {
        printf("\nElement %d: %s\n", periodicTable[i].atomicNumber, periodicTable[i].name);
        printf("What's the symbol? ");
        scanf("%s", answer);

        // Normalize answer to uppercase
        for (int j = 0; j < strlen(answer); j++) {
            answer[j] = (answer[j] >= 'a' && answer[j] <= 'z') ? answer[j] - 32 : answer[j];
        }
        
        if (strcmp(answer, periodicTable[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct symbol is: %s\n", periodicTable[i].symbol);
        }
    }

    printf("\nYour total score is: %d out of %d\n", score, ELEMENTS);
}

void displayPeriodicTable() {
    printf("Periodic Table of Elements (First 10)\n");
    printf("-----------------------------------------------------\n");
    printf("| Atomic No | Element Name | Symbol | Atomic Weight |\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < ELEMENTS; i++) {
        printf("| %9d | %-12s | %-6s | %12.3f |\n", 
            periodicTable[i].atomicNumber, 
            periodicTable[i].name, 
            periodicTable[i].symbol, 
            periodicTable[i].atomicWeight);
    }
    printf("-----------------------------------------------------\n");
}

int main() {
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Display Periodic Table\n");
        printf("2. Take the Quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayPeriodicTable();
                break;
            case 2:
                quiz();
                break;
            case 3:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}