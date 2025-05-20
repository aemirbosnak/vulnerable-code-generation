//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    // Check rows and columns
    for(i=0; i<SIZE; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE];

    // Initialize the board with empty spaces
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '-';
        }
    }

    int player = 0;
    int moves = 0;

    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn. Enter your move: ", player+1);
        scanf("%d %d", &moves, &player);

        if(player == 0) {
            board[moves/3][moves%3] = 'X';
        }
        else {
            board[moves/3][moves%3] = 'O';
        }

        if(checkWin(board)) {
            printf("\nPlayer %d wins!\n", player+1);
            break;
        }

        moves++;
        if(moves == 9) {
            printf("\nIt's a draw.\n");
            break;
        }
    }

    return 0;
}