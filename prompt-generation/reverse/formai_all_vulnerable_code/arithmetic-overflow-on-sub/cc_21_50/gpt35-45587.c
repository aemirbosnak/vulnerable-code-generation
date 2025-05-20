//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {0}; // Initialize board with all zeroes
    int player = 1;
    int row, col;
    srand(time(NULL)); // Seed random number generator with time
    int cpu_row, cpu_col;
    int winner = 0;
    
    // Print instructions
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("To make your mark, enter the row and column numbers when prompted.\n");
    printf("The first player to get three in a row wins!\n\n");
    
    // Loop until there's a winner or the board is full
    while (winner == 0 && player <= 9) {
        // Print the board
        printf("   1 2 3\n");
        printf("---------\n");
        for (int i = 0; i < 3; i++) {
            printf("%d |", i+1);
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    printf(" ");
                } else if (board[i][j] == 1) {
                    printf("X");
                } else {
                    printf("O");
                }
                printf("|");
            }
            printf("\n---------\n");
        }
        
        // Get the user's move
        printf("Player %d, enter a row number (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter a column number (1-3): ", player);
        scanf("%d", &col);
        if (board[row-1][col-1] != 0) {
            printf("That spot is already taken!\n");
        } else {
            board[row-1][col-1] = player;
            player = (player == 1) ? 2 : 1;
        }
        
        // Check for a winner
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0) {
                winner = board[i][0];
            }
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
                winner = board[0][i];
            }
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
            winner = board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0) {
            winner = board[0][2];
        }
        
        // If the board is full and there's no winner, it's a tie
        if (player == 9 && winner == 0) {
            winner = -1;
        }
    }
    
    // Print the final board and winner/tie message
    printf("   1 2 3\n");
    printf("---------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("X");
            } else {
                printf("O");
            }
            printf("|");
        }
        printf("\n---------\n");
    }
    if (winner == -1) {
        printf("It's a tie!\n");
    } else if (winner == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    
    // Play again?
    char play_again;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again); // Space before %c to consume newline
    if (play_again == 'y') {
        main(); // Run the program again
    } else {
        printf("Goodbye!\n");
    }
    
    return 0;
}