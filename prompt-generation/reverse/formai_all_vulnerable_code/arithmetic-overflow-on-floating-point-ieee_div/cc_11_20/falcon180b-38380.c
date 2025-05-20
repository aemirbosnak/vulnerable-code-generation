//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 1000000
#define MAX_DICE 100
#define MAX_SIDES 100

int main() {
    int num_dice, num_sides, num_rolls, i, j, k, sum;
    int freq[MAX_DICE][MAX_SIDES];
    double avg, std_dev;
    char filename[50];
    FILE *fp;
    time_t start_time, end_time;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        for (j = 1; j <= num_sides; j++) {
            freq[i][j] = 0;
        }
    }

    for (i = 0; i < num_rolls; i++) {
        sum = 0;
        for (j = 0; j < num_dice; j++) {
            k = rand() % num_sides + 1;
            sum += k;
            freq[j][k]++;
        }
        printf("%d\n", sum);
    }

    for (i = 0; i < num_dice; i++) {
        for (j = 1; j <= num_sides; j++) {
            printf("%d ", freq[i][j]);
        }
        printf("\n");
    }

    avg = (double)num_rolls / (double)num_sides;
    std_dev = 0.0;

    for (i = 0; i < num_dice; i++) {
        for (j = 1; j <= num_sides; j++) {
            std_dev += pow((double)freq[i][j] - avg, 2.0);
        }
    }

    std_dev = sqrt(std_dev / ((double)num_dice * (double)num_sides));

    printf("Average: %.2f\n", avg);
    printf("Standard deviation: %.2f\n", std_dev);

    sprintf(filename, "rolls.txt");
    fp = fopen(filename, "w");

    for (i = 0; i < num_dice; i++) {
        for (j = 1; j <= num_sides; j++) {
            fprintf(fp, "%d ", freq[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}