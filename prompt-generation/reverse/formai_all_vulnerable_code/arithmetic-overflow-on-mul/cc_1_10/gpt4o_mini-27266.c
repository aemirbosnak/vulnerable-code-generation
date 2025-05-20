//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function prototypes
void print_usage(const char *prog_name);
int load_image(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height);
void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height);
char pixel_to_ascii(unsigned char r, unsigned char g, unsigned char b);

int main(int argc, char *argv[]) {
    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3]; // Store RGB values
    int width, height;

    // Ensure proper argument count
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Load the image from the file
    if (load_image(argv[1], image, &width, &height) != 0) {
        fprintf(stderr, "Error loading image.\n");
        return EXIT_FAILURE;
    }

    // Convert the image to ASCII art
    convert_to_ascii(image, width, height);

    return EXIT_SUCCESS;
}

// Function to display usage instructions
void print_usage(const char *prog_name) {
    printf("Usage: %s <image_file>\n", prog_name);
    printf("Converts an image to ASCII art (limited to 100x100 pixels).\n");
}

// Function to load an image
int load_image(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return -1;
    }

    // Assuming the file is in a PPM format (P6)
    char header[3];
    fscanf(file, "%2s\n%d %d\n255\n", header, width, height); // Read header

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed maximum allowed size of 100x100.\n");
        fclose(file);
        return -1;
    }

    // Read pixel data
    fread(image, 3, (*width) * (*height), file);
    fclose(file);
    return 0;
}

// Function to convert the image pixels to ASCII art
void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    const int scaling_factor = 6; // Adjust scaling to fit ASCII 256 characters
    for (int i = 0; i < height; i += scaling_factor) {
        for (int j = 0; j < width; j += scaling_factor) {
            char ascii_char = pixel_to_ascii(image[i][j][0], image[i][j][1], image[i][j][2]);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

// Function to convert RGB pixel to an ASCII character
char pixel_to_ascii(unsigned char r, unsigned char g, unsigned char b) {
    float gray_value = (0.299 * r + 0.587 * g + 0.114 * b); // Convert to grayscale
    // Map gray value to ASCII
    const char *ascii_chars = "@%#*+=-:. "; // Characters from dark to light
    int index = (int)(gray_value * (strlen(ascii_chars) - 1) / 255);
    return ascii_chars[index];
}