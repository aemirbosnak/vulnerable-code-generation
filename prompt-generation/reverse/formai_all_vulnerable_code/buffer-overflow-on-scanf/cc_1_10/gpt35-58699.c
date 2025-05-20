//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 100
#define MAX_COL 100

void generate_numbers(int matrix[MAX_ROW][MAX_COL], int rows, int cols);
void print_matrix(int matrix[MAX_ROW][MAX_COL], int rows, int cols);
void find_min_max(int matrix[MAX_ROW][MAX_COL], int rows, int cols);

int main()
{
    int rows, cols;
    int matrix[MAX_ROW][MAX_COL];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    generate_numbers(matrix, rows, cols);

    printf("\nGenerated Matrix:\n");
    print_matrix(matrix, rows, cols);

    find_min_max(matrix, rows, cols);

    return 0;
}

void generate_numbers(int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void find_min_max(int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    int minimum, maximum;

    minimum = maximum = matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minimum) {
                minimum = matrix[i][j];
            } else if (matrix[i][j] > maximum) {
                maximum = matrix[i][j];
            }
        }
    }

    printf("\nMinimum value in matrix: %d\n", minimum);
    printf("Maximum value in matrix: %d\n", maximum);
}