//FormAI DATASET v1.0 Category: Checkers Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define SIZE 8

// Define the possible pieces
#define EMPTY 0
#define BLACK 1 
#define WHITE 2

// Define the game board
int board[SIZE][SIZE];

// Define the players
int player1 = BLACK;
int player2 = WHITE;

// Function to initialize the board
void init_board() {
    int row, col;
    for (row=0; row<SIZE; row++) {
        for (col=0; col<SIZE; col++) {
            // Setup the empty board
            if ((row+col) % 2 == 0) {
                board[row][col] = EMPTY;
            }
            // Setup the player 1 pieces
            else if (row < 3) {
                board[row][col] = BLACK;
            }
            // Setup the player 2 pieces
            else if (row > 4) {
                board[row][col] = WHITE;
            }
            // Setup the empty spaces
            else {
                board[row][col] = EMPTY;
            }
        }
    }
}

// Function to display the board
void display_board() {
    printf("\n");
    int row, col;
    for (row=0; row<SIZE; row++) {
        printf("%d", SIZE-row);
        for (col=0; col<SIZE; col++) {
            switch (board[row][col]) {
                case EMPTY:
                    printf(" ");
                    break;
                case BLACK:
                    printf("B");
                    break;
                case WHITE:
                    printf("W");
                    break;
                default:
                    break;
            }
            printf("|");
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main() {
    int row, col, i, j;
    int player = player1;
    init_board();
    display_board();
    printf("\nPlayer 1: BLACK\nPlayer 2: WHITE\n");
    
    while (1) {
        // Get the player's move
        printf("Player %d's turn\n", player);
        printf("Enter the row number of the piece you want to move: ");
        scanf("%d", &row);
        printf("Enter the column number of the piece you want to move: ");
        scanf("%d", &col);
        
        // Validate the move
        if (board[row-1][col-1] == player) {
            // Move the piece
            printf("Enter the row number of the space you want to move to: ");
            scanf("%d", &i);
            printf("Enter the column number of the space you want to move to: ");
            scanf("%d", &j);
            if (board[i-1][j-1] == EMPTY) {
                board[row-1][col-1] = EMPTY;
                board[i-1][j-1] = player;
            }
            
            // Update the board if a piece was captured
            else if (board[i-1][j-1] != player) {
                int d_row = i - row;
                int d_col = j - col;
                int temp_row = row - d_row;
                int temp_col = col - d_col;
                if (temp_row >= 0 && temp_col >= 0 && board[temp_row][temp_col] == EMPTY) {
                    board[row-1][col-1] = EMPTY;
                    board[i-1][j-1] = player;
                    board[temp_row][temp_col] = EMPTY;
                }
            }
            
            // Switch players
            if (player == player1) {
                player = player2;
            }
            else {
                player = player1;
            }
        }
        else {
            printf("Invalid move. Try again.\n");
        }
        
        // Display the updated board
        display_board();
    }
    return 0;
}