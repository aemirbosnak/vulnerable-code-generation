//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000 // Maximum width of the image
#define MAX_HEIGHT 1000 // Maximum height of the image

// Function to flip an image vertically
void flipVertical(int image[][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height/2; i++) { // Iterate through half of the height
        for (int j = 0; j < width; j++) { // Iterate through the entire width
            // Swap the pixel at (i,j) with the pixel at (height-i-1, j)
            int temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int image[][MAX_WIDTH], int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i][j] + brightness; // Add the brightness value to the pixel
            if (pixel < 0) { // If the result is less than 0, set to 0
                pixel = 0;
            }
            else if (pixel > 255) { // If the result is greater than 255, set to 255
                pixel = 255;
            }
            image[i][j] = pixel; // Update the pixel value
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int image[][MAX_WIDTH], int width, int height, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast)); // Calculate the factor
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i][j];
            pixel = (int)(factor * (pixel - 128) + 128); // Apply the factor to each pixel
            if (pixel < 0) { // If the result is less than 0, set to 0
                pixel = 0;
            }
            else if (pixel > 255) { // If the result is greater than 255, set to 255
                pixel = 255;
            }
            image[i][j] = pixel; // Update the pixel value
        }
    }
}

// Function to print an image
void printImage(int image[][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]); // Print each pixel value
        }
        printf("\n"); // Move to the next row
    }
}

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH]; // Declare the image array
    int width, height, brightness, contrast; // Declare variables for user input

    printf("Enter the width and height of the image (maximum %d x %d): ", MAX_WIDTH, MAX_HEIGHT);
    scanf("%d %d", &width, &height); // Get the width and height from user
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions too large\n");
        return 1;
    }

    printf("Enter the pixel values for the image:\n");
    for (int i = 0; i < height; i++) { // Get the pixel values from user
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter the amount to adjust the brightness (between -255 and 255): ");
    scanf("%d", &brightness); // Get the brightness adjustment value from user
    adjustBrightness(image, width, height, brightness); // Adjust the brightness of the image

    printf("Enter the amount to adjust the contrast (between -255 and 255): ");
    scanf("%d", &contrast); // Get the contrast adjustment value from user
    adjustContrast(image, width, height, contrast); // Adjust the contrast of the image

    printf("Original image:\n");
    printImage(image, width, height); // Print the original image

    flipVertical(image, width, height); // Flip the image vertically

    printf("Flipped image:\n");
    printImage(image, width, height); // Print the flipped image

    return 0;
}