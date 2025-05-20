//Falcon-180B DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_SYMBOLS 2

void print_board(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for(int j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % NUM_SYMBOLS + 1;
        }
    }

    int player = 1;
    while(1) {
        print_board(board);
        int row, col;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &row, &col);
        row--; col--;

        if(board[row][col]!= 0) {
            printf("Invalid move.\n");
            continue;
        }

        board[row][col] = player;

        if(check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}