//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Define the game board
    int board[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Define the players
    char player1[20], player2[20];
    printf("Player 1, enter your name: ");
    scanf("%s", player1);
    printf("Player 2, enter your name: ");
    scanf("%s", player2);
    
    // Determine who goes first
    int turn = rand() % 2 + 1;
    printf("%s will go first.\n", turn == 1 ? player1 : player2);
    
    // Play the game
    int winner = 0;
    while (winner == 0) {
        // Display the board
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        // Get the player's move
        int move, row, col;
        printf("%s, enter your move: ", turn == 1 ? player1 : player2);
        scanf("%d", &move);
        
        // Validate the move
        if (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
            continue;
        }
        row = (move - 1) / 3;
        col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("That spot is already taken. Please choose another spot.\n");
            continue;
        }
        
        // Make the move on the board
        board[row][col] = turn == 1 ? 'X' : 'O';
        
        // Check for a winner
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = turn;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                winner = turn;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = turn;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = turn;
        }
        
        // Switch turns
        turn = turn == 1 ? 2 : 1;
    }
    
    // Display the winner
    printf("\n%s wins!\n", winner == 1 ? player1 : player2);
    
    return 0;
}