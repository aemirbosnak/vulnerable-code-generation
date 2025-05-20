//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for board size and symbol representation
#define ROWS 3
#define COLS 3
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'

// Function prototypes
void displayBoard(char board[][COLS]);
int takeTurn(char symbol, char board[][COLS]);
int checkWin(char symbol, char board[][COLS]);

// Main function
int main() {
    char board[ROWS][COLS]; // 2D array for game board
    char player1 = X_SYMBOL; // Player 1 symbol
    char player2 = O_SYMBOL; // Player 2 symbol
    int turn = 0; // Turn counter
    int winner = 0; // Winner flag
    
    // Initialize board with empty spaces
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Seed random number generator with current time
    srand(time(NULL));
    
    // Randomly decide who goes first
    if(rand() % 2 == 0) {
        printf("Player 1 (X) goes first.\n");
    } else {
        printf("Player 2 (O) goes first.\n");
        // Swap player symbols
        char temp = player1;
        player1 = player2;
        player2 = temp;
    }
    
    // Game loop
    while(turn < 9 && !winner) {
        // Display board
        displayBoard(board);
        
        // Take turn for appropriate player
        if(turn % 2 == 0) {
            printf("Player 1's (X) turn:\n");
            winner = takeTurn(player1, board);
        } else {
            printf("Player 2's (O) turn:\n");
            winner = takeTurn(player2, board);
        }
        
        turn++;
    }
    
    // Display final board state
    displayBoard(board);
    
    // Display winner or tie message
    if(winner == 1) {
        printf("Player 1 (X) wins!\n");
    } else if(winner == 2) {
        printf("Player 2 (O) wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}

// Function to display current state of board
void displayBoard(char board[][COLS]) {
    printf("   1   2   3\n");
    printf("  -----------\n");
    for(int i=0; i<ROWS; i++) {
        printf("%d| ", i+1);
        for(int j=0; j<COLS; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("  -----------\n");
    }
}

// Function to prompt player for their turn and update board
int takeTurn(char symbol, char board[][COLS]) {
    int row, col;
    printf("Enter a row number (1-3): ");
    scanf("%d", &row);
    printf("Enter a column number (1-3): ");
    scanf("%d", &col);
    
    // Convert user input to 0-based array index
    row--;
    col--;
    
    // Check if chosen space is already taken
    if(board[row][col] != ' ') {
        printf("That space is already taken! Choose another.\n");
        return 0;
    }
    
    // Update board with chosen symbol
    board[row][col] = symbol;
    
    // Check for win condition
    if(checkWin(symbol, board)) {
        return symbol == X_SYMBOL ? 1 : 2; // Return player number based on symbol
    }
    
    return 0;
}

// Function to check for win condition
int checkWin(char symbol, char board[][COLS]) {
    // Check for horizontal win
    for(int i=0; i<ROWS; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    
    // Check for vertical win
    for(int i=0; i<COLS; i++) {
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    
    // Check for diagonal win
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    
    return 0;
}