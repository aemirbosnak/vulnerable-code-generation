//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die() {
    return (rand() % 6) + 1; // Generates a number between 1 and 6
}

// Function to display the result of a die roll
void display_die(int die_value) {
    switch (die_value) {
        case 1:
            printf(" ------- \n");
            printf("|       |\n");
            printf("|   *   |\n");
            printf("|       |\n");
            printf(" ------- \n");
            break;
        case 2:
            printf(" ------- \n");
            printf("| *     |\n");
            printf("|       |\n");
            printf("|     * |\n");
            printf(" ------- \n");
            break;
        case 3:
            printf(" ------- \n");
            printf("| *     |\n");
            printf("|   *   |\n");
            printf("|     * |\n");
            printf(" ------- \n");
            break;
        case 4:
            printf(" ------- \n");
            printf("| *   * |\n");
            printf("|       |\n");
            printf("| *   * |\n");
            printf(" ------- \n");
            break;
        case 5:
            printf(" ------- \n");
            printf("| *   * |\n");
            printf("|   *   |\n");
            printf("| *   * |\n");
            printf(" ------- \n");
            break;
        case 6:
            printf(" ------- \n");
            printf("| *   * |\n");
            printf("| *   * |\n");
            printf("| *   * |\n");
            printf(" ------- \n");
            break;
        default:
            break;
    }
}

// Function to roll multiple dice
void roll_multiple_dice(int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        int result = roll_die();
        printf("Die %d: ", i + 1);
        display_die(result);
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int num_dice;

    // Ask user how many dice to roll
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll (1-5)? ");
    scanf("%d", &num_dice);

    if(num_dice < 1 || num_dice > 5) {
        printf("Please enter a valid number between 1 and 5.\n");
        return 1; // Exit with error
    }

    printf("\nRolling %d dice...\n\n", num_dice);
    roll_multiple_dice(num_dice);
    
    printf("Thank you for using the Dice Roller!\n");
    return 0; // Successful execution
}