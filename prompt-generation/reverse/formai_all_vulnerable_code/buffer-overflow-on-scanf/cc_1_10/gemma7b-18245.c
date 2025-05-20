//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 grid of numbers
    int grid[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Place the treasure in a random location
    int x = rand() % 5;
    int y = rand() % 5;
    grid[x][y] = 10;

    // Initialize the player's position
    int px = 0;
    int py = 0;

    // Game loop
    while (grid[px][py] != 10) {
        // Print the grid
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        char move;
        printf("Enter your move (h/w/s/e): ");
        scanf("%c", &move);

        // Move the player
        switch (move) {
            case 'h':
                px--;
                break;
            case 'w':
                py++;
                break;
            case 's':
                px++;
                break;
            case 'e':
                py--;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }
    }

    // You found the treasure!
    printf("You found the treasure!\n");

    return 0;
}