//Falcon-180B DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board(void) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void check_win(void) {
    int i, j;
    char c = 'X';
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j]!= c) {
                return;
            }
        }
    }
    printf("Player %c wins!\n", c);
    exit(0);
}

void play_turn(char player) {
    int row, col;
    printf("Player %c, enter your move (row col): ", player);
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '\0') {
        board[row][col] = player;
        check_win();
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main(void) {
    srand(time(NULL));
    int player = rand() % 2;
    while (1) {
        print_board();
        play_turn(player == 0? 'X' : 'O');
        player =!player;
    }
    return 0;
}