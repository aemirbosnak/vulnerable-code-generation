//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>

#define SIZE 9 

int board[SIZE][SIZE];

void print_board() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int find_empty_cell(int *r, int *c) {
    for (*r = 0; *r < SIZE; ++(*r)) {
        for (*c = 0; *c < SIZE; ++(*c)) {
            if (board[*r][*c] == 0)
                return 1;
        }
    }
    return 0;
}

int is_valid(int r, int c, int num) {
    // check row constraint
    for (int i = 0; i < SIZE; ++i) {
        if (board[r][i] == num)
            return 0;
    }
    
    // check column constraint
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][c] == num)
            return 0;
    }
    
    // check 3x3 sub-grid constraint
    int sub_row_start = r - r % 3;
    int sub_col_start = c - c % 3;
    for (int i = sub_row_start; i < sub_row_start + 3; ++i) {
        for (int j = sub_col_start; j < sub_col_start + 3; ++j) {
            if (board[i][j] == num)
                return 0;
        }
    }
    
    return 1;
}

int solve_board() {
    int r, c;
    if (!find_empty_cell(&r, &c))
        return 1; // solution found
    
    for (int num = 1; num <= 9; ++num) {
        if (is_valid(r, c, num)) {
            board[r][c] = num;
            if (solve_board())
                return 1; // solution found before reaching end
            board[r][c] = 0; // backtrack
        }
    }
    return 0; // no valid number found
}

int main() {
    printf("Enter the Sudoku board:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    
    printf("\nSudoku board before solving:\n");
    print_board();
    
    if (solve_board()) {
        printf("Solution found:\n");
        print_board();
    }
    else {
        printf("No solution found!\n");
    }
    
    return 0;
}