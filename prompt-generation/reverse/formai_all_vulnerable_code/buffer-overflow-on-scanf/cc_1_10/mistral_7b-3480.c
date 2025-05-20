//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void print_pattern(int **arr, int rows, int cols);
void generate_pattern(int **arr, int rows, int cols);

int main() {
    int **pattern, rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    pattern = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        pattern[i] = (int *)malloc(cols * sizeof(int));
    }

    generate_pattern(pattern, rows, cols);
    print_pattern(pattern, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);

    return 0;
}

void generate_pattern(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i + j + 1;
        }
    }
}

void print_pattern(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}