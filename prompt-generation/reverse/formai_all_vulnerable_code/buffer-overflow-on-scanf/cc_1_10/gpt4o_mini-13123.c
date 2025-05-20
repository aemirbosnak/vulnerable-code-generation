//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

typedef enum { EMPTY, PLAYER_X, PLAYER_O } Cell;
typedef struct {
    Cell board[SIZE][SIZE];
    Cell currentPlayer;
} GameState;

void initializeGame(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    game->currentPlayer = PLAYER_X;
}

void printBoard(GameState *game) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (game->board[i][j]) {
                case PLAYER_X: printf(" X "); break;
                case PLAYER_O: printf(" O "); break;
                default: printf(" . ");
            }
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----------\n");
    }
    printf("\n");
}

bool isWinningMove(GameState *game, int row, int col) {
    Cell player = game->currentPlayer;
    
    // Check row
    if (game->board[row][0] == player && game->board[row][1] == player && game->board[row][2] == player)
        return true;
    
    // Check column
    if (game->board[0][col] == player && game->board[1][col] == player && game->board[2][col] == player)
        return true;
    
    // Check diagonals
    if (row == col) {
        if (game->board[0][0] == player && game->board[1][1] == player && game->board[2][2] == player)
            return true;
    }
    
    if (row + col == SIZE - 1) {
        if (game->board[0][2] == player && game->board[1][1] == player && game->board[2][0] == player)
            return true;
    }
    
    return false;
}

bool isBoardFull(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

void switchPlayer(GameState *game) {
    game->currentPlayer = (game->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void playerMove(GameState *game) {
    int row, col;
    while (true) {
        printf("Player %c, enter your move (row and column): ", (game->currentPlayer == PLAYER_X) ? 'X' : 'O');
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && game->board[row][col] == EMPTY) {
            game->board[row][col] = game->currentPlayer;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(GameState *game) {
    // Simple AI: Random Move
    int row, col;
    while (true) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (game->board[row][col] == EMPTY) {
            game->board[row][col] = game->currentPlayer;
            printf("AI Player %c played at %d %d\n", (game->currentPlayer == PLAYER_X) ? 'X' : 'O', row, col);
            break;
        }
    }
}

int main() {
    GameState game;
    initializeGame(&game);
    
    while (true) {
        printBoard(&game);
        
        if (game.currentPlayer == PLAYER_X) {
            playerMove(&game);
        } else {
            aiMove(&game);
        }
        
        if (isWinningMove(&game, (game.currentPlayer == PLAYER_X) ? 0 : 1, (game.currentPlayer == PLAYER_X) ? 0 : 1)) {
            printBoard(&game);
            printf("Player %c wins!\n", (game.currentPlayer == PLAYER_X) ? 'X' : 'O');
            break;
        }
        
        if (isBoardFull(&game)) {
            printBoard(&game);
            printf("It's a draw!\n");
            break;
        }
        
        switchPlayer(&game);
    }
    
    return 0;
}