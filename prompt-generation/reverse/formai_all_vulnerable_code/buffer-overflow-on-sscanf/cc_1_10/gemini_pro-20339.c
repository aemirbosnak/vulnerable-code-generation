//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters used to represent the shades of gray
char* asciiChars = " .,-~:;!*#%@";

// Convert an image to ASCII art
char* imageToASCII(const char* filename) {
    // Open the image file
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned int width, height;
    fread(&width, sizeof(unsigned int), 1, fp);
    fread(&height, sizeof(unsigned int), 1, fp);

    // Read the image data
    unsigned char* data = malloc(width * height * 3);
    fread(data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    char* ascii = malloc(width * height + 1);
    for (int i = 0; i < width * height; i++) {
        // Calculate the average gray value of the pixel
        int gray = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2]) / 3;

        // Map the gray value to an ASCII character
        ascii[i] = asciiChars[gray / 32];
    }
    ascii[width * height] = '\0';

    // Return the ASCII art representation of the image
    return ascii;
}

// Print the ASCII art to the console
void printASCII(char* ascii, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the ASCII art
void freeASCII(char* ascii) {
    free(ascii);
}

// Main function
int main(int argc, char** argv) {
    // Check if the user specified an image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Convert the image to ASCII art
    char* ascii = imageToASCII(argv[1]);
    if (!ascii) {
        return 1;
    }

    // Get the dimensions of the image
    int width, height;
    sscanf(ascii, "%d %d", &width, &height);

    // Print the ASCII art to the console
    printASCII(ascii, width, height);

    // Free the memory allocated for the ASCII art
    freeASCII(ascii);

    return 0;
}