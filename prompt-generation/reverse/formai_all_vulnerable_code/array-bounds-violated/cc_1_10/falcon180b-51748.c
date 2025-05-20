//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    // Check rows
    for(i = 0; i < SIZE; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for(i = 0; i < SIZE; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    int player = 1;
    int choice;

    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        choice = rand() % 9 + 1;
        if(board[choice / 3][choice % 3]!= 'X' && board[choice / 3][choice % 3]!= 'O') {
            board[choice / 3][choice % 3] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move, try again.\n");
        }

        if(checkWin(board)) {
            drawBoard(board);
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }

    return 0;
}