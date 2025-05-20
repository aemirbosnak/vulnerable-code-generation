//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_MOVES 100

struct Cell {
    int x;
    int y;
    int value;
};

void init_board(struct Cell board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = 0;
        }
    }
}

void print_board(struct Cell board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
}

void generate_board(struct Cell board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10;
        }
    }
}

int is_valid_move(struct Cell board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y].value == 0) {
        return 1;
    }
    return 0;
}

int main() {
    struct Cell board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    generate_board(board);
    print_board(board);

    int moves = 0;
    int x, y;
    while (moves < MAX_MOVES) {
        printf("Enter your move (x y): ");
        scanf("%d %d", &x, &y);
        if (is_valid_move(board, x, y)) {
            board[x][y].value = moves + 1;
            print_board(board);
            moves++;
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}