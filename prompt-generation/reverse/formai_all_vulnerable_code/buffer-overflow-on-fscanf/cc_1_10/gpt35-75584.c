//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define constants for the image dimensions
#define ROWS 300
#define COLS 300

// Define functions to perform image processing tasks
void flip_image(int image[ROWS][COLS], int rows, int cols);
void adjust_brightness(int image[ROWS][COLS], int rows, int cols, int brightness);
void adjust_contrast(int image[ROWS][COLS], int rows, int cols, float contrast);

// Main function to read in an image and perform image processing tasks
int main(void) {
    // Declare variables for the image array and input file
    int image[ROWS][COLS];
    FILE *input_file;

    // Attempt to open the input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read in the image data from the input file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(input_file, "%d", &image[i][j]);
        }
    }

    // Close the input file
    fclose(input_file);

    // Perform the desired image processing tasks
    flip_image(image, ROWS, COLS);
    adjust_brightness(image, ROWS, COLS, 50);
    adjust_contrast(image, ROWS, COLS, 1.5);

    // Print out the processed image
    printf("Processed image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Exit the program
    return 0;
}

// Function to flip an image horizontally
void flip_image(int image[ROWS][COLS], int rows, int cols) {
    // Traverse each row of the image and swap the elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols - j - 1];
            image[i][cols - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(int image[ROWS][COLS], int rows, int cols, int brightness) {
    // Traverse each pixel of the image and adjust the brightness
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] += brightness;
            // Ensure that the pixel values stay within the valid range of 0-255
            if (image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(int image[ROWS][COLS], int rows, int cols, float contrast) {
    // Traverse each pixel of the image and adjust the contrast
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = (int)(contrast * (image[i][j] - 128) + 128);
            // Ensure that the pixel values stay within the valid range of 0-255
            if (image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}