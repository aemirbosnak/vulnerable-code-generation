//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIE_SIDES 20
#define MAX_ROLLS 100

void clearBuffer() {
    while (getchar() != '\n');
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void displayRolls(int rolls[], int count, int sides) {
    printf("\nResults of your rolls with a %d-sided die:\n", sides);
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
    printf("Total: %d\n", calculateTotal(rolls, count));
}

int calculateTotal(int rolls[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += rolls[i];
    }
    return total;
}

void displayMenu() {
    printf("Welcome to the Dice Roller!\n");
    printf("1. Roll a die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int choice;
    int dieSides;
    int rollCount;
    int rolls[MAX_ROLLS];

    do {
        displayMenu();
        
        // Validate input
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
            clearBuffer();
        }
        
        switch (choice) {
            case 1:
                printf("Enter the number of sides for the die (2 to %d): ", MAX_DIE_SIDES);
                while (scanf("%d", &dieSides) != 1 || dieSides < 2 || dieSides > MAX_DIE_SIDES) {
                    printf("Invalid input. Please enter a number between 2 and %d: ", MAX_DIE_SIDES);
                    clearBuffer();
                }
                printf("You rolled a: %d\n", rollDice(dieSides));
                break;

            case 2:
                printf("Enter the number of sides for the die (2 to %d): ", MAX_DIE_SIDES);
                while (scanf("%d", &dieSides) != 1 || dieSides < 2 || dieSides > MAX_DIE_SIDES) {
                    printf("Invalid input. Please enter a number between 2 and %d: ", MAX_DIE_SIDES);
                    clearBuffer();
                }

                printf("How many times would you like to roll the die (1 to %d): ", MAX_ROLLS);
                while (scanf("%d", &rollCount) != 1 || rollCount < 1 || rollCount > MAX_ROLLS) {
                    printf("Invalid input. Please enter a number between 1 and %d: ", MAX_ROLLS);
                    clearBuffer();
                }

                for (int i = 0; i < rollCount; i++) {
                    rolls[i] = rollDice(dieSides);
                }
                displayRolls(rolls, rollCount, dieSides);
                break;

            case 3:
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        if (choice != 3) {
            printf("\nPress Enter to continue...");
            clearBuffer();
            getchar(); // Wait for user to press Enter
        }
        
    } while (choice != 3);

    return 0;
}