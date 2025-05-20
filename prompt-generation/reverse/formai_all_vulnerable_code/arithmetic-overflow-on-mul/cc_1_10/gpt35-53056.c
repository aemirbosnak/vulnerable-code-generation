//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
// C Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast example program
// Written in a Donald Knuth style

#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipImageHorizontal(unsigned char* image, int width, int height) {
    int y, x;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width/2; x++) { // For each row, swap pixels from opposite sides
            unsigned char temp = image[y*width + x];
            image[y*width + x] = image[y*width + (width - x - 1)];
            image[y*width + (width - x - 1)] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(unsigned char* image, int width, int height, int brightness) {
    int y, x;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int val = image[y*width + x] + brightness;
            image[y*width + x] = (val > 255) ? 255 : ((val < 0) ? 0 : val); // Clamp the value between 0 and 255
        }
    }
}

// Function to change the contrast of an image
void changeContrast(unsigned char* image, int width, int height, float contrast) {
    int y, x;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int val = (int) ((image[y*width + x] - 128) * contrast + 128); // Apply contrast formula to each pixel
            image[y*width + x] = (val > 255) ? 255 : ((val < 0) ? 0 : val); // Clamp the value between 0 and 255
        }
    }
}

// Main function
int main() {
    FILE* inputFile = fopen("image.pgm", "rb");
    FILE* outputFile = fopen("processed.pgm", "wb");

    // Read image header
    int width, height;
    fscanf(inputFile, "P5 %d %d 255 ", &width, &height);

    // Allocate memory for image
    unsigned char* image = (unsigned char*) malloc(width * height);

    // Read image data
    fread(image, sizeof(unsigned char), width * height, inputFile);

    // Flip image horizontally
    flipImageHorizontal(image, width, height);

    // Change brightness by 50
    changeBrightness(image, width, height, 50);

    // Change contrast by 1.5x
    changeContrast(image, width, height, 1.5f);

    // Write processed image to file
    fprintf(outputFile, "P5 %d %d 255 ", width, height);
    fwrite(image, sizeof(unsigned char), width * height, outputFile);

    // Clean up
    free(image);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}