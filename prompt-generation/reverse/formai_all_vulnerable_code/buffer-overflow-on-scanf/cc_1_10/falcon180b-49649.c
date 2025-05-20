//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

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
    int player = 0;
    int i, j;

    // Initialize board
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Main game loop
    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player+1);

        // Get input from player
        int x, y;
        scanf("%d %d", &x, &y);

        // Check if move is valid
        if(x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move\n");
            continue;
        }

        // Update board
        if(player == 0) {
            board[x][y] = 'X';
        } else {
            board[x][y] = 'O';
        }

        // Check for win
        if(checkWin(board)) {
            printf("Player %d wins!\n", player+1);
            break;
        }

        // Switch player
        player =!player;
    }

    return 0;
}