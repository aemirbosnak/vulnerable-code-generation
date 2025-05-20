//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10 // Maximum number of dice to roll
#define MAX_FACES 20 // Maximum number of faces on a die

// Function prototypes
void displayMenu();
void rollDice(int numberOfDice, int faces);
void displayResults(int results[], int size);
void clearBuffer();

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear any extra newline character

        switch (choice) {
            case 1: {
                int numberOfDice, faces;
                printf("Enter the number of dice to roll (1 - %d): ", MAX_DICE);
                scanf("%d", &numberOfDice);
                clearBuffer();
                printf("Enter the number of faces on the die (2 - %d): ", MAX_FACES);
                scanf("%d", &faces);
                clearBuffer();

                if (numberOfDice < 1 || numberOfDice > MAX_DICE || faces < 2 || faces > MAX_FACES) {
                    printf("Invalid input. Please try again.\n");
                    break;
                }
                rollDice(numberOfDice, faces);
                break;
            }
            case 2:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Welcome to the Dice Roller ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
}

// Function to roll dice
void rollDice(int numberOfDice, int faces) {
    int results[MAX_DICE];
    printf("Rolling %d dice with %d faces...\n", numberOfDice, faces);

    for (int i = 0; i < numberOfDice; i++) {
        results[i] = (rand() % faces) + 1; // Random number between 1 and faces
    }

    displayResults(results, numberOfDice);
}

// Function to display the results of the dice roll
void displayResults(int results[], int size) {
    printf("Results: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}