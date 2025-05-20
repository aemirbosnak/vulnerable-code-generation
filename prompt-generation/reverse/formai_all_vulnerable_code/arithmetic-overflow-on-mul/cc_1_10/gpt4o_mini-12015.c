//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define an ASCII character set based on perceived brightness
const char* ascii_chars = " .:-=+*%@#";

// Function to calculate the brightness of a pixel
double calculate_brightness(unsigned char r, unsigned char g, unsigned char b) {
    // Perceived brightness calculation using luminance formula
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

// Function to convert an image to ASCII art
void convert_image_to_ascii(const char* input_filename, const char* output_filename, int width, int height) {
    FILE* infile = fopen(input_filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening input file.\n");
        return;
    }

    // Simple PPM (PPM format, for simplicity)
    char header[20];
    fgets(header, sizeof(header), infile);
    fgets(header, sizeof(header), infile); // skip the "P6" header detail
    fscanf(infile, "%d %d", &width, &height);
    int max_color_value;
    fscanf(infile, "%d", &max_color_value);
    fgetc(infile); // Read the newline after the max color value

    // Prepare an array for storing pixel brightness
    double* brightness_array = (double*)malloc(width * height * sizeof(double));
    if (!brightness_array) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(infile);
        return;
    }

    // Read pixel data and calculate brightness
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r = fgetc(infile);
            unsigned char g = fgetc(infile);
            unsigned char b = fgetc(infile);
            double brightness = calculate_brightness(r, g, b);
            brightness_array[y * width + x] = brightness;
        }
    }
    fclose(infile);

    // Convert brightness to ASCII characters
    FILE* outfile = fopen(output_filename, "w");
    if (!outfile) {
        fprintf(stderr, "Error opening output file.\n");
        free(brightness_array);
        return;
    }

    // Scale brightness to ASCII character range
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double brightness = brightness_array[y * width + x];
            int ascii_index = (int)((brightness / (max_color_value * 3)) * (strlen(ascii_chars) - 1));
            fputc(ascii_chars[ascii_index], outfile);
        }
        fputc('\n', outfile); // New line after each row
    }

    fclose(outfile);
    free(brightness_array);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.txt> <width> <height>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    // Convert image to ASCII
    convert_image_to_ascii(input_filename, output_filename, width, height);
    
    printf("Image converted to ASCII successfully!\n");
    
    return 0;
}