//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char player = 'X';
    int i, j, choice, flag = 0;

    printf("Player 1: X and Player 2: O\n");
    printf("Player 1's Turn\n");

    while (flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %c's Turn", player);
        printf("\nEnter your move: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9) {
            if (board[0][choice - 1]!= 'X' && board[0][choice - 1]!= 'O') {
                board[0][choice - 1] = player;
                flag = checkWin(board);
            } else {
                printf("\nInvalid Move! Try Again.\n");
            }
        } else {
            printf("\nInvalid Move! Try Again.\n");
        }

        if (flag == 0) {
            player = (player == 'X')? 'O' : 'X';
        }
    }

    printf("\nPlayer %c Wins!\n", player);

    return 0;
}