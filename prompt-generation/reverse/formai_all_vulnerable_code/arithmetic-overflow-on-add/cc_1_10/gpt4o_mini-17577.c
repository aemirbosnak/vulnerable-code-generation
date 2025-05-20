//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void rollDice(int numDice, int numSides);
void displayResults(int *results, int numDice);
void displayMenu();
int getUserInput();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice, numSides;
    char choice;

    do {
        displayMenu();
        choice = getchar();
        getchar(); // Consume the newline character

        switch (choice) {
            case '1':
                printf("Enter the number of dice (1-%d): ", MAX_DICE);
                numDice = getUserInput();
                printf("Enter the number of sides on dice (1-%d): ", MAX_SIDES);
                numSides = getUserInput();
                if (numDice <= MAX_DICE && numSides <= MAX_SIDES) {
                    rollDice(numDice, numSides);
                } else {
                    printf("Inputs exceed limits.\n");
                }
                break;
            case '2':
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '2');

    return 0;
}

void displayMenu() {
    printf("\n=== Dice Roller ===\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int getUserInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            while(getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a number: ");
        } else {
            while(getchar() != '\n'); // Clear the input buffer
            return input;
        }
    }
}

void rollDice(int numDice, int numSides) {
    int results[MAX_DICE];
    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1; // Generate a random number from 1 to numSides
    }

    displayResults(results, numDice);
}

void displayResults(int *results, int numDice) {
    int total = 0;
    printf("Results: ");
    
    for (int i = 0; i < numDice; i++) {
        printf("%d ", results[i]);
        total += results[i];
    }
    
    printf("\nTotal: %d\n", total);
}