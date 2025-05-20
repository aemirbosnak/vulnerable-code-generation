//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int main() {
    int matrix[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result[ROW][COL];

    printf("Matrix 1:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nSum of matrices:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            result[i][j] = matrix[i][j] + matrix[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nDifference of matrices:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            result[i][j] = matrix[i][j] - matrix[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nProduct of matrices:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            result[i][j] = matrix[i][j] * matrix[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}