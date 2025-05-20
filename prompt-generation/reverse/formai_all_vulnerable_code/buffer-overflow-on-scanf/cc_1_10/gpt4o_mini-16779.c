//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
    char turn;
} Game;

void initBoard(Game *game);
void printBoard(Game *game);
bool isValidMove(Game *game, int startX, int startY, int endX, int endY);
void movePiece(Game *game, int startX, int startY, int endX, int endY);
bool isBishopMove(int startX, int startY, int endX, int endY);
bool isRookMove(int startX, int startY, int endX, int endY);
bool isKnightMove(int startX, int startY, int endX, int endY);
void switchTurn(Game *game);

int main() {
    Game game;
    initBoard(&game);
    
    while (true) {
        printBoard(&game);
        printf("%c's turn. Enter move (ex: e2 e4): ", game.turn);
        char start[3], end[3];
        scanf("%s %s", start, end);

        int startX = start[0] - 'a';
        int startY = SIZE - (start[1] - '0');
        int endX = end[0] - 'a';
        int endY = SIZE - (end[1] - '0');

        if (isValidMove(&game, startX, startY, endX, endY)) {
            movePiece(&game, startX, startY, endX, endY);
            switchTurn(&game);
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}

void initBoard(Game *game) {
    char initial[] = "rnbqkbnrpppppppp                                PPPPPPPP RNBQKBNR";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            game->board[i][j] = initial[i * SIZE + j];
        }
    }
    game->turn = 'W';
}

void printBoard(Game *game) {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", game->board[i][j] == ' ' ? '.' : game->board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(Game *game, int startX, int startY, int endX, int endY) {
    char piece = game->board[startY][startX];
    if (piece == ' ' || (game->turn == 'W' && piece > 'Z') || (game->turn == 'B' && piece < 'a')) {
        return false;
    }
    if (startX == endX && startY == endY) return false; // No moving to the same spot
    if (game->board[endY][endX] != ' ' && 
        ((game->turn == 'W' && game->board[endY][endX] > 'Z') || 
         (game->turn == 'B' && game->board[endY][endX] < 'a'))) {
        return false; // Can't capture own piece
    }

    switch (piece) {
        case 'p': return endY == startY - 1 && startX == endX; // Simplified pawn movement
        case 'r': return isRookMove(startX, startY, endX, endY);
        case 'n': return isKnightMove(startX, startY, endX, endY);
        case 'b': return isBishopMove(startX, startY, endX, endY);
        default: return false; // Simplifying remaining pieces
    }
}

void movePiece(Game *game, int startX, int startY, int endX, int endY) {
    game->board[endY][endX] = game->board[startY][startX];
    game->board[startY][startX] = ' ';
}

bool isBishopMove(int startX, int startY, int endX, int endY) {
    return abs(startX - endX) == abs(startY - endY);
}

bool isRookMove(int startX, int startY, int endX, int endY) {
    return startX == endX || startY == endY;
}

bool isKnightMove(int startX, int startY, int endX, int endY) {
    return (abs(startX - endX) == 2 && abs(startY - endY) == 1) || 
           (abs(startX - endX) == 1 && abs(startY - endY) == 2);
}

void switchTurn(Game *game) {
    game->turn = (game->turn == 'W') ? 'B' : 'W';
}