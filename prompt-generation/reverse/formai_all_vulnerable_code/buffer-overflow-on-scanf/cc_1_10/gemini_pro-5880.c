//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Turing machine simulation
int main() {
    // Initialize the Turing machine
    int tape[1000] = {0};
    int head = 0;
    int state = 0;

    // Define the Turing machine's rules
    int rules[5][3] = {
        {0, 0, 1},  // State 0: If the current cell is 0, write 0, move right, and go to state 1
        {1, 1, 2},  // State 1: If the current cell is 1, write 1, move left, and go to state 2
        {2, 1, 3},  // State 2: If the current cell is 1, write 1, move left, and go to state 3
        {3, 0, 4},  // State 3: If the current cell is 0, write 0, move right, and go to state 4
        {4, 1, 0}   // State 4: If the current cell is 1, write 1, move left, and go to state 0
    };
    printf("Enter matrix dimensions:\n");
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Original Matrix: \n");
    for(int p = 0; p < rows; p++) {
        for(int q = 0; q < cols; q++) {
            printf(" %d ", matrix[p][q]);
        }
        printf("\n");
    }
    int transposeMatrix[rows][cols];
    printf("Transpose of above matrix is: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    for(int p = 0; p < cols; p++) {
        for(int q = 0; q < rows; q++) {
            printf(" %d ", transposeMatrix[p][q]);
        }
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}