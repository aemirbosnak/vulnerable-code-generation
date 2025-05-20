//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9
#define EMPTY_CELL 0

typedef struct {
    int cells[BOARD_SIZE][BOARD_SIZE];
    bool is_fixed[BOARD_SIZE][BOARD_SIZE];
} Board;

bool is_valid_board(Board *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        bool seen[BOARD_SIZE + 1] = {0};
        for (int col = 0; col < BOARD_SIZE; col++) {
            int value = board->cells[row][col];
            if (value == EMPTY_CELL) {
                continue;
            }
            if (seen[value]) {
                return false;
            }
            seen[value] = true;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        bool seen[BOARD_SIZE + 1] = {0};
        for (int row = 0; row < BOARD_SIZE; row++) {
            int value = board->cells[row][col];
            if (value == EMPTY_CELL) {
                continue;
            }
            if (seen[value]) {
                return false;
            }
            seen[value] = true;
        }
    }

    for (int box_row = 0; box_row < 3; box_row++) {
        for (int box_col = 0; box_col < 3; box_col++) {
            bool seen[BOARD_SIZE + 1] = {0};
            for (int row = box_row * 3; row < box_row * 3 + 3; row++) {
                for (int col = box_col * 3; col < box_col * 3 + 3; col++) {
                    int value = board->cells[row][col];
                    if (value == EMPTY_CELL) {
                        continue;
                    }
                    if (seen[value]) {
                        return false;
                    }
                    seen[value] = true;
                }
            }
        }
    }

    return true;
}

bool solve_board(Board *board) {
    // Find an empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == EMPTY_CELL) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If there are no empty cells, the board is solved
    if (row == -1) {
        return true;
    }

    // Try all possible values for the empty cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        // Check if the value is valid for the cell
        board->cells[row][col] = value;
        if (is_valid_board(board)) {
            // Recursively solve the board with the new value
            if (solve_board(board)) {
                return true;
            }
        }
        // If the value is not valid, reset the cell to empty
        board->cells[row][col] = EMPTY_CELL;
    }

    // If no valid values were found, the board is not solvable
    return false;
}

int main() {
    // Create a board
    Board board;
    memset(&board, 0, sizeof(board));

    // Read the board from the user
    printf("Enter the board: \n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            scanf("%d", &board.cells[row][col]);
            board.is_fixed[row][col] = (board.cells[row][col] != EMPTY_CELL);
        }
    }

    // Solve the board
    if (solve_board(&board)) {
        // Print the solved board
        printf("The solved board is: \n");
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                printf("%d ", board.cells[row][col]);
            }
            printf("\n");
        }
    } else {
        printf("The board is not solvable. \n");
    }

    return 0;
}