//FormAI DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4    // The size of the game grid
#define MAX_VALUE 8    // The maximum value for a tile

// Function to print the game grid
void print_board(int board[][SIZE]) {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game grid with random values
void init_board(int board[][SIZE]) {
    srand(time(NULL));    // Seed the random number generator
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = rand() % (MAX_VALUE+1);
        }
    }
}

// Function to check if the game is over (all tiles have been flipped)
int is_game_over(int flipped[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(!flipped[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    int board[SIZE][SIZE];    // The game grid
    int flipped[SIZE][SIZE];    // The flipped status of each tile
    int num_flipped = 0;    // The number of flipped tiles
    int row, col;    // The row and column of the tile to flip
    
    init_board(board);    // Initialize the game grid
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            flipped[i][j] = 0;    // None of the tiles are flipped yet
        }
    }
    print_board(board);    // Print the starting game grid
    
    while(!is_game_over(flipped)) {    // Continue playing until all tiles are flipped
        printf("\nEnter the row and column of a tile to flip (e.g. '2 3'): ");
        scanf("%d %d", &row, &col);
        if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && !flipped[row][col]) {
            printf("\nFlipping tile [%d][%d]...\n", row, col);
            flipped[row][col] = 1;    // Flip the tile
            num_flipped++;
            print_board(board);    // Print the updated game grid
        }
        else {
            printf("\nInvalid input or tile already flipped.\n");
        }
    }

    printf("\nCongratulations! You flipped all %d tiles in the game.\n", num_flipped);
    return 0;
}