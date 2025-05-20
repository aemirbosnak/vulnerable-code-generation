//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for proper number of arguments
    if (argc < 2) {
        fprintf(stderr, "Error: You must specify an input file.\n");
        exit(EXIT_FAILURE);
    }
     
    FILE* input = fopen(argv[1], "rb");
    
    // Check if file opened successfully
    if (!input) {
        fprintf(stderr, "Error: Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the header of the image to get height and width
    int width, height;
    char header[54];
    fread(header, sizeof(char), 54, input);
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Create buffer to hold image data
    int size = 3 * width * height;
    unsigned char* data = (unsigned char*)malloc(sizeof(unsigned char) * size);
    fread(data, sizeof(unsigned char), size, input);

    // Loop through each pixel and convert it to ASCII art
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get RGB values for current pixel
            int offset = (i * width + j) * 3;
            int r = data[offset];
            int g = data[offset + 1];
            int b = data[offset + 2];

            // Determine which ASCII character to use based on grayscale value
            int grayscale = (r + g + b) / 3;
            char ascii_char;
            if (grayscale < 50) {
                ascii_char = '@';
            }
            else if (grayscale < 100) {
                ascii_char = '#';
            }
            else if (grayscale < 150) {
                ascii_char = '&';
            }
            else if (grayscale < 200) {
                ascii_char = '$';
            }
            else if (grayscale < 250) {
                ascii_char = '!';
            }
            else {
                ascii_char = ' ';
            }

            // Output ASCII character
            putchar(ascii_char);
        }
        putchar('\n');
    }

    // Free memory and close file
    free(data);
    fclose(input);

    return 0;
}