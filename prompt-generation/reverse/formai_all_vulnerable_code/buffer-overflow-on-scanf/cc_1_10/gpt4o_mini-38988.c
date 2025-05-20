//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

void display_logo() {
    printf("\033[1;32m"); // Set text color to neon green
    printf("  ____            _          _              \n");
    printf(" |  _ \\ _ __ ___ | |__   ___| |__   ___ _ __ \n");
    printf(" | | | | '__/ _ \\| '_ \\ / _ \\ '_ \\ / _ \\ '__|\n");
    printf(" | |_| | | | (_) | | | |  __/ | | |  __/ |   \n");
    printf(" |____/|_|  \\___/|_| |_|\\___|_| |_|\\___|_|   \n");
    printf("\033[0m"); // Reset text color
}

void display_instructions() {
    printf("\033[1;34m"); // Set text color to neon blue
    printf("Welcome to the Neon Dice Roller!\n");
    printf("Roll up to %d dice with customizable sides.\n", MAX_DICE);
    printf("Instructions:\n");
    printf("1. Enter the number of dice to roll (1 - %d).\n", MAX_DICE);
    printf("2. Enter the number of sides on each die (4, 6, 8, 10, 12, 20).\n");
    printf("3. Watch the neon results unravel before your eyes!\n");
    printf("Type 'exit' to quit.\n");
    printf("\033[0m"); // Reset text color
}

int roll_dice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and 'sides'
}

void roll_dice_multiple(int number_of_dice, int sides) {
    printf("\033[1;35m"); // Set text color to neon purple
    printf("Rolling %d dice with %d sides...\n", number_of_dice, sides);
    
    int total = 0;
    for (int i = 0; i < number_of_dice; i++) {
        int result = roll_dice(sides);
        printf("Die %d: %d\n", i + 1, result);
        total += result;
    }
    
    printf("Total: %d\n", total);
    printf("\033[0m"); // Reset text color
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    display_logo();
    display_instructions();

    while (1) {
        char input[100];
        int number_of_dice, sides;

        printf("\nEnter number of dice (1-%d): ", MAX_DICE);
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        number_of_dice = atoi(input);

        if (number_of_dice < 1 || number_of_dice > MAX_DICE) {
            printf("\033[1;31mInvalid number of dice! Please try again.\n\033[0m"); // Error message in red
            continue;
        }

        printf("Enter number of sides on each die (4, 6, 8, 10, 12, 20): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        sides = atoi(input);

        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("\033[1;31mInvalid number of sides! Please try again.\n\033[0m"); // Error message in red
            continue;
        }

        roll_dice_multiple(number_of_dice, sides);
    }

    printf("\033[1;36mThank you for using the Neon Dice Roller! Stay stylish in the cyber world!\033[0m\n");

    return 0;
}