//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, size, count, num, player1_choice, player2_choice, player_turn, winner;
    int** board;
    
    // Get size of the board from user
    printf("Enter the size of the board: ");
    scanf("%d", &size);
    
    // Allocate memory for the board
    board = (int**) malloc(size * sizeof(int*));
    for (i = 0; i < size; i++) {
        board[i] = (int*) malloc(size * sizeof(int));
    }
    
    // Initialize board with random numbers between 1 and 9
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = rand() % 9 + 1;
        }
    }
    
    // Print the board
    printf("\nBoard:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    // Initialize player turn and count
    player_turn = 1;
    count = 0;
    
    // Loop until there is a winner or the board is filled
    while (winner == 0 && count < size*size) {
        printf("\nPlayer %d's turn.\n", player_turn);
        printf("Enter the row and column number: ");
        scanf("%d %d", &i, &j);
        
        // Check if the chosen location is valid
        if (i >= 0 && i < size && j >= 0 && j < size) {
            // Check if the location is already occupied
            if (board[i][j] == 0) {
                printf("Location already occupied. Choose another location.\n");
                continue;
            }
            // Mark the location
            num = board[i][j];
            board[i][j] = 0;
            count++;
            
            // Check if there is a horizontal match
            for (k = 0; k < size; k++) {
                if (board[i][k] == num) {
                    board[i][k] = 0;
                    count++;
                }
            }
            
            // Check if there is a vertical match
            for (k = 0; k < size; k++) {
                if (board[k][j] == num) {
                    board[k][j] = 0;
                    count++;
                }
            }
            
            // Switch player turn
            if (player_turn == 1) {
                player_turn = 2;
            } else {
                player_turn = 1;
            }
        } else {
            printf("Invalid location. Choose another location.\n");
        }
        
        // Print the updated board
        printf("\nUpdated Board:\n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        // Check if there is a winner
        if (count == size*size) {
            if (player1_choice > player2_choice) {
                winner = 1;
            } else if (player2_choice > player1_choice) {
                winner = 2;
            } else {
                winner = -1;
            }
        }
    }
    
    // Print winner
    if (winner == 1) {
        printf("\nPlayer 1 wins the game!\n");
    } else if (winner == 2) {
        printf("\nPlayer 2 wins the game!\n");
    } else {
        printf("\nIt's a tie!\n");
    }
    
    // Free memory
    for (i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);
    
    return 0;
}