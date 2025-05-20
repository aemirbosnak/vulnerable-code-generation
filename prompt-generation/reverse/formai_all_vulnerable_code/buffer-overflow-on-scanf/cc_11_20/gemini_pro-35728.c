//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

int board[3][3] = {0}; // initialize the board to all 0s

int checkWinner() {
    int i, j, sum;
    
    // Check rows
    for (i = 0; i < 3; i++) {
        sum = 0;
        for (j = 0; j < 3; j++) {
            sum += board[i][j];
        }
        if (sum == 3) {  // Player X wins
            return 1;
        } else if (sum == -3) { // Player O wins
            return -1;
        }
    }


    // Check columns
    for (j = 0; j < 3; j++) {
        sum = 0;
        for (i = 0; j < 3; i++) {
            sum += board[i][j];
        }
        if (sum == 3) {  // Player X wins
            return 1;
        } else if (sum == -3) { // Player O wins
            return -1;
        }
    }

    // Check diagonals
    sum = board[0][0] + board[1][1] + board[2][2];
    if (sum == 3) {  // Player X wins
        return 1;
    } else if (sum == -3) { // Player O wins
        return -1;
    }

    sum = board[0][2] + board[1][1] + board[2][0];
    if (sum == 3) {  // Player X wins
        return 1;
    } else if (sum == -3) { // Player O wins 
        return -1;
    }

    // No winner yet
    return 0;
}

int minmax(int depth, int player) {
    int i, j, bestScore, score;
    
    // Check for a winner
    int winner = checkWinner();
    if (winner == 1) {
        return 10;  // Player X wins
    } else if (winner == -1) {
        return -10; // Player O wins
    } else if (winner == 0) {
        return 0;  // No winner yet
    }
    
    // Maximize the score for the player who is currently playing
    if (player == 1) {
        bestScore = -10000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                // Only consider empty spaces
                if (board[i][j] == 0) {
                    board[i][j] = 1;  // Place an X in the empty space
                    score = minmax(depth + 1, -player);  // Recursively call minmax for the other player
                    board[i][j] = 0;  // Remove the X from the empty space
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    } else {
        bestScore = 10000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                // Only consider empty spaces
                if (board[i][j] == 0) {
                    board[i][j] = -1;  // Place an O in the empty space
                    score = minmax(depth + 1, -player);  // Recursively call minmax for the other player
                    board[i][j] = 0;  // Remove the O from the empty space
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    }
    
    return bestScore;
}

int main() {
    int i, j, player = 1, move, score;
    
    while (1) {
        // Get the player's move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        
        // Convert the move to a board position
        i = (move - 1) / 3;
        j = (move - 1) % 3;
        
        // Place the player's move on the board
        board[i][j] = player;
        
        // Check for a winner
        int winner = checkWinner();
        if (winner == 1) {
            printf("Player X wins!\n");
            break;
        } else if (winner == -1) {
            printf("Player O wins!\n");
            break;
        }
        
        // Get the computer's move
        score = minmax(0, -player);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                // Only consider empty spaces
                if (board[i][j] == 0) {
                    board[i][j] = -player;  // Place an O in the empty space
                    if (score == minmax(0, player)) {
                        break;
                    }
                    board[i][j] = 0;  // Remove the O from the empty space
                }
            }
        }
        
        // Place the computer's move on the board
        board[i][j] = -player;
        
        // Print the board
        printf("\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    printf("X");
                } else if (board[i][j] == -1) {
                    printf("O");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        
        // Switch players
        player = -player;
    }
    
    return 0;
}