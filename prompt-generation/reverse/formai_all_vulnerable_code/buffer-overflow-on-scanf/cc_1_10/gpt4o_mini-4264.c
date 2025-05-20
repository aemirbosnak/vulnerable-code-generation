//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void rollDice(int numDice, int numSides);
void displayRollResults(int *results, int numDice);
void gameMenu();
void clearScreen();

int main() {
    srand(time(NULL));  // Seed the random number generator
    int choice;

    do {
        gameMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1: {
                int numDice, numSides;
                printf("Enter the number of dice (1-%d): ", MAX_DICE);
                scanf("%d", &numDice);
                if (numDice < 1 || numDice > MAX_DICE) {
                    printf("Invalid number of dice. Please try again.\n");
                    break;
                }

                printf("Enter the number of sides on each die (1-%d): ", MAX_SIDES);
                scanf("%d", &numSides);
                if (numSides < 1 || numSides > MAX_SIDES) {
                    printf("Invalid number of sides. Please try again.\n");
                    break;
                }

                rollDice(numDice, numSides);
                break;
            }

            case 2: {
                int numDice;
                printf("How many dice would you like to roll? (1-%d): ", MAX_DICE);
                scanf("%d", &numDice);

                if (numDice < 1 || numDice > MAX_DICE) {
                    printf("Invalid number of dice. Please try again.\n");
                    break;
                }

                int results[MAX_DICE];
                for (int i = 0; i < numDice; ++i) {
                    results[i] = (rand() % 6) + 1;  // Simulating a standard 6-sided die
                }
                displayRollResults(results, numDice);
                break;
            }

            case 3:
                printf("Exiting the Dice Roller. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void rollDice(int numDice, int numSides) {
    int results[MAX_DICE];
    for (int i = 0; i < numDice; ++i) {
        results[i] = (rand() % numSides) + 1;  // Roll and store result
    }
    displayRollResults(results, numDice);
}

void displayRollResults(int *results, int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

void gameMenu() {
    printf("==== Dice Roller Menu ====\n");
    printf("1. Roll a custom die\n");
    printf("2. Roll standard dice (6 sides)\n");
    printf("3. Exit\n");
    printf("==========================\n");
}

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear screen
}