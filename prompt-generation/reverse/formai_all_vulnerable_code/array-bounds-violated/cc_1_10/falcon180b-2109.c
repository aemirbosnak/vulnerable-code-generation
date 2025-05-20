//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void draw_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else if (board[i][j] == 2) {
                printf("O");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 3;
        }
    }
    int player_turn = 1;
    int game_over = 0;
    while (!game_over) {
        draw_board(board);
        printf("Player %d's turn\n", player_turn);
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move\n");
            continue;
        }
        if (board[choice / 3 - 1][choice % 3 - 1] == 0) {
            board[choice / 3 - 1][choice % 3 - 1] = player_turn;
            if (check_win(board)) {
                printf("Player %d wins!\n", player_turn);
                game_over = 1;
            } else {
                player_turn =!player_turn;
            }
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}