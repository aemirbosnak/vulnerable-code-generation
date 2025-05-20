//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size
#define TABLE_ROWS 5
#define TABLE_COLS 5

// Define the player types
#define PLAYER_ONE 1
#define PLAYER_TWO 2

// Define the game states
#define GAME_IN_PROGRESS 1
#define GAME_OVER 0

// Define the winning combinations
int winningCombinations[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

// Define the table
int table[TABLE_ROWS][TABLE_COLS];

// Define the current player
int currentPlayer = PLAYER_ONE;

// Define the game state
int gameState = GAME_IN_PROGRESS;

// Function to initialize the table
void initializeTable() {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table[i][j] = 0;
        }
    }
}

// Function to print the table
void printTable() {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

// Function to get the player's move
int getPlayerMove() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move - 1;
}

// Function to make a move
void makeMove(int player, int move) {
    table[move / TABLE_COLS][move % TABLE_COLS] = player;
}

// Function to check if the game is over
int checkGameOver() {
    // Check if there is a winning combination
    for (int i = 0; i < 8; i++) {
        if (table[winningCombinations[i][0] / TABLE_COLS][winningCombinations[i][0] % TABLE_COLS] != 0 &&
            table[winningCombinations[i][0] / TABLE_COLS][winningCombinations[i][0] % TABLE_COLS] == table[winningCombinations[i][1] / TABLE_COLS][winningCombinations[i][1] % TABLE_COLS] &&
            table[winningCombinations[i][0] / TABLE_COLS][winningCombinations[i][0] % TABLE_COLS] == table[winningCombinations[i][2] / TABLE_COLS][winningCombinations[i][2] % TABLE_COLS]) {
            return 1;
        }
    }

    // Check if the table is full
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            if (table[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to play the game
void playGame() {
    initializeTable();

    while (gameState == GAME_IN_PROGRESS) {
        printTable();

        int move = getPlayerMove();

        makeMove(currentPlayer, move);

        if (checkGameOver()) {
            gameState = GAME_OVER;
            printTable();
            if (currentPlayer == PLAYER_ONE) {
                printf("Player One wins!\n");
            } else {
                printf("Player Two wins!\n");
            }
        } else {
            // Switch the current player
            currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }
    }
}

int main() {
    srand(time(NULL));

    playGame();

    return 0;
}