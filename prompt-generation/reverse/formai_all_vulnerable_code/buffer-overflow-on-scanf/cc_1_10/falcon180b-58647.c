//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000  // Maximum number of sides for dice
#define MAX_DICE 1000   // Maximum number of dice to roll

// Function to roll the dice and return the result
int roll_dice(int sides, int num_dice) {
    int result = 0;
    for (int i = 0; i < num_dice; i++) {
        result += rand() % sides + 1;
    }
    return result;
}

// Function to print the result of rolling the dice
void print_result(int result) {
    if (result == 1) {
        printf("You rolled a 1.\n");
    } else if (result == 2) {
        printf("You rolled a 2.\n");
    } else if (result == 3) {
        printf("You rolled a 3.\n");
    } else if (result == 4) {
        printf("You rolled a 4.\n");
    } else if (result == 5) {
        printf("You rolled a 5.\n");
    } else if (result == 6) {
        printf("You rolled a 6.\n");
    } else {
        printf("You rolled a %d.\n", result);
    }
}

int main() {
    int num_dice, sides;
    srand(time(NULL));  // Seed the random number generator with the current time

    // Get the number of dice and the number of sides from the user
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides for each dice: ");
    scanf("%d", &sides);

    // Roll the dice and print the result
    int result = roll_dice(sides, num_dice);
    print_result(result);

    return 0;
}