//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Function to flip an image
void flipImage(int **image, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height / 2; j++) {
            int temp = image[j][i];
            image[j][i] = image[height - j - 1][i];
            image[height - j - 1][i] = temp;
        }
    }
}

// Function to change brightness/contrast
void changeBrightnessContrast(int **image, int width, int height, float brightness, float contrast) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int value = image[j][i];
            value = round((value * contrast) + brightness);
            value = value > 255? 255 : value;
            value = value < 0? 0 : value;
            image[j][i] = value;
        }
    }
}

int main() {
    int width, height;
    printf("Enter width of the image: ");
    scanf("%d", &width);
    printf("Enter height of the image: ");
    scanf("%d", &height);

    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Fill the image with random values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Flip the image
    flipImage(image, width, height);

    // Change brightness/contrast
    float brightness = 1.5;
    float contrast = 1.2;
    changeBrightnessContrast(image, width, height, brightness, contrast);

    // Print the image
    printf("Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}