//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

int main(int argc, char *argv[]) {
    int num_dice, i;
    int *dice_values;
    int total = 0;
    int max_value = 0;
    int min_value = 999;
    int num_rolls = 0;
    int frequency[SIDES] = {0};
    char *filename = "dice_rolls.txt";
    FILE *file;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice from the user
    printf("Enter the number of dice to roll (1-100): ");
    scanf("%d", &num_dice);

    // Allocate memory for the dice values
    dice_values = (int *)malloc(sizeof(int) * num_dice);

    // Roll the dice
    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % SIDES + 1;
        total += dice_values[i];

        // Update the max and min values
        if (dice_values[i] > max_value) {
            max_value = dice_values[i];
        }
        if (dice_values[i] < min_value) {
            min_value = dice_values[i];
        }

        // Update the frequency count
        frequency[dice_values[i] - 1]++;
    }

    // Print the results
    printf("Total: %d\n", total);
    printf("Max: %d\n", max_value);
    printf("Min: %d\n", min_value);
    printf("Frequency:\n");
    for (i = 0; i < SIDES; i++) {
        printf("%d: %d\n", i + 1, frequency[i]);
    }

    // Save the results to a file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        return 1;
    }
    fprintf(file, "Total: %d\n", total);
    fprintf(file, "Max: %d\n", max_value);
    fprintf(file, "Min: %d\n", min_value);
    fprintf(file, "Frequency:\n");
    for (i = 0; i < SIDES; i++) {
        fprintf(file, "%d: %d\n", i + 1, frequency[i]);
    }
    fclose(file);

    // Free the memory
    free(dice_values);

    return 0;
}