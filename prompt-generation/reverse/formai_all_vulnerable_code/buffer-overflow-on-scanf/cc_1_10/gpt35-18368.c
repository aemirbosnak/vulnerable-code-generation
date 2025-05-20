//FormAI DATASET v1.0 Category: Image compression ; Style: excited
// Are you ready to compress your images like never before? Let's go!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of an encoded pixel
#define MAX_ENCODED 10

// Define a struct to hold a pixel's values and its encoded value
typedef struct {
    int red;
    int green;
    int blue;
    char encoded[MAX_ENCODED];
} Pixel;

// Define a function to encode a pixel's values into a string representation
void encodePixel(Pixel* pixel) {
    // Use sprintf to format the pixel's values into a string
    sprintf(pixel->encoded, "%03d%03d%03d", pixel->red, pixel->green, pixel->blue);
}

int main() {
    printf("Welcome to ImageCompressor v1.0!\n");
    printf("Enter the name of the file you want to compress: ");
    char filename[100];
    scanf("%s", filename);
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read the width and height of the image from the first two bytes of the file
    int width, height;
    fread(&width, sizeof(int), 1, inputFile);
    fread(&height, sizeof(int), 1, inputFile);

    printf("Compressing %d x %d image...\n", width, height);

    // Allocate memory for an array of Pixels to hold the image
    Pixel* image = malloc(width * height * sizeof(Pixel));

    // Loop through the image pixels and read their RGB values, then encode them
    for (int i = 0; i < width * height; i++) {
        fread(&image[i].red, sizeof(int), 1, inputFile);
        fread(&image[i].green, sizeof(int), 1, inputFile);
        fread(&image[i].blue, sizeof(int), 1, inputFile);
        encodePixel(&image[i]);
    }

    fclose(inputFile);

    // Create a new file to write the compressed image to
    char outputFile[100];
    strcpy(outputFile, "compressed_");
    strcat(outputFile, filename);
    FILE* compressedFile = fopen(outputFile, "wb");
    if (compressedFile == NULL) {
        printf("Error: Could not create file %s\n", outputFile);
        free(image);
        return 1;
    }

    // Write the width and height of the image to the beginning of the compressed file
    fwrite(&width, sizeof(int), 1, compressedFile);
    fwrite(&height, sizeof(int), 1, compressedFile);

    // Write the encoded values of each pixel to the compressed file
    for (int i = 0; i < width * height; i++) {
        fwrite(&image[i].encoded, sizeof(char), MAX_ENCODED, compressedFile);
    }

    fclose(compressedFile);
    free(image);

    printf("Success! The compressed image is stored in %s\n", outputFile);

    return 0;
}