//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define NUM_PIECES 12

typedef struct {
    int x;
    int y;
    char symbol;
} Piece;

void initBoard(Piece board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j].symbol = '-';
        }
    }
}

void printBoard(Piece board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j].symbol);
        }
        printf("\n");
    }
}

int isValidMove(Piece board[SIZE][SIZE], int fromX, int fromY, int toX, int toY, char pieceSymbol) {
    if (fromX < 0 || fromX >= SIZE || fromY < 0 || fromY >= SIZE ||
        toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE) {
        return 0;
    }

    if (board[fromX][fromY].symbol!= pieceSymbol) {
        return 0;
    }

    if (toX == fromX && toY == fromY) {
        return 0;
    }

    if (abs(toX - fromX)!= 1 || abs(toY - fromY)!= 1) {
        return 0;
    }

    if (board[toX][toY].symbol!= '-') {
        return 0;
    }

    return 1;
}

int main() {
    srand(time(NULL));

    Piece board[SIZE][SIZE];
    initBoard(board);

    int player = 1;
    int numMoves = 0;

    while (1) {
        printBoard(board);
        printf("Player %d's turn.\n", player);
        int fromX, fromY, toX, toY;
        scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);

        if (!isValidMove(board, fromX, fromY, toX, toY, (player % 2)? 'X' : 'O')) {
            printf("Invalid move.\n");
            continue;
        }

        board[toX][toY].symbol = (player % 2)? 'X' : 'O';
        board[fromX][fromY].symbol = '-';

        numMoves++;

        if (numMoves == NUM_PIECES) {
            printf("Draw.\n");
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}