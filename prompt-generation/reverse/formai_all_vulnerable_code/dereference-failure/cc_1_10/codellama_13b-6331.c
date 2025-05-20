//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
/*
 * C Program to Perform Basic Image Processing Tasks
 * Flipping an image, changing brightness/contrast
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define MAX_SIZE MAX_WIDTH * MAX_HEIGHT

int main() {
    // Declare variables
    int width, height;
    int x, y, i, j;
    int img_in[MAX_SIZE];
    int img_out[MAX_SIZE];
    int brightness, contrast;

    // Read image dimensions and pixels from file
    FILE *fp = fopen("image.pgm", "rb");
    if (!fp) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Read magic number
    char magic[2];
    fread(magic, sizeof(char), 2, fp);
    if (strcmp(magic, "P5") != 0) {
        printf("Error: Invalid file format\n");
        return 1;
    }

    // Read width and height
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Read maximum gray value
    int max_gray;
    fread(&max_gray, sizeof(int), 1, fp);

    // Read pixels
    for (i = 0; i < width * height; i++) {
        img_in[i] = fgetc(fp);
    }

    // Close file
    fclose(fp);

    // Flip image horizontally
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            img_out[y * width + x] = img_in[x * height + y];
        }
    }

    // Change brightness and contrast
    brightness = 100;
    contrast = 100;
    for (i = 0; i < width * height; i++) {
        img_out[i] = (img_out[i] - 128) * contrast / 100 + 128 + brightness;
    }

    // Save output image
    fp = fopen("output.pgm", "wb");
    if (!fp) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Write magic number
    fwrite(magic, sizeof(char), 2, fp);

    // Write width and height
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write maximum gray value
    fwrite(&max_gray, sizeof(int), 1, fp);

    // Write pixels
    for (i = 0; i < width * height; i++) {
        fputc(img_out[i], fp);
    }

    // Close file
    fclose(fp);

    return 0;
}