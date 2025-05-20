//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

int main() {
    // Read image file and store pixel values in a 2D array
    FILE *imageFile = fopen("input_image.txt", "r");
    int numRows, numCols;
    fscanf(imageFile, "%d %d\n", &numRows, &numCols);
    int **image = (int **) malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        image[i] = (int *) malloc(numCols * sizeof(int));
        for (int j = 0; j < numCols; j++) {
            fscanf(imageFile, "%d", &image[i][j]);
        }
    }
    fclose(imageFile);
    
    // Flip image horizontally
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][numCols - 1 - j];
            image[i][numCols - 1 - j] = temp;
        }
    }
    
    // Adjust brightness and contrast of image
    float brightness = 0.5;
    float contrast = 0.8;
    float pixelValueMultiplier = (MAX_PIXEL_VALUE * (contrast - 1)) + (MAX_PIXEL_VALUE * brightness);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int newPixelValue = (int) (pixelValueMultiplier * (image[i][j] - MAX_PIXEL_VALUE/2) + MAX_PIXEL_VALUE/2);
            if (newPixelValue < 0) {
                newPixelValue = 0;
            }
            if (newPixelValue > MAX_PIXEL_VALUE) {
                newPixelValue = MAX_PIXEL_VALUE;
            }
            image[i][j] = newPixelValue;
        }
    }
    
    // Write modified image to file
    FILE *outputFile = fopen("output_image.txt", "w");
    fprintf(outputFile, "%d %d\n", numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            fprintf(outputFile, "%d ", image[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
    
    // Free memory used by image array
    for (int i = 0; i < numRows; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}