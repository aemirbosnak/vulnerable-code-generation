//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayRollResult(int roll) {
    printf("You rolled a: %d\n", roll);
}

void printGratitudeMessage() {
    printf("Thank you for rolling the dice! Your luck is appreciated!\n");
}

int main() {
    int numberOfRolls;
    char continueRolling;
    
    // Seed the random number generator
    srand(time(0));
    
    printf("Welcome to the Gratitude Dice Roller!\n");
    printf("How many times would you like to roll the dice? ");
    
    // Get the number of rolls from the user
    if (scanf("%d", &numberOfRolls) != 1 || numberOfRolls <= 0) {
        printf("Please enter a valid positive integer!\n");
        return 1;
    }

    printf("You have chosen to roll the dice %d times.\n", numberOfRolls);
    
    for (int i = 0; i < numberOfRolls; i++) {
        // Generate a random roll between 1 and 6
        int roll = (rand() % 6) + 1;
        displayRollResult(roll);
        
        // Print a gratitude message after each roll
        printGratitudeMessage();
        
        // Ask user if they want to continue rolling
        if (i < numberOfRolls - 1) {
            printf("Would you like to roll again? (Y/N): ");
            getchar();  // Clear the newline character from the input buffer
            continueRolling = getchar();
            if (continueRolling == 'N' || continueRolling == 'n') {
                break;
            }
        }
    }

    printf("Thank you for playing the Gratitude Dice Roller!\n");
    printf("May your future rolls be filled with good fortune!\n");

    return 0;
}