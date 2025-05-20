//GEMINI-pro DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 5
#define NUM_PLAYERS 2
#define MAX_MOVES 25

// Types
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char symbol;
    int score;
} Player;

// Function Prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int checkWinner(char board[BOARD_SIZE][BOARD_SIZE]);
Position getMove(Player player, char board[BOARD_SIZE][BOARD_SIZE]);

// Main Function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    // Create the players
    Player players[NUM_PLAYERS] = {
        {'X', 0},
        {'O', 0}
    };

    // Play the game
    int moves = 0;
    int currentPlayer = 0;
    while (moves < MAX_MOVES) {
        // Get the current player's move
        Position move = getMove(players[currentPlayer], board);

        // Place the player's symbol on the board
        board[move.x][move.y] = players[currentPlayer].symbol;

        // Print the board
        printBoard(board);

        // Check if the player has won
        int winner = checkWinner(board);
        if (winner != -1) {
            printf("Player %d wins!\n", winner + 1);
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
        moves++;
    }

    // If the game ends in a draw
    if (moves == MAX_MOVES) {
        printf("Draw!\n");
    }

    return 0;
}

// Function Definitions

// Initialize the game board
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if there is a winner
int checkWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
            return i;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
            return i;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
        return 0;
    }

    if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
        return 4;
    }

    // No winner yet
    return -1;
}

// Get the player's move
Position getMove(Player player, char board[BOARD_SIZE][BOARD_SIZE]) {
    Position move;
    int validMove = 0;

    // Get the player's input
    while (!validMove) {
        printf("Player %d, enter your move (row, column): ", player.symbol);
        scanf("%d %d", &move.x, &move.y);

        // Check if the move is valid
        if (move.x < 0 || move.x >= BOARD_SIZE || move.y < 0 || move.y >= BOARD_SIZE || board[move.x][move.y] != ' ') {
            printf("Invalid move. Please try again.\n");
        } else {
            validMove = 1;
        }
    }

    return move;
}