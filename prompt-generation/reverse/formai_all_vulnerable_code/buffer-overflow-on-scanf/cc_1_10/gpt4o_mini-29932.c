//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants representing different types of dice
#define D4  4
#define D6  6
#define D8  8
#define D10 10
#define D12 12
#define D20 20

// Function prototypes
int rollDice(int sides);
void displayMenu();
void displayRollResult(int result, int sides);
void simulateRolls();

// Main entry point of the program
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome message
    printf("=== Welcome to the Post-Apocalyptic Dice Roller ===\n");
    printf("In a world shattered by chaos, the roll of a dice can determine your fate...\n");

    // Display menu and simulate rolls based on user choice
    simulateRolls();

    return 0;
}

// Function to roll a dice with a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to display the menu of options
void displayMenu() {
    printf("\nChoose a type of dice to roll:\n");
    printf("1. D4\n");
    printf("2. D6\n");
    printf("3. D8\n");
    printf("4. D10\n");
    printf("5. D12\n");
    printf("6. D20\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

// Function to display the result of a roll
void displayRollResult(int result, int sides) {
    printf("You rolled a %d on a D%d! ", result, sides);
    if (result == sides) {
        printf("Critical success! The fates smile upon you.\n");
    } else if (result == 1) {
        printf("A grim failure. Misfortune follows...\n");
    } else {
        printf("A decent roll. Survive another day.\n");
    }
}

// Function to simulate rolling based on user input
void simulateRolls() {
    int choice = 0;
    while (choice != 7) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int result = rollDice(D4);
                displayRollResult(result, D4);
                break;
            }
            case 2: {
                int result = rollDice(D6);
                displayRollResult(result, D6);
                break;
            }
            case 3: {
                int result = rollDice(D8);
                displayRollResult(result, D8);
                break;
            }
            case 4: {
                int result = rollDice(D10);
                displayRollResult(result, D10);
                break;
            }
            case 5: {
                int result = rollDice(D12);
                displayRollResult(result, D12);
                break;
            }
            case 6: {
                int result = rollDice(D20);
                displayRollResult(result, D20);
                break;
            }
            case 7:
                printf("You have chosen to exit. May your journey be swift.\n");
                break;
            default:
                printf("Invalid choice. The wasteland holds no mercy for those who stray...\n");
                break;
        }
    }
}