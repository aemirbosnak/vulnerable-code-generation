//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} ChessGame;

// Function prototypes
void initBoard(ChessGame* game);
void displayBoard(ChessGame* game);
int isValidMove(ChessGame* game, int fromX, int fromY, int toX, int toY);
void makeMove(ChessGame* game, int fromX, int fromY, int toX, int toY);
void switchPlayer(ChessGame* game);
void aiMove(ChessGame* game);
void getRandomMove(ChessGame* game, int* fromX, int* fromY, int* toX, int* toY);

int main() {
    ChessGame game;
    initBoard(&game);
    
    while (1) {
        displayBoard(&game);

        if (game.currentPlayer == WHITE) {
            int fromX, fromY, toX, toY;
            printf("Enter your move (fromX fromY toX toY): ");
            scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);
            if (isValidMove(&game, fromX, fromY, toX, toY)) {
                makeMove(&game, fromX, fromY, toX, toY);
                switchPlayer(&game);
            } else {
                printf("Invalid move, try again.\n");
            }
        } else {
            aiMove(&game);
            switchPlayer(&game);
        }
    }
    return 0;
}

void initBoard(ChessGame* game) {
    memset(game->board, EMPTY, SIZE * SIZE);
    game->board[0][0] = game->board[0][7] = BLACK; // Rooks
    game->board[0][1] = game->board[0][6] = BLACK; // Knights
    game->board[0][2] = game->board[0][5] = BLACK; // Bishops
    game->board[0][3] = game->board[0][4] = BLACK; // King and Queen
    game->board[7][0] = game->board[7][7] = WHITE; // Rooks
    game->board[7][1] = game->board[7][6] = WHITE; // Knights
    game->board[7][2] = game->board[7][5] = WHITE; // Bishops
    game->board[7][3] = game->board[7][4] = WHITE; // King and Queen
    for (int i = 0; i < SIZE; i++) {
        game->board[1][i] = BLACK; // Black pawns
        game->board[6][i] = WHITE; // White pawns
    }
    game->currentPlayer = WHITE;
}

void displayBoard(ChessGame* game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(ChessGame* game, int fromX, int fromY, int toX, int toY) {
    // Check bounds
    if (fromX < 0 || fromX >= SIZE || fromY < 0 || fromY >= SIZE || 
        toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE) {
        return 0;
    }
    // Check ownership of piece
    if (game->board[fromX][fromY] == EMPTY || 
        (game->board[fromX][fromY] == WHITE && game->currentPlayer == BLACK) || 
        (game->board[fromX][fromY] == BLACK && game->currentPlayer == WHITE)) {
        return 0;
    }
    // Basic rule: Can't move to a square occupied by the same color
    if (game->board[toX][toY] != EMPTY && 
        ((game->board[fromX][fromY] == WHITE && game->board[toX][toY] == WHITE) || 
        (game->board[fromX][fromY] == BLACK && game->board[toX][toY] == BLACK))) {
        return 0;
    }
    // Placeholder for actual move validation logic
    return 1;
}

void makeMove(ChessGame* game, int fromX, int fromY, int toX, int toY) {
    game->board[toX][toY] = game->board[fromX][fromY];
    game->board[fromX][fromY] = EMPTY;
}

void switchPlayer(ChessGame* game) {
    game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
}

void aiMove(ChessGame* game) {
    int fromX, fromY, toX, toY;
    getRandomMove(game, &fromX, &fromY, &toX, &toY);
    if (isValidMove(game, fromX, fromY, toX, toY)) {
        makeMove(game, fromX, fromY, toX, toY);
        printf("AI moved from (%d,%d) to (%d,%d)\n", fromX, fromY, toX, toY);
    }
}

void getRandomMove(ChessGame* game, int* fromX, int* fromY, int* toX, int* toY) {
    srand(time(NULL));
    *fromX = rand() % SIZE;
    *fromY = rand() % SIZE;
    *toX = rand() % SIZE;
    *toY = rand() % SIZE;
}