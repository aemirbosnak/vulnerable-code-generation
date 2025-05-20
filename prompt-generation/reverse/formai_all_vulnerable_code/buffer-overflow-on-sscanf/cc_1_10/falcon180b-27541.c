//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

typedef enum {
    WHITE,
    BLACK,
    EMPTY
} PieceColor;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    PieceColor color;
    char symbol;
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].color = EMPTY;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][0].color = WHITE;
        board[i][BOARD_SIZE - 1].color = BLACK;
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        board[0][j].color = BLACK;
        board[BOARD_SIZE - 1][j].color = WHITE;
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();

    while (1) {
        printf("White's turn.\n");
        printBoard();

        char input[100];
        scanf("%s", input);

        int fromX, fromY, toX, toY;
        PieceColor color;
        if (sscanf(input, "move %c %d %d to %d %d", &color, &fromX, &fromY, &toX, &toY) == 5) {
            if (board[fromX][fromY].color == color && board[toX][toY].color == EMPTY) {
                board[toX][toY].color = color;
                board[fromX][fromY].color = EMPTY;
            }
        }
    }

    return 0;
}