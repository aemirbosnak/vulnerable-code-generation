//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 64
#define MAX_MOVES 10

typedef struct Move {
    int x, y, direction, capture;
} Move;

Move moves[MAX_MOVES];

void makeMove(int x, int y, int direction, int capture) {
    moves[0].x = x;
    moves[0].y = y;
    moves[0].direction = direction;
    moves[0].capture = capture;
}

int main() {
    int board[BOARD_SIZE] = {0};
    board[2] = 1;
    board[5] = 1;
    board[12] = 2;
    board[15] = 2;

    int movesMade = 0;

    while (movesMade < MAX_MOVES && board[2] && board[12]) {
        int moveX, moveY, direction, capture;

        printf("Enter move (x, y, direction, capture): ");
        scanf("%d %d %d %d", &moveX, &moveY, &direction, &capture);

        makeMove(moveX, moveY, direction, capture);

        board[moveY] = board[moveY] ^ 1;

        if (capture) {
            board[capture] = 0;
        }

        movesMade++;
    }

    if (board[2] == 0) {
        printf("White wins!");
    } else if (board[12] == 0) {
        printf("Black wins!");
    } else {
        printf("Draw!");
    }

    return 0;
}