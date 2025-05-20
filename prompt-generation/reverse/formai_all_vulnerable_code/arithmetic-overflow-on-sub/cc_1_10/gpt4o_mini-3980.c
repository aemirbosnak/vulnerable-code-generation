//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, RED, BLACK, RED_KING, BLACK_KING } Piece;

char pieceToChar(Piece piece) {
    switch (piece) {
        case RED: return 'R';
        case BLACK: return 'B';
        case RED_KING: return 'r';
        case BLACK_KING: return 'b';
        default: return '.';
    }
}

typedef struct {
    Piece board[SIZE][SIZE];
    int currentTurn; // 0 for Red, 1 for Black
} Game;

void initializeGame(Game* game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    for (int j = 0; j < SIZE; j += 2) {
        game->board[0][j] = BLACK;
        game->board[1][j + 1] = BLACK;
        game->board[2][j] = BLACK;
        game->board[5][j + 1] = RED;
        game->board[6][j] = RED;
        game->board[7][j + 1] = RED;
    }
    game->currentTurn = 0; // Red starts
}

void displayBoard(Game* game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", pieceToChar(game->board[i][j]));
        }
        printf("\n");
    }
    printf("Current turn: %s\n", game->currentTurn == 0 ? "Red" : "Black");
}

int movePiece(Game* game, char startCol, int startRow, char endCol, int endRow) {
    int startX = SIZE - startRow - 1; // Convert to board indexing
    int startY = startCol - 'a';
    int endX = SIZE - endRow - 1;
    int endY = endCol - 'a';

    Piece movingPiece = game->board[startX][startY];
    if (movingPiece == EMPTY || (game->currentTurn == 0 && movingPiece != RED && movingPiece != RED_KING) ||
        (game->currentTurn == 1 && movingPiece != BLACK && movingPiece != BLACK_KING)) {
        printf("Invalid move: No piece at starting position.\n");
        return 0;
    }
    
    // Basic movement logic (no jumping or capturing for simplicity)
    if (abs(endX - startX) == 1 && abs(endY - startY) == 1 && game->board[endX][endY] == EMPTY) {
        game->board[endX][endY] = movingPiece;
        game->board[startX][startY] = EMPTY;
        if (movingPiece == RED && endX == 0) {
            game->board[endX][endY] = RED_KING;
        } else if (movingPiece == BLACK && endX == SIZE - 1) {
            game->board[endX][endY] = BLACK_KING;
        }
        game->currentTurn = !game->currentTurn; // Switch turn
        return 1;
    }
    
    printf("Invalid move: Pieces can only move diagonally to an empty square.\n");
    return 0;
}

int main() {
    Game game;
    initializeGame(&game);

    char startCol, endCol;
    int startRow, endRow;

    while (1) {
        displayBoard(&game);
        printf("Enter your move (e.g., 'a3 b4' or 'quit' to exit): ");
        char command[100];
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "%c%d %c%d", &startCol, &startRow, &endCol, &endRow) == 4) {
            if (movePiece(&game, startCol, startRow, endCol, endRow) == 0) {
                printf("Move failed. Try again.\n");
            }
        } else if (strcmp(command, "quit\n") == 0) {
            printf("Exiting game. Thanks for playing!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}