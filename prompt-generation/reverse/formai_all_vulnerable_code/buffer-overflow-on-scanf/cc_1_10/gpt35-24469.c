//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the number of rows and columns
#define ROWS 5
#define COLS 5

// Function to initialize the game board with zeros
void initializeGameBoard(int gameBoard[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameBoard[i][j] = 0;
        }
    }
}

// Function to print the game board
void printGameBoard(int gameBoard[][COLS]) {
    printf("\n");

    // Print column headers
    printf("   ");
    for(int i = 0; i < COLS; i++) {
        printf("%d ", i+1);
    }
    printf("\n");

    // Print rows with row headers
    for(int i = 0; i < ROWS; i++) {
        printf("%d  ", i+1);

        for(int j = 0; j < COLS; j++) {
            printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

// Function to get the position of the next move from the user
void getUserMove(int *x, int *y) {
    printf("Enter the row and column numbers for your next move: ");
    scanf("%d %d", x, y);

    // Decrement the row and column numbers to match the array indexing
    *x = *x - 1;
    *y = *y - 1;
}

// Function to determine if the game is over
int isGameOver(int gameBoard[][COLS]) {
    // Check for a horzontal win
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS - 3; j++) {
            if(gameBoard[i][j] != 0 && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j+1] == gameBoard[i][j+2] && gameBoard[i][j+2] == gameBoard[i][j+3]) {
                return gameBoard[i][j];
            }
        }
    }

    // Check for a vertical win
    for(int i = 0; i < ROWS - 3; i++) {
        for(int j = 0; j < COLS; j++) {
            if(gameBoard[i][j] != 0 && gameBoard[i][j] == gameBoard[i+1][j] && gameBoard[i+1][j] == gameBoard[i+2][j] && gameBoard[i+2][j] == gameBoard[i+3][j]) {
                return gameBoard[i][j];
            }
        }
    }

    // Check for a diagonal win (\)
    for(int i = 0; i < ROWS - 3; i++) {
        for(int j = 0; j < COLS - 3; j++) {
            if(gameBoard[i][j] != 0 && gameBoard[i][j] == gameBoard[i+1][j+1] && gameBoard[i+1][j+1] == gameBoard[i+2][j+2] && gameBoard[i+2][j+2] == gameBoard[i+3][j+3]) {
                return gameBoard[i][j];
            }
        }
    }

    // Check for a diagonal win (/)
    for(int i = 3; i < ROWS; i++) {
        for(int j = 0; j < COLS - 3; j++) {
            if(gameBoard[i][j] != 0 && gameBoard[i][j] == gameBoard[i-1][j+1] && gameBoard[i-1][j+1] == gameBoard[i-2][j+2] && gameBoard[i-2][j+2] == gameBoard[i-3][j+3]) {
                return gameBoard[i][j];
            }
        }
    }

    // Check for a tie
    int isTie = 1;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(gameBoard[i][j] == 0) {
                isTie = 0;
            }
        }
    }
    if(isTie) {
        return 3;
    }

    // If there is no winner and no tie, return 0
    return 0;
}

int main() {
    // Declare the game board and initialize it with zeros
    int gameBoard[ROWS][COLS];
    initializeGameBoard(gameBoard);

    // Print the initial game board
    printGameBoard(gameBoard);

    // Loop until the game is over
    int currentPlayer = 1;
    int isGameEnd = 0;
    while(!isGameEnd) {
        // Get the user's move
        int x, y;
        getUserMove(&x, &y);

        // Check if the move is valid
        if(gameBoard[x][y] != 0) {
            printf("That cell is already occupied. Please choose another cell.\n");
            continue;
        }

        // Update the game board with the user's move
        gameBoard[x][y] = currentPlayer;

        // Print the updated game board
        printGameBoard(gameBoard);

        // Check if the game is over
        int winner = isGameOver(gameBoard);
        if(winner != 0) {
            if(winner == 1) {
                printf("Player 1 Wins!\n");
            } else if(winner == 2) {
                printf("Player 2 Wins!\n");
            } else {
                printf("It's a tie!\n");
            }
            isGameEnd = 1;
        }

        // Switch to the other player
        if(currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    return 0;
}