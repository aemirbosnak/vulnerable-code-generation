//Falcon-180B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY '.'
#define X 'X'
#define O 'O'

void drawBoard(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int x, y, player = 1;
    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        if(player % 2 == 1) {
            printf("Enter your move (row and column): ");
            scanf("%d%d", &x, &y);
            x--; y--;
            if(board[x][y]!= EMPTY) {
                printf("Invalid move!\n");
                continue;
            }
            board[x][y] = X;
            if(checkWin(board)) {
                printf("Player 1 wins!\n");
                break;
            }
            player++;
        } else {
            int validMove = 0;
            while(!validMove) {
                x = rand() % SIZE;
                y = rand() % SIZE;
                if(board[x][y] == EMPTY) {
                    board[x][y] = O;
                    validMove = 1;
                }
            }
            if(checkWin(board)) {
                printf("Player 2 wins!\n");
                break;
            }
            player++;
        }
    }
    return 0;
}