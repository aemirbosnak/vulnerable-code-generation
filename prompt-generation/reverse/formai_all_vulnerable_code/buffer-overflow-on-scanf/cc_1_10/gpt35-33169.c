//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X' // Player 1
#define PLAYER_O 'O' // Player 2
#define EMPTY_SPACE ' '

// Structure for storing a move made by a player
typedef struct {
    int row;
    int col;
} Move;

// Structure for storing the current state of the game
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
} GameState;

// Function for initializing the game board
void initGame(GameState* gs) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            gs->board[i][j] = EMPTY_SPACE;
        }
    }
    gs->currentPlayer = PLAYER_X;
}

// Function for printing the game board
void printBoard(GameState* gs) {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %c | %c | %c ", gs->board[i][0], gs->board[i][1], gs->board[i][2]);
        if(i < BOARD_SIZE-1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// Function for checking if a move is valid
bool isValidMove(GameState* gs, Move* move) {
    if(move->row < 0 || move->row >= BOARD_SIZE || move->col < 0 || move->col >= BOARD_SIZE) {
        // Move is out of bounds
        return false;
    }
    if(gs->board[move->row][move->col] != EMPTY_SPACE) {
        // Space is already occupied
        return false;
    }
    return true;
}

// Function for getting the next move from the player
void getNextMove(GameState* gs, Move* move) {
    printf("Player %c's turn. Enter row and column to place your mark (e.g. 1 2): ", gs->currentPlayer);
    scanf("%d %d", &move->row, &move->col);
}

// Function for switching the current player
void switchPlayer(GameState* gs) {
    if(gs->currentPlayer == PLAYER_X) {
        gs->currentPlayer = PLAYER_O;
    } else {
        gs->currentPlayer = PLAYER_X;
    }
}

// Function for getting the opposite player
char getOpponent(GameState* gs) {
    if(gs->currentPlayer == PLAYER_X) {
        return PLAYER_O;
    } else {
        return PLAYER_X;
    }
}

// Function for checking if a player has won the game
bool hasWon(GameState* gs, char player) {
    // Check rows
    for(int i=0; i<BOARD_SIZE; i++) {
        if(gs->board[i][0] == player && gs->board[i][1] == player && gs->board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for(int i=0; i<BOARD_SIZE; i++) {
        if(gs->board[0][i] == player && gs->board[1][i] == player && gs->board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if(gs->board[0][0] == player && gs->board[1][1] == player && gs->board[2][2] == player) {
        return true;
    }
    if(gs->board[0][2] == player && gs->board[1][1] == player && gs->board[2][0] == player) {
        return true;
    }
    return false;
}

// Function for checking if the game is over
bool isGameOver(GameState* gs) {
    // Check if board is full
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(gs->board[i][j] == EMPTY_SPACE) {
                return false;
            }
        }
    }
    // Check if a player has won
    if(hasWon(gs, PLAYER_X) || hasWon(gs, PLAYER_O)) {
        return true;
    }
    // No empty spaces and no winner => tie game
    return true;
}

// Function for making a move on the board
void makeMove(GameState* gs, Move* move) {
    gs->board[move->row][move->col] = gs->currentPlayer;
}

// Function for simulating a game
void simulateGame() {
    GameState gs;
    initGame(&gs);
    Move move;
    while(!isGameOver(&gs)) {
        printBoard(&gs);
        getNextMove(&gs, &move);
        while(!isValidMove(&gs, &move)) {
            printf("Invalid move. Please try again.\n");
            getNextMove(&gs, &move);
        }
        makeMove(&gs, &move);
        if(hasWon(&gs, gs.currentPlayer)) {
            printf("\nPlayer %c has won the game!\n", gs.currentPlayer);
            return;
        }
        switchPlayer(&gs);
    }
    printBoard(&gs);
    printf("\nGame ended in a tie!\n");
}

int main() {
    simulateGame();
    return 0;
}