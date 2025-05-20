//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
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

    // Check horizontal lines
    for(i = 0; i < SIZE; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[i][1] == board[i][2] && board[i][2] == board[i][0])) {
            return 1;
        }
    }

    // Check vertical lines
    for(i = 0; i < SIZE; i++) {
        if((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
           (board[1][i] == board[2][i] && board[2][i] == board[0][i])) {
            return 1;
        }
    }

    // Check diagonal lines
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

void playGame(char board[SIZE][SIZE]) {
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);

        do {
            printf("Enter your move (row and column): ");
            scanf("%d %d", &i, &j);
            i--; j--;
        } while((i < 0 || i >= SIZE) || (j < 0 || j >= SIZE) || board[i][j]!= '\0');

        board[i][j] = (player == 1)? 'X' : 'O';

        if(checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }
}

int main() {
    char board[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = '\0';
        }
    }

    playGame(board);

    return 0;
}