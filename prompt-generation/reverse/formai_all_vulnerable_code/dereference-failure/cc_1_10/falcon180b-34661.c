//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

int **create_board(int **board) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

int is_valid(int **board, int x, int y, int num) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][y] == num)
            return 0;
    }
    for (j = 0; j < SIZE; j++) {
        if (board[x][j] == num)
            return 0;
    }
    int box_x = (x / 3) * 3;
    int box_y = (y / 3) * 3;
    for (i = box_x; i < box_x + 3; i++) {
        for (j = box_y; j < box_y + 3; j++) {
            if (board[i][j] == num)
                return 0;
        }
    }
    return 1;
}

void print_board(int **board) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int **board = create_board(NULL);
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % SIZE + 1;
        }
    }
    int count = 0;
    while (count < 81) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (is_valid(board, x, y, board[x][y])) {
            int num = rand() % SIZE + 1;
            while (!is_valid(board, x, y, num)) {
                num = rand() % SIZE + 1;
            }
            board[x][y] = num;
            count++;
        }
    }
    printf("Sudoku board:\n");
    print_board(board);
    return 0;
}