//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
    // Load image
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error loading image\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image data
    unsigned char *data = (unsigned char*)malloc(3 * width * height);

    // Read image data
    fread(data, 3, width * height, fp);

    fclose(fp);

    // Flip image horizontally
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int temp = data[(y * width + x) * 3];
            data[(y * width + x) * 3] = data[(y * width + width - x - 1) * 3];
            data[(y * width + width - x - 1) * 3] = temp;
        }
    }

    // Change brightness and contrast
    float brightness = 1.5;
    float contrast = 1.5;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;

            float r = data[index] * brightness;
            float g = data[index + 1] * brightness;
            float b = data[index + 2] * brightness;

            r = (r - 128) * contrast + 128;
            g = (g - 128) * contrast + 128;
            b = (b - 128) * contrast + 128;

            data[index] = r;
            data[index + 1] = g;
            data[index + 2] = b;
        }
    }

    // Save modified image
    FILE *fp2 = fopen("modified_image.bmp", "wb");
    if (fp2 == NULL) {
        printf("Error saving image\n");
        exit(1);
    }

    fwrite(header, 1, 54, fp2);
    fwrite(data, 3, width * height, fp2);

    fclose(fp2);

    free(data);

    return 0;
}