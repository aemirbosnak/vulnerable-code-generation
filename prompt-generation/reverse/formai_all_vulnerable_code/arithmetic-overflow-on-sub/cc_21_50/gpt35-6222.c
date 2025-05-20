//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //initialize empty board
    int player = 1;
    int row, col;
    int end = 0; //end game flag

    printf("*** Welcome to Tic-Tac-Toe! ***\n");

    while (!end) {
        //display board
        printf("\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        //ask for player input
        printf("Player %d, enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter column (1-3): ", player);
        scanf("%d", &col);

        //check if spot is already taken
        if (board[row-1][col-1] != ' ') {
            printf("That spot is already taken. Try again.\n");
            continue;
        }

        //place player's symbol on board
        if (player == 1) {
            board[row-1][col-1] = 'X';
        } else {
            board[row-1][col-1] = 'O';
        }

        //check for win or tie
        if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            printf("Player %d wins!\n", player);
            end = 1;
        } else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
                    && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
                    && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
            printf("It's a tie!\n");
            end = 1;
        }

        //switch to other player
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}