//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the rules of the dice game
void display_rules() {
    printf("Welcome to the Dice Roller Game!\n");
    printf("------------------------------------------------\n");
    printf("Rules:\n");
    printf("1. You can roll between 1 to 6 dice at a time.\n");
    printf("2. The result of each die will be displayed.\n");
    printf("3. You can choose to roll the dice again or exit.\n");
    printf("------------------------------------------------\n");
}

// Function to roll the dice and return the results
void roll_dice(int num_dice, int results[]) {
    for (int i = 0; i < num_dice; i++) {
        results[i] = (rand() % 6) + 1; // Random number between 1 and 6
    }
}

// Function to display the results of the roll
void display_results(int num_dice, int results[]) {
    printf("You rolled %d dice:\n", num_dice);
    for (int i = 0; i < num_dice; i++) {
        printf("Die %d: %d\n", i + 1, results[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;
    int num_dice;
    int results[6]; // Array to hold results for up to 6 dice

    // Display rules of the game
    display_rules();

    do {
        // Ask the user for the number of dice to roll
        printf("How many dice would you like to roll (1-6)? ");
        scanf("%d", &num_dice);
        
        // Validate the input
        while (num_dice < 1 || num_dice > 6) {
            printf("Invalid number. Please enter a number between 1 and 6: ");
            scanf("%d", &num_dice);
        }

        // Roll the dice and display the results
        roll_dice(num_dice, results);
        display_results(num_dice, results);

        // Ask the user if they want to roll again
        printf("Would you like to roll again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        
    } while (choice == 1);
    
    printf("Thank you for playing the Dice Roller Game! Goodbye!\n");
    return 0;
}