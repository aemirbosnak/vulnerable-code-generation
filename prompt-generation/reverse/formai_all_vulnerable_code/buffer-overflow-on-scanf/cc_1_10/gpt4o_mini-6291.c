//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

// Function prototype
void rollDice(int numDice, int numFaces);
void displayResults(int results[], int numDice);

int main() {
    int numDice = 0, numFaces = 0;

    srand(time(NULL)); // Seed random number generator

    // Get user input for number of dice and faces
    printf("Welcome to the C Dice Roller!\n");
    printf("Enter the number of dice (1 to %d): ", MAX_DICE);
    scanf("%d", &numDice);

    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice. Exiting program.\n");
        return 1;
    }

    printf("Enter the number of faces on the dice (4, 6, 8, 10, 12, 20): ");
    scanf("%d", &numFaces);

    if (numFaces != 4 && numFaces != 6 && numFaces != 8 
        && numFaces != 10 && numFaces != 12 && numFaces != 20) {
        printf("Invalid number of faces. Exiting program.\n");
        return 1;
    }

    // Roll the dice
    rollDice(numDice, numFaces);

    return 0;
}

// Function to roll the dice
void rollDice(int numDice, int numFaces) {
    int results[MAX_DICE];
    
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numFaces) + 1; // Roll the dice
    }
    
    displayResults(results, numDice);
}

// Function to display the results of the rolls
void displayResults(int results[], int numDice) {
    printf("You rolled:\n");
    for (int i = 0; i < numDice; i++) {
        printf("Dice %d: %d\n", i + 1, results[i]);
    }

    // Calculate the total
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += results[i];
    }
    printf("Total rolled: %d\n", total);
}

// Function to print a menu
void displayMenu() {
    printf("\nDice Roller Menu:\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
}

// Function to handle the menu selection
void menuHandler() {
    int choice;

    do {
        displayMenu();
        printf("Please choose an option (1-2): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int numDice, numFaces;
                printf("Enter the number of dice (1 to %d): ", MAX_DICE);
                scanf("%d", &numDice);
                printf("Enter the number of faces (4, 6, 8, 10, 12, 20): ");
                scanf("%d", &numFaces);
                rollDice(numDice, numFaces);
                break;
            }
            case 2:
                printf("Exiting. Thank you for using the Dice Roller!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 2);
}

int mainLoop() {
    char repeat;
    do {
        menuHandler();
        printf("Would you like to roll again? (Y/N): ");
        scanf(" %c", &repeat);
    } while (repeat == 'Y' || repeat == 'y');
    
    return 0;
}