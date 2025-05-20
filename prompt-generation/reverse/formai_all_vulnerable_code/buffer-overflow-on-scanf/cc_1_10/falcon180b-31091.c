//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 3

bool board[BOARD_SIZE][BOARD_SIZE] = {false};

void draw_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j]) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int check_winner() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] && board[i][1] && board[i][2]) {
            return 1;
        }
        if (board[0][i] && board[1][i] && board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] && board[1][1] && board[2][2]) {
        return 1;
    }
    if (board[0][2] && board[1][1] && board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = false;
        }
    }
    int player = rand() % 2;
    int moves = 0;
    while (moves < BOARD_SIZE * BOARD_SIZE) {
        draw_board();
        int x, y;
        if (player == 0) {
            printf("Player 1's turn.\n");
        } else {
            printf("Player 2's turn.\n");
        }
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE &&!board[x][y]) {
            board[x][y] = true;
            player =!player;
            moves++;
            if (check_winner()) {
                draw_board();
                printf("Player %d wins!\n", player + 1);
                break;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}