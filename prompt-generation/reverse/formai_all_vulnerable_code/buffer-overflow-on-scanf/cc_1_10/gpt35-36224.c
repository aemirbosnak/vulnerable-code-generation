//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <time.h>
#include <stdio.h>

// Define some constants
#define GAME_WIDTH 10
#define GAME_HEIGHT 10
#define MAX_NUM_MOVES 50

// Define some variables
char gameBoard[GAME_WIDTH][GAME_HEIGHT];
int currentRow = 0;
int currentCol = 0;
int numMoves = 0;

// A helper function to randomly generate a number between
// min and max (inclusive)
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Initialize the game board to all spaces
    for (int row = 0; row < GAME_HEIGHT; row++) {
        for (int col = 0; col < GAME_WIDTH; col++) {
            gameBoard[row][col] = ' ';
        }
    }

    // Set the starting position randomly on the board
    srand(time(NULL));
    currentRow = randomInRange(0, GAME_HEIGHT - 1);
    currentCol = randomInRange(0, GAME_WIDTH - 1);
    gameBoard[currentRow][currentCol] = 'X';

    // Game loop
    char input;
    while (numMoves < MAX_NUM_MOVES) {
        // Print the game board
        printf("\n\n");
        for (int row = 0; row < GAME_HEIGHT; row++) {
            for (int col = 0; col < GAME_WIDTH; col++) {
                if (row == currentRow && col == currentCol) {
                    printf("X");
                } else {
                    printf("%c", gameBoard[row][col]);
                }
            }
            printf("\n");
        }

        // Print game instructions
        printf("\n\nUse WASD to move. You have %d moves left.\n", MAX_NUM_MOVES - numMoves);
        
        // Get user input
        scanf(" %c", &input);
        
        // Update the game board and position based on user input
        switch (input) {
            case 'w':
                if (currentRow > 0) {
                    gameBoard[currentRow][currentCol] = ' ';
                    currentRow--;
                    gameBoard[currentRow][currentCol] = 'X';
                    numMoves++;
                } else { printf("You're at the edge of the world!\n"); }
                break;
            case 'a':
                if (currentCol > 0) {
                    gameBoard[currentRow][currentCol] = ' ';
                    currentCol--;
                    gameBoard[currentRow][currentCol] = 'X';
                    numMoves++;
                } else { printf("You're at the edge of the world!\n"); }
                break;
            case 's':
                if (currentRow < GAME_HEIGHT - 1) {
                    gameBoard[currentRow][currentCol] = ' ';
                    currentRow++;
                    gameBoard[currentRow][currentCol] = 'X';
                    numMoves++;
                } else { printf("You're at the edge of the world!\n"); }
                break;
            case 'd':
                if (currentCol < GAME_WIDTH - 1) {
                    gameBoard[currentRow][currentCol] = ' ';
                    currentCol++;
                    gameBoard[currentRow][currentCol] = 'X';
                    numMoves++;
                } else { printf("You're at the edge of the world!\n"); }
                break;
            default:
                printf("Invalid input!\n");
        }
    }
    printf("\n\nYou've run out of moves! Game over.");
    return 0;
}