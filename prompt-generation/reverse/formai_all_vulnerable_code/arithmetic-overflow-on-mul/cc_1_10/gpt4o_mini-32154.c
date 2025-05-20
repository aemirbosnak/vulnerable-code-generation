//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS " .:-=+*%@#" // Characters used for ASCII representation

// Struct for RGB color values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

// Function to convert RGB to grayscale
unsigned char rgb_to_grayscale(Color color) {
    return (0.299 * color.r + 0.587 * color.g + 0.114 * color.b);
}

// Function to map grayscale value to ASCII character
char gray_to_ascii(unsigned char gray) {
    int index = gray * (strlen(ASCII_CHARS) - 1) / 255; // Normalize to ASCII char range
    return ASCII_CHARS[index];
}

// Function to read a PPM image file
int read_ppm(const char *filename, Color image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Only P6 format is supported.\n");
        fclose(file);
        return -1;
    }
    
    fscanf(file, "%d %d", width, height);
    int max_value;
    fscanf(file, "%d", &max_value);
    fgetc(file); // Read the newline after max_value

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image exceeds maximum dimensions of %dx%d\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(file);
        return -1;
    }

    // Read pixel data
    fread(image[0], sizeof(Color), (*width) * (*height), file);
    fclose(file);
    return 0;
}

// Function to convert image to ASCII art
void image_to_ascii(Color image[MAX_HEIGHT][MAX_WIDTH], int width, int height, char output[MAX_HEIGHT][MAX_WIDTH]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char gray = rgb_to_grayscale(image[y][x]);
            output[y][x] = gray_to_ascii(gray);
        }
    }
}

// Function to print the ASCII art
void print_ascii_art(char output[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(output[y][x]);
        }
        putchar('\n');
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_image.ppm>\n", argv[0]);
        return 1;
    }

    Color image[MAX_HEIGHT][MAX_WIDTH];
    char output[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    if (read_ppm(argv[1], image, &width, &height) != 0) {
        return 1; // Error handling if reading fails
    }

    image_to_ascii(image, width, height, output);
    print_ascii_art(output, width, height);

    return 0;
}