//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char board[3][3]) {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3], char player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

void play() {
    char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    char player = 'X';
    int move = 0;

    while(1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %c's turn. Enter a number from 1 to 9: ", player);
        scanf("%d", &move);
        move--;

        if(board[move/3][move%3]!= 'X' && board[move/3][move%3]!= 'O') {
            board[move/3][move%3] = player;
            if(checkWin(board, player)) {
                printf("\n%c wins!\n", player);
                break;
            }
            player = (player == 'X')? 'O' : 'X';
        } else {
            printf("\nInvalid move. Try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;

    while(1) {
        printf("\n1. Play Tic Tac Toe\n2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                play();
                break;
            case 2:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}