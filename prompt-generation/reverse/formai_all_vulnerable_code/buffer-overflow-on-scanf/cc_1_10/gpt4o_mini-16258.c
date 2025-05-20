//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInputBuffer() {
    while (getchar() != '\n'); // clear the input buffer
}

int getPositiveInteger() {
    int num;
    
    while (1) {
        printf("Enter a positive integer: ");
        if (scanf("%d", &num) != 1 || num <= 0) {
            printf("Invalid input. Please try again.\n");
            clearInputBuffer(); // clear invalid input
        } else {
            clearInputBuffer(); // clear the buffer after successful input
            return num;
        }
    }
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Random number between 1 and sides
}

void rollMultipleDice() {
    int numberOfDice = getPositiveInteger();
    int diceSides = getPositiveInteger();
    int total = 0;

    printf("Rolling %d dice with %d sides each:\n", numberOfDice, diceSides);
    for (int i = 0; i < numberOfDice; i++) {
        int roll = rollDice(diceSides);
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
            printf("Invalid choice. Please try again.\n");
            clearInputBuffer(); // clear invalid input
            continue;
        }
        clearInputBuffer(); // clear the buffer after successful input

        if (choice == 1) {
            rollMultipleDice();
        }
    } while (choice != 2);

    printf("Thank you for using the Dice Roller! Goodbye!\n");
    return 0;
}