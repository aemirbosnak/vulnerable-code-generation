//Falcon-180B DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 100
#define NUM_COLS 10

int main() {
    int **data;
    int i, j;
    srand(time(NULL));

    // Allocate memory for the data set
    data = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++) {
        data[i] = (int *)malloc(NUM_COLS * sizeof(int));
    }

    // Generate random data set
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            data[i][j] = rand() % 100;
        }
    }

    // Print data set
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    // Perform data mining
    int max_val = data[0][0];
    int min_val = data[0][0];
    int sum_val = 0;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }
            if (data[i][j] < min_val) {
                min_val = data[i][j];
            }
            sum_val += data[i][j];
        }
    }
    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);
    printf("Sum of values: %d\n", sum_val);

    // Free memory
    for (i = 0; i < NUM_ROWS; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}