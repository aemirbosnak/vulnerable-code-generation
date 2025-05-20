//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n;
    int **matrix;
    srand(time(0));

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &n);

    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    printf("\nThe original matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] += 1;
            } else {
                matrix[i][j] -= 1;
            }
            sum += matrix[i][j];
        }
    }

    printf("\nThe modified matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThe sum of the elements in the modified matrix is: %d", sum);

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}