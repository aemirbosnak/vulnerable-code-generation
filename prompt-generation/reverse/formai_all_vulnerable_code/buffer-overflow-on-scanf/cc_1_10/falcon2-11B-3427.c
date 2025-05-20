//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char color;
    Point position;
} Piece;

Piece blackPieces[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
Piece whitePieces[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int blackScore, whiteScore;

int isValidPosition(int x, int y) {
    return x >= 0 && y >= 0 && x < MAX_BOARD_SIZE && y < MAX_BOARD_SIZE;
}

void printBoard(void) {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (i == 0 || i == MAX_BOARD_SIZE - 1 || j == 0 || j == MAX_BOARD_SIZE - 1)
                printf("%2d ", i * MAX_BOARD_SIZE + j + 1);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void movePiece(int x, int y, int newX, int newY, char color) {
    if (!isValidPosition(x, y) ||!isValidPosition(newX, newY)) {
        printf("Invalid move.\n");
        return;
    }
    if (color == 'B') {
        blackPieces[x][y].color = 'W';
        blackPieces[newX][newY].color = 'B';
        blackScore += 1;
    } else {
        whitePieces[x][y].color = 'W';
        whitePieces[newX][newY].color = 'B';
        whiteScore += 1;
    }
    printBoard();
}

int main() {
    int x, y, newX, newY;
    char color;

    printf("Welcome to Checkers!\n");
    printf("Enter a valid move: ");
    scanf("%d %d %d %d %c", &x, &y, &newX, &newY, &color);
    if (isValidPosition(x, y) && isValidPosition(newX, newY) && (color == 'B' || color == 'W')) {
        movePiece(x, y, newX, newY, color);
    } else {
        printf("Invalid move.\n");
    }
    printf("Black score: %d\n", blackScore);
    printf("White score: %d\n", whiteScore);
    return 0;
}