//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void rollDice(int sides);
void displayMenu();
int getUserInput();
void handleChoice(int choice);
void clearScreen();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int choice;

    do {
        clearScreen();
        displayMenu();
        choice = getUserInput();
        
        // Handle user choices including exit option
        handleChoice(choice);

    } while (choice != 3);

    printf("Thank you for using the Dice Roller. Goodbye!\n");
    return 0;
}

// Function to clear the screen using system call
void clearScreen() {
    // This works for Unix/Linux systems
    printf("\033[H\033[J"); 
}

// Function to display the menu options
void displayMenu() {
    printf("===================================\n");
    printf("        Welcome to Dice Roller     \n");
    printf("===================================\n");
    printf("1. Roll a Standard Die (6 sides)\n");
    printf("2. Roll a Custom Die (Input Sides)\n");
    printf("3. Exit\n");
    printf("===================================\n");
    printf("Please enter your choice: ");
}

// Function to get validated user input
int getUserInput() {
    int choice;
    int result = scanf("%d", &choice);
    while (result != 1 || (choice < 1 || choice > 3)) {
        printf("Invalid input. Please enter a number between 1 and 3: ");
        // Clear invalid input from the buffer
        while (getchar() != '\n');
        result = scanf("%d", &choice);
    }
    return choice;
}

// Function to handle user's choice
void handleChoice(int choice) {
    int sides;
    
    switch (choice) {
        case 1:
            printf("\nRolling a standard 6-sided die...\n");
            rollDice(6);
            break;
        case 2:
            printf("\nEnter the number of sides for the custom die: ");
            scanf("%d", &sides);
            while (sides <= 0) {
                printf("Please enter a positive integer for the number of sides: ");
                scanf("%d", &sides);
            }
            printf("Rolling a custom %d-sided die...\n", sides);
            rollDice(sides);
            break;
        case 3:
            break;
        default:
            printf("\nUnexpected error. Please try again.\n");
    }
}

// Function to roll a die of a given number of sides
void rollDice(int sides) {
    // Simulate the die roll
    int roll = (rand() % sides) + 1;
    printf("You rolled a %d!\n", roll);
    
    // Ask if user wants to roll again
    printf("Press Enter to roll again...");
    while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for user to hit Enter
}