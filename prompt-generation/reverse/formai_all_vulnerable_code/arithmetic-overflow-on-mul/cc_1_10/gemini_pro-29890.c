//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Macro to swap two values
#define SWAP(a, b) { int t = a; a = b; b = t; }

// Function to flip an image horizontally
void flip_horizontally(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            SWAP(image[i * width + j], image[i * width + (width - j - 1)]);
        }
    }
}

// Function to flip an image vertically
void flip_vertically(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            SWAP(image[i * width + j], image[(height - i - 1) * width + j]);
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i * width + j] + brightness;
            if (pixel < 0) pixel = 0;
            if (pixel > 255) pixel = 255;
            image[i * width + j] = pixel;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = (128 + contrast * (image[i * width + j] - 128));
            if (pixel < 0) pixel = 0;
            if (pixel > 255) pixel = 255;
            image[i * width + j] = pixel;
        }
    }
}

int main() {
    // Open the image file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening the image file.\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 54, 1, file);

    // Get the image width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);
    if (image == NULL) {
        printf("Error allocating memory for the image data.\n");
        fclose(file);
        return 1;
    }

    // Read the image data
    fread(image, width * height, 1, file);

    // Close the image file
    fclose(file);

    // Flip the image horizontally
    flip_horizontally(image, width, height);

    // Flip the image vertically
    flip_vertically(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 1.5);

    // Open the output image file
    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        printf("Error opening the output image file.\n");
        free(image);
        return 1;
    }

    // Write the image header
    fwrite(header, 54, 1, file);

    // Write the image data
    fwrite(image, width * height, 1, file);

    // Close the output image file
    fclose(file);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}