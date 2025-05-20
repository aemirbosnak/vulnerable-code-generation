//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int randomize(int max) {
    srand(time(NULL));
    return rand() % max;
}

int main() {
    int player1, player2, count = 0;

    // Set up game board
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    printf("Welcome to the Visionary Tic Tac Toe Game!\n");
    printf("Player 1 is X, Player 2 is O.\n\n");

    // Display the board at the beginning of the game
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }

    // Loop to keep playing until there is a winner or board is full
    while(count < 9) {
        // Player 1's turn
        printf("\nPlayer 1, please enter a row (1-3): ");
        scanf("%d", &player1);
        printf("\nAnd now enter a column (1-3): ");
        scanf("%d", &player2);

        // Check if spot is empty or not
        if(board[player1-1][player2-1] == '-') {
            board[player1-1][player2-1] = 'X';
            count++;
        } else {
            printf("That spot is not empty. Please try again.\n");
            continue;
        }

        // Display the updated board
        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                printf("%c ", board[row][col]);
            }
            printf("\n");
        }

        // Check if player 1 wins
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
           board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
           board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
           board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
           board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
           board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' ||
           board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
           board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
            printf("\nPlayer 1 wins!\n");
            break;
        }

        // Player 2's turn
        printf("\nPlayer 2's turn.\n");

        // Generate random numbers for player 2's row and col
        player1 = randomize(3) + 1;
        player2 = randomize(3) + 1;

        // Check if spot is empty or not
        if(board[player1-1][player2-1] == '-') {
            board[player1-1][player2-1] = 'O';
            count++;
        } else {
            printf("That spot is not empty. Choosing another random move...\n");
            continue;
        }

        // Display the updated board
        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                printf("%c ", board[row][col]);
            }
            printf("\n");
        }

        // Check if player 2 wins
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
           board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
           board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
           board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
           board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
           board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' ||
           board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
           board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
            printf("\nPlayer 2 wins!\n");
            break;
        }

    }

    if(count == 9) {
        printf("\nThe game ended in a tie!\n");
    }

    return 0;
}