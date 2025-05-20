//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the canvas dimensions
#define WIDTH 640
#define HEIGHT 480

// Create a struct to represent each pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Declare the canvas
Pixel canvas[WIDTH][HEIGHT];

int main() {
    // Create a file to store the image
    FILE *file = fopen("image.ppm", "w");

    // Write the header to the file
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    fprintf(file, "255\n");

    // Loop through each pixel and generate its color
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate the distance from the center of the canvas
            double distance = sqrt(pow(x - WIDTH / 2, 2) + pow(y - HEIGHT / 2, 2));

            // Generate a color based on the distance
            if (distance < WIDTH / 4) {
                canvas[x][y].r = 255;
                canvas[x][y].g = 0;
                canvas[x][y].b = 0;
            } else if (distance < WIDTH / 2) {
                canvas[x][y].r = 0;
                canvas[x][y].g = 255;
                canvas[x][y].b = 0;
            } else {
                canvas[x][y].r = 0;
                canvas[x][y].g = 0;
                canvas[x][y].b = 255;
            }
        }
    }

    // Write the pixels to the file
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(file, "%d %d %d\n", canvas[x][y].r, canvas[x][y].g, canvas[x][y].b);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}