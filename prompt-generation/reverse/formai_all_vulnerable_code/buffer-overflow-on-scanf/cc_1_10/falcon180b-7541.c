//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MAX_ROLLS 1000000

int main() {
    int num_sides, num_rolls, i, j, roll;
    double total = 0, sides_sum = 0;
    char input[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get user input for number of sides on the dice
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    // Validate user input
    if (num_sides <= 0 || num_sides > MAX_SIDES) {
        printf("Invalid number of sides!\n");
        return 1;
    }

    // Get user input for number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    // Validate user input
    if (num_rolls <= 0 || num_rolls > MAX_ROLLS) {
        printf("Invalid number of rolls!\n");
        return 1;
    }

    // Roll the dice and calculate the total
    for (i = 0; i < num_rolls; i++) {
        roll = rand() % num_sides + 1;
        total += roll;
        sides_sum += roll * roll;
    }

    // Calculate the average roll
    double avg_roll = total / num_rolls;

    // Calculate the standard deviation of the rolls
    double std_dev = sqrt(sides_sum / num_rolls - avg_roll * avg_roll);

    // Print the results
    printf("Total: %d\n", total);
    printf("Average roll: %.2f\n", avg_roll);
    printf("Standard deviation: %.2f\n", std_dev);

    return 0;
}