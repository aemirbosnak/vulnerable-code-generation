//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3];

void art() {
    printf("\n~*~*~ Welcome to the surreal Tic Tac Toe AI ~*~*~\n");
    printf("         ___________         \n");
    printf("        |           |        \n");
    printf("        |   X   O   |        \n");
    printf("        |    \\  /   |        \n");
    printf("        |     \\/    |        \n");
    printf("        |     /\\    |        \n");
    printf("        |    /  \\   |        \n");
    printf("        |___O___X__|        \n");
    printf("                          \n");
}

void setup() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}

void draw_board() {
    printf("_____________\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf("  | ");
            } else if (board[i][j] == 1) {
                printf("X | ");
            } else {
                printf("O | ");
            }
        }
        printf("\n|___|___|___|\n");
    }
}

int check_win(int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

void ai_move() {
    int x, y;

    do {
        srand(time(NULL));
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != 0);

    board[x][y] = 2;
}

void player_move(int player) {
    int x, y;

    do {
        printf("\nPlayer %d, choose your move (row column): ", player);
        scanf("%d %d", &x, &y);
        x--;
        y--;
    } while (board[x][y] != 0);

    board[x][y] = player;
}

int main() {
    int player = 1;
    int winner = 0;
    int moves = 0;

    setup();
    art();
    draw_board();

    do {
        if (player == 1) {
            player_move(player);
        } else {
            ai_move();
        }

        draw_board();
        winner = check_win(player);
        player = (player == 1) ? 2 : 1;
        moves++;

        if (moves == 9) {
            printf("\nDraw!\n");
            return 0;
        }
    } while (winner == 0);

    printf("\nPlayer %d wins!\n", player);

    return 0;
}