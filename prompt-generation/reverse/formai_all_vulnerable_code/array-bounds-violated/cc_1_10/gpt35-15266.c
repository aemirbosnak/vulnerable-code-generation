//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printBoard(int board[3][3]);
void initializeBoard(int board[3][3]);
int checkWin(int board[3][3], int player);

int main() {
    int board[3][3]; // Tic-tac-toe board
    int player = 1; // Player 1 always goes first
    int row, col; // Row and column numbers entered by the player
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the board
    initializeBoard(board);
    
    // Main game loop
    while(1) {
        // Print the board
        printBoard(board);
        
        // Prompt the player to enter a move
        printf("Player %d, enter row number (0-2): ", player);
        scanf("%d", &row);
        printf("Player %d, enter column number (0-2): ", player);
        scanf("%d", &col);
        
        // Check if the move is valid
        if(board[row][col] != 0) {
            printf("That space is already occupied. Please try again.\n");
            continue;
        }
        
        // Make the player's move
        board[row][col] = player;
        
        // Check if the game has been won
        if(checkWin(board, player)) {
            printf("Player %d wins!\n", player);
            printBoard(board);
            break;
        }
        
        // Check if the game has ended in a tie
        int i, j;
        int tie = 1;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    tie = 0;
                    break;
                }
            }
            if(!tie) {
                break;
            }
        }
        if(tie) {
            printf("The game is a tie.\n");
            printBoard(board);
            break;
        }
        
        // Switch to the other player
        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}

// Function to print the tic-tac-toe board
void printBoard(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            switch(board[i][j]) {
                case 0:
                    printf("-");
                    break;
                case 1:
                    printf("X");
                    break;
                case 2:
                    printf("O");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to initialize the tic-tac-toe board
void initializeBoard(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to check if the game has been won
int checkWin(int board[3][3], int player) {
    int i, j;
    // Check rows
    for(i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // Default case: game has not been won
    return 0;
}