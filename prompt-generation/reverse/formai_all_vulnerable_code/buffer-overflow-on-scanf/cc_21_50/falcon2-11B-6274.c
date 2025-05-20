//Falcon2-11B DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a 10x10 grid of characters
    char grid[10][10] = {0};

    // Fill the grid with '*' symbols
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '*';
        }
    }

    // Print the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    // Start a game loop
    int game_over = 0;
    while (!game_over) {
        // Get user input
        char direction;
        printf("Enter direction (N, S, E, W): ");
        scanf(" %c", &direction);

        // Check if the user's input is valid
        if (direction!= 'N' && direction!= 'S' && direction!= 'E' && direction!= 'W') {
            printf("Invalid input. Please enter N, S, E, or W.\n");
            continue;
        }

        // Move the player
        switch (direction) {
            case 'N':
                if (grid[0][9]!= '*') {
                    grid[0][9] = '*';
                }
                break;
            case 'S':
                if (grid[9][0]!= '*') {
                    grid[9][0] = '*';
                }
                break;
            case 'E':
                if (grid[9][9]!= '*') {
                    grid[9][9] = '*';
                }
                break;
            case 'W':
                if (grid[0][0]!= '*') {
                    grid[0][0] = '*';
                }
                break;
        }

        // Check if the player has won
        if (grid[0][0] == '*' && grid[0][1] == '*' && grid[0][2] == '*' &&
            grid[1][0] == '*' && grid[1][1] == '*' && grid[1][2] == '*' &&
            grid[2][0] == '*' && grid[2][1] == '*' && grid[2][2] == '*' &&
            grid[3][0] == '*' && grid[3][1] == '*' && grid[3][2] == '*' &&
            grid[4][0] == '*' && grid[4][1] == '*' && grid[4][2] == '*' &&
            grid[5][0] == '*' && grid[5][1] == '*' && grid[5][2] == '*' &&
            grid[6][0] == '*' && grid[6][1] == '*' && grid[6][2] == '*' &&
            grid[7][0] == '*' && grid[7][1] == '*' && grid[7][2] == '*' &&
            grid[8][0] == '*' && grid[8][1] == '*' && grid[8][2] == '*') {
                game_over = 1;
                printf("Congratulations! You have won the game!\n");
            }

        // Print the grid
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}