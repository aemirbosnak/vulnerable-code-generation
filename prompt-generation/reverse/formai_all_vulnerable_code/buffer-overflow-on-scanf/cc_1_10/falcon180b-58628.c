//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Cryptic
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

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void play_game() {
    int player = 1;
    int choice;
    int valid_move = 1;

    srand(time(NULL));
    int row = rand() % ROWS;
    int col = rand() % COLS;
    board[row][col] = 'X';

    while (valid_move) {
        print_board();
        printf("Player %d's turn.\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
            board[row][col] = (player == 1)? 'X' : 'O';
            valid_move = check_win();
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
    }

    print_board();
    if (player == 1)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");
}

int main() {
    play_game();
    return 0;
}