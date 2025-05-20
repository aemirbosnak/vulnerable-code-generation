//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

typedef enum { EMPTY = ' ', PLAYER_X = 'X', PLAYER_O = 'O' } Piece;
typedef struct {
    Piece board[SIZE][SIZE];
} GameState;

void initializeBoard(GameState *game) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            game->board[i][j] = EMPTY;
}

void printBoard(GameState *game) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", game->board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----\n");
    }
}

int checkWinner(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2] && game->board[i][0] != EMPTY)
            return game->board[i][0];
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i] && game->board[0][i] != EMPTY)
            return game->board[0][i];
    }
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2] && game->board[0][0] != EMPTY)
        return game->board[0][0];
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0] && game->board[0][2] != EMPTY)
        return game->board[0][2];
    return EMPTY;
}

int isBoardFull(GameState *game) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (game->board[i][j] == EMPTY) return 0;
    return 1;
}

void playerMove(GameState *game) {
    int x, y;
    while (1) {
        printf("Enter your move (row and column 0-2, space separated): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && game->board[x][y] == EMPTY) {
            game->board[x][y] = PLAYER_X;
            break;
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}

void aiMove(GameState *game) {
    int x, y;
    srand(time(NULL));
    while (1) {
        x = rand() % SIZE;
        y = rand() % SIZE;
        if (game->board[x][y] == EMPTY) {
            game->board[x][y] = PLAYER_O;
            break;
        }
    }
}

int main() {
    GameState game;
    initializeBoard(&game);
    int winner = EMPTY;

    while (winner == EMPTY && !isBoardFull(&game)) {
        printBoard(&game);
        playerMove(&game);
        winner = checkWinner(&game);
        if (winner != EMPTY) break;
        if (!isBoardFull(&game)) {
            aiMove(&game);
            winner = checkWinner(&game);
        }
    }
    
    printBoard(&game);
    if (winner == PLAYER_X) {
        printf("Congratulations! You win!\n");
    } else if (winner == PLAYER_O) {
        printf("AI wins! Better luck next time.\n");
    } else {
        printf("It's a draw.\n");
    }
    return 0;
}