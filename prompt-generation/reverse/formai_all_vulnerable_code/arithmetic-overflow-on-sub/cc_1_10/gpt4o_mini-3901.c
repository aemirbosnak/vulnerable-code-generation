//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} Game;

void initializeGame(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                game->board[i][j] = PLAYER1; // Player 1 pieces
            } else if ((i + j) % 2 == 1 && i > 4) {
                game->board[i][j] = PLAYER2; // Player 2 pieces
            } else {
                game->board[i][j] = EMPTY; // Empty square
            }
        }
    }
}

void displayBoard(const Game *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (game->board[i][j]) {
                case EMPTY: printf(". "); break;
                case PLAYER1: printf("X "); break;
                case PLAYER2: printf("O "); break;
            }
        }
        printf("\n");
    }
}

int isMoveValid(Game *game, int fromX, int fromY, int toX, int toY, Piece player) {
    if (toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE)
        return 0; // Move out of bounds
    if (game->board[toX][toY] != EMPTY)
        return 0; // Destination not empty

    int direction = (player == PLAYER1) ? 1 : -1;
    if (toX == fromX + direction && (toY == fromY + 1 || toY == fromY - 1))
        return 1; // Simple move

    if (toX == fromX + 2 * direction && (toY == fromY + 2 || toY == fromY - 2)) {
        int midX = fromX + direction;
        int midY = (fromY + toY) / 2;
        if (game->board[midX][midY] != EMPTY && game->board[midX][midY] != player)
            return 1; // Jump move
    }

    return 0;
}

void makeMove(Game *game, int fromX, int fromY, int toX, int toY) {
    Piece player = game->board[fromX][fromY];
    game->board[toX][toY] = player; // Move piece
    game->board[fromX][fromY] = EMPTY; // Empty previous position

    // Check if it's a jump and remove the jumped piece
    if (abs(toX - fromX) == 2) {
        int midX = (fromX + toX) / 2;
        int midY = (fromY + toY) / 2;
        game->board[midX][midY] = EMPTY; // Remove the jumped piece
    }
}

int main() {
    Game game;
    initializeGame(&game);
    displayBoard(&game);

    int fromX, fromY, toX, toY;
    Piece currentPlayer = PLAYER1;

    while (1) {
        char fromCol, toCol;
        printf("Player %d's turn (Enter move: fromRow fromCol toRow toCol): ", (currentPlayer == PLAYER1) ? 1 : 2);
        scanf("%d %c %d %c", &fromX, &fromCol, &toX, &toCol);
        
        // Convert input
        fromX--;
        fromY = fromCol - 'A';
        toX--;
        toY = toCol - 'A';

        // Validate and make move
        if (isMoveValid(&game, fromX, fromY, toX, toY, currentPlayer)) {
            makeMove(&game, fromX, fromY, toX, toY);
            displayBoard(&game);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch players
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}