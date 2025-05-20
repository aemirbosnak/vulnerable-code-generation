//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_MOVES 15

int main() {
    srand(time(0)); // Seed for random number generator
    
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize the board with all 0s
    int x, y, i, j, moves = 0;
    char response;
    
    // Place the target at a random location on the board
    int target_x = rand() % BOARD_SIZE;
    int target_y = rand() % BOARD_SIZE;
    printf("Paranoid Table Game. Can you find the hidden spot?\n");
    printf("You have %d moves to guess the target.\n", MAX_MOVES);
    
    while (moves < MAX_MOVES) {
        printf("\nEnter the coordinates (x,y) you want to check.\n");
        printf("Enter x: ");
        scanf("%d", &x);
        printf("Enter y: ");
        scanf("%d", &y);
        
        // Check if the coordinate is valid
        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        
        // Check if the spot has already been checked
        if (board[x][y] == 1) {
            printf("You already checked that spot. Try again.\n");
            continue;
        }
        
        board[x][y] = 1; // Mark the spot as checked
        moves++; // Increment the number of moves
        
        // Check if the spot is the target
        if (x == target_x && y == target_y) {
            printf("Congratulations! You found the hidden spot in %d moves.\n", moves);
            return 0;
        } else {
            printf("Sorry, the spot (%d,%d) is not the hidden spot.\n", x, y);
            
            // Print the board with 0s as unchecked spots and 1s as checked spots
            printf("Current Board:\n   ");
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", j);
            }
            printf("\n");
            
            for (i = 0; i < BOARD_SIZE; i++) {
                printf("%d: ", i);
                for (j = 0; j < BOARD_SIZE; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
        }
    }
    
    // Ran out of moves
    printf("Sorry, you ran out of moves. Game over.\n");
    
    // Print the solution board with T as the target spot
    printf("Solution Board:\n   ");
    for (j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d: ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == target_x && j == target_y) {
                printf("T ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    
    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &response);
    
    if (response == 'y' || response == 'Y') {
        main(); // Restart the game
    } else {
        printf("Thanks for playing. Bye!\n");
        return 0;
    }
}