//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define EMPTY '.'
#define BLACK 'X'
#define WHITE 'O'

char board[SIZE][SIZE]; //board representation
int turn; //player turn
int moves; //number of moves

void initBoard() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            board[i][j] = EMPTY;
        }
    }
}

void drawBoard() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(int x1, int y1, int x2, int y2) {
    if(board[x1][y1] == EMPTY || board[x1][y1] == turn) {
        if(board[x2][y2] == EMPTY) {
            board[x1][y1] = EMPTY;
            board[x2][y2] = turn;
            moves++;
            turn = (turn == BLACK)? WHITE : BLACK;
        }
    }
}

int checkWin() {
    for(int i=0;i<SIZE;i++) {
        if(board[i][0]!= EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= EMPTY) {
            return 1;
        }
        if(board[0][i]!= EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= EMPTY) {
            return 1;
        }
    }
    if(board[0][0]!= EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= EMPTY) {
        return 1;
    }
    if(board[0][2]!= EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= EMPTY) {
        return 1;
    }
    return 0;
}

int checkDraw() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            if(board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    turn = (rand() % 2)? BLACK : WHITE;
    initBoard();
    drawBoard();
    int x, y;
    while(1) {
        printf("Player %c's turn.\n", turn == BLACK? '1' : '2');
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);
        makeMove(x-1, y-1, x-1, y-1);
        drawBoard();
        if(checkWin()) {
            printf("Player %c wins!\n", turn == BLACK? '1' : '2');
            break;
        } else if(checkDraw()) {
            printf("It's a draw.\n");
            break;
        }
        turn = (turn == BLACK)? WHITE : BLACK;
    }
    return 0;
}