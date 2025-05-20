//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

int main() {
    int num_dice, num_sides, i, j;
    int *dice_values;
    double mean, variance, standard_deviation;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides for each dice: ");
    scanf("%d", &num_sides);

    dice_values = (int *) malloc(num_dice * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_sides + 1;
    }

    start_time = clock();

    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice_values[i]);
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    mean = 0.0;
    for (i = 0; i < num_dice; i++) {
        mean += dice_values[i];
    }
    mean /= num_dice;

    variance = 0.0;
    for (i = 0; i < num_dice; i++) {
        variance += pow((dice_values[i] - mean), 2);
    }
    variance /= num_dice;

    standard_deviation = sqrt(variance);

    printf("\nMean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", standard_deviation);
    printf("CPU time used: %.2f seconds\n", cpu_time_used);

    free(dice_values);

    return 0;
}