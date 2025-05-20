//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} Game;

void initializeGame(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
            if (i < 3 && (i + j) % 2 == 1) {
                game->board[i][j] = RED;
            } else if (i > 4 && (i + j) % 2 == 1) {
                game->board[i][j] = BLACK;
            }
        }
    }
}

void displayBoard(Game *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == RED) {
                printf("R ");
            } else if (game->board[i][j] == BLACK) {
                printf("B ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, Piece player, Game *game) {
    if (endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE || 
        game->board[endRow][endCol] != EMPTY) {
        return 0;
    }
    
    int direction = (player == RED) ? 1 : -1;
    if (endRow - startRow == direction) {
        return (abs(endCol - startCol) == 1);
    }
    
    if (endRow - startRow == 2 * direction) {
        int midRow = startRow + direction;
        int midCol = startCol + (endCol - startCol) / 2;
        if (game->board[midRow][midCol] != EMPTY && game->board[midRow][midCol] != player) {
            return 1; // valid capture
        }
    }

    return 0;
}

void makeMove(int startRow, int startCol, int endRow, int endCol, Game *game) {
    Piece player = game->board[startRow][startCol];
    game->board[endRow][endCol] = player;
    game->board[startRow][startCol] = EMPTY;

    if (abs(endRow - startRow) == 2) {
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        game->board[midRow][midCol] = EMPTY; // capture
    }
}

int main() {
    Game game;
    initializeGame(&game);

    Piece currentPlayer = RED;
    while (1) {
        displayBoard(&game);
        char startColChar, endColChar;
        int startRow, endRow;
        
        printf("Player %s's turn. Enter move (ex: a3 b4): ", currentPlayer == RED ? "RED" : "BLACK");
        if (scanf(" %c%d %c%d", &startColChar, &startRow, &endColChar, &endRow) != 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        int startCol = startColChar - 'a';
        int endCol = endColChar - 'a';
        startRow -= 1; // convert to 0-index
        endRow -= 1;   // convert to 0-index

        if (currentPlayer != game.board[startRow][startCol]) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (isValidMove(startRow, startCol, endRow, endCol, currentPlayer, &game)) {
            makeMove(startRow, startCol, endRow, endCol, &game);
            currentPlayer = (currentPlayer == RED) ? BLACK : RED;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}