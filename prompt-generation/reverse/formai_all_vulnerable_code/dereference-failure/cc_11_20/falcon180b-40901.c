//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for the image
    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Fill the image with random values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % MAX_VALUE;
    }

    // Print the original image
    printf("Original Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Flip the image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            unsigned char temp = image[i * WIDTH + j];
            image[i * WIDTH + j] = image[i * WIDTH + WIDTH - 1 - j];
            image[i * WIDTH + WIDTH - 1 - j] = temp;
        }
    }

    // Print the flipped image
    printf("\nFlipped Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Change the brightness of the image
    int brightness = rand() % 256;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i * WIDTH + j] += brightness;
            if (image[i * WIDTH + j] > MAX_VALUE) {
                image[i * WIDTH + j] = MAX_VALUE;
            } else if (image[i * WIDTH + j] < 0) {
                image[i * WIDTH + j] = 0;
            }
        }
    }

    // Print the brightened image
    printf("\nBrightened Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Change the contrast of the image
    int contrast = rand() % 256;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = (image[i * WIDTH + j] * contrast) / MAX_VALUE;
            if (value > MAX_VALUE) {
                value = MAX_VALUE;
            } else if (value < 0) {
                value = 0;
            }
            image[i * WIDTH + j] = value;
        }
    }

    // Print the contrasted image
    printf("\nContrasted Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image
    free(image);

    return 0;
}