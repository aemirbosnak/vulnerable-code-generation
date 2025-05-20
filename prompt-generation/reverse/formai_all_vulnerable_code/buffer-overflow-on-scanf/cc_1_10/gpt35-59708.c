//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void displayTable(char table[3][3]);
bool checkWin(char table[3][3], char player);
bool checkDraw(char table[3][3]);
void humanTurn(char table[3][3], char player);
void computerTurn(char table[3][3], char player);

int main(void) {
    // Initialize the table and set all values to '-'
    char table[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    
    // Set player equal to X
    char player = 'X';
    
    // Variable to keep track of whether the game is over
    bool gameOver = false;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Game loop
    while (!gameOver) {
        // Display the table
        displayTable(table);
        
        // Player's turn if player is X, otherwise computer's turn
        if (player == 'X') {
            humanTurn(table, player);   
        } else {
            computerTurn(table, player);
        }
        
        // Check for a win or draw
        if (checkWin(table, player)) {
            printf("%c wins!\n", player);
            gameOver = true;
        } else if (checkDraw(table)) {
            printf("It's a draw!\n");
            gameOver = true;
        }
        
        // Switch to the other player
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    
    return 0;
}

// Function to display the table
void displayTable(char table[3][3]) {
    printf("\n\n");
    printf(" %c | %c | %c \n", table[0][0], table[0][1], table[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", table[1][0], table[1][1], table[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", table[2][0], table[2][1], table[2][2]);
}

// Function to check for a win
bool checkWin(char table[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == player && table[i][1] == player && table[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (table[0][i] == player && table[1][i] == player && table[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (table[0][0] == player && table[1][1] == player && table[2][2] == player) {
        return true;
    }
    
    if (table[0][2] == player && table[1][1] == player && table[2][0] == player) {
        return true;
    }
    
    // If no win, return false
    return false;
}

// Function to check for a draw
bool checkDraw(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] == '-') {
                return false;
            }
        }
    }
    
    return true;
}

// Function for the player's turn
void humanTurn(char table[3][3], char player) {
    int row, col;
    
    // Loop until a valid move is entered
    do {
        printf("Enter row and column for %c (0-2): ", player);
        scanf("%d %d", &row, &col);
        
        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || table[row][col] != '-') {
            printf("Invalid move, try again.\n");
        }
    } while (row < 0 || row > 2 || col < 0 || col > 2 || table[row][col] != '-');
    
    // Update the table
    table[row][col] = player;
}

// Function for the computer's turn
void computerTurn(char table[3][3], char player) {
    int row, col;
    
    // Loop until a valid move is found
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (table[row][col] != '-');
    
    // Update the table
    table[row][col] = player;
}