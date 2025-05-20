//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the color palette
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

int main() {
    // Get the user input for the fractal type
    int fractalType;
    printf("Enter the fractal type (1 for Mandelbrot, 2 for Julia): ");
    scanf("%d", &fractalType);

    // Get the user input for the size of the image
    int width, height;
    printf("Enter the size of the image (width and height): ");
    scanf("%d %d", &width, &height);

    // Create the image data
    unsigned char *imageData = (unsigned char *)malloc(width * height * 3);

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the complex number for the pixel
            double real = ((double)x / (double)width) * 3.5 - 2.5;
            double imag = ((double)y / (double)height) * 2.0 - 1.0;

            // Initialize the iteration variables
            int iterations = 0;
            double zReal = 0.0;
            double zImag = 0.0;

            // Perform the Mandelbrot or Julia set iteration
            if (fractalType == 1) {
                while (iterations < MAX_ITERATIONS && zReal * zReal + zImag * zImag <= 4.0) {
                    double tempReal = zReal * zReal - zImag * zImag + real;
                    zImag = 2.0 * zReal * zImag + imag;
                    zReal = tempReal;
                    iterations++;
                }
            } else {
                while (iterations < MAX_ITERATIONS && zReal * zReal + zImag * zImag <= 4.0) {
                    double tempReal = zReal * zReal - zImag * zImag + real;
                    zImag = 2.0 * zReal * zImag + imag;
                    zReal = tempReal;
                    iterations++;
                }
            }

            // Set the color for the pixel
            int red = iterations % 8 * 31;
            int green = iterations % 16 * 15;
            int blue = iterations % 32 * 7;

            // Set the pixel color in the image data
            imageData[(y * width + x) * 3] = red;
            imageData[(y * width + x) * 3 + 1] = green;
            imageData[(y * width + x) * 3 + 2] = blue;
        }
    }

    // Save the image data to a file
    FILE *file = fopen("fractal.bmp", "wb");
    if (file == NULL) {
        printf("Error: Unable to save image to file.\n");
        return 1;
    }

    fwrite(imageData, 1, width * height * 3, file);

    fclose(file);

    printf("Image saved to file fractal.bmp.\n");

    return 0;
}