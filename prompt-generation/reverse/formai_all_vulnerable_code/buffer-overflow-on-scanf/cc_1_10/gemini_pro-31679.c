//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
enum GameState {
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW
};

// Initialize the game board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void printBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Get the player's move
int getMove(char player) {
    int move;

    do {
        printf("Player %c, enter your move (1-%d): ", player, BOARD_SIZE * BOARD_SIZE);
        scanf("%d", &move);
    } while (move < 1 || move > BOARD_SIZE * BOARD_SIZE || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ');

    return move;
}

// Make a move on the game board
void makeMove(int move, char player) {
    board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = player;
}

// Check if the game is over
enum GameState checkGameState() {
    // Check for a win in a row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for a win in a column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for a win in a diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // Check for a draw
    int numMoves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != ' ') {
                numMoves++;
            }
        }
    }

    if (numMoves == BOARD_SIZE * BOARD_SIZE) {
        return DRAW;
    }

    // The game is still playing
    return PLAYING;
}

// Play the game
void playGame() {
    // Initialize the game board
    initBoard();

    // Print the game board
    printBoard();

    // Get the first player's move
    int move = getMove(PLAYER1);

    // Make the move on the game board
    makeMove(move, PLAYER1);

    // Check if the game is over
    enum GameState state = checkGameState();

    // While the game is still playing
    while (state == PLAYING) {
        // Print the game board
        printBoard();

        // Get the second player's move
        move = getMove(PLAYER2);

        // Make the move on the game board
        makeMove(move, PLAYER2);

        // Check if the game is over
        state = checkGameState();
    }

    // Print the game board
    printBoard();

    // Print the game result
    switch (state) {
        case PLAYER1_WIN:
            printf("Player 1 wins!");
            break;
        case PLAYER2_WIN:
            printf("Player 2 wins!");
            break;
        case DRAW:
            printf("It's a draw!");
            break;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    playGame();

    return 0;
}