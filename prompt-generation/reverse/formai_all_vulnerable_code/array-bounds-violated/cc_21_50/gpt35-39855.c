//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create 2D array for game board
    int board[5][5];

    // Fill game board with random integers between 1 and 9
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            board[i][j] = rand() % 9 + 1;
        }
    }

    // Initialize player's starting position
    int playerRow = 2;
    int playerCol = 2;

    // Display game board and player's starting position
    printf("Welcome to the game!\n\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == playerRow && j == playerCol) {
                printf("P ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // Start game loop
    while(1) {
        // Get player input
        printf("\nEnter a direction (up, down, left, right): ");
        char input[10];
        scanf("%s", input);

        // Update player's position based on input
        if(strcmp(input, "up") == 0) {
            playerRow--;
        } else if(strcmp(input, "down") == 0) {
            playerRow++;
        } else if(strcmp(input, "left") == 0) {
            playerCol--;
        } else if(strcmp(input, "right") == 0) {
            playerCol++;
        }

        // Check if player has won
        if(board[playerRow][playerCol] == 9) {
            printf("\nCongratulations! You have reached the end.\n");
            break;
        }

        // Check if player's move is valid
        if(playerRow < 0 || playerRow > 4 || playerCol < 0 || playerCol > 4) {
            printf("\nInvalid move. You cannot leave the game board.\n");
            // Undo invalid move
            if(strcmp(input, "up") == 0) {
                playerRow++;
            } else if(strcmp(input, "down") == 0) {
                playerRow--;
            } else if(strcmp(input, "left") == 0) {
                playerCol++;
            } else if(strcmp(input, "right") == 0) {
                playerCol--;
            }
        } else {
            // Display updated game board
            printf("\n");
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(i == playerRow && j == playerCol) {
                        printf("P ");
                    } else {
                        printf("%d ", board[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}