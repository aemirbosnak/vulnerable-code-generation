//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max size of the image
#define MAX_SIZE 100

// Define the max brightness and contrast values
#define MAX_BRIGHTNESS 255
#define MAX_CONTRAST 100

// Function to flip the image horizontally
void flipHorizontally(int image[MAX_SIZE][MAX_SIZE], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Function to flip the image vertically
void flipVertically(int image[MAX_SIZE][MAX_SIZE], int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(int image[MAX_SIZE][MAX_SIZE], int width, int height, int brightness) {
    // Calculate the factor to multiply each pixel by
    float factor = ((float)brightness / (float)MAX_BRIGHTNESS);
    
    // Multiply each pixel by the factor
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image[i][j] = (int)(image[i][j] * factor);
        }
    }
}

// Function to change the contrast of the image
void changeContrast(int image[MAX_SIZE][MAX_SIZE], int width, int height, int contrast) {
    // Define the max and min pixel values
    int max_pixel = 0;
    int min_pixel = MAX_BRIGHTNESS;
    
    // Calculate the max and min pixel values
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (image[i][j] > max_pixel) {
                max_pixel = image[i][j];
            }
            if (image[i][j] < min_pixel) {
                min_pixel = image[i][j];
            }
        }
    }
    
    // Calculate the factor to add to each pixel
    float factor = (float)(contrast - MAX_CONTRAST) / 100.0f;
    
    // Add the factor to each pixel
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int pixel = image[i][j];
            pixel = (int)((pixel - min_pixel) * factor + pixel);
            if (pixel < 0) {
                pixel = 0;
            }
            if (pixel > MAX_BRIGHTNESS) {
                pixel = MAX_BRIGHTNESS;
            }
            image[i][j] = pixel;
        }
    }
}

// Main function
int main() {
    int image[MAX_SIZE][MAX_SIZE];
    int width, height;
    
    // Read the image dimensions from a file
    FILE *input_file = fopen("input.txt", "r");
    fscanf(input_file, "%d %d", &width, &height);
    
    // Read the image pixel values from a file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(input_file, "%d", &image[i][j]);
        }
    }
    fclose(input_file);
    
    // Flip the image horizontally
    flipHorizontally(image, width, height);
    
    // Flip the image vertically
    flipVertically(image, width, height);
    
    // Change the brightness of the image
    changeBrightness(image, width, height, 200);
    
    // Change the contrast of the image
    changeContrast(image, width, height, 75);
    
    // Write the modified image pixel values to a file
    FILE *output_file = fopen("output.txt", "w");
    fprintf(output_file, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(output_file, "%d ", image[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
    
    return 0;
}