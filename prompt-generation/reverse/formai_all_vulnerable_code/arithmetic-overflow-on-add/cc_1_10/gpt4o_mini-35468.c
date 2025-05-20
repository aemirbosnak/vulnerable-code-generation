//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numDice, int numSides) {
    int total = 0;
    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1;
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

void displayMenu() {
    printf("\n=== Dice Roller ===\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Roll dice with custom sides\n");
    printf("4. Exit\n");
    printf("====================\n");
}

int main() {
    srand(time(0)); // Initialize random number generator
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int numSides;
                printf("Enter number of sides for the die: ");
                scanf("%d", &numSides);
                rollDice(1, numSides);
                break;
            }
            case 2: {
                int numDice, numSides;
                printf("Enter number of dice to roll: ");
                scanf("%d", &numDice);
                printf("Enter number of sides for the dice: ");
                scanf("%d", &numSides);
                rollDice(numDice, numSides);
                break;
            }
            case 3: {
                int numDice;
                printf("Enter number of dice to roll: ");
                scanf("%d", &numDice);
                rollDice(numDice, 6); // Default to 6 sides
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}