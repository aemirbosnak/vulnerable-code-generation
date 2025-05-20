//Code Llama-13B DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
/*
 * Pixel Art Generator
 *
 * A simple program that generates a unique pixel art image based on the
 * user's input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Struct to represent a pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to generate a random pixel color
Pixel generateRandomColor() {
    Pixel pixel;
    pixel.r = rand() % 256;
    pixel.g = rand() % 256;
    pixel.b = rand() % 256;
    return pixel;
}

// Function to print a pixel
void printPixel(Pixel pixel) {
    printf("\x1B[38;2;%d;%d;%dm██\x1B[0m", pixel.r, pixel.g, pixel.b);
}

// Function to generate a pixel art image
void generatePixelArt(int width, int height) {
    Pixel pixels[width][height];
    srand(time(NULL));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pixels[i][j] = generateRandomColor();
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printPixel(pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);
    generatePixelArt(width, height);
    return 0;
}