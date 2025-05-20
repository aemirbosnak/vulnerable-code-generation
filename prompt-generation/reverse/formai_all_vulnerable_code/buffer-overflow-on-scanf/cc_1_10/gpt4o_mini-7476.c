//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20
#define MIN_SIDES 4

void display_menu() {
    printf("\n--- Welcome to the Dice Roller ---\n");
    printf("1. Roll a Die\n");
    printf("2. Roll Multiple Dice\n");
    printf("3. Set Custom Dice Sides\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
}

int roll_die(int sides) {
    return (rand() % sides) + 1;
}

void roll_multiple_dice(int num_dice, int sides) {
    int roll;
    printf("Rolling %d D%d...\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        roll = roll_die(sides);
        printf("Die %d: %d\n", i + 1, roll);
    }
}

int main() {
    srand(time(NULL));

    int choice, num_dice, custom_sides = 6;
    int is_custom = 0;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Rolling a D%d...\n", is_custom ? custom_sides : 6);
                printf("Result: %d\n", roll_die(is_custom ? custom_sides : 6));
                break;
            case 2:
                printf("Enter number of dice to roll: ");
                scanf("%d", &num_dice);
                if (num_dice <= 0) {
                    printf("Please enter a positive number of dice.\n");
                    break;
                }
                roll_multiple_dice(num_dice, is_custom ? custom_sides : 6);
                break;
            case 3:
                do {
                    printf("Enter number of sides for the die (%d to %d): ", MIN_SIDES, MAX_SIDES);
                    scanf("%d", &custom_sides);
                    if (custom_sides < MIN_SIDES || custom_sides > MAX_SIDES) {
                        printf("Invalid number of sides. Please try again.\n");
                    } else {
                        is_custom = 1;
                        printf("Custom die set to D%d\n", custom_sides);
                    }
                } while (custom_sides < MIN_SIDES || custom_sides > MAX_SIDES);
                break;
            case 4:
                printf("Thank you for using the Dice Roller. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}