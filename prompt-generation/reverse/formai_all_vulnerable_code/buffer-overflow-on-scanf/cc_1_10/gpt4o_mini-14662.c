//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 100

// Function to roll a dice with a given number of sides
int roll_dice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and the number of sides
}

// Function to display the history of rolls
void display_history(int history[], int count) {
    printf("\nRoll History:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, history[i]);
    }
}

// Main function
int main() {
    int sides, rolls, history[MAX_HISTORY], roll_count = 0;
    char choice;

    // Initialize random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    
    do {
        // Ask the user how many sides the dice has
        printf("How many sides does your dice have? ");
        scanf("%d", &sides);
        
        // Check for a valid number of sides
        if (sides < 1) {
            printf("A dice must have at least one side. Please try again.\n");
            continue;
        }

        // Ask the user how many times to roll the dice
        printf("How many times would you like to roll the dice? ");
        scanf("%d", &rolls);
        
        // Check for a valid number of rolls
        if (rolls < 1 || roll_count + rolls > MAX_HISTORY) {
            printf("Please enter a valid number of rolls (1 - %d).\n", MAX_HISTORY - roll_count);
            continue;
        }

        // Roll the dice the specified number of times
        for (int i = 0; i < rolls; i++) {
            int result = roll_dice(sides);
            history[roll_count++] = result; // Store the result for history
            printf("Roll %d: You rolled a %d!\n", i + 1, result);
        }

        // Ask if the user wants to see the history
        printf("Would you like to see the history of your rolls? (y/n): ");
        getchar(); // To consume the newline character
        choice = getchar();
        
        if (choice == 'y' || choice == 'Y') {
            display_history(history, roll_count);
        }

        // Ask if the user wants to roll again
        printf("Would you like to roll again? (y/n): ");
        getchar(); // To consume the newline character
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller! Goodbye!\n");
    return 0;
}