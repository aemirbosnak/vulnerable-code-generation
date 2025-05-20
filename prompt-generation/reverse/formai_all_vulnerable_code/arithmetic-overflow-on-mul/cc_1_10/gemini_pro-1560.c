//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = image[i * width + j] + brightness;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = round(factor * (image[i * width + j] - 128) + 128);
        }
    }
}

// Main function
int main() {
    // Read the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Read the image data from the file
    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 1.5);

    // Write the image to a file
    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Write the image dimensions to the file
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);

    // Write the image data to the file
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}