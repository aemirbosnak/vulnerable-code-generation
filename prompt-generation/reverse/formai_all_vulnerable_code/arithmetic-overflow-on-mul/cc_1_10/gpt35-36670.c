//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a pixel is within image bounds
int withinBounds(int i, int j, int width, int height) {
    if (i >= 0 && i < height && j >= 0 && j < width) {
        return 1;
    } else {
        return 0;
    }
}

// Function to modify a pixel's RGB values
void modifyPixel(unsigned char *pixels, int i, int j, int width, int k, int f) {
    int index = (i * width + j) * 3 + k;
    pixels[index] = (unsigned char) (pixels[index] * f);
}

// Recursive function to modify entire image
void modifyImage(unsigned char *pixels, int i, int j, int width, int height, int k, int f) {
    if (withinBounds(i, j, width, height)) {
        modifyPixel(pixels, i, j, width, k, f);
        modifyImage(pixels, i+1, j, width, height, k, f);
        modifyImage(pixels, i-1, j, width, height, k, f);
        modifyImage(pixels, i, j+1, width, height, k, f);
        modifyImage(pixels, i, j-1, width, height, k, f);
    }
}

int main() {
    char fileName[50];
    printf("Enter the file name (with extension): ");
    scanf("%s", fileName);
    
    // Open the file for reading in binary mode
    FILE *file = fopen(fileName, "r+b");
    if (!file) {
        printf("Error opening file.");
        return 1;
    }
    
    // Get the width and height of the image
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    
    // Allocate memory for pixel data
    int numPixels = width * height;
    unsigned char *pixels = malloc(numPixels * 3);
    if (!pixels) {
        printf("Error allocating memory.");
        return 1;
    }
    
    // Get the pixel data from the file
    fseek(file, 54, SEEK_SET);
    fread(pixels, sizeof(unsigned char), numPixels * 3, file);
    fclose(file);
    
    // Modify the pixel data recursively
    int k;
    float f;
    printf("Enter the RGB value to modify (r/g/b): ");
    char rgb[2];
    scanf("%s", rgb);
    printf("Enter the factor to modify by: ");
    scanf("%f", &f);
    if (strcmp(rgb, "r") == 0) {
        k = 0;
    } else if (strcmp(rgb, "g") == 0) {
        k = 1;
    } else if (strcmp(rgb, "b") == 0) {
        k = 2;
    } else {
        printf("Invalid input.");
        return 1;
    }
    modifyImage(pixels, 0, 0, width, height, k, f);
    
    // Write the modified pixel data back to the file
    file = fopen(fileName, "r+b");
    if (!file) {
        printf("Error opening file.");
        return 1;
    }
    fseek(file, 54, SEEK_SET);
    fwrite(pixels, sizeof(unsigned char), numPixels * 3, file);
    fclose(file);
    printf("Image modified and saved successfully!");
    
    // Free the allocated memory
    free(pixels);
    
    return 0;
}