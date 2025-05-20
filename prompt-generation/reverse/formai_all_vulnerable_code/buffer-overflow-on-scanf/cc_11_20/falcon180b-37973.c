//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define MIN_VALUE 1
#define MAX_VALUE 6

int main() {
    int dice[NUM_DICE];
    int i, j, total = 0;
    char input[10];

    // Initialize random seed
    srand(time(NULL));

    // Roll the dice
    for (i = 0; i < NUM_DICE; i++) {
        dice[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Display the dice values
    printf("Dice values: ");
    for (i = 0; i < NUM_DICE; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");

    // Calculate the total value
    for (i = 0; i < NUM_DICE; i++) {
        total += dice[i];
    }

    // Display the total value
    printf("Total value: %d\n", total);

    // Ask user for their guess
    printf("Enter your guess for the total value (1-%d): ", total);
    scanf("%s", input);

    // Validate user input
    if (strcmp(input, "1") == 0 || strcmp(input, "2") == 0 || strcmp(input, "3") == 0 || strcmp(input, "4") == 0 || strcmp(input, "5") == 0 || strcmp(input, "6") == 0) {
        int guess = atoi(input);

        // Check if user guess is correct
        if (guess == total) {
            printf("Congratulations! You guessed correctly!\n");
        } else {
            printf("Sorry, your guess is incorrect.\n");
        }
    } else {
        printf("Invalid input. Please enter a number between 1 and %d.\n", total);
    }

    return 0;
}