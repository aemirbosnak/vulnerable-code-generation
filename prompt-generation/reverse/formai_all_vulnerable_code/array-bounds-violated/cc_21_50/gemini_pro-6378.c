//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH  80
#define HEIGHT 24
#define DELAY  20000

struct cell {
    int x, y;
    int alive;
};

int main(void) {
    struct cell cells[WIDTH * HEIGHT];
    int i, j, k, l, n, count;

    // Initialize the cells
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            cells[i * WIDTH + j].x = i;
            cells[i * WIDTH + j].y = j;
            cells[i * WIDTH + j].alive = rand() % 2;
        }
    }

    // Main loop
    while (1) {
        // Clear the screen
        printf("\033[2J\033[1;1H");

        // Display the cells
        for (i = 0; i < WIDTH; i++) {
            for (j = 0; j < HEIGHT; j++) {
                if (cells[i * WIDTH + j].alive) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        // Update the cells
        for (i = 0; i < WIDTH; i++) {
            for (j = 0; j < HEIGHT; j++) {
                // Count the number of alive neighbors
                count = 0;
                for (k = -1; k <= 1; k++) {
                    for (l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) continue;
                        if (i + k >= 0 && i + k < WIDTH && j + l >= 0 && j + l < HEIGHT && cells[(i + k) * WIDTH + (j + l)].alive) {
                            count++;
                        }
                    }
                }

                // Apply the rules of the Game of Life
                if (cells[i * WIDTH + j].alive) {
                    if (count == 2 || count == 3) cells[i * WIDTH + j].alive = 1;
                    else cells[i * WIDTH + j].alive = 0;
                } else {
                    if (count == 3) cells[i * WIDTH + j].alive = 1;
                }
            }
        }

        // Sleep
        usleep(DELAY);
    }

    return 0;
}