//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Open the image file
    FILE* imageFile = fopen(argv[1], "rb");
    if (!imageFile) {
        fprintf(stderr, "Could not open image file\n");
        return 1;
    }

    // Read the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);

    // Read the image pixels
    int* pixels = (int*)malloc(width * height * sizeof(int));
    fread(pixels, sizeof(int), width * height, imageFile);

    // Flip the image horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[i * width + width - 1 - j];
            pixels[i * width + width - 1 - j] = temp;
        }
    }

    // Change the brightness of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int original = pixels[i * width + j];
            int newValue = original * (1.0 + argv[2][0]);
            if (newValue > 255) newValue = 255;
            if (newValue < 0) newValue = 0;
            pixels[i * width + j] = newValue;
        }
    }

    // Change the contrast of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int original = pixels[i * width + j];
            int newValue = original * (1.0 + argv[3][0]);
            if (newValue > 255) newValue = 255;
            if (newValue < 0) newValue = 0;
            pixels[i * width + j] = newValue;
        }
    }

    // Write the modified image to a new file
    FILE* outputFile = fopen(argv[4], "wb");
    if (!outputFile) {
        fprintf(stderr, "Could not create output file\n");
        return 1;
    }

    fwrite(&width, sizeof(int), 1, outputFile);
    fwrite(&height, sizeof(int), 1, outputFile);
    fwrite(pixels, sizeof(int), width * height, outputFile);

    fclose(imageFile);
    fclose(outputFile);

    return 0;
}