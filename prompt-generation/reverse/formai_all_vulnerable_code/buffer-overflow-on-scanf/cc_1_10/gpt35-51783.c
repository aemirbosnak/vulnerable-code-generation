//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>

void printBoard(char board[][9]) {
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8]);
    printf("-----+---+-----\n");
    printf("%c|%c|%c|%c|%c|%c|%c|%c|%c\n", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8]);
}

int solve(char board[][9], int row, int col) {
    if(row == 9) {
        return 1;
    }
    if(col == 9) {
        return solve(board, row + 1, 0);
    }
    if(board[row][col] != '-') {
        return solve(board, row, col + 1);
    }
    for(int num = 1; num <= 9; num++) {
        board[row][col] = num + '0';
        if(isValid(board, row, col)) {
            if(solve(board, row, col + 1)) {
                return 1;
            }
        }
    }
    board[row][col] = '-';
    return 0;
}

int isValid(char board[][9], int row, int col) {
    return isValidRow(board, row) && isValidCol(board, col) && isValidBox(board, row - row%3, col - col%3);
}

int isValidRow(char board[][9], int row) {
    int arr[9] = {0};
    for(int i = 0; i < 9; i++) {
        if(board[row][i] != '-') {
            if(arr[board[row][i]-'1'] != 0) {
                return 0;
            }
            arr[board[row][i]-'1']++;
        }
    }
    return 1;
}

int isValidCol(char board[][9], int col) {
    int arr[9] = {0};
    for(int i = 0; i < 9; i++) {
        if(board[i][col] != '-') {
            if(arr[board[i][col]-'1'] != 0) {
                return 0;
            }
            arr[board[i][col]-'1']++;
        }
    }
    return 1;
}

int isValidBox(char board[][9], int row, int col) {
    int arr[9] = {0};
    for(int i = row; i < row + 3; i++) {
        for(int j = col; j < col + 3; j++) {
            if(board[i][j] != '-') {
                if(arr[board[i][j]-'1'] != 0) {
                    return 0;
                }
                arr[board[i][j]-'1']++;
            }
        }
    }
    return 1;
}

int main() {
    char board[9][9];
    printf("Enter the Sudoku Puzzle (Use '-' for empty cells):\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
    printf("Solving the Sudoku Puzzle...\n");
    if(solve(board, 0, 0)) {
        printf("Sudoku Puzzle Solved:\n");
        printBoard(board);
    }
    else {
        printf("Error: Sudoku Puzzle cannot be solved!\n");
    }
    return 0;
}