//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game constants
#define BOARD_SIZE 4
#define NUM_PAIRS 8
#define MAX_TURNS 20
#define SCORE_PER_PAIR 10

// Game state
int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];
int score;
int turns;

// Function prototypes
void initializeGame();
void printBoard();
int getMove();
int checkPair(int x1, int y1, int x2, int y2);
void revealPair(int x1, int y1, int x2, int y2);
void hidePair(int x1, int y1, int x2, int y2);
int checkWin();

// Main game loop
int main() {
    initializeGame();

    while (turns < MAX_TURNS && checkWin() == 0) {
        printBoard();
        int move = getMove();

        int x1 = move / BOARD_SIZE;
        int y1 = move % BOARD_SIZE;

        if (revealed[x1][y1] == 1) {
            printf("You already revealed that tile!\n");
            continue;
        }

        revealed[x1][y1] = 1;

        printBoard();
        int move2 = getMove();

        int x2 = move2 / BOARD_SIZE;
        int y2 = move2 % BOARD_SIZE;

        if (revealed[x2][y2] == 1) {
            printf("You already revealed that tile!\n");
            continue;
        }

        revealed[x2][y2] = 1;

        if (checkPair(x1, y1, x2, y2)) {
            score += SCORE_PER_PAIR;
            printf("You found a pair!\n");
        } else {
            hidePair(x1, y1, x2, y2);
            printf("No match!\n");
        }

        turns++;
    }

    printBoard();

    if (checkWin() == 1) {
        printf("Congratulations! You won the game with a score of %d.\n", score);
    } else {
        printf("Game over! You lost with a score of %d.\n", score);
    }

    return 0;
}

// Initialize the game state
void initializeGame() {
    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % NUM_PAIRS;
        }
    }

    // Initialize the revealed array to all 0s
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }

    // Initialize the score and turns to 0
    score = 0;
    turns = 0;
}

// Print the game board
void printBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j] == 0) {
                printf("X ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Get a move from the player
int getMove() {
    int move;
    printf("Enter your move (row, column): ");
    scanf("%d, %d", &move, &move);
    return move;
}

// Check if two tiles form a pair
int checkPair(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

// Reveal a pair of tiles
void revealPair(int x1, int y1, int x2, int y2) {
    revealed[x1][y1] = 1;
    revealed[x2][y2] = 1;
}

// Hide a pair of tiles
void hidePair(int x1, int y1, int x2, int y2) {
    revealed[x1][y1] = 0;
    revealed[x2][y2] = 0;
}

// Check if the game is won
int checkWin() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}