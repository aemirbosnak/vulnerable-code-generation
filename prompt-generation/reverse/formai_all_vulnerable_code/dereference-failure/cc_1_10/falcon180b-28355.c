//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define MAGENTA 6
#define CYAN 7

int main() {
    // Initialize the screen
    int **screen = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        screen[i] = (int *)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = BLACK;
        }
    }

    // Set the colors
    int colors[8] = {
        BLACK,
        WHITE,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        MAGENTA,
        CYAN
    };

    // Seed the random number generator
    srand(time(NULL));

    // Generate the art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int color = colors[rand() % 8];
            screen[i][j] = color;
        }
    }

    // Print the art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", screen[i][j]);
        }
        printf("\n");
    }

    // Clean up the memory
    for (int i = 0; i < HEIGHT; i++) {
        free(screen[i]);
    }
    free(screen);

    return 0;
}