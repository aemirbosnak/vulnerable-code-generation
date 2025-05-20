//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Donald Knuth style Dice Roller */

int main() {
    int faces, dice, rolls, i, j, rollsum;
    srand(time(NULL));

    printf("How many dice do you want to roll?\n");
    scanf("%d", &dice);

    printf("How many faces do these dice have?\n");
    scanf("%d", &faces);

    printf("How many rolls do you want to make?\n");
    scanf("%d", &rolls);

    int **results = (int **) malloc(dice * sizeof(int *));
    for (i = 0; i < dice; i++) {
        results[i] = (int *) malloc(rolls * sizeof(int));
    }

    /* Rolling the dice */
    for (i = 0; i < rolls; i++) {
        rollsum = 0;
        printf("Roll #%d: ", i + 1);
        for (j = 0; j < dice; j++) {
            results[j][i] = rand() % faces + 1;
            printf("%d", results[j][i]);
            rollsum += results[j][i];
            if (j < dice - 1) {
                printf(", ");
            }
        }
        printf(" (Total: %d)\n", rollsum);
    }

    /* Displaying the results */
    printf("\nResults:\n");
    for (i = 0; i < dice; i++) {
        printf("Die #%d: ", i + 1);
        for (j = 0; j < rolls; j++) {
            printf("%d", results[i][j]);
            if (j < rolls - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    /* Freeing the memory */
    for (i = 0; i < dice; i++) {
        free(results[i]);
    }
    free(results);

    return 0;
}