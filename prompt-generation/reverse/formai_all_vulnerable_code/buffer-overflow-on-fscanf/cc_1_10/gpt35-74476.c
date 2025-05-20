//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512

int clamp(int value, int min, int max) {
    return (value < min) ? min : (value > max) ? max : value;
}

void flipImage(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    unsigned char tempImage[MAX_HEIGHT][MAX_WIDTH];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            tempImage[row][col] = image[row][col];
        }
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            image[row][col] = tempImage[row][width - col - 1];
        }
    }
}

void changeBrightness(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int value = image[row][col] + brightness;
            image[row][col] = (unsigned char) clamp(value, 0, 255);
        }
    }
}

void changeContrast(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int value = (int) (factor * (image[row][col] - 128) + 128);
            image[row][col] = (unsigned char) clamp(value, 0, 255);
        }
    }
}

int main() {
    // Read image from file
    FILE *imageFile = fopen("input.pgm", "rb");
    char magicNumber[3];
    int width, height, maxVal;
    fscanf(imageFile, "%s %d %d %d", magicNumber, &width, &height, &maxVal);
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fscanf(imageFile, "%c", &image[row][col]);
        }
    }
    fclose(imageFile);

    // Flip image
    flipImage(image, width, height);

    // Change brightness
    changeBrightness(image, width, height, 50);

    // Change contrast
    changeContrast(image, width, height, 50);

    // Write image to file
    FILE *outputFile = fopen("output.pgm", "wb");
    fprintf(outputFile, "%s\n%d %d\n%d\n", magicNumber, width, height, maxVal);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fprintf(outputFile, "%c", image[row][col]);
        }
    }
    fclose(outputFile);

    return 0;
}