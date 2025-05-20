//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a fractal
void generateFractal() {
    // Set the width and height of the fractal
    int width = 500;
    int height = 500;

    // Initialize the image
    int image[width][height];

    // Generate the fractal
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Set the color of the pixel
            int r = 0;
            int g = 0;
            int b = 0;

            // Calculate the distance from the center
            double distance = sqrt(pow(j - width / 2, 2) + pow(i - height / 2, 2));

            // Set the color of the pixel based on the distance
            if (distance < 100) {
                r = 255;
                g = 255;
                b = 255;
            } else if (distance < 200) {
                r = 255;
                g = 0;
                b = 0;
            } else if (distance < 300) {
                r = 0;
                g = 255;
                b = 255;
            } else if (distance < 400) {
                r = 0;
                g = 255;
                b = 0;
            } else {
                r = 0;
                g = 0;
                b = 255;
            }

            // Set the color of the pixel in the image
            image[i][j] = (r << 16) + (g << 8) + b;
        }
    }

    // Print the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    generateFractal();
    return 0;
}