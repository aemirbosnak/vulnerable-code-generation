//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Function to roll multiple dice
int rollMultipleDice(int numDice, int sides) {
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rollDie(sides);
    }
    return total;
}

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll 1d6\n");
    printf("2. Roll 2d6\n");
    printf("3. Roll 1d20\n");
    printf("4. Roll multiple dice\n");
    printf("5. Exit\n");
    printf("Please enter your choice (1-5): ");
    scanf("%d", &choice);
    return choice;
}

// Function to handle rolling multiple dice interaction
void handleMultipleDice() {
    int numDice, sides;
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides on each die: ");
    scanf("%d", &sides);
    int result = rollMultipleDice(numDice, sides);
    printf("You rolled: %d (rolling %dd%d)\n", result, numDice, sides);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;

    do {
        choice = displayMenu();
        
        switch (choice) {
            case 1:
                printf("You rolled a single d6: %d\n", rollDie(6));
                break;
            case 2:
                printf("You rolled 2d6: %d\n", rollMultipleDice(2, 6));
                break;
            case 3:
                printf("You rolled a single d20: %d\n", rollDie(20));
                break;
            case 4:
                handleMultipleDice();
                break;
            case 5:
                printf("Exiting the program. Thank you for using the Dice Roller!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}