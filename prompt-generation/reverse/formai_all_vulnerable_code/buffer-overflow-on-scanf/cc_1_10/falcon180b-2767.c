//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

#define SIZE 9

void print_matrix(int matrix[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int matrix[SIZE][SIZE], int i, int j, int num) {
    int k;

    for (k = 0; k < SIZE; k++) {
        if (matrix[i][k] == num || matrix[k][j] == num)
            return 0;
    }

    int sub_i = (i / 3) * 3;
    int sub_j = (j / 3) * 3;

    for (k = sub_i; k < sub_i + 3; k++) {
        for (int l = sub_j; l < sub_j + 3; l++) {
            if (matrix[k][l] == num)
                return 0;
        }
    }

    return 1;
}

int backtrack(int matrix[SIZE][SIZE], int i, int j) {
    if (i == SIZE - 1 && j == SIZE - 1)
        return 1;

    if (j == SIZE - 1)
        return backtrack(matrix, i + 1, 0);

    if (i == SIZE - 1)
        return backtrack(matrix, 0, j + 1);

    int num = 1;

    while (num <= SIZE) {
        if (is_valid(matrix, i, j, num)) {
            matrix[i][j] = num;

            if (backtrack(matrix, i, j + 1))
                return 1;

            matrix[i][j] = 0;
        }
        num++;
    }

    return 0;
}

int main() {
    int matrix[SIZE][SIZE];

    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = backtrack(matrix, 0, 0);

    if (result) {
        printf("Sudoku solved:\n");
        print_matrix(matrix);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}