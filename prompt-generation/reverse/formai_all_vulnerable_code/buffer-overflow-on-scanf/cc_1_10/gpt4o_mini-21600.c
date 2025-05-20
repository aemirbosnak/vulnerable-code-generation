//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
int rollDice(int sides);
void playGame();
void printRollResults(int roll1, int roll2);

int main() {
    srand(time(NULL)); // Seed the random number generator
    int option;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                playGame();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (option != 2);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("------------------------\n");
}

// Function to roll dice and return the result
int rollDice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and sides
}

// Function to handle the game logic
void playGame() {
    int numOfSides;
    printf("Enter the number of sides on the dice (e.g., 6 for a standard dice): ");
    scanf("%d", &numOfSides);

    if (numOfSides < 1) {
        printf("Number of sides must be at least 1. Try again.\n");
        return;
    }

    int roll1 = rollDice(numOfSides);
    int roll2 = rollDice(numOfSides);
    printRollResults(roll1, roll2);
}

// Function to print the results of the rolls
void printRollResults(int roll1, int roll2) {
    printf("You rolled a %d and a %d!\n", roll1, roll2);
    printf("Total: %d\n", roll1 + roll2);
    if (roll1 == roll2) {
        printf("You got a double!\n");
    }
}