//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_GENERATIONS 1000

void print_cell(int x, int y, int alive) {
    if (alive) {
        printf("#");
    } else {
        printf(" ");
    }
}

void print_board(int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            print_cell(i, j, board[i][j]);
        }
        printf("\n");
    }
}

void randomize_board(int board[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void next_generation(int board[MAX_SIZE][MAX_SIZE], int size) {
    int new_board[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int alive_neighbors = 0;
            if (i > 0 && board[i - 1][j]) {
                alive_neighbors++;
            }
            if (i < size - 1 && board[i + 1][j]) {
                alive_neighbors++;
            }
            if (j > 0 && board[i][j - 1]) {
                alive_neighbors++;
            }
            if (j < size - 1 && board[i][j + 1]) {
                alive_neighbors++;
            }
            if (alive_neighbors == 3) {
                new_board[i][j] = 1;
            } else if (alive_neighbors == 2 && board[i][j]) {
                new_board[i][j] = 1;
            } else if (alive_neighbors > 3) {
                new_board[i][j] = 0;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the board: ");
    scanf("%d", &size);

    int board[MAX_SIZE][MAX_SIZE];
    randomize_board(board, size);

    for (int i = 0; i < MAX_GENERATIONS; i++) {
        print_board(board, size);
        next_generation(board, size);
    }

    return 0;
}