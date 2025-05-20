//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie(int sides) {
    return (rand() % sides) + 1; // returns a value between 1 and 'sides'
}

// Function to roll multiple dice
void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides:\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = rollDie(sides);
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Dice Roller ===\n");
    printf("1. Roll Dice\n");
    printf("2. View Previous Rolls\n");
    printf("3. Exit\n");
    printf("===================\n");
    printf("Choose an option: ");
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice;
    int numDice, sides;
    int previousRolls[100][3]; // To keep track of previous rolls {numDice, sides, total}
    int rollCount = 0;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of dice to roll: ");
                scanf("%d", &numDice);
                printf("Enter number of sides on the dice: ");
                scanf("%d", &sides);
                
                // Store previous roll for review
                if (rollCount < 100) {
                    previousRolls[rollCount][0] = numDice;
                    previousRolls[rollCount][1] = sides;
                    previousRolls[rollCount][2] = 0; // Placeholder for total
                }

                rollMultipleDice(numDice, sides);
                
                // Calculate total for the previous roll storage
                if (rollCount < 100) {
                    previousRolls[rollCount][2] = numDice * (sides / 2); // Average case stored
                    rollCount++;
                }

                break;

            case 2:
                printf("\n=== Previous Rolls ===\n");
                if (rollCount == 0) {
                    printf("No rolls recorded yet.\n");
                } else {
                    for (int i = 0; i < rollCount; i++) {
                        printf("Roll %d: %d dice with %d sides, Total: %d\n", 
                                i + 1, previousRolls[i][0], previousRolls[i][1], previousRolls[i][2]);
                    }
                }
                break;

            case 3:
                printf("Exiting the Dice Roller. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option, please choose again.\n");
        }
    }

    return 0;
}