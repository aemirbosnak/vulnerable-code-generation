//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("Welcome to the C Dice Roller!\n");
    printf("Roll your dice and see what fortune awaits you!\n");
    printf("--------------------------------------------------\n");
}

int roll_die(int sides) {
    return (rand() % sides) + 1; // Returns a random number between 1 and 'sides'
}

void roll_multiple_dice(int dice, int sides) {
    int sum = 0;
    printf("Rolling %d D%d...\n", dice, sides);
    for (int i = 0; i < dice; i++) {
        int result = roll_die(sides);
        printf("Roll %d: %d\n", i + 1, result);
        sum += result;
    }
    printf("Total: %d\n", sum);
}

void display_dice_options() {
    printf("Choose your options:\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Exit\n");
    printf("Please enter the number corresponding to your choice: ");
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int choice;

    print_welcome_message();

    do {
        display_dice_options();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int sides;
                printf("How many sides does your die have? ");
                scanf("%d", &sides);
                int result = roll_die(sides);
                printf("You rolled a D%d and got: %d\n", sides, result);
                break;
            }
            case 2: {
                int dice, sides;
                printf("How many dice do you want to roll? ");
                scanf("%d", &dice);
                printf("How many sides does each die have? ");
                scanf("%d", &sides);
                roll_multiple_dice(dice, sides);
                break;
            }
            case 3:
                printf("Thanks for playing! See you next time!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        printf("\n");
    } while (choice != 3);
    
    return 0;
}