//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

// Function to roll a single die
void roll_die(int *value) {
    *value = rand() % 6 + 1;
}

// Function to roll multiple dice
void roll_dice(int num_dice, int *values) {
    for (int i = 0; i < num_dice; i++) {
        roll_die(&values[i]);
    }
}

// Function to print the values of the dice
void print_dice(int num_dice, int *values) {
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num_dice;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE || num_dice < 1) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    int *values = malloc(num_dice * sizeof(int)); // Allocate memory for the dice values

    if (values == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    roll_dice(num_dice, values);
    print_dice(num_dice, values);

    free(values); // Free the memory allocated for the dice values

    return 0;
}