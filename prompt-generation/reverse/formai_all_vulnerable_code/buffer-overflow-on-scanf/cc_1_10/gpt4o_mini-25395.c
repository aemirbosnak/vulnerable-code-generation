//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
void rollDice(int dice, int sides);
int getValidInput(int min, int max);
void clearScreen();
void pause();

int main() {
    int choice, dice, sides;

    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        displayMenu();
        choice = getValidInput(1, 4); // Accept choices only between 1 and 4

        switch (choice) {
            case 1:
                printf("Enter number of dice to roll: ");
                dice = getValidInput(1, 10); // Limit to rolling 1-10 dice
                printf("Enter number of sides on the dice: ");
                sides = getValidInput(4, 20); // Limit to 4-20 sided dice
                
                rollDice(dice, sides);
                break;
            case 2:
                printf("Enter the number of sides for the dice you wish to roll (e.g., 6 for a six-sided die): ");
                sides = getValidInput(4, 20); // Limit to 4-20 sided dice
                
                printf("You will roll one %d-sided die.\n", sides);
                rollDice(1, sides);
                break;
            case 3:
                clearScreen();
                printf("Thanks for using the Dice Roller! Goodbye!\n");
                exit(0);
            case 4:
                clearScreen();
                printf("Help: This program allows you to roll dice with specified sides\n");
                printf("and quantity. Choose an option to either roll multiple dice,\n");
                printf("roll a single die, or exit the program.\n");
                pause();
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
        
        pause();
    }

    return 0;
}

void displayMenu() {
    clearScreen();
    printf("----- Dice Roller Menu -----\n");
    printf("1. Roll multiple dice\n");
    printf("2. Roll a single die\n");
    printf("3. Exit\n");
    printf("4. Help\n");
    printf("Please enter your choice (1-4): ");
}

void rollDice(int dice, int sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides...\n", dice, sides);
    
    for (int i = 0; i < dice; i++) {
        int roll = (rand() % sides) + 1; // Generate a random roll
        printf("Die %d rolled: %d\n", i + 1, roll);
        total += roll; // Accumulate total rolls
    }
    
    printf("Total of all rolls: %d\n", total);
}

int getValidInput(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }
    }
}

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J"); // ANSI escape codes for clearing screen
}

void pause() {
    printf("Press Enter to continue...");
    getchar(); // To consume the newline after entering input
    getchar(); // Wait for user to press Enter
}