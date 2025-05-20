//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define EMPTY_CELL 0

void read_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
bool solve_board(int board[BOARD_SIZE][BOARD_SIZE]);
bool is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num);
bool find_empty_cell(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *col);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    
    read_board(board);
    
    printf("Input: \n");
    print_board(board);
    
    bool is_solvable = solve_board(board);
    if (is_solvable) {
        printf("Solution: \n");
        print_board(board);
    } else {
        printf("This board is unsolvable.\n");
    }
   
    return 0;
}

void read_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Enter the board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool solve_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    
    if (!find_empty_cell(board, &row, &col)) {
        return true;
    }
    
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
                return true;
            }
            board[row][col] = EMPTY_CELL;
        }
    }
    
    return false;
}

bool is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // check row
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[row][j] == num && j != col) {
            return false;
        }
    }
    
    // check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num && i != row) {
            return false;
        } 
    }
    
    // check square
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j] == num && i != row && j != col) {
                return false;
            }
        }
    }
    
    return true;
}

bool find_empty_cell(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *col) {
    for (*row = 0; *row < BOARD_SIZE; (*row)++) {
        for (*col = 0; *col < BOARD_SIZE; (*col)++) {
            if (board[*row][*col] == EMPTY_CELL) {
                return true;
            }
        }
    }
    
    return false;
}