//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

// function for printing the matrix
void printMatrix(char matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function for simulating percolation
void percolation(char matrix[][MAX], int rows, int cols) {
    
    // set top and bottom rows as open
    for (int j = 0; j < cols; j++) {
        matrix[0][j] = 'O';
        matrix[rows-1][j] = 'O';
    }
    
    // randomly open some cells
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int r = rand() % 2;
            if (r == 0 && matrix[i][j] == 'X') {
                matrix[i][j] = 'O';
            }
        }
    }
    
    // simulate percolation
    int percolates = 0;
    while (!percolates) {
        for (int i = 1; i < rows-1; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 'O') {
                    if (matrix[i-1][j] == 'O' || matrix[i+1][j] == 'O') {
                        matrix[i][j] = 'O';
                    }
                }
                if (i == rows-2 && matrix[i][j] == 'O') {
                    percolates = 1;
                }
            }
        }
        printMatrix(matrix, rows, cols);
    }
    printf("Percolation achieved!\n");
}

int main() {
    
    int rows, cols;
    
    printf("Enter number of rows and columns (max %d): ", MAX);
    scanf("%d %d", &rows, &cols);
    
    // initialize matrix with all closed cells
    char matrix[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 'X';
        }
    }
    
    // simulate percolation
    percolation(matrix, rows, cols);
    
    return 0;
}