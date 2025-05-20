//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define the Sudoku board as a 2D array
#define BOARD_SIZE 9
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} board_t;

// Helper function to check if a number is valid to be placed in a given cell
bool is_valid(const char* cell, const char num) {
    // Check if the number is already present in the cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (cell[i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cell[i] == num && cell[i*BOARD_SIZE + j]!= '.' && cell[i*BOARD_SIZE + j]!= 0) {
                return false;
            }
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cell[j] == num && cell[i*BOARD_SIZE + j]!= '.' && cell[i*BOARD_SIZE + j]!= 0) {
                return false;
            }
        }
    }

    // Check if the number is already present in the 3x3 sub-grid
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                if (cell[i*BOARD_SIZE + j] == num && cell[i*BOARD_SIZE + k]!= '.' && cell[i*BOARD_SIZE + k]!= 0) {
                    return false;
                }
                if (cell[j*BOARD_SIZE + i] == num && cell[j*BOARD_SIZE + k]!= '.' && cell[j*BOARD_SIZE + k]!= 0) {
                    return false;
                }
                if (cell[k*BOARD_SIZE + i] == num && cell[k*BOARD_SIZE + j]!= '.' && cell[k*BOARD_SIZE + j]!= 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

// Helper function to print the Sudoku board
void print_board(board_t* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board->board[i][j]);
        }
        printf("\n");
    }
}

// Helper function to solve the Sudoku puzzle using a brute force method
bool solve_sudoku(board_t* board) {
    // Check if the puzzle is already solved
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == '.') {
                return false;
            }
        }
    }

    // Check if there are any empty cells
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == '.') {
                int num;
                do {
                    num = 0;
                    while (num < 1 || num > 9) {
                        printf("Enter a number between 1 and 9: ");
                        scanf("%d", &num);
                    }
                } while (!is_valid(board->board[i][j], num));
                board->board[i][j] = num + '1';
            }
        }
    }

    // Try all possible values for each empty cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == '.') {
                int num = 1;
                do {
                    board->board[i][j] = num + '1';
                    if (solve_sudoku(board)) {
                        return true;
                    }
                    board->board[i][j] = '.';
                    num++;
                } while (num <= 9);
            }
        }
    }

    return false;
}

int main() {
    board_t board;
    char input[BOARD_SIZE * BOARD_SIZE];

    printf("Enter the initial Sudoku puzzle: \n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%s", &input);
            board.board[i][j] = input[j];
        }
    }

    printf("Solving Sudoku...\n");
    if (solve_sudoku(&board)) {
        printf("Puzzle solved!\n");
        print_board(&board);
    } else {
        printf("Sorry, the puzzle is unsolvable.\n");
    }

    return 0;
}