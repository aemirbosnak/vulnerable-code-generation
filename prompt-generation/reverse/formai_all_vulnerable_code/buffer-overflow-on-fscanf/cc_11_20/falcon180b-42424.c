//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    // Create a 2D array to store the image
    int image[HEIGHT][WIDTH] = {0};

    // Read in the image data from a file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    int row, col;
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            fscanf(fp, "%d", &image[row][col]);
        }
    }
    fclose(fp);

    // Flip the image horizontally
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH/2; col++) {
            int temp = image[row][col];
            image[row][col] = image[row][WIDTH-1-col];
            image[row][WIDTH-1-col] = temp;
        }
    }

    // Change the brightness and contrast of the image
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            int brightness = (int)round(image[row][col] * 1.5);
            int contrast = (int)round(brightness * 0.8);
            image[row][col] = contrast;
        }
    }

    // Write the modified image data to a file
    FILE *fp2 = fopen("modified_image.txt", "w");
    if (fp2 == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            fprintf(fp2, "%d ", image[row][col]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}