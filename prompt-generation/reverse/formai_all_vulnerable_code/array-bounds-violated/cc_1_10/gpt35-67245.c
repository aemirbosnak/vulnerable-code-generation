//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Initialize the board with the starting positions
char board[SIZE][SIZE] = {
    {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
    {'b', '-', 'b', '-', 'b', '-', 'b', '-'},
    {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
    {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'}
};

// Function to display the current state of the board
void display_board()
{
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    // Variable to keep track of current player's turn
    char player = 'r';
    
    // Loop until a player wins
    while(1) {
        printf("%c's turn\n", player);
        
        // Display the current state of the board
        display_board();
        
        // Get the player's move (assuming input format - "a1 b2")
        char move[5];
        printf("Enter your move: ");
        scanf("%s", move);
        
        // Parse the move and get the source and destination positions
        int src_x = move[0] - 'a';
        int src_y = move[1] - '1';
        int dest_x = move[3] - 'a';
        int dest_y = move[4] - '1';
        
        // Check if the move is valid
        if(board[src_y][src_x] == player && board[dest_y][dest_x] == '-') {
            int diff_x = dest_x - src_x;
            int diff_y = dest_y - src_y;
            
            // Check if the move is a diagonal move by one square
            if(abs(diff_x) == 1 && abs(diff_y) == 1) {
                // Make the move
                board[src_y][src_x] = '-';
                board[dest_y][dest_x] = player;
                
                // Switch player's turn
                if(player == 'r') {
                    player = 'b';
                } else {
                    player = 'r';
                }
            } else {
                printf("Invalid move. You can only move diagonally by one square.\n");
            }
        } else {
            printf("Invalid move. You can only move your own pieces to an empty square.\n");
        }
    }
    
    return 0;
}