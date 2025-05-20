//Falcon-180B DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    int rand_int = rand() % (max - min + 1) + min;
    return rand_int;
}

// Function to generate a random float between min and max
float rand_float(float min, float max) {
    float rand_float = (float)rand() / RAND_MAX * (max - min) + min;
    return rand_float;
}

int main() {
    int num_rolls, num_dice, max_rolls = 100;
    int i, j, sum;
    float avg;
    char play_again;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user wants to quit
    do {
        // Ask the user how many rolls they want to make
        printf("How many rolls do you want to make? ");
        scanf("%d", &num_rolls);

        // Generate the specified number of rolls
        for (i = 0; i < num_rolls; i++) {
            // Ask the user how many dice they want to roll
            printf("How many dice do you want to roll? ");
            scanf("%d", &num_dice);

            // Roll the dice and calculate the sum
            sum = 0;
            for (j = 0; j < num_dice; j++) {
                sum += rand_num(1, 6);
            }

            // Print the result of the roll
            printf("You rolled %d dice and got a total of %d.\n", num_dice, sum);
        }

        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}