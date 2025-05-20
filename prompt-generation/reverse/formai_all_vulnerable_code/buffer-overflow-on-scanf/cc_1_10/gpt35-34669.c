//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to compress the given image
void compressImage(int** image, int rows, int cols) {
    // Declare a pointer to point to the compressed image
    int* compressedImage = malloc((rows * cols / 2) * sizeof(int));

    // Loop through each pixel in the image
    for (int i = 0, j = 0; i < rows * cols; i += 2, j++) {
        // Combine two adjacent pixels into a single pixel by averaging their values
        int averagePixel = (image[i / cols][i % cols] + image[(i + 1) / cols][(i + 1) % cols]) / 2;

        // Store the averaged pixel value in the compressed image array
        compressedImage[j] = averagePixel;
    }

    // Print the original image
    printf("\nOriginal Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Print the compressed image
    printf("\nCompressed Image:\n");
    for (int i = 0; i < rows * cols / 2; i++) {
        printf("%d ", compressedImage[i]);
    }

    // Free the memory allocated to the compressed image pointer
    free(compressedImage);
}

// Main function
int main() {
    // Declare variables to hold the dimensions of the image
    int rows, cols;

    // Prompt the user to enter the dimensions of the image
    printf("Enter the dimensions of the image (rows cols): ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory to hold the image
    int** image = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        image[i] = malloc(cols * sizeof(int));
    }

    // Prompt the user to enter the values of the image pixels
    for (int i = 0; i < rows; i++) {
        printf("Enter the values of row %d: ", i + 1);
        for (int j = 0; j < cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Compress the image and print the result
    compressImage(image, rows, cols);

    // Free the memory allocated to the image pointer
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);

    // Return 0 to indicate successful program execution
    return 0;
}