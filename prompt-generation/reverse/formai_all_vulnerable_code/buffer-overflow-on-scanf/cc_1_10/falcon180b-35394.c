//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void initialize(int **, int, int);
void print_matrix(int **, int, int);
void simulate_baggage_handling(int **, int, int);

int main() {
    int rows, cols;
    int **baggage_matrix;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    baggage_matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        baggage_matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    srand(time(NULL));
    initialize(baggage_matrix, rows, cols);
    print_matrix(baggage_matrix, rows, cols);
    simulate_baggage_handling(baggage_matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(baggage_matrix[i]);
    }
    free(baggage_matrix);

    return 0;
}

void initialize(int **baggage_matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            baggage_matrix[i][j] = rand() % 2;
        }
    }
}

void print_matrix(int **baggage_matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", baggage_matrix[i][j]);
        }
        printf("\n");
    }
}

void simulate_baggage_handling(int **baggage_matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (baggage_matrix[i][j] == 1) {
                int new_row = rand() % rows;
                int new_col = rand() % cols;

                while (baggage_matrix[new_row][new_col] == 1) {
                    new_row = rand() % rows;
                    new_col = rand() % cols;
                }

                baggage_matrix[i][j] = 0;
                baggage_matrix[new_row][new_col] = 1;
            }
        }
    }
}