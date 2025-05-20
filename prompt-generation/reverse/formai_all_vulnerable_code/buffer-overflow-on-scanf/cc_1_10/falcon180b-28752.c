//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

#define N 8
#define M 8
#define EMPTY 0
#define WHITE 1
#define BLACK -1

int board[N][M]; //initialize the board

void initializeBoard() {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(board[i][j] == EMPTY) {
                printf(" ");
            }
            else if(board[i][j] == WHITE) {
                printf("W");
            }
            else {
                printf("B");
            }
        }
        printf("\n");
    }
}

int isValid(int i, int j) {
    if(i>=0 && i<N && j>=0 && j<M) {
        return 1;
    }
    else {
        return 0;
    }
}

void move(int fromRow, int fromCol, int toRow, int toCol) {
    int piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;
    board[toRow][toCol] = piece;
}

int main() {
    initializeBoard();
    int i, j;
    printf("Enter the coordinates of the piece to move: ");
    scanf("%d%d", &i, &j);
    while(!isValid(i, j)) {
        printf("Invalid coordinates. Enter again: ");
        scanf("%d%d", &i, &j);
    }
    printf("Enter the coordinates of the destination: ");
    scanf("%d%d", &i, &j);
    while(!isValid(i, j)) {
        printf("Invalid coordinates. Enter again: ");
        scanf("%d%d", &i, &j);
    }
    if(board[i][j] == WHITE) {
        move(i, j, i, j-1); //move the piece down
    }
    else if(board[i][j] == BLACK) {
        move(i, j, i, j+1); //move the piece up
    }
    printBoard();
    return 0;
}