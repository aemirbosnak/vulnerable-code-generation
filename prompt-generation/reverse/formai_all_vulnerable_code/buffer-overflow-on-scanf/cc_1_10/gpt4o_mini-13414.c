//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 5
#define MAX_SIDES 20

void printRolls(int dice[], int count) {
    printf("You rolled: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

int rollSingleDie(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int sides, int count) {
    int rolls[MAX_DICE];
    for (int i = 0; i < count; i++) {
        rolls[i] = rollSingleDie(sides);
    }
    printRolls(rolls, count);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int sides, count;
    char choice;

    printf("Welcome to the C Dice Roller!\n");
    do {
        printf("Enter the number of sides on the die (2-%d): ", MAX_SIDES);
        scanf("%d", &sides);
        if (sides < 2 || sides > MAX_SIDES) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
        scanf("%d", &count);
        if (count < 1 || count > MAX_DICE) {
            printf("Invalid number of dice. Please try again.\n");
            continue;
        }

        rollMultipleDice(sides, count);
        
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Dice Roller! Goodbye!\n");
    return 0;
}