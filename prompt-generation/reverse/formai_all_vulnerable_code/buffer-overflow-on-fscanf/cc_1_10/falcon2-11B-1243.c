//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// Function to flip an image horizontally
void flipImage(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(unsigned char *image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = (unsigned char) (temp * (1 - factor) + 255 * factor);
        }
    }
}

// Function to change the contrast of an image
void changeContrast(unsigned char *image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = (unsigned char) (temp * (1 - factor) + 255 * factor);
        }
    }
}

int main() {
    // Read an image
    unsigned char *image = NULL;
    int width, height;
    image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        exit(1);
    }
    fscanf(stdin, "%d %d", &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(stdin, "%hhu", &image[i * width + j]);
        }
    }

    // Flip the image
    flipImage(image, width, height);

    // Change the brightness of the image
    float brightness = 0.5;
    changeBrightness(image, width, height, brightness);

    // Change the contrast of the image
    float contrast = 0.5;
    changeContrast(image, width, height, contrast);

    // Write the modified image to stdout
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(stdout, "%hhu", image[i * width + j]);
        }
        fprintf(stdout, "\n");
    }

    free(image);
    return 0;
}