//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

#define BRIGHTNESS 0.5
#define CONTRAST 1.5

int main() {
    int i, j, k;
    float **image, **temp;

    // Allocate memory for the image
    image = (float **)malloc(HEIGHT * sizeof(float *));
    for (i = 0; i < HEIGHT; i++) {
        image[i] = (float *)malloc(WIDTH * sizeof(float));
    }

    // Initialize the image with random values
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = rand() / (float)RAND_MAX;
        }
    }

    // Flip the image horizontally
    temp = (float **)malloc(HEIGHT * sizeof(float *));
    for (i = 0; i < HEIGHT; i++) {
        temp[i] = (float *)malloc(WIDTH * sizeof(float));
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            temp[i][WIDTH - j - 1] = image[i][j];
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = temp[i][j];
        }
    }
    free(temp);

    // Adjust brightness and contrast
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = (image[i][j] - 0.5) * BRIGHTNESS + 0.5;
            image[i][j] = (image[i][j] * CONTRAST) + 0.5;
        }
    }

    // Save the modified image to a file
    FILE *fp = fopen("image.txt", "w");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%f ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Free memory
    for (i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}