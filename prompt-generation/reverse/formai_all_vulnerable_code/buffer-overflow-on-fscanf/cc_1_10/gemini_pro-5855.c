//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Sudoku board size
#define BOARD_SIZE 9

// Constants representing the sub-grids' sizes
#define SUB_GRID_SIZE 3

// Structure to represent a Sudoku cell
typedef struct {
    int value;
    bool is_fixed;
} Cell;

// Structure to represent the Sudoku board
typedef struct {
    Cell board[BOARD_SIZE][BOARD_SIZE];
} Board;

// Function to read a Sudoku puzzle from a file
static Board* read_puzzle(const char* filename) {
    Board* board = malloc(sizeof(Board));

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        free(board);
        return NULL;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char c;
            fscanf(file, "%c", &c);

            if (c == '.') {
                board->board[i][j].value = 0;
                board->board[i][j].is_fixed = false;
            } else {
                board->board[i][j].value = c - '0';
                board->board[i][j].is_fixed = true;
            }
        }
    }

    fclose(file);

    return board;
}

// Function to print a Sudoku board
static void print_board(const Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j].is_fixed) {
                printf("%d", board->board[i][j].value);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to check if a value is present in a row
static bool is_in_row(const Board* board, int row, int value) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[row][i].value == value) {
            return true;
        }
    }
    return false;
}

// Function to check if a value is present in a column
static bool is_in_column(const Board* board, int column, int value) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[i][column].value == value) {
            return true;
        }
    }
    return false;
}

// Function to check if a value is present in a sub-grid
static bool is_in_sub_grid(const Board* board, int row, int column, int value) {
    int sub_grid_row = row / SUB_GRID_SIZE;
    int sub_grid_column = column / SUB_GRID_SIZE;

    for (int i = sub_grid_row * SUB_GRID_SIZE; i < sub_grid_row * SUB_GRID_SIZE + SUB_GRID_SIZE; i++) {
        for (int j = sub_grid_column * SUB_GRID_SIZE; j < sub_grid_column * SUB_GRID_SIZE + SUB_GRID_SIZE; j++) {
            if (board->board[i][j].value == value) {
                return true;
            }
        }
    }

    return false;
}

// Function to check if a value is valid for a given cell
static bool is_valid(const Board* board, int row, int column, int value) {
    return !is_in_row(board, row, value) && !is_in_column(board, column, value) && !is_in_sub_grid(board, row, column, value);
}

// Function to solve the Sudoku puzzle recursively
static bool solve_sudoku(Board* board) {
    // Find the first empty cell
    int row = -1;
    int column = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j].value == 0) {
                row = i;
                column = j;
                break;
            }
        }
    }

    // If no empty cell was found, the puzzle is solved
    if (row == -1 || column == -1) {
        return true;
    }

    // Try all possible values for the empty cell
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (is_valid(board, row, column, i)) {
            board->board[row][column].value = i;

            // If the puzzle is solved with this value, return true
            if (solve_sudoku(board)) {
                return true;
            }

            // If the puzzle is not solved with this value, reset the cell to its original value
            board->board[row][column].value = 0;
        }
    }

    // If no valid value was found for the empty cell, the puzzle is not solvable
    return false;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Board* board = read_puzzle(argv[1]);
    if (board == NULL) {
        return 1;
    }

    printf("Unsolved puzzle:\n");
    print_board(board);

    if (solve_sudoku(board)) {
        printf("Solved puzzle:\n");
        print_board(board);
    } else {
        printf("Puzzle could not be solved.\n");
    }

    free(board);

    return 0;
}