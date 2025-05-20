//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void welcome_message() {
    printf("==============================================\n");
    printf("             Welcome to Dice Roller           \n");
    printf("==============================================\n");
    printf("Roll virtual dice and enjoy your game!\n");
    printf("You can roll up to %d dice with sides up to %d.\n", MAX_DICE, MAX_SIDES);
    printf("Enter '0' as the number of dice to exit.\n");
    printf("==============================================\n");
}

int roll_dice(int sides) {
    return (rand() % sides) + 1;
}

void roll_multiple_dice(int num_dice, int sides) {
    int total = 0;

    printf("Rolling %d dice with %d sides...\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        int result = roll_dice(sides);
        printf("Die %d rolled: %d\n", i + 1, result);
        total += result;
    }
    
    printf("Total: %d\n", total);
}

void get_user_input() {
    int num_dice = 0;
    int sides = 0;

    while (1) {
        printf("Enter the number of dice (1 to %d, 0 to exit): ", MAX_DICE);
        scanf("%d", &num_dice);

        if (num_dice == 0) {
            printf("Exiting Dice Roller. Thank you!\n");
            break;
        } else if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid number of dice. Please try again.\n");
            continue;
        }

        printf("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);

        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        roll_multiple_dice(num_dice, sides);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Display the welcome message
    welcome_message();

    // Handle user input and rolling of the dice
    get_user_input();

    return 0;
}