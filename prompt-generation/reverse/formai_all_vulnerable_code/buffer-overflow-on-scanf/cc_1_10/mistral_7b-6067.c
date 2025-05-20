//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    int row, col;
} point;

int search2D(int matrix[SIZE][SIZE], int target, point start);

void printMatrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int i, j, matrix[SIZE][SIZE], target;
    point start;

    printf("Enter the elements of matrix\n");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }

    printf("Enter the target element\n");
    scanf("%d", &target);

    printf("Matrix elements are:\n");
    printMatrix(matrix);

    start.row = 0;
    start.col = 0;

    if (search2D(matrix, target, start))
        printf("Target found at (%d, %d)\n", start.row, start.col);
    else
        printf("Target not found\n");

    return 0;
}

int search2D(int matrix[SIZE][SIZE], int target, point current) {
    int found = 0;

    if (matrix[current.row][current.col] == target) {
        found = 1;
    } else if (current.row < SIZE && current.col < SIZE) {
        found = search2D(matrix, target, (point){current.row + 1, current.col});
        if (!found)
            found = search2D(matrix, target, (point){current.row, current.col + 1});
    }

    return found;
}