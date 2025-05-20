//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the dimensions of the canvas
#define WIDTH 800
#define HEIGHT 600

// Define the colors to use
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

int main(int argc, char *argv[]) {
    // Initialize the canvas
    int **canvas = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        canvas[i] = malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the pixel art
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // Choose a random color
            int color = rand() % 6;

            // Set the pixel to the chosen color
            canvas[y][x] = (color == 0)? BLACK :
                (color == 1)? WHITE :
                (color == 2)? RED :
                (color == 3)? GREEN :
                (color == 4)? BLUE :
                (color == 5)? 0xFF00FF : BLACK;
        }
    }

    // Print the pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%06X ", canvas[y][x]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < HEIGHT; i++) {
        free(canvas[i]);
    }
    free(canvas);

    return 0;
}