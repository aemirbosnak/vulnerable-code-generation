//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu();
void rollDice(int sides, int count);
void clearInputBuffer();

int main() {
    int choice = 0;
    int sides = 0;
    int count = 0;

    // Seed the random number generator
    srand(time(NULL));

    while (choice != 3) {
        printMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the number of sides on the die (e.g., 6, 20): ");
                if (scanf("%d", &sides) != 1 || sides < 1) {
                    clearInputBuffer();
                    printf("Invalid input! Please enter a positive number.\n");
                    sides = 0;
                    continue;
                }
                
                printf("Enter the number of dice to roll: ");
                if (scanf("%d", &count) != 1 || count < 1) {
                    clearInputBuffer();
                    printf("Invalid input! Please enter a positive number.\n");
                    count = 0;
                    continue;
                }
                
                rollDice(sides, count);
                break;

            case 2:
                printf("Enter the number of sides on the die (e.g., 6, 20): ");
                if (scanf("%d", &sides) != 1 || sides < 1) {
                    clearInputBuffer();
                    printf("Invalid input! Please enter a positive number.\n");
                    sides = 0;
                    continue;
                }

                printf("Enter the number of dice to roll: ");
                if (scanf("%d", &count) != 1 || count < 1) {
                    clearInputBuffer();
                    printf("Invalid input! Please enter a positive number.\n");
                    count = 0;
                    continue;
                }

                printf("Rolling %d d%d multiple times:\n", count, sides);
                for (int i = 0; i < count; i++) {
                    int result = (rand() % sides) + 1;
                    printf("Roll %d: %d\n", i + 1, result);
                }
                break;

            case 3:
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                break;

            default:
                printf("Invalid selection! Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}

void rollDice(int sides, int count) {
    int total = 0;
    printf("Rolling %d d%d:\n", count, sides);
    for (int i = 0; i < count; i++) {
        int result = (rand() % sides) + 1;
        printf("Roll %d: %d\n", i + 1, result);
        total += result;
    }
    printf("Total of rolls: %d\n", total);
}

void printMenu() {
    printf("\nDice Roller Menu:\n");
    printf("1. Roll a specific number of dice\n");
    printf("2. Roll a specific number of dice multiple times\n");
    printf("3. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Flush the input buffer
}