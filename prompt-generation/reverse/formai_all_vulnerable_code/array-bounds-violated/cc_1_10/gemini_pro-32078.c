//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Get the image width and height
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Read the image data
    pixel data[width * height];
    fread(data, sizeof(pixel), width * height, fp);

    // Close the file
    fclose(fp);

    // Flip the image horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            pixel temp = data[i * width + j];
            data[i * width + j] = data[i * width + width - j - 1];
            data[i * width + width - j - 1] = temp;
        }
    }

    // Change the brightness and contrast
    float brightness = 0.5;
    float contrast = 1.5;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i * width + j].r = (unsigned char)(data[i * width + j].r * brightness * contrast);
            data[i * width + j].g = (unsigned char)(data[i * width + j].g * brightness * contrast);
            data[i * width + j].b = (unsigned char)(data[i * width + j].b * brightness * contrast);
        }
    }

    // Write the image to a file
    fp = fopen("image_modified.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the header information
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write the image data
    fwrite(data, sizeof(pixel), width * height, fp);

    // Close the file
    fclose(fp);

    return 0;
}