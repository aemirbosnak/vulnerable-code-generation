//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int board[3][3] = {0};
    int turn = 0;
    int space;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1, choose your move:\n");

    while (space!= -1) {
        scanf("%d", &space);
        if (space > 8 || space < 1) {
            printf("Invalid input, try again.\n");
            continue;
        }
        if (board[space - 1][0] == 1 || board[space - 1][0] == 2) {
            printf("Move already taken, try again.\n");
            continue;
        }
        board[space - 1][0] = turn;
        turn = 1 - turn;
        printf("Player %d: %c\n", turn, 'X' + turn);
        printf("Player 2, choose your move:\n");
    }

    while (1) {
        scanf("%d", &space);
        if (space > 8 || space < 1) {
            printf("Invalid input, try again.\n");
            continue;
        }
        if (board[space - 1][0] == 1 || board[space - 1][0] == 2) {
            printf("Move already taken, try again.\n");
            continue;
        }
        board[space - 1][0] = turn;
        turn = 1 - turn;
        printf("Player %d: %c\n", turn, 'X' + turn);
        if (turn == 2) {
            printf("Player 2 wins!\n");
            break;
        } else if (turn == 1) {
            printf("Player 1 wins!\n");
            break;
        }
    }

    return 0;
}