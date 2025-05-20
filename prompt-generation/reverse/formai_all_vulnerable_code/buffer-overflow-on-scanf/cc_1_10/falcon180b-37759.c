//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 100

int main() {
    int rows, cols, numbers, i, j, k, l, m;
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS];
    int sum[MAX_ROWS][MAX_COLS];

    // Get input from user
    printf("Enter number of rows and columns (<= %d): ", MAX_ROWS);
    scanf("%d %d", &rows, &cols);
    printf("Enter number of random numbers (<= %d): ", MAX_NUMBERS);
    scanf("%d", &numbers);

    // Initialize matrix1 with random numbers
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 100;
        }
    }

    // Initialize matrix2 with zeros
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix2[i][j] = 0;
        }
    }

    // Add matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result
    printf("\nResult:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}