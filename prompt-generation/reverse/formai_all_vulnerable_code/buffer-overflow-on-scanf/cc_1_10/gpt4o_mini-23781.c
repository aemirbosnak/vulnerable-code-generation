//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void welcomeMessage();
void startRoll();
int rollDice(int sides);
void displayResult(int roll);
void exitProgram();

// Main function
int main() {
    welcomeMessage();
    startRoll();
    exitProgram();
    return 0; // End of main function
}

// Function to display welcome message
void welcomeMessage() {
    printf("================================\n");
    printf("       Welcome to Dice Roller!  \n");
    printf("================================\n");
}

// Function to start the dice rolling process
void startRoll() {
    char choice = 'y'; // Initialize choice to continue
    int sides, roll;

    while (choice == 'y' || choice == 'Y') {
        printf("Enter the number of sides on your die: ");
        scanf("%d", &sides); // User input for number of sides

        // Validating the number of sides
        if (sides < 2) {
            printf("Invalid number of sides. Please try again.\n");
            continue; // Go to the next iteration if invalid
        }

        roll = rollDice(sides); // Roll the dice
        displayResult(roll); // Show the result
        
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice); // Space before %c to ignore whitespace
    }
}

// Function to roll the dice and return the result
int rollDice(int sides) {
    return (rand() % sides) + 1; // Generate a random roll
}

// Function to display the rolling result
void displayResult(int roll) {
    printf("You rolled a %d!\n", roll); // Display the roll result
}

// Function to exit the program
void exitProgram() {
    printf("Thank you for using Dice Roller! Goodbye!\n");
}