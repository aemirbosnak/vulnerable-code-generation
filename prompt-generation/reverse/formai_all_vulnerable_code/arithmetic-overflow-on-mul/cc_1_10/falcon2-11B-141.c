//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <zlib.h>

// Function to flip an image horizontally
void flipHorizontal(unsigned char* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(i * width) + (width - 1 - j)];
            image[(i * width) + (width - 1 - j)] = temp;
        }
    }
}

// Function to flip an image vertically
void flipVertical(unsigned char* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(i * width) + (width - 1 - j)];
            image[(i * width) + (width - 1 - j)] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(unsigned char* image, int width, int height, float brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] *= brightness;
            image[i * width + j] += (unsigned char)255;
        }
    }
}

// Function to change the contrast of an image
void changeContrast(unsigned char* image, int width, int height, float contrast) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char brightness = image[i * width + j] / 255;
            image[i * width + j] = (unsigned char)(((contrast * brightness) - 128) * 255);
        }
    }
}

int main() {
    unsigned char* image;
    int width, height;
    FILE* fp;

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    image = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    fp = fopen("image.raw", "rb");
    fread(image, width * height * sizeof(unsigned char), 1, fp);
    fclose(fp);

    // Flipping the image horizontally
    flipHorizontal(image, width, height);

    // Flipping the image vertically
    flipVertical(image, width, height);

    // Changing the brightness of the image
    changeBrightness(image, width, height, 0.5);

    // Changing the contrast of the image
    changeContrast(image, width, height, 1.5);

    // Writing the modified image to a file
    fp = fopen("image_modified.raw", "wb");
    fwrite(image, width * height * sizeof(unsigned char), 1, fp);
    fclose(fp);

    printf("Image processing completed.\n");

    free(image);

    return 0;
}