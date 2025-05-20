//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main(int argc, char *argv[]) {
    int **image = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize image with random values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Flip image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH - j - 1];
            image[i][WIDTH - j - 1] = temp;
        }
    }

    // Change brightness
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int brightness = (image[i][j] * 128) / 256;
            image[i][j] = brightness;
        }
    }

    // Change contrast
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int contrast = (image[i][j] - 128) * 2;
            image[i][j] = contrast;
        }
    }

    // Print image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}