//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

int main() {
    // Initialize variables
    int width, height;
    char grid[MAX_WIDTH][MAX_HEIGHT];
    int i, j, x, y, next_x, next_y;
    int visited[MAX_WIDTH][MAX_HEIGHT];

    // Get the width and height of the grid from the user
    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);

    // Initialize the grid with 0s and 1s
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            grid[i][j] = (i % 2 == 0) ? 1 : 0;
        }
    }

    // Generate a random number between 0 and 1
    double random = drand48();

    // Start the game loop
    while (1) {
        // Choose a random cell to place the X
        x = (int) (width * random);
        y = (int) (height * random);

        // Check if the cell is empty
        if (grid[y][x] == 0) {
            // Place the X in the cell
            grid[y][x] = 1;

            // Mark the cell as visited
            visited[y][x] = 1;

            // Find the next cell to place the O
            next_x = (int) (width * (random - 0.5));
            next_y = (int) (height * (random - 0.5));

            // Check if the next cell is empty
            if (grid[next_y][next_x] == 0) {
                // Place the O in the cell
                grid[next_y][next_x] = 2;

                // Mark the cell as visited
                visited[next_y][next_x] = 1;
            }
        }

        // Print the grid
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (visited[height][width] == 1) {
            break;
        }
    }

    // Print the final grid
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}