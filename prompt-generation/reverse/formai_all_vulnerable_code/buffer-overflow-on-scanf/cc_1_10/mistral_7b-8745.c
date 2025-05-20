//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 10

int main() {
    int i, j, min_row, min_col, max_row, max_col, num, count = 0;
    int matrix[MAX][MAX];

    printf("Enter the size of the spiral matrix: ");
    scanf("%d", &num);

    if (num > MAX || num < 0) {
        printf("Invalid size. Size should be between 0 and %d\n", MAX);
        return -1;
    }

    min_row = 0;
    min_col = 0;
    max_row = num - 1;
    max_col = num - 1;

    // Print first row
    for (i = min_col; i <= max_col; i++) {
        printf("%d ", matrix[min_row][i]);
        matrix[min_row][i] = ++count;
    }
    printf("\n");

    // Print remaining left columns
    for (i = min_row + 1; i <= max_row; i++) {
        printf("%d ", matrix[i][min_col]);
        matrix[i][min_col] = ++count;
    }

    if (num > 2) {
        // Print remaining top rows
        for (j = min_col + 1; j <= max_col; j++) {
            printf("%d ", matrix[max_row][j]);
            matrix[max_row][j] = ++count;
        }
        printf("\n");

        // Print remaining right columns
        for (i = max_row - 1; i > min_row; i--) {
            printf("%d ", matrix[i][max_col]);
            matrix[i][max_col] = ++count;
        }

        // Print remaining bottom rows
        for (j = max_col - 1; j > min_col; j--) {
            printf("%d ", matrix[min_row][j]);
            matrix[min_row][j] = ++count;
        }

        // Print center element
        printf("\n%d ", matrix[min_row + (max_row - min_row) / 2][min_col + (max_col - min_col) / 2]);
        matrix[min_row + (max_row - min_row) / 2][min_col + (max_col - min_col) / 2] = ++count;
    }

    return 0;
}