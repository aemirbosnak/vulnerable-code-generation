//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
} ChessGame;

void initialize_board(ChessGame *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    game->board[0][0] = game->board[0][7] = WHITE; // Example: Place two white pieces.
    game->board[7][0] = game->board[7][7] = BLACK; // Example: Place two black pieces.
    game->current_player = WHITE;
}

void print_board(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int startRow, int startCol, int endRow, int endCol, const ChessGame *game) {
    // Basic validation for this example (you can expand further)
    if (startRow < 0 || startRow >= BOARD_SIZE || 
        startCol < 0 || startCol >= BOARD_SIZE || 
        endRow < 0 || endRow >= BOARD_SIZE || 
        endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }
    
    char startPiece = game->board[startRow][startCol];
    char endPiece = game->board[endRow][endCol];

    if (startPiece == EMPTY || startPiece != game->current_player) {
        return 0;
    }

    // Example logic: Can only move to empty square or capture opponent's piece
    if (endPiece != EMPTY && endPiece == game->current_player) {
        return 0;
    }
    return 1;
}

void make_move(ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    if (is_valid_move(startRow, startCol, endRow, endCol, game)) {
        game->board[endRow][endCol] = game->board[startRow][startCol];
        game->board[startRow][startCol] = EMPTY;
        game->current_player = (game->current_player == WHITE) ? BLACK : WHITE;
    } else {
        printf("Invalid move!\n");
    }
}

void get_move_input(int *startRow, int *startCol, int *endRow, int *endCol) {
    char startPos[3], endPos[3];
    printf("Enter move (e.g. e2 e4): ");
    scanf("%s %s", startPos, endPos);

    *startCol = startPos[0] - 'a';
    *startRow = 8 - (startPos[1] - '0');
    *endCol = endPos[0] - 'a';
    *endRow = 8 - (endPos[1] - '0');
}

int main() {
    ChessGame game;
    initialize_board(&game);

    while (1) {
        print_board(&game);
        int startRow, startCol, endRow, endCol;
        get_move_input(&startRow, &startCol, &endRow, &endCol);
        make_move(&game, startRow, startCol, endRow, endCol);
    }

    return 0;
}