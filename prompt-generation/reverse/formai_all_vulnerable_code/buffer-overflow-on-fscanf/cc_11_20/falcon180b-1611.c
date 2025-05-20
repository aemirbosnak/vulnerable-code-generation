//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    int image[WIDTH][HEIGHT];

    // Read image from file
    FILE* fp = fopen("image.dat", "rb");
    if (fp == NULL) {
        printf("Error reading image file.\n");
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);

    // Flip image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }

    // Change brightness and contrast
    int brightness = 50;
    int contrast = 30;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = image[i][j];

            int newValue = (value * (100 + brightness)) / 100 + contrast;

            if (newValue > 255) {
                newValue = 255;
            } else if (newValue < 0) {
                newValue = 0;
            }

            image[i][j] = newValue;
        }
    }

    // Save modified image to file
    FILE* fp2 = fopen("modified_image.dat", "wb");
    if (fp2 == NULL) {
        printf("Error writing image file.\n");
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(fp2, "%d ", image[i][j]);
        }
    }

    fclose(fp2);

    return 0;
}