//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9
#define MAX_TRIES 1000

int board[MAX_SIZE][MAX_SIZE];
int size;

void init_board(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[MAX_SIZE][MAX_SIZE], int row, int col, int num)
{
    int i, j;
    for (i = 0; i < size; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    for (i = 0; i < size; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (i = sub_row; i < sub_row + 3; i++) {
        for (j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j, num, row, col;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                do {
                    num = rand() % 9 + 1;
                } while (!is_valid(board, i, j, num));
                board[i][j] = num;
            }
        }
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int board[MAX_SIZE][MAX_SIZE];
    int size;
    printf("Enter the size of the Sudoku board (between 3 and 9): ");
    scanf("%d", &size);
    if (size < 3 || size > 9) {
        printf("Invalid size!\n");
        return 1;
    }
    init_board(board, size);
    int tries = 0;
    while (tries < MAX_TRIES) {
        if (solve_sudoku(board, size)) {
            printf("Solved Sudoku board:\n");
            print_board(board, size);
            return 0;
        }
        tries++;
        init_board(board, size);
    }
    printf("Failed to solve Sudoku board.\n");
    return 1;
}