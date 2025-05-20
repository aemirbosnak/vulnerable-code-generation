//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 200
#define WIDTH 200

int main() {
    int i, j, k;
    int img[HEIGHT][WIDTH];
    int new_img[HEIGHT][WIDTH];
    int mean = 0;
    int sum = 0;

    // Read in the image
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            scanf("%d", &img[i][j]);
        }
    }

    // Calculate the mean
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            sum += img[i][j];
        }
    }

    mean = sum / (HEIGHT * WIDTH);

    // Flip the image
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            new_img[i][j] = img[HEIGHT - i - 1][j];
        }
    }

    // Change brightness/contrast
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            new_img[i][j] = (new_img[i][j] - mean) * 2 + mean;
        }
    }

    // Print out the new image
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%d ", new_img[i][j]);
        }
        printf("\n");
    }

    return 0;
}