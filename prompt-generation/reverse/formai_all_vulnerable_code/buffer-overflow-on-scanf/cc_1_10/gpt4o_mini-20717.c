//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
int rollDice(int sides);
void clearBuffer();

int main() {
    int choice, sides, rolls;

    // Seed the random number generator
    srand(time(NULL));

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the number of sides on the die (e.g., 6, 10, 20): ");
                if (scanf("%d", &sides) != 1 || sides < 1) {
                    clearBuffer();
                    printf("Invalid input! Sides must be a positive integer.\n");
                } else {
                    printf("Rolling a %d-sided die... You rolled a %d!\n", sides, rollDice(sides));
                }
                break;

            case 2:
                printf("Enter the number of rolls: ");
                if (scanf("%d", &rolls) != 1 || rolls < 1) {
                    clearBuffer();
                    printf("Invalid input! Rolls must be a positive integer.\n");
                } else {
                    printf("Rolling a 6-sided die %d times:\n", rolls);
                    for (int i = 0; i < rolls; i++) {
                        printf("Roll %d: %d\n", i + 1, rollDice(6));
                    }
                }
                break;

            case 3:
                printf("Exiting the program. Thank you for rolling with us!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll a single die\n");
    printf("2. Roll a 6-sided die multiple times\n");
    printf("3. Exit\n");
}

// Function to roll the dice
int rollDice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and sides
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Discard invalid input till newline is found
}