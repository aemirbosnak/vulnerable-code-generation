//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll dice and print result
void rollDice() {
    int numDice, sides, i, result;

    // Get number of dice and sides from user
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides: ");
    scanf("%d", &sides);

    // Roll dice and print results
    for (i = 0; i < numDice; i++) {
        result = randInt(1, sides);
        printf("Dice %d: %d\n", i+1, result);
    }
}

int main() {
    int choice;

    // Seed random number generator with current time
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Dice Roller!\n");

    // Main menu loop
    while (1) {
        printf("\n");
        printf("1. Roll dice\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollDice();
                break;
            case 2:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}