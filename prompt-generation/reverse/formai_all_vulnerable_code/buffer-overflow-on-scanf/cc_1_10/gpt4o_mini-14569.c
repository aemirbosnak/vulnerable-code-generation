//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} Game;

void initializeBoard(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    game->board[0][0] = game->board[0][7] = game->board[7][0] = game->board[7][7] = WHITE; // Rooks
    game->board[0][1] = game->board[0][6] = game->board[7][1] = game->board[7][6] = WHITE; // Knights
    game->board[0][2] = game->board[0][5] = game->board[7][2] = game->board[7][5] = WHITE; // Bishops
    game->board[0][3] = game->board[0][4] = BLACK; // Kings and Queens
    game->board[7][3] = game->board[7][4] = BLACK; // Kings and Queens
    for (int j = 0; j < SIZE; j++) {
        game->board[1][j] = WHITE; // White Pawns
        game->board[6][j] = BLACK; // Black Pawns
    }
    game->currentPlayer = WHITE;
}

void printBoard(Game *game) {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isMoveValid(Game *game, int srcRow, int srcCol, int destRow, int destCol) {
    // Simple validity checker for straight moves (not a full chess engine)
    if (srcRow < 0 || srcRow >= SIZE || srcCol < 0 || srcCol >= SIZE ||
        destRow < 0 || destRow >= SIZE || destCol < 0 || destCol >= SIZE ||
        game->board[srcRow][srcCol] == EMPTY ||
        game->board[destRow][destCol] != EMPTY && 
        game->board[destRow][destCol] == game->currentPlayer) {
        return 0;
    }
    return 1; // Accepting move for simplicity
}

void movePiece(Game *game, int srcRow, int srcCol, int destRow, int destCol) {
    if (isMoveValid(game, srcRow, srcCol, destRow, destCol)) {
        game->board[destRow][destCol] = game->board[srcRow][srcCol];
        game->board[srcRow][srcCol] = EMPTY;
        game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
    } else {
        printf("Invalid move from %c%d to %c%d!\n", srcCol + 'A', SIZE - srcRow, destCol + 'A', SIZE - destRow);
    }
}

void promptMove(Game *game) {
    char src[3], dest[3];
    printf("%c's turn. Enter your move (e.g., A2 A3): ", game->currentPlayer);
    scanf("%s %s", src, dest);
    
    int srcRow = SIZE - (src[1] - '0');
    int srcCol = src[0] - 'A';
    int destRow = SIZE - (dest[1] - '0');
    int destCol = dest[0] - 'A';
    
    movePiece(game, srcRow, srcCol, destRow, destCol);
}

int main() {
    Game game;
    initializeBoard(&game);
    while (1) {
        printBoard(&game);
        promptMove(&game);
    }
    return 0;
}