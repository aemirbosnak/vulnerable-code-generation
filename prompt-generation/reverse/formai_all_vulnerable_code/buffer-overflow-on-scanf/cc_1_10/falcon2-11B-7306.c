//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image vertically
void flip_vertical(int *img, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = img[j + cols - 1 - i];
            img[j + cols - 1 - i] = img[i + j];
            img[i + j] = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void adjust_brightness_contrast(int *img, int rows, int cols, int brightness, int contrast) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = img[i + j];
            int new_value = (value * contrast) + (brightness * brightness);
            img[i + j] = new_value;
        }
    }
}

int main() {
    int rows, cols, brightness, contrast;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the brightness and contrast values: ");
    scanf("%d %d", &brightness, &contrast);

    // Allocate memory for the image
    int *img = (int *)malloc(rows * cols * sizeof(int));

    // Initialize the image with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            img[i + j] = rand() % 256;
        }
    }

    // Flip the image vertically
    flip_vertical(img, rows, cols);

    // Change the brightness/contrast of the image
    adjust_brightness_contrast(img, rows, cols, brightness, contrast);

    // Print the flipped and adjusted image
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", img[i + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(img);

    return 0;
}