//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8
#define COLS 4
#define ROWS 2

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int check_draw(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void play_game(char board[ROWS][COLS]) {
    int i, j, player = 1;
    char choice;
    while (1) {
        printf("Player %d's turn\n", player);
        printf("Enter your choice (row and column): ");
        scanf("%d%c", &i, &choice);
        i--;
        choice -= '0';
        if (board[i][choice] == '-') {
            board[i][choice] = (player == 1)? 'X' : 'O';
            player++;
            if (check_win(board)) {
                printf("Player %d wins!\n", player);
                break;
            } else if (check_draw(board)) {
                printf("It's a draw.\n");
                break;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    play_game(board);
    return 0;
}