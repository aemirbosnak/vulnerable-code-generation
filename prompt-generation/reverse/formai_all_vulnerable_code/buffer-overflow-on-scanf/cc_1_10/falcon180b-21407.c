//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Function to flip an image
void flipImage(int width, int height, int **image) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Function to change brightness/contrast
void changeBrightnessContrast(int width, int height, int **image, float brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = image[i][j];
            float newValue = (float)value * brightness + 128;
            newValue = (newValue * contrast) / 255;
            if (newValue > 255) {
                newValue = 255;
            } else if (newValue < 0) {
                newValue = 0;
            }
            image[i][j] = (int)newValue;
        }
    }
}

// Function to display an image
void displayImage(int width, int height, int **image) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    scanf("%d %d", &width, &height);

    // Allocate memory for the image
    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Read in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Flip the image
    flipImage(width, height, image);

    // Change brightness/contrast
    float brightness = 2.0;
    float contrast = 1.5;
    changeBrightnessContrast(width, height, image, brightness, contrast);

    // Display the original image
    printf("Original Image:\n");
    displayImage(width, height, image);

    // Display the modified image
    printf("\nModified Image:\n");
    displayImage(width, height, image);

    return 0;
}