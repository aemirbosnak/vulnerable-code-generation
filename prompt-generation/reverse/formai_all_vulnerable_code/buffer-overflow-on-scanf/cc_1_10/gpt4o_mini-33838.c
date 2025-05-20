//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void print_rolls(int rolls[], int count);
void roll_dice(int number_of_dice, int sides);
void clear_input_buffer();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int number_of_dice, sides;
    char choice;

    do {
        // Get number of dice from user
        printf("Welcome to the Dice Roller!\n");
        printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
        scanf("%d", &number_of_dice);
        clear_input_buffer();
        if (number_of_dice < 1 || number_of_dice > MAX_DICE) {
            printf("Invalid number of dice. Please try again.\n");
            continue;
        }

        // Get number of sides from user
        printf("Enter the number of sides for each die (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        clear_input_buffer();
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        // Roll the dice
        roll_dice(number_of_dice, sides);

        // Ask if the user wants to roll again
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
        clear_input_buffer();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller. Goodbye!\n");
    return 0;
}

void roll_dice(int number_of_dice, int sides) {
    int rolls[MAX_DICE];
    int total = 0;

    printf("Rolling %d D%d...\n", number_of_dice, sides);
    for (int i = 0; i < number_of_dice; i++) {
        rolls[i] = (rand() % sides) + 1; // Generate a random roll between 1 and sides
        total += rolls[i];
    }

    print_rolls(rolls, number_of_dice);
    printf("Total: %d\n", total);
}

void print_rolls(int rolls[], int count) {
    printf("You rolled: ");
    for (int i = 0; i < count; i++) {
        if (i > 0) printf(", ");
        printf("%d", rolls[i]);
    }
    printf("\n");
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}