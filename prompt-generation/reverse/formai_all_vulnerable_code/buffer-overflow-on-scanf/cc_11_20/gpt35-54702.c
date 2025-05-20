//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the game board with a 10x10 array
    int board[10][10];
    
    // Fill the board with zeros
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            board[i][j] = 0;
        }
    }
    
    // Generate the position of the treasure randomly
    int treasure_x = rand() % 10;
    int treasure_y = rand() % 10;
    
    // Game loop
    while(1) {
        
        // Print the game board
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                if(i == treasure_x && j == treasure_y) {
                    printf("T ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }
        
        // Get the user's guess
        int guess_x, guess_y;
        printf("Enter your guess (x y): ");
        scanf("%d %d", &guess_x, &guess_y);
        
        // Check if the guess is correct
        if(guess_x == treasure_x && guess_y == treasure_y) {
            printf("Congratulations! You found the treasure!\n");
            break;
        } else if(guess_x < 0 || guess_x >= 10 || guess_y < 0 || guess_y >= 10) {
            printf("Invalid guess. Please try again.\n");
        } else if(board[guess_x][guess_y] == 1) {
            printf("You have already guessed that location. Please try again.\n");
        } else {
            printf("Sorry, that is not the location of the treasure. Please try again.\n");
            board[guess_x][guess_y] = 1;
        }
    }
    
    return 0;
}