//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    int image[WIDTH][HEIGHT];
    int flipped_image[WIDTH][HEIGHT];
    int bright_image[WIDTH][HEIGHT];
    int contrast_image[WIDTH][HEIGHT];

    // Read in the image file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: Image file not found.\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);

    // Flip the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            flipped_image[i][j] = image[HEIGHT - i - 1][WIDTH - j - 1];
        }
    }

    // Change brightness and contrast
    int brightness = 50;
    int contrast = 20;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = image[i][j];
            int new_value = (value * (100 + brightness)) / 100;
            bright_image[i][j] = new_value;

            int diff = new_value - (brightness * 128);
            new_value = (new_value * contrast) / 100;
            contrast_image[i][j] = new_value + diff;
        }
    }

    // Save the modified images
    FILE *fp_flipped = fopen("flipped_image.txt", "w");
    if (fp_flipped == NULL) {
        printf("Error: Could not save flipped image.\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp_flipped, "%d ", flipped_image[i][j]);
        }
        fprintf(fp_flipped, "\n");
    }

    fclose(fp_flipped);

    FILE *fp_bright = fopen("bright_image.txt", "w");
    if (fp_bright == NULL) {
        printf("Error: Could not save bright image.\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp_bright, "%d ", bright_image[i][j]);
        }
        fprintf(fp_bright, "\n");
    }

    fclose(fp_bright);

    FILE *fp_contrast = fopen("contrast_image.txt", "w");
    if (fp_contrast == NULL) {
        printf("Error: Could not save contrast image.\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp_contrast, "%d ", contrast_image[i][j]);
        }
        fprintf(fp_contrast, "\n");
    }

    fclose(fp_contrast);

    return 0;
}