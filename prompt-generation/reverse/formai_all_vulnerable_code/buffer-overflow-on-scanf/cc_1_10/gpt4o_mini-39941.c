//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = RED;
                } else if (i > 4) {
                    board[i][j] = BLACK;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY; 
            }
        }
    }
}

void printBoard() {
    printf("\nThe surreal battlefield of checker souls:\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED) {
                printf(" R ");
            } else if (board[i][j] == BLACK) {
                printf(" B ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int isValidMove(int srcX, int srcY, int destX, int destY, Piece player) {
    if (destX < 0 || destY < 0 || destX >= BOARD_SIZE || destY >= BOARD_SIZE)
        return 0;
    
    if (board[destX][destY] == EMPTY) {
        if (player == RED && (destX == srcX + 1 || destX == srcX + 2) && 
           (destY == srcY - 1 || destY == srcY + 1)) {
            return 1; // Regular move
        }
        if (player == BLACK && (destX == srcX - 1 || destX == srcX - 2) && 
           (destY == srcY - 1 || destY == srcY + 1)) {
            return 1; // Regular move
        }
    }
    return 0;
}

void surrealMove() {
    int srcX, srcY, destX, destY;
    
    printf("In this dimension where time bends: ");
    scanf("%d %d %d %d", &srcX, &srcY, &destX, &destY);
    
    Piece currentPlayer = (srcX + srcY) % 2 == 0 ? BLACK : RED;  
    if (isValidMove(srcX, srcY, destX, destY, currentPlayer)) {
        board[destX][destY] = currentPlayer;
        board[srcX][srcY] = EMPTY;
        printf("Move executed in the cosmic dance.\n\n");
    } else {
        printf("The move is a chimera, not valid in this realm.\n\n");
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    
    while(1) {
        printBoard();
        surrealMove();
        
        // Extra surreal twist—randomly change one piece color after every move
        if (rand() % 10 < 2) {  // 20% chance to incite change
            int posX = rand() % BOARD_SIZE;
            int posY = rand() % BOARD_SIZE;
            if (board[posX][posY] != EMPTY) {
                board[posX][posY] = (board[posX][posY] == RED) ? BLACK : RED;
                printf("A spontaneous metamorphosis occurred at (%d, %d).\n\n", posX, posY);
            }
        }
    }

    return 0;
}