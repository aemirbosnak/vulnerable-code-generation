//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 4
#define COL 4

void initBoard(char board[ROW][COL]);
void printBoard(char board[ROW][COL]);
int checkWin(char board[ROW][COL]);
void flipCard(char board[ROW][COL], int row, int col);

int main() {
    srand(time(NULL));
    char board[ROW][COL];
    initBoard(board);
    int player = 1;
    int moves = 0;
    while(1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn. Enter row and column: ", player);
        scanf("%d%d", &moves);
        if(board[moves/ROW][moves%COL]!= '*') {
            flipCard(board, moves/ROW, moves%COL);
            if(checkWin(board)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
            player =!player;
        } else {
            printf("\nInvalid move. Try again.\n");
        }
        moves++;
    }
    return 0;
}

void initBoard(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }
    if(board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }
    return 0;
}

void flipCard(char board[ROW][COL], int row, int col) {
    if(board[row][col] == '*') {
        board[row][col] = (rand() % 2)? 'X' : 'O';
    }
}