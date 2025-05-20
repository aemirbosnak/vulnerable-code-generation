//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY ' '
#define PLAYER1 '1'
#define PLAYER2 '2'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} Game;

void initializeBoard(Game *game) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if ((r + c) % 2 != 0) {
                if (r < 3)
                    game->board[r][c] = BLACK;
                else if (r > 4)
                    game->board[r][c] = WHITE;
                else
                    game->board[r][c] = EMPTY;
            } else {
                game->board[r][c] = EMPTY;
            }
        }
    }
}

void printBoard(Game *game) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int r = 0; r < SIZE; r++) {
        printf("%d ", r);
        for (int c = 0; c < SIZE; c++) {
            printf("%c ", game->board[r][c]);
        }
        printf("\n");
    }
}

int isMoveValid(Game *game, int fromRow, int fromCol, int toRow, int toCol) {
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE)
        return 0; // Out of bounds

    char piece = game->board[fromRow][fromCol];
    char target = game->board[toRow][toCol];

    if (piece == EMPTY || target != EMPTY)
        return 0; // No piece to move or target isn't empty

    int direction = (game->currentPlayer == PLAYER1) ? -1 : 1;

    // Regular forward moves
    if (toRow == fromRow + direction && (toCol == fromCol + 1 || toCol == fromCol - 1))
        return 1;

    // Capture moves
    if (toRow == fromRow + 2 * direction && (toCol == fromCol + 2 || toCol == fromCol - 2)) {
        int midRow = fromRow + direction;
        int midCol = (fromCol + toCol) / 2;
        if (game->board[midRow][midCol] != EMPTY && game->board[midRow][midCol] != piece)
            return 1; // Valid capture
    }

    return 0;
}

void makeMove(Game *game, int fromRow, int fromCol, int toRow, int toCol) {
    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = EMPTY;

    // Capture logic
    if (abs(toRow - fromRow) == 2) {
        int midRow = (fromRow + toRow) / 2;
        int midCol = (fromCol + toCol) / 2;
        game->board[midRow][midCol] = EMPTY; // Remove the captured piece
    }

    // Switch players
    game->currentPlayer = (game->currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
}

int main() {
    Game game;
    game.currentPlayer = PLAYER1;
    initializeBoard(&game);
    
    int fromRow, fromCol, toRow, toCol;

    while (1) {
        printBoard(&game);
        printf("Player %s's turn. Enter your move (fromRow fromCol toRow toCol): ", 
               (game.currentPlayer == PLAYER1) ? "1 (W)" : "2 (B)");
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

        if (isMoveValid(&game, fromRow, fromCol, toRow, toCol)) {
            makeMove(&game, fromRow, fromCol, toRow, toCol);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}