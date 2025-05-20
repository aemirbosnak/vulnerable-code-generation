//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a dice roll
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Initialize the game
    int players;
    printf("Enter the number of players (2-8): ");
    scanf("%d", &players);
    
    // Check that the number of players is within range
    if (players < 2 || players > 8) {
        printf("Invalid number of players. Please enter a number between 2 and 8.\n");
        return 0;
    }
    
    // Initialize player scores
    int scores[players];
    for (int i = 0; i < players; i++) {
        scores[i] = 0;
    }
    
    // Initialize the board (10x10 grid)
    int board[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    
    // Set the starting positions for each player
    int positions[players][2];
    positions[0][0] = 0;
    positions[0][1] = 0;
    positions[1][0] = 0;
    positions[1][1] = 9;
    if (players >= 3) {
        positions[2][0] = 9;
        positions[2][1] = 0;
    }
    if (players >= 4) {
        positions[3][0] = 9;
        positions[3][1] = 9;
    }
    if (players >= 5) {
        positions[4][0] = 4;
        positions[4][1] = 2;
    }
    if (players >= 6) {
        positions[5][0] = 4;
        positions[5][1] = 7;
    }
    if (players >= 7) {
        positions[6][0] = 2;
        positions[6][1] = 4;
    }
    if (players == 8) {
        positions[7][0] = 7;
        positions[7][1] = 4;
    }
    
    // Play the game until a winner is found
    int winner = 0;
    while (winner == 0) {
        // Loop through each player and take their turn
        for (int i = 0; i < players; i++) {
            printf("Player %d, press enter to roll the dice: ", i+1);
            getchar();
            
            // Roll the dice and move the player
            int roll = rollDice();
            printf("You rolled a %d\n", roll);
            int row = positions[i][0];
            int col = positions[i][1];
            if (row % 2 == 0) {
                if (col + roll < 10) {
                    col += roll;
                } else {
                    row += 1;
                    col = 9 - (roll - (9 - col));
                }
            } else {
                if (col - roll >= 0) {
                    col -= roll;
                } else {
                    row += 1;
                    col = roll - col - 1;
                }
            }
            positions[i][0] = row;
            positions[i][1] = col;
            
            // Check if the player has landed on a square with a score
            if (board[row][col] != 0) {
                scores[i] += board[row][col];
                board[row][col] = 0;
            }
            
            // Print the updated board and player scores
            printf("Board:\n");
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (positions[i][0] == j && positions[i][1] == k) {
                        printf("%d\x1b[31m*\x1b[0m ", board[j][k]);
                    } else {
                        printf("%d ", board[j][k]);
                    }
                }
                printf("\n");
            }
            printf("Scores:\n");
            for (int j = 0; j < players; j++) {
                printf("Player %d: %d\n", j+1, scores[j]);
            }
            
            // Check if the player has won
            if (scores[i] >= 100) {
                winner = i+1;
                break;
            }
        }
    }
    
    // Print the winner
    printf("Player %d has won!", winner);
    
    return 0;
}