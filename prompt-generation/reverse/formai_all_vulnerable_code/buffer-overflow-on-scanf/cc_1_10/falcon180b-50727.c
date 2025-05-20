//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int size;
    int i, j;
    double matrix1[MAX_SIZE][MAX_SIZE];
    double matrix2[MAX_SIZE][MAX_SIZE];
    double result[MAX_SIZE][MAX_SIZE];

    // Get the size of the matrices
    printf("Enter the size of the matrices (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get the elements of matrix 1
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    // Get the elements of matrix 2
    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result
    printf("Result of matrix addition:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}