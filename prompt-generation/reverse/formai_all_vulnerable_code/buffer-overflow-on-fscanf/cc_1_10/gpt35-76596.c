//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to convert color image to grayscale
void convertToGrayscale(unsigned char* image, int rows, int cols) {
    int row, col;
    unsigned char* ptr = image;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            // Extract RGB values of a pixel
            unsigned char r = *(ptr++);
            unsigned char g = *(ptr++);
            unsigned char b = *(ptr++);
            // Convert to grayscale using luminosity method
            unsigned char gray = (unsigned char) (0.21 * r + 0.72 * g + 0.07 * b);
            // Write grayscale value back to RGB channels
            *(ptr - 3) = gray;
            *(ptr - 2) = gray;
            *(ptr - 1) = gray;
        }
    }
}

// Function to convert image to ASCII art
void convertToASCII(unsigned char* image, int rows, int cols) {
    char ascii[MAX_SIZE][MAX_SIZE];
    // Set ASCII characters based on pixel brightness
    char charset[] = " .:-=+*#%@";
    int range = sizeof(charset) - 1;
    int row, col;
    unsigned char* ptr = image;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            // Extract grayscale value of a pixel
            unsigned char gray = *(ptr++);
            // Map grayscale value to corresponding ASCII character
            int index = (int) (gray * range / 255.0);
            ascii[row][col] = charset[index];
        }
    }
    // Print ASCII art to console
    printf("\n");
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            printf("%c", ascii[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    FILE* fp;
    unsigned char* image;
    int rows, cols, channels;

    // Open image file
    fp = fopen("image.jpg", "rb");
    if (!fp) {
        printf("Error: failed to open image file.\n");
        return 1;
    }

    // Read image dimensions and allocate memory for image data
    fscanf(fp, "P6\n%d %d\n%d\n", &cols, &rows, &channels);
    image = (unsigned char*) malloc(rows * cols * channels);

    // Read image data
    fread(image, sizeof(unsigned char), rows * cols * channels, fp);

    // Close image file
    fclose(fp);

    // Convert image to grayscale
    convertToGrayscale(image, rows, cols);

    // Convert image to ASCII art and print to console
    convertToASCII(image, rows, cols);

    // Free memory allocated for image data
    free(image);

    return 0;
}