//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000

int main() {
    int num_dice, num_faces, num_rolls;
    int *dice_values, *roll_values;
    char *dice_str;
    int i, j, k, total_rolls = 0;
    int max_value = 0, min_value = 9999;
    int sum = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice and their number of faces from the user
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of faces for each die: ");
    scanf("%d", &num_faces);

    // Allocate memory for the dice and roll values
    dice_values = (int *)malloc(num_dice * sizeof(int));
    roll_values = (int *)malloc(num_dice * num_faces * sizeof(int));

    // Roll the dice and store their values
    for (i = 0; i < num_dice; i++) {
        for (j = 0; j < num_faces; j++) {
            dice_values[i] = rand() % num_faces + 1;
            roll_values[total_rolls] = dice_values[i];
            total_rolls++;
        }
    }

    // Print the result of each roll
    printf("\n");
    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: ", i + 1);
        for (j = 0; j < num_faces; j++) {
            printf("%d ", dice_values[i]);
        }
        printf("\n");
    }

    // Calculate the sum of all the rolls
    for (i = 0; i < total_rolls; i++) {
        sum += roll_values[i];
    }

    // Find the maximum and minimum values rolled
    for (i = 0; i < total_rolls; i++) {
        if (roll_values[i] > max_value) {
            max_value = roll_values[i];
        }
        if (roll_values[i] < min_value) {
            min_value = roll_values[i];
        }
    }

    // Print the results
    printf("\nTotal sum of all rolls: %d\n", sum);
    printf("Maximum value rolled: %d\n", max_value);
    printf("Minimum value rolled: %d\n", min_value);

    // Free the allocated memory
    free(dice_values);
    free(roll_values);

    return 0;
}