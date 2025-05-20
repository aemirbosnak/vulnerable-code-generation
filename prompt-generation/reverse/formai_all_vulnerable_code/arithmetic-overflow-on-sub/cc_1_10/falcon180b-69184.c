//Falcon-180B DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 5

void printBoard(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initBoard(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        if(board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= '-') {
            return 1;
        }
        if(board[0][i]!= '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= '-') {
            return 1;
        }
    }
    if(board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= '-') {
        return 1;
    }
    if(board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= '-') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];
    initBoard(board);
    printBoard(board);

    int player = 1;
    int choice;
    int x, y;

    while(1) {
        system("clear");
        printBoard(board);
        if(player % 2 == 1) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);
        x--; y--;
        if(board[x][y]!= '-') {
            printf("Invalid move\n");
            continue;
        }
        board[x][y] = (player % 2)? 'X' : 'O';
        if(checkWin(board)) {
            printf("Player %d wins!\n", (player % 2) + 1);
            break;
        }
        player++;
    }

    return 0;
}