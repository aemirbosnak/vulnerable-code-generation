//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main() {
    // Initialize the image array
    int image[HEIGHT][WIDTH];

    // Read the image from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);

    // Flip the image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH - j - 1];
            image[i][WIDTH - j - 1] = temp;
        }
    }

    // Change the brightness of the image by 50%
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = (int)(image[i][j] * 1.5);
        }
    }

    // Change the contrast of the image by 25%
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = (int)(image[i][j] * 0.75 + 50);
        }
    }

    // Write the modified image to file
    FILE *fp2 = fopen("modified_image.txt", "w");
    if (fp2 == NULL) {
        printf("Error: could not open modified image file.\n");
        exit(1);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(fp2, "%d ", image[i][j]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}