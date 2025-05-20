//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
// Oh my goodness! This is the Game of Life in C.
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void display_board(int board[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("\n\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[MAX_ROWS][MAX_COLS], int row, int col, int rows, int cols) {
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && i < rows && j >= 0 && j < cols && !(i == row && j == col)) {
                if(board[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void play_game(int board[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int new_board[MAX_ROWS][MAX_COLS];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int num_neighbors = count_neighbors(board, i, j, rows, cols);
            if(board[i][j] == 1) {
                if(num_neighbors < 2 || num_neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if(num_neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    printf("OMG! We are playing the Game of Life!\n\n");
    int rows, cols, num_generations;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of generations to play: ");
    scanf("%d", &num_generations);

    int board[MAX_ROWS][MAX_COLS];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }

    display_board(board, rows, cols);
    for(int i = 0; i < num_generations; i++) {
        play_game(board, rows, cols);
        display_board(board, rows, cols);
    }

    printf("Wow, that was intense!\n");
    return 0;
}