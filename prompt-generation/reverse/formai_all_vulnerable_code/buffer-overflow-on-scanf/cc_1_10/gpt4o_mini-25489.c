//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void print_banner() {
    printf("*****************************************\n");
    printf("*            Welcome to Dice Roller     *\n");
    printf("*****************************************\n");
}

void roll_dice(int num_dice, int num_sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides each:\n", num_dice, num_sides);
    for (int i = 0; i < num_dice; i++) {
        int roll = (rand() % num_sides) + 1;  // Generate a random number between 1 and num_sides
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total Roll: %d\n", total);
}

int main() {
    int num_dice, num_sides;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    print_banner();

    do {
        // Get the number of dice from the user
        printf("Enter number of dice to roll (1 to %d): ", MAX_DICE);
        scanf("%d", &num_dice);
        while (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid input. Please enter between 1 and %d: ", MAX_DICE);
            scanf("%d", &num_dice);
        }

        // Get the number of sides from the user
        printf("Enter number of sides on each die (1 to %d): ", MAX_SIDES);
        scanf("%d", &num_sides);
        while (num_sides < 1 || num_sides > MAX_SIDES) {
            printf("Invalid input. Please enter between 1 and %d: ", MAX_SIDES);
            scanf("%d", &num_sides);
        }

        roll_dice(num_dice, num_sides);

        // Ask if the user wants to roll again
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller! Goodbye!\n");
    return 0;
}