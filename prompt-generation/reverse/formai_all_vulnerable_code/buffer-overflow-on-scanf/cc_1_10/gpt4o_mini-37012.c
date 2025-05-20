//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
} GameState;

void initBoard(GameState *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 1) {
                game->board[i][j] = PLAYER_1;
            } else if (i > 4 && (i + j) % 2 == 1) {
                game->board[i][j] = PLAYER_2;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void displayBoard(GameState *game) {
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  ---------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c| ", game->board[i][j]);
        }
        printf("\n  ---------------\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, GameState *game) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) return 0;
    if (game->board[endX][endY] != EMPTY) return 0;
    
    char player = (game->currentPlayer == 1) ? PLAYER_1 : PLAYER_2;
    
    if (game->board[startX][startY] != player) return 0;
    
    // Normal move
    if (abs(endX - startX) == 1 && abs(endY - startY) == 1) {
        return 1;
    }
    
    // Capture
    if (abs(endX - startX) == 2 && abs(endY - startY) == 2) {
        int capturedX = (startX + endX) / 2;
        int capturedY = (startY + endY) / 2;
        char opponent = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        if (game->board[capturedX][capturedY] == opponent) {
            return 1;
        }
    }
    
    return 0;
}

void makeMove(int startX, int startY, int endX, int endY, GameState *game) {
    char player = (game->currentPlayer == 1) ? PLAYER_1 : PLAYER_2;
    game->board[endX][endY] = player;
    game->board[startX][startY] = EMPTY;
    
    // Capture
    if (abs(endX - startX) == 2 && abs(endY - startY) == 2) {
        int capturedX = (startX + endX) / 2;
        int capturedY = (startY + endY) / 2;
        game->board[capturedX][capturedY] = EMPTY;
    }
}

void switchPlayer(GameState *game) {
    game->currentPlayer = (game->currentPlayer == 1) ? 2 : 1;
}

int main() {
    GameState game;
    game.currentPlayer = 1;
    
    initBoard(&game);
    
    int startX, startY, endX, endY;
    while (1) {
        displayBoard(&game);
        printf("Player %d turn. Enter your move (startX startY endX endY): ", game.currentPlayer);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
        
        if (isValidMove(startX, startY, endX, endY, &game)) {
            makeMove(startX, startY, endX, endY, &game);
            switchPlayer(&game);
        } else {
            printf("Invalid move, try again.\n");
        }

        // Check for win condition (not implemented for simplicity)
    }
    
    return 0;
}