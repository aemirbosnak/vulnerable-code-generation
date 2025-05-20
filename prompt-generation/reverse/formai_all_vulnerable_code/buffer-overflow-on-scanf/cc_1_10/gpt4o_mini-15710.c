//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} CheckersGame;

void initializeBoard(CheckersGame* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    game->board[i][j] = 'b'; // black pieces
                } else if (i > 4) {
                    game->board[i][j] = 'r'; // red pieces
                } else {
                    game->board[i][j] = ' '; // empty
                }
            } else {
                game->board[i][j] = ' '; // empty squares
            }
        }
    }
}

void printBoard(CheckersGame* game) {
    printf("  A B C D E F G H\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", game->board[i][j]);
        }
        printf("\n +----------------+\n");
    }
}

int isValidMove(CheckersGame* game, int startRow, int startCol, int endRow, int endCol, char player) {
    // Check if the destination square is empty
    if (game->board[endRow][endCol] != ' ') return 0;

    // Check if the move is a valid diagonal move
    if (abs(endRow - startRow) == 1 && abs(endCol - startCol) == 1) {
        return 1; // Regular move
    } else if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2) {
        // Check if there is an opponent's piece to capture
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        if (game->board[midRow][midCol] != ' ' && game->board[midRow][midCol] != player) {
            return 1; // Capture move
        }
    }

    return 0; // Invalid move
}

void makeMove(CheckersGame* game, int startRow, int startCol, int endRow, int endCol) {
    game->board[endRow][endCol] = game->board[startRow][startCol];
    game->board[startRow][startCol] = ' ';
    
    // Check if a capture happened
    if (abs(endRow - startRow) == 2) {
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        game->board[midRow][midCol] = ' '; // Remove captured piece
    }
}

int main() {
    CheckersGame game;
    initializeBoard(&game);
    printBoard(&game);

    char currentPlayer = 'r';
    int startRow, startCol, endRow, endCol;

    while (1) {
        printf("Player %c, enter your move (e.g. A3 B4): ", currentPlayer);
        char start[3], end[3];
        if (scanf("%s %s", start, end) != 2) {
            printf("Invalid input, please try again.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        startRow = start[1] - '1';
        startCol = start[0] - 'A';
        endRow = end[1] - '1';
        endCol = end[0] - 'A';

        if (startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE ||
            endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE ||
            game.board[startRow][startCol] != currentPlayer || 
            !isValidMove(&game, startRow, startCol, endRow, endCol, currentPlayer)) {
            printf("Invalid move, try again!\n");
            continue;
        }

        makeMove(&game, startRow, startCol, endRow, endCol);
        printBoard(&game);

        // Switch player
        currentPlayer = (currentPlayer == 'r') ? 'b' : 'r';
    }

    return 0;
}