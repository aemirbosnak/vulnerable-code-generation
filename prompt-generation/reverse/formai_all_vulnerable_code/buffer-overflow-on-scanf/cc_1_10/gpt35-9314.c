//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creates a 2D array that represents the game board
int **create_board(int rows, int columns) {
    int **board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = (int *)malloc(columns * sizeof(int));
    }
    return board;
}

// Fills the game board with random numbers between 1 and 100
void fill_board(int **board, int rows, int columns) {
    srand(time(0)); // Seeds random number generator
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = rand() % 100 + 1;
        }
    }
}

// Prints the game board
void print_board(int **board, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Finds the sum of all even numbers in the game board
int sum_of_evens(int **board, int rows, int columns) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j] % 2 == 0) {
                sum += board[i][j];
            }
        }
    }
    return sum;
}

// Main function
int main() {
    int rows, columns;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    int **board = create_board(rows, columns);
    fill_board(board, rows, columns);
    printf("\nGame board:\n");
    print_board(board, rows, columns);
    int sum = sum_of_evens(board, rows, columns);
    printf("\nSum of even numbers in game board: %d", sum);
    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}