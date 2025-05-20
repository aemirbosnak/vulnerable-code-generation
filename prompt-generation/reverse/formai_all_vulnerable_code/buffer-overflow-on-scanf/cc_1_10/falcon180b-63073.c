//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

void draw_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("X");
            } else if (board[i][j] == -1) {
                printf("O");
            }
        }
        printf(" |\n");
    }
    printf("+---+---+\n");
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int move_count = 0;
    int player = 1;

    while (move_count < BOARD_SIZE * BOARD_SIZE) {
        draw_board(board);
        int x, y;
        printf("Player %d's turn.\n", player);
        if (scanf("%d%d", &x, &y)!= 2 || x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid input.\n");
            continue;
        }
        if (board[x][y]!= 0) {
            printf("Invalid move.\n");
            continue;
        }
        board[x][y] = player;
        move_count++;
        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = -player;
    }

    return 0;
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0]!= 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j]!= 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    if (board[0][0]!= 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2]!= 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0;
}