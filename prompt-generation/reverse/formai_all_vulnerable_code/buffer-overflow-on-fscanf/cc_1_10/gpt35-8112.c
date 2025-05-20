//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the width and height of the image
#define WIDTH 50
#define HEIGHT 30

// Define the maximum and minimum values for intensity
#define MAX_INTENSITY 255
#define MIN_INTENSITY 0

// Struct for storing RGB values
typedef struct {
    int r;
    int g;
    int b;
} RGBColor;

// Function to get the average intensity of the RGB values
int getAverageIntensity(RGBColor color) {
    int avg = (color.r + color.g + color.b) / 3;
    return avg;
}

// Function to map the intensity of the pixel to a ASCII character
char mapIntensityToChar(int intensity) {
    char charMap[] = " .:-=+*X#%@";
    int range = MAX_INTENSITY - MIN_INTENSITY;
    int value = floor(((intensity - MIN_INTENSITY) * 10) / range);
    return charMap[value];
}

int main() {
    // Declare a 2D array to store the ASCII art
    char asciiArt[HEIGHT][WIDTH];

    // Declare a 2D array to store the RGB values of the image
    RGBColor image[HEIGHT][WIDTH];

    // Read the image and store the RGB values
    FILE *fp;
    fp = fopen("image.txt", "r");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d,%d,%d", &image[i][j].r, &image[i][j].g, &image[i][j].b);
        }
    }
    fclose(fp);

    // Convert RGB values to ASCII characters and store in asciiArt array
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int intensity = getAverageIntensity(image[i][j]);
            asciiArt[i][j] = mapIntensityToChar(intensity);
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}