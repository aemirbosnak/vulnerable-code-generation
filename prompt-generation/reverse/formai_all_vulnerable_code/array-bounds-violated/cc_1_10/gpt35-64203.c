//FormAI DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>

// The checker board is represented by a 2D array of integers
// The value 0 represents an empty cell, 1 represents a red checker, and 2 represents a black checker.
int board[8][8] = {
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

// Function to print the checker board
void print_board() {
    printf("\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a checker from one position to another
void move_checker(int r1, int c1, int r2, int c2) {
    // Only move if the destination cell is empty
    if(board[r2][c2] == 0) {
        // Move the checker
        board[r2][c2] = board[r1][c1];
        board[r1][c1] = 0;
        
        printf("Moved checker from (%d,%d) to (%d,%d)\n", r1, c1, r2, c2);
    }
    else {
        printf("Destination cell is not empty\n");
    }
}

// Main function to play the game
int main() {
    int player = 1; // 1 for red checker and 2 for black checker
    int r1, c1, r2, c2;
    
    while(1) {
        // Print the board
        print_board();
        
        // Get the move from the player
        printf("Player %d's turn\n", player);
        printf("Enter the row and column of the checker you want to move: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the row and column of the destination: ");
        scanf("%d %d", &r2, &c2);
        
        // Move the checker
        move_checker(r1, c1, r2, c2);
        
        // Switch the player
        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}