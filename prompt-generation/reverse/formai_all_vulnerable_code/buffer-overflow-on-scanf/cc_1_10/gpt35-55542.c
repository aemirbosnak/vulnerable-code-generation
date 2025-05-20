//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool solve_sudoku();
bool is_valid_move(int row, int col, int num);
bool find_unassigned_location(int *row, int *col);
void print_board();

int main() {
    printf("Welcome to the Sudoku Solver!\n");
    printf("Enter the numbers on the board, use 0 for blank spaces:\n");
    
    // Get input from user to fill in the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("Enter row %d: ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    // Solve the sudoku
    if (solve_sudoku()) {
        printf("\nSolution:\n");
        print_board();
    } else {
        printf("\nNo solution found.\n");
    }
    
    return 0;
}

bool solve_sudoku() {
    int row, col;
    
    // Check if the board is completely filled
    if (!find_unassigned_location(&row, &col)) {
        return true;
    }
    
    // Try every number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        
        // If the move is valid, add the number to the board
        if (is_valid_move(row, col, num)) {
            board[row][col] = num;
            
            // Recursively solve the rest of the board
            if (solve_sudoku()) {
                return true;
            }
            
            // If a valid solution cannot be found, backtrack and try a different number
            board[row][col] = 0;
        }
    }
    
    // If no solution can be found, return false
    return false;
}

bool is_valid_move(int row, int col, int num) {
    
    // Check the row for duplicates
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    
    // Check the column for duplicates
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    
    // Check the 3x3 box for duplicates
    int box_row = row - row%3;
    int box_col = col - col%3;
    for (int i = box_row; i < box_row+3; i++) {
        for (int j = box_col; j < box_col+3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    
    // If no duplicates are found, return true
    return true;
}

bool find_unassigned_location(int *row, int *col) {
    
    // Find the next unassigned location
    for (*row = 0; *row < BOARD_SIZE; (*row)++) {
        for (*col = 0; *col < BOARD_SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    
    // If no unassigned location is found, return false
    return false;
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}