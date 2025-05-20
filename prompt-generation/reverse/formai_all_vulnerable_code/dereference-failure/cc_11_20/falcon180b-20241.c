//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

int main() {
    // create image
    int **image = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // set initial values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = 255;
        }
    }

    // flip image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }

    // adjust brightness
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] += 50;
        }
    }

    // adjust contrast
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] *= 1.5;
        }
    }

    // print image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}