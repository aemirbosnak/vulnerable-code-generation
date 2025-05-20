//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void play_game() {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Player %d, enter your move (row and column): ", i + 1);
            scanf("%d%d", &k, &j);
            if (board[i][j]!= 0) {
                printf("Invalid move, try again.\n");
                continue;
            }
            board[i][j] = (i + 1) * 10 + (j + 1);
            if (check_win()) {
                printf("Player %d wins!\n", i + 1);
                exit(0);
            }
        }
    }
    if (check_win()) {
        printf("It's a draw.\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    play_game();
    return 0;
}