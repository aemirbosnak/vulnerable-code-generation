//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum string length
#define MAX_LENGTH 1000

// Define ASCII character set
char ascii_chars[] = {' ', '.', ',', ':', ';', 'i', 'l', 'o', 'x', '8', '$', '@'};

// Define function to get color intensity value
int get_intensity_value(int r, int g, int b) {
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

// Define function to get corresponding ASCII character based on intensity value
char get_ascii_char(int intensity) {
    int char_index = (intensity * 12) / 255;
    return ascii_chars[char_index];
}

// Define main function
int main() {
    // Open input file
    FILE* input_file = fopen("input_image.bmp", "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read file header
    unsigned char file_header[14];
    fread(file_header, sizeof(unsigned char), 14, input_file);

    // Read image header
    unsigned char image_header[40];
    fread(image_header, sizeof(unsigned char), 40, input_file);

    // Get image dimensions
    int width = *(int*)&image_header[4];
    int height = *(int*)&image_header[8];

    // Calculate padding
    int padding = (4 - (width * 3) % 4) % 4;

    // Allocate memory for image data
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    // Read image data
    fread(image_data, sizeof(unsigned char), width * height * 3, input_file);

    // Close input file
    fclose(input_file);

    // Open output file
    FILE* output_file = fopen("output_ascii.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Loop through image data and convert to ASCII
    int intensity;
    char ascii_char;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get RGB values
            int r = (int)image_data[(i * width + j) * 3 + 2];
            int g = (int)image_data[(i * width + j) * 3 + 1];
            int b = (int)image_data[(i * width + j) * 3];

            // Get intensity value
            intensity = get_intensity_value(r, g, b);

            // Get corresponding ASCII character
            ascii_char = get_ascii_char(intensity);

            // Print ASCII character to output file
            fputc(ascii_char, output_file);
        }
        // Print newline character to output file
        fputc('\n', output_file);

        // Skip padding
        fseek(input_file, padding, SEEK_CUR);
    }

    // Close output file
    fclose(output_file);

    // Free memory for image data
    free(image_data);

    return 0;
}