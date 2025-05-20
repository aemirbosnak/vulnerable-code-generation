//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to flip the image horizontally
void flipHorizontal(int image[][3], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image[i][j * 3];
            image[i][j * 3] = image[height - 1 - i][j * 3];
            image[height - 1 - i][j * 3] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(int image[][3], int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][j * 3];
            int g = image[i][j * 3 + 1];
            int b = image[i][j * 3 + 2];
            r = round(r * brightness);
            g = round(g * brightness);
            b = round(b * brightness);
            image[i][j * 3] = r;
            image[i][j * 3 + 1] = g;
            image[i][j * 3 + 2] = b;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(int image[][3], int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][j * 3];
            int g = image[i][j * 3 + 1];
            int b = image[i][j * 3 + 2];
            r = round((r - 0.5) * contrast + 0.5);
            g = round((g - 0.5) * contrast + 0.5);
            b = round((b - 0.5) * contrast + 0.5);
            image[i][j * 3] = r;
            image[i][j * 3 + 1] = g;
            image[i][j * 3 + 2] = b;
        }
    }
}

int main() {
    int image[][3] = {
        {255, 0, 0}, {0, 255, 0}, {0, 0, 255},
        {255, 255, 0}, {255, 0, 255}, {0, 255, 255},
        {255, 0, 0}, {0, 255, 0}, {0, 0, 255}
    };
    int width = 3;
    int height = 3;

    // Flipping the image horizontally
    flipHorizontal(image, width, height);

    // Changing the brightness of the image
    int brightness = 1.5;
    changeBrightness(image, width, height, brightness);

    // Changing the contrast of the image
    int contrast = 0.5;
    changeContrast(image, width, height, contrast);

    // Printing the modified image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j * 3]);
        }
        printf("\n");
    }

    return 0;
}