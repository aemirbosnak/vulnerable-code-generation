//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip the image
void flip(int **img, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = img[i][j];
            img[i][j] = img[i][cols - j - 1];
            img[i][cols - j - 1] = temp;
        }
    }
}

// Function to change brightness and contrast
void change_brightness_contrast(int **img, int rows, int cols, float brightness, float contrast) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = img[i][j];
            float new_value = (value * contrast) + brightness;
            if (new_value > 255) {
                new_value = 255;
            } else if (new_value < 0) {
                new_value = 0;
            }
            img[i][j] = (int) new_value;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the image
    int **img = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        img[i] = (int *) malloc(cols * sizeof(int));
    }

    // Initialize the image with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            img[i][j] = rand() % 256;
        }
    }

    // Flip the image
    flip(img, rows, cols);

    // Change brightness and contrast
    float brightness = 0.5;
    float contrast = 1.5;
    change_brightness_contrast(img, rows, cols, brightness, contrast);

    // Print the modified image
    printf("Modified image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image
    for (int i = 0; i < rows; i++) {
        free(img[i]);
    }
    free(img);

    return 0;
}