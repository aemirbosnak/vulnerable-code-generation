//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    int i, j, k, n;
    float *image = (float *)malloc(sizeof(float) * WIDTH * HEIGHT);

    // Read image data from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open image file.\n");
        exit(1);
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%f", &image[i*WIDTH+j]);
        }
    }
    fclose(fp);

    // Flip image horizontally
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH/2; j++) {
            n = j;
            k = WIDTH - j - 1;
            float temp = image[i*WIDTH+j];
            image[i*WIDTH+j] = image[i*WIDTH+k];
            image[i*WIDTH+k] = temp;
        }
    }

    // Adjust brightness and contrast
    float brightness = 1.5;
    float contrast = 1.2;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i*WIDTH+j] = brightness*image[i*WIDTH+j] + contrast;
        }
    }

    // Write modified image data to file
    FILE *fp_out = fopen("modified_image.txt", "w");
    if (fp_out == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp_out, "%.6f ", image[i*WIDTH+j]);
        }
        fprintf(fp_out, "\n");
    }
    fclose(fp_out);

    // Free memory
    free(image);

    return 0;
}