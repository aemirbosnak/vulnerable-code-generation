//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip the image horizontally
void flipHorizontally(unsigned char *image, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            int index1 = y * width + x;
            int index2 = y * width + (width - x - 1);
            unsigned char temp = image[index1];
            image[index1] = image[index2];
            image[index2] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(unsigned char *image, int width, int height, int brightness) {
    int i;
    for (i = 0; i < width * height; i++) {
        int pixel = image[i] + brightness;
        if (pixel < 0) {
            image[i] = 0;
        } else if (pixel > 255) {
            image[i] = 255;
        } else {
            image[i] = pixel;
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(unsigned char *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    int i;
    for (i = 0; i < width * height; i++) {
        int pixel = (int)(factor * (image[i] - 128) + 128);
        if (pixel < 0) {
            image[i] = 0;
        } else if (pixel > 255) {
            image[i] = 255;
        } else {
            image[i] = pixel;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading in binary mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Failed to open input file: %s\n", argv[1]);
        return 1;
    }

    // Read the image header (assuming 24-bit RGB format)
    char header[54];
    fread(header, sizeof(char), 54, file);
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int size = 3 * width * height;

    // Allocate memory for the image data
    unsigned char *image = (unsigned char *)malloc(size);
    if (image == NULL) {
        printf("Failed to allocate memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), size, file);
    fclose(file);

    // Flip the image horizontally
    flipHorizontally(image, width, height);

    // Adjust the brightness of the image
    adjustBrightness(image, width, height, 50);

    // Adjust the contrast of the image
    adjustContrast(image, width, height, 50.0);

    // Open the output file for writing in binary mode
    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        printf("Failed to open output file\n");
        free(image);
        return 1;
    }

    // Write the image header and data to the output file
    fwrite(header, sizeof(char), 54, file);
    fwrite(image, sizeof(unsigned char), size, file);
    fclose(file);

    // Free the memory used for the image data
    free(image);

    printf("Image processing completed successfully\n");

    return 0;
}