//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of integers
    int board[MAX_NUM][MAX_NUM] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    // Place the treasure in a random location
    board[rand() % MAX_NUM][rand() % MAX_NUM] = 1;

    // Display the board
    for (int r = 0; r < MAX_NUM; r++) {
        for (int c = 0; c < MAX_NUM; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Get the player's move
    int row, column;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &column);

    // Check if the move is valid
    if (board[row][column] == 0) {
        printf("Invalid move.\n");
    } else {
        // Dig for the treasure
        board[row][column] = 2;

        // Display the updated board
        for (int r = 0; r < MAX_NUM; r++) {
            for (int c = 0; c < MAX_NUM; c++) {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Check if the treasure has been found
        if (board[row][column] == 1) {
            printf("You found the treasure!\n");
        } else {
            printf("Sorry, the treasure was not found.\n");
        }
    }

    return 0;
}