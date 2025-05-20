//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
    #include <stdlib.h>

    // Function to print the board
    void print_board(int** board, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Function to count the number of living neighbors
    int count_neighbors(int** board, int rows, int cols, int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int r = (row + i + rows) % rows;
                int c = (col + j + cols) % cols;
                if (board[r][c] == 1) count++;
            }
        }
        return count;
    }

    // Function to update the board
    void update_board(int** board, int rows, int cols) {
        int** new_board = malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
            new_board[i] = malloc(cols * sizeof(int));
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int count = count_neighbors(board, rows, cols, i, j);
                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    new_board[i][j] = 0;
                } else if (board[i][j] == 0 && count == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = board[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            free(board[i]);
        }
        free(board);
        board = new_board;
    }

    // Main function
    int main() {
        int rows = 20;
        int cols = 20;
        int** board = malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
            board[i] = malloc(cols * sizeof(int));
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = rand() % 2;
            }
        }
        print_board(board, rows, cols);
        for (int i = 0; i < 10; i++) {
            update_board(board, rows, cols);
            print_board(board, rows, cols);
        }
        for (int i = 0; i < rows; i++) {
            free(board[i]);
        }
        free(board);
        return 0;
    }