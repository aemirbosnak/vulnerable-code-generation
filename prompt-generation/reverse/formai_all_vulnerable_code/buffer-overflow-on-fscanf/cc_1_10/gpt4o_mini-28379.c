//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define ASCII_WIDTH 100 // Width of ASCII output
#define ASCII_HEIGHT 50 // Height of ASCII output
#define MAX_PIXELS 256  // Maximum pixel value for grayscale

// Function to convert an RGB pixel to grayscale
uint8_t rgb_to_grayscale(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
}

// Function to load a PPM image from file
uint8_t** load_ppm(const char* filename, int* width, int* height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported PPM format\n");
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file);  // Consume the newline after max color value

    uint8_t** image = (uint8_t**)malloc((*height) * sizeof(uint8_t*));
    for (int i = 0; i < *height; i++) {
        image[i] = (uint8_t*)malloc((*width) * 3 * sizeof(uint8_t));
        fread(image[i], sizeof(uint8_t), (*width) * 3, file);
    }

    fclose(file);
    return image;
}

// Function to free the image memory
void free_image(uint8_t** image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

// Function to convert the image to ASCII art
void convert_to_ascii(uint8_t** image, int width, int height) {
    const char* ascii_chars = "@%#*+=-:. "; // Characters from darkest to lightest
    int num_ascii_chars = strlen(ascii_chars);
    
    for (int y = 0; y < height; y += height / ASCII_HEIGHT) {
        for (int x = 0; x < width; x += width / ASCII_WIDTH) {
            int r = image[y][3 * x];
            int g = image[y][3 * x + 1];
            int b = image[y][3 * x + 2];
            uint8_t gray = rgb_to_grayscale(r, g, b);
            int ascii_index = (gray * (num_ascii_chars - 1)) / 255;
            putchar(ascii_chars[ascii_index]);
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    uint8_t** image = load_ppm(argv[1], &width, &height);
    if (!image) {
        return EXIT_FAILURE;
    }

    // Resize the image to fit the ASCII output dimensions
    for (int i = height - 1; i > 0; i -= height / ASCII_HEIGHT) {
        for (int j = width - 1; j > 0; j -= width / ASCII_WIDTH) {
            uint8_t r = image[i][3 * j];
            uint8_t g = image[i][3 * j + 1];
            uint8_t b = image[i][3 * j + 2];
            image[i][3 * j] = rgb_to_grayscale(r, g, b);
            image[i][3 * j + 1] = 0; // Clear G
            image[i][3 * j + 2] = 0; // Clear B
        }
    }

    printf("ASCII Art Representation:\n");
    convert_to_ascii(image, width, height);
    
    free_image(image, height);
    return EXIT_SUCCESS;
}