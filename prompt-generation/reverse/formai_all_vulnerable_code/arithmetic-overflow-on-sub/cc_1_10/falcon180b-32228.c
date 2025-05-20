//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice
int roll_dice(int num_sides) {
    return rand_num(1, num_sides);
}

int main() {
    int num_dice, num_sides, total = 0;
    char repeat;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Ask the user for the number of dice and the number of sides on each die
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    // Roll the dice and calculate the total
    for (int i = 0; i < num_dice; i++) {
        total += roll_dice(num_sides);
    }

    // Display the result
    printf("You rolled %d dice with %d sides each and got a total of %d.\n", num_dice, num_sides, total);

    // Ask the user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &repeat);

    // Repeat if desired
    while (repeat == 'y' || repeat == 'Y') {
        total = 0;
        for (int i = 0; i < num_dice; i++) {
            total += roll_dice(num_sides);
        }
        printf("You rolled %d dice with %d sides each and got a total of %d.\n", num_dice, num_sides, total);
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &repeat);
    }

    return 0;
}