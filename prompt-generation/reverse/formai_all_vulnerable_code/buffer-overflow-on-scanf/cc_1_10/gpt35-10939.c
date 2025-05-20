//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = { // Initialize the board with game pieces
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
    {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
    {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'}
};

void print_board() { // Function to print the game board
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", i);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to Cryptic Checkers!\n");
    print_board();

    int player = 1; // Initialize player variable
    
    while(1) { // Infinite loop until game is over
        int row1, col1, row2, col2; // Variables for user input
        printf("Player %d: Choose a piece to move (row col): ", player);
        scanf("%d %d", &row1, &col1);
        printf("Player %d: Choose a destination (row col): ", player);
        scanf("%d %d", &row2, &col2);

        // Check that player is moving their own game piece
        if(player == 1 && (board[row1][col1] != 'x' && board[row1][col1] != 'X')) {
            printf("Invalid game piece, please choose a valid game piece.\n"); continue;
        } else if(player == 2 && (board[row1][col1] != 'o' && board[row1][col1] != 'O')) {
            printf("Invalid game piece, please choose a valid game piece.\n"); continue;
        }

        // Check that move is valid
        if((row1 - row2 == 1 || row1 - row2 == -1) && (col1 - col2 == 1 || col1 - col2 == -1)) {
            if(player == 1 && board[row2][col2] == ' ') { // Move player 1 piece
                board[row2][col2] = board[row1][col1];
                board[row1][col1] = ' ';
                print_board();
                player = 2; // Next player's turn
            } else if(player == 2 && board[row2][col2] == ' ') { // Move player 2 piece
                board[row2][col2] = board[row1][col1];
                board[row1][col1] = ' ';
                print_board();
                player = 1; // Next player's turn
            } else { // Invalid move
                printf("Invalid move, please choose a valid destination.\n"); continue;
            }
        } else { // Invalid move
            printf("Invalid move, please choose a valid destination.\n"); continue;
        }
    }
    return 0;
}