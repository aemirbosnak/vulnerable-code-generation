//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 1000
#define MAX_SIDES 100

int main() {
    int num_rolls, num_sides, i;
    int *rolls;
    double mean, variance, sd;
    FILE *fp;

    srand(time(NULL));

    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    rolls = (int *) malloc(num_rolls * sizeof(int));

    for (i = 0; i < num_rolls; i++) {
        rolls[i] = rand() % num_sides + 1;
    }

    mean = 0;
    for (i = 0; i < num_rolls; i++) {
        mean += rolls[i];
    }
    mean /= num_rolls;

    variance = 0;
    for (i = 0; i < num_rolls; i++) {
        variance += pow((rolls[i] - mean), 2);
    }
    variance /= num_rolls;

    sd = sqrt(variance);

    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", sd);

    fp = fopen("dice_rolls.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < num_rolls; i++) {
        fprintf(fp, "%d\n", rolls[i]);
    }

    fclose(fp);

    free(rolls);

    return 0;
}