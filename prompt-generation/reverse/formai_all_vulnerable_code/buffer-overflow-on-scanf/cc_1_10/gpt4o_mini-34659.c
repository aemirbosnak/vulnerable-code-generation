//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} CheckersGame;

void initializeBoard(CheckersGame *game) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if ((row + col) % 2 == 1) {
                if (row < 3) {
                    game->board[row][col] = 'B'; // Black pieces
                } else if (row > 4) {
                    game->board[row][col] = 'W'; // White pieces
                } else {
                    game->board[row][col] = ' '; // Empty
                }
            } else {
                game->board[row][col] = ' '; // Empty
            }
        }
    }
}

void printBoard(const CheckersGame *game) {
    printf("   A B C D E F G H\n");
    printf("  -----------------\n");
    for (int row = 0; row < SIZE; row++) {
        printf("%d| ", row + 1);
        for (int col = 0; col < SIZE; col++) {
            printf("%c ", game->board[row][col]);
        }
        printf("\n");
    }
    printf("  -----------------\n");
}

bool movePiece(CheckersGame *game, char fromCol, int fromRow, char toCol, int toRow) {
    int fCol = fromCol - 'A';
    int fRow = fromRow - 1;
    int tCol = toCol - 'A';
    int tRow = toRow - 1;

    if (fRow >= SIZE || fRow < 0 || fCol >= SIZE || fCol < 0 || tRow >= SIZE || tRow < 0 || tCol >= SIZE || tCol < 0) {
        printf("The void seemed too far to traverse...\n");
        return false;
    }

    if (game->board[fRow][fCol] == ' ' || game->board[tRow][tCol] != ' ') {
        printf("Ah, the piece is a ghost in this realm...\n");
        return false;
    }

    // A simple rule for moving: move diagonally and only one step
    if ((tRow == fRow + 1 || tRow == fRow - 1) && (tCol == fCol + 1 || tCol == fCol - 1)) {
        game->board[tRow][tCol] = game->board[fRow][fCol];
        game->board[fRow][fCol] = ' ';
        return true;
    }

    printf("The stars did not align for this move...\n");
    return false;
}

bool playTurn(CheckersGame *game) {
    char fromCol, toCol;
    int fromRow, toRow;
    
    printf("Choose your ephemeral dancer (e.g., A2 B3): ");
    scanf(" %c%d %c%d", &fromCol, &fromRow, &toCol, &toRow);
    
    return movePiece(game, fromCol, fromRow, toCol, toRow);
}

int main() {
    CheckersGame game;
    initializeBoard(&game);
    
    printf("Welcome to the surreal landscape of Checkers!\n");
    printf("As the pieces move like whispers in the wind...\n");

    while (true) {
        printBoard(&game);
        if (!playTurn(&game)) {
            printf("Let us ponder the mysteries of the universe...\n");
        }
        printf("\nA soft breeze tells us to continue...\n");
    }

    return 0;
}