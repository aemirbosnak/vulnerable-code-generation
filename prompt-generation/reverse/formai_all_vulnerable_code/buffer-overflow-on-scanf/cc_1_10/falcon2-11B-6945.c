//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct {
    int board[MAX_SIZE][MAX_SIZE];
} Sudoku;

void print_sudoku(Sudoku *sudoku) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%3d ", sudoku->board[i][j]);
        }
        printf("\n");
    }
}

void solve(Sudoku *sudoku) {
    int empty_cell = find_empty_cell(sudoku);
    if (empty_cell == -1) {
        printf("Sudoku solved!\n");
        return;
    }
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (is_valid(sudoku, i)) {
            sudoku->board[empty_cell / MAX_SIZE][empty_cell % MAX_SIZE] = i;
            solve(sudoku);
            if (empty_cell!= -1) {
                sudoku->board[empty_cell / MAX_SIZE][empty_cell % MAX_SIZE] = 0;
            }
        }
    }
}

int find_empty_cell(Sudoku *sudoku) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (sudoku->board[i][j] == 0) {
                return j * MAX_SIZE + i;
            }
        }
    }
    return -1;
}

int is_valid(Sudoku *sudoku, int value) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (sudoku->board[i][j] == value) {
                return 0;
            }
            if (sudoku->board[i / MAX_SIZE][j / MAX_SIZE] == value) {
                return 0;
            }
            if (sudoku->board[i / MAX_SIZE][j] == value || sudoku->board[i][j / MAX_SIZE] == value) {
                return 0;
            }
            if (sudoku->board[i / MAX_SIZE - 1 / MAX_SIZE][j / MAX_SIZE + 1 / MAX_SIZE] == value ||
                sudoku->board[i / MAX_SIZE + 1 / MAX_SIZE][j / MAX_SIZE + 1 / MAX_SIZE] == value ||
                sudoku->board[i / MAX_SIZE + 1 / MAX_SIZE][j / MAX_SIZE - 1 / MAX_SIZE] == value ||
                sudoku->board[i / MAX_SIZE - 1 / MAX_SIZE][j / MAX_SIZE + 1 / MAX_SIZE] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku sudoku;
    printf("Enter the Sudoku board:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &sudoku.board[i][j]);
        }
    }
    solve(&sudoku);
    print_sudoku(&sudoku);
    return 0;
}