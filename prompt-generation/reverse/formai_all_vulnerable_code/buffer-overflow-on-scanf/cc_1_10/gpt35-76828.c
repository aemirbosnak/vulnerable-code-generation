//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9            // Size of the board

int board[SIZE][SIZE];    // The board

// Function to print the board
void print_board() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given value is allowed in the row
int check_row(int row, int value) {
    for(int i=0;i<SIZE;i++) {
        if(board[row][i] == value) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the given value is allowed in the column
int check_column(int column, int value) {
    for(int i=0;i<SIZE;i++) {
        if(board[i][column] == value) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the given value is allowed in the 3x3 box
int check_box(int row, int column, int value) {
    int box_row = row / 3;
    int box_column = column / 3;
    for(int i=box_row*3;i<box_row*3+3;i++) {
        for(int j=box_column*3;j<box_column*3+3;j++) {
            if(board[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the board using backtracking
int solve_board(int row, int column) {
    // If we have reached the end of the board, then the board is solved
    if(column == SIZE) {
        row++;
        column = 0;
        if(row == SIZE) {
            return 1;
        }
    }
    // Skip the given values
    if(board[row][column] != 0) {
        return solve_board(row,column+1);
    }
    // Try all possible values for the empty cell
    for(int i=1;i<=SIZE;i++) {
        if(check_row(row,i) && check_column(column,i) && check_box(row,column,i)) {
            board[row][column] = i;

            if(solve_board(row,column+1)) {
                return 1;
            }
            board[row][column] = 0;
        }
    }
    return 0;
}

int main() {
    // Input the board
    printf("Enter the board:\n");
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            scanf("%d",&board[i][j]);
        }
    }

    // Solve the board
    if(solve_board(0,0)) {
        printf("\nSolved Board:\n");
        print_board();
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}