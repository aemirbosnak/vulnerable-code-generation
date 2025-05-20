//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random integer
int generateRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to clear the console
void clearConsole() {
    system("clear || cls");
}

// Function to display the game board
void displayGameBoard(char gameBoard[][3]) {
    printf("\n");
    printf("\t %c | %c | %c \n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("\t---------\n");
    printf("\t %c | %c | %c \n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\t---------\n");
    printf("\t %c | %c | %c \n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    printf("\n");
}

// Function to check if the game is over
bool isGameOver(char gameBoard[][3]) {
    // Check for horizontal wins
    for(int i=0; i<3; i++) {
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            if(gameBoard[i][0] == 'X' || gameBoard[i][0] == 'O')
                return true;
        }
    }
    // Check for vertical wins
    for(int i=0; i<3; i++) {
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            if(gameBoard[0][i] == 'X' || gameBoard[0][i] == 'O')
                return true;
        }
    }
    // Check for diagonal wins
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        if(gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')
            return true;
    } else if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        if(gameBoard[0][2] == 'X' || gameBoard[0][2] == 'O')
            return true;
    }
    // Check if all cells have been filled
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(gameBoard[i][j] == '_')
                return false;
        }
    }
    // If all cells have been filled and there is no win, return true
    return true;
}

int main() {
    char gameBoard[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    bool gameOver = false;
    int currentPlayer = 0;
    srand(time(0)); // Initialize the random number generator
    
    while(!gameOver) {
        if(currentPlayer == 0) {
            printf("Player 1's turn (X):\n");
        } else {
            printf("Player 2's turn (O):\n");
        }
        
        // Get user input for row and column
        int row, col;
        printf("Enter row (0, 1, or 2): ");
        scanf("%d", &row);
        printf("Enter column (0, 1, or 2): ");
        scanf("%d", &col);
        
        // Check if the input is valid
        if(row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input! Please enter a row and column between 0 and 2.\n");
            continue;
        }
        if(gameBoard[row][col] != '_') {
            printf("That cell has already been filled! Please choose another.\n");
            continue;
        }
        
        // Update the game board
        if(currentPlayer == 0) {
            gameBoard[row][col] = 'X';
        } else {
            gameBoard[row][col] = 'O';
        }
        
        // Display the updated game board
        clearConsole();
        displayGameBoard(gameBoard);
        
        // Check if the game is over
        gameOver = isGameOver(gameBoard);
        if(gameOver) {
            printf("Game over!\n");
            if(currentPlayer == 0) {
                printf("Player 1 (X) wins!\n");
            } else {
                printf("Player 2 (O) wins!\n");
            }
            break;
        }
        
        // Switch to the other player
        currentPlayer = (currentPlayer + 1) % 2;
    }
    
    return 0;
}