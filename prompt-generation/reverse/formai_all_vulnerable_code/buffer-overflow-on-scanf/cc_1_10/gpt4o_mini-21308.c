//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void rollDice(int diceCount, int sides);
void displayRolls(int rolls[], int count);
int calculateSum(int rolls[], int count);
void clearInputBuffer();

int main() {
    int diceCount, sides;
    char choice;

    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the C Dice Roller!\n");
    printf("This program allows you to roll a specified number of dice with a defined number of sides.\n");

    do {
        printf("\nHow many dice would you like to roll? (1-10): ");
        scanf("%d", &diceCount);
        if (diceCount < 1 || diceCount > MAX_DICE) {
            printf("Please enter a valid number of dice (1-10).\n");
            clearInputBuffer();
            continue;
        }

        printf("How many sides should these dice have? (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Please choose a valid number of sides (4, 6, 8, 10, 12, 20).\n");
            clearInputBuffer();
            continue;
        }

        rollDice(diceCount, sides);

        printf("\nWould you like to roll again? (y/n): ");
        clearInputBuffer(); // Clear the input buffer for the next choice
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Dice Roller. Have a great day!\n");
    return 0;
}

void rollDice(int diceCount, int sides) {
    int rolls[MAX_DICE];
    int sum;

    printf("\nRolling %d dice with %d sides...\n", diceCount, sides);
    
    for (int i = 0; i < diceCount; i++) {
        rolls[i] = (rand() % sides) + 1;  // Generate a random roll
    }

    displayRolls(rolls, diceCount);
    sum = calculateSum(rolls, diceCount);
    printf("Total sum of rolls: %d\n", sum);
}

void displayRolls(int rolls[], int count) {
    printf("You rolled: ");
    for (int i = 0; i < count; i++) {
        printf("%d", rolls[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf(".\n");
}

int calculateSum(int rolls[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += rolls[i];
    }
    return total;
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}