//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20

// Function prototypes
void printWelcome();
void printInstructions();
int rollDice(int sides);
void playAgain();

int main() {
    // Setting the random seed
    srand(time(NULL));

    printWelcome();
    printInstructions();
    playAgain();

    return 0;
}

// Function to print a welcome message
void printWelcome() {
    printf("*****************************************\n");
    printf("**         Welcome to the Dice Roller! **\n");
    printf("*****************************************\n");
}

// Function to print instructions for the user
void printInstructions() {
    printf("Instructions:\n");
    printf("1. Choose the number of sides for your dice (between 1 and %d).\n", MAX_SIDES);
    printf("2. The roller will produce a random outcome based on your choice!\n");
    printf("3. Keep rolling as many times as you desire!\n");
    printf("4. When you want to stop, just decide not to roll again!\n");
    printf("Now, let's get started!\n\n");
}

// Function that simulates rolling a dice
int rollDice(int sides) {
    return rand() % sides + 1; // Generate number between 1 and sides
}

// Function that allows the user to play again
void playAgain() {
    char choice;
    int sides;

    do {
        printf("Enter the number of sides for your dice (1 - %d): ", MAX_SIDES);
        if (scanf("%d", &sides) != 1 || sides < 1 || sides > MAX_SIDES) {
            printf("Invalid input. Please enter a number between 1 and %d.\n\n", MAX_SIDES);
            while(getchar() != '\n'); // Clear invalid input
            continue; // Restart the loop
        }

        printf("Rolling a %d-sided dice...\n", sides);
        
        char keepRolling;
        do {
            int result = rollDice(sides);
            printf("You rolled a: %d\n", result);
            printf("Do you want to roll again? (y/n): ");
            scanf(" %c", &keepRolling);
        } while (keepRolling == 'y' || keepRolling == 'Y');

        printf("Would you like to roll a different dice? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing! Goodbye!\n");
}