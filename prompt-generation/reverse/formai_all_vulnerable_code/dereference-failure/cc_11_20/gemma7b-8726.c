//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_WATER 10

int main() {
    // Allocate memory for the water matrix
    int **water = (int**)malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++) {
        water[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the water matrix
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            water[i][j] = 0;
        }
    }

    // Simulate the water percolating
    int x = 0, y = 0, water_amount = MAX_WATER;
    srand(time(NULL));
    while (water_amount > 0) {
        // Randomly choose a direction
        int dir_x = rand() % 4 - 2;
        int dir_y = rand() % 4 - 2;

        // If the chosen direction is valid and the water amount is greater than 0
        if (dir_x != 0 && dir_y != 0 && water_amount > 0) {
            // Move the water in the chosen direction
            water[x][y] -= 1;
            water[x + dir_x][y + dir_y] += 1;

            // Update the water amount
            water_amount--;
        }

        // Increment the x and y coordinates
        x++;
        y++;
    }

    // Print the water matrix
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", water[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(water[i]);
    }
    free(water);

    return 0;
}