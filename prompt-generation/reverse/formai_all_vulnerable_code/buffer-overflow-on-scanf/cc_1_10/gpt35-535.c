//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function to print the game board
void print_board(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) 
                printf("   * ");
            else
                printf("%4d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if all the tiles are visible
int game_won(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1)
                return 0;
        }
    }
    return 1;
}

// Main function to play the game
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    int board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the game board with random numbers
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
        }
    }

    // Set all the tiles as hidden
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }

    // Start the game loop
    while (!game_won(board)) {
        // Print the game board
        printf("\n");
        print_board(board);
        printf("\n");

        // Get the user input
        int row1, col1, row2, col2;
        printf("Enter the row and column of the first tile (separated by a space): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second tile (separated by a space): ");
        scanf("%d %d", &row2, &col2);

        // Check if the tiles are a match
        if (board[row1][col1] == board[row2][col2]) {
            printf("You found a match!\n");
            board[row1][col1] = board[row2][col2] = -2;
        } else {
            printf("Sorry, try again!\n");
        }
    }

    // Print the game board one last time
    printf("\n");
    print_board(board);
    printf("\n");

    // Print the victory message
    printf("Congratulations, you won the game!\n");

    return 0;
}