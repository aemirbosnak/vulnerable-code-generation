//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum image dimensions
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define the maximum ASCII character scale
#define MAX_SCALE 255

// Define the threshold for black and white pixels
#define THRESHOLD 100

// Define the ASCII character set
const char* ASCII_CHARS = "@#$%&*=-+;:,.   ";

// Function to load an image file
void load_image(const char* filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("Error: Unable to open file \"%s\"\n", filename);
        exit(1);
    }
    
    // Read the header information
    char header[54];
    fread(header, 1, 54, file);
    
    // Read the image dimensions
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    
    // Read the image data
    int row_size = (*width * 3 + 3) & (~3);
    unsigned char data[row_size];
    
    for (int i = 0; i < *height; i++) {
        fread(data, 1, row_size, file);
        
        for (int j = 0; j < *width; j++) {
            image[i][j] = data[j * 3];
        }
    }
    
    fclose(file);
}

// Function to convert an image to ASCII art
void ascii_convert(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int scale) {
    // Calculate the scale factor
    float scale_factor = (float)(MAX_SCALE - 1) / scale;
    
    // Iterate over each pixel and convert to ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Normalize the pixel value
            float norm_value = (float)image[i][j] / 255.0;
            
            // Calculate the ASCII code for the pixel
            int ascii_code = norm_value * scale_factor + 0.5;
            
            // Clamp the ASCII code to the valid range
            if (ascii_code < 0) {
                ascii_code = 0;
            } else if (ascii_code >= scale) {
                ascii_code = scale - 1;
            }
            
            // Print the ASCII character to the console
            printf("%c", ASCII_CHARS[ascii_code]);
        }
        
        printf("\n");
    }
}

int main() {
    // Load the image file
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    
    load_image("image.bmp", image, &width, &height);
    
    // Convert the image to ASCII art
    ascii_convert(image, width, height, 10);
    
    return 0;
}