//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Cell;

typedef struct {
    Cell board[SIZE][SIZE];
} Game;

void initializeGame(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 != j % 2) {
                if (i < 3) game->board[i][j] = PLAYER2;
                else if (i > 4) game->board[i][j] = PLAYER1;
                else game->board[i][j] = EMPTY;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(const Game *game) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            switch (game->board[i][j]) {
                case EMPTY: printf(". "); break;
                case PLAYER1: printf("O "); break;
                case PLAYER2: printf("X "); break;
            }
        }
        printf("\n");
    }
}

int isValidMove(Game *game, int startX, int startY, int endX, int endY, Cell player) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) return 0;
    if (game->board[endX][endY] != EMPTY) return 0;

    int direction = (player == PLAYER1) ? -1 : 1;

    // Check for single square move
    if (endX == startX + direction && (endY == startY + 1 || endY == startY - 1))
        return 1;

    // Check for jump
    if (endX == startX + 2 * direction && (endY == startY + 2 || endY == startY - 2)) {
        int jumpedX = startX + direction;
        int jumpedY = (endY > startY) ? startY + 1 : startY - 1;
        if (game->board[jumpedX][jumpedY] != EMPTY && game->board[jumpedX][jumpedY] != player)
            return 1;
    }

    return 0;
}

void makeMove(Game *game, int startX, int startY, int endX, int endY) {
    Cell player = game->board[startX][startY];
    game->board[endX][endY] = player;
    game->board[startX][startY] = EMPTY;

    // Check for jump and remove the opponent's piece
    if (abs(endX - startX) == 2) {
        int jumpedX = (startX + endX) / 2;
        int jumpedY = (startY + endY) / 2;
        game->board[jumpedX][jumpedY] = EMPTY;
    }
}

void playGame() {
    Game game;
    initializeGame(&game);
    Cell currentPlayer = PLAYER1;
    int startX, startY, endX, endY;

    while (1) {
        printBoard(&game);
        
        printf("Player %d's turn (format: startX startY endX endY): ", currentPlayer == PLAYER1 ? 1 : 2);
        if (scanf("%d %d %d %d", &startX, &startY, &endX, &endY) != 4) {
            printf("Invalid input. Please enter four integers.\n");
            while (getchar() != '\n');  // Clear the buffer
            continue;
        }

        if (game.board[startX][startY] != currentPlayer) {
            printf("Invalid move: Not your piece!\n");
            continue;
        }

        if (isValidMove(&game, startX, startY, endX, endY, currentPlayer)) {
            makeMove(&game, startX, startY, endX, endY);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}