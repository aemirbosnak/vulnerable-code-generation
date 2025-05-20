//Falcon-180B DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j;
    char board[SIZE][SIZE];
    char player = 'X';
    int flag = 0;
    int ch;
    srand(time(0));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }

    while (flag == 0) {
        system("clear");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("Player %c's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &i, &j);
        if (board[i][j]!= '*') {
            printf("Sorry, that spot is already taken!\n");
        } else {
            board[i][j] = player;
            flag = check_win(board);
        }
        if (flag == 0) {
            player = (player == 'X')? 'O' : 'X';
        }
    }

    return 0;
}

int check_win(char board[SIZE][SIZE]) {
    int i, j;
    int win = 0;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0]!= '*' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            win = 1;
            break;
        }
    }

    // Check columns
    for (j = 0; j < SIZE; j++) {
        if (board[0][j]!= '*' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            win = 1;
            break;
        }
    }

    // Check diagonals
    if (board[0][0]!= '*' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        win = 1;
    }

    if (board[0][2]!= '*' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        win = 1;
    }

    return win;
}