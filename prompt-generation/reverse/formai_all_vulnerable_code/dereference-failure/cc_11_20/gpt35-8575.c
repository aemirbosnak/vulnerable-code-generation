//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if image file name is provided as argument
    if(argc < 2) {
        printf("No image file name provided. Exiting...\n");
        return 1;
    }
    // Open the image file
    FILE *file = fopen(argv[1], "rb+");
    if(file == NULL) {
        printf("Could not open image file. Exiting...\n");
        return 1;
    }
    // Read image header
    char header[54];
    fread(header, sizeof(char), 54, file);
    // Get image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    // Get image padding
    int padding = (4 - (width * sizeof(int)) % 4) % 4;
    // Allocate memory for image pixels
    int **pixels = (int**)malloc(sizeof(int*) * height);
    for(int i = 0; i < height; ++i) {
        pixels[i] = (int*)malloc(sizeof(int) * width);
    }
    // Read image pixels
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            fread(&pixels[i][j], sizeof(int), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }
    // Process image
    // Sample: Convert image to grayscale
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            int r = (pixels[i][j] >> 16) & 0xff;
            int g = (pixels[i][j] >> 8) & 0xff;
            int b = pixels[i][j] & 0xff;
            int gray = (r * 0.3 + g * 0.59 + b * 0.11);
            pixels[i][j] = (gray << 16) | (gray << 8) | gray;
        }
        fseek(file, padding, SEEK_CUR);
    }
    // Write modified image to file
    rewind(file);
    fwrite(header, sizeof(char), 54, file);
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            fwrite(&pixels[i][j], sizeof(int), 1, file);
        }
        for(int j = 0; j < padding; ++j) {
            fputc(0, file);
        }
    }
    // Free memory
    for(int i = 0; i < height; ++i) {
        free(pixels[i]);
    }
    free(pixels);
    // Close file
    fclose(file);
    printf("Image processing completed successfully.\n");
    return 0;
}