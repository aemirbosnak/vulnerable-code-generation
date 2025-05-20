//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define WHITE 0
#define BLACK 1
#define EMPTY 2

int board[SIZE][SIZE];

void initBoard() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == WHITE) {
                printf("W ");
            } else if(board[i][j] == BLACK) {
                printf("B ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void makeMove(int x, int y, int player) {
    if(player == WHITE) {
        board[x][y] = WHITE;
    } else {
        board[x][y] = BLACK;
    }
}

int checkWin(int player) {
    for(int i=0; i<SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    for(int i=0; i<SIZE; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));
    initBoard();

    int turn = WHITE;

    while(1) {
        printBoard();
        int x, y;
        printf("Player %d's turn. Enter your move (x y): ", turn+1);
        scanf("%d %d", &x, &y);
        makeMove(x, y, turn);

        if(checkWin(turn)) {
            printf("Player %d wins!\n", turn+1);
            break;
        }

        turn = (turn == WHITE)? BLACK : WHITE;
    }

    return 0;
}