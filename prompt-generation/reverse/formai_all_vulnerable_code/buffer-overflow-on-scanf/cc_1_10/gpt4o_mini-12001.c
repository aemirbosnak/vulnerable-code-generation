//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void print_menu() {
    printf("Welcome to the C Dice Roller!\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int roll_die(int sides) {
    return (rand() % sides) + 1;
}

void roll_dice(int number_of_dice, int sides) {
    int total = 0;
    
    printf("Rolling %d d%d...\n", number_of_dice, sides);
    for (int i = 0; i < number_of_dice; i++) {
        int result = roll_die(sides);
        printf("Roll %d: %d\n", i + 1, result);
        total += result;
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL)); // Seed the random number generator.
    
    int choice;
    int num_dice, sides;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting the Dice Roller. Goodbye!\n");
            break;
        } else if (choice != 1) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        printf("Enter the number of dice (1 to %d): ", MAX_DICE);
        scanf("%d", &num_dice);
        if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Number of dice must be between 1 and %d.\n", MAX_DICE);
            continue;
        }

        printf("Enter the number of sides per die (1 to %d): ", MAX_SIDES);
        scanf("%d", &sides);
        if (sides < 1 || sides > MAX_SIDES) {
            printf("Number of sides must be between 1 and %d.\n", MAX_SIDES);
            continue;
        }

        roll_dice(num_dice, sides);
    }

    return 0;
}