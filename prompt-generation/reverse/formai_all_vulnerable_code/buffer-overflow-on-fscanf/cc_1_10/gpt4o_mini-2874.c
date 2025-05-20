//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define CHAR_WIDTH 1
#define CHAR_HEIGHT 1
#define MAX_BRIGHTNESS 255
#define ASCII_CHARS " .:-=+*%@#"

// Function to map pixel value to corresponding ASCII character
char pixel_to_ascii(int pixel_value) {
    int index = (pixel_value * (sizeof(ASCII_CHARS) - 1)) / MAX_BRIGHTNESS;
    return ASCII_CHARS[index];
}

// Function to print ASCII representation of the image
void print_ascii_art(int **image, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            char ascii_char = pixel_to_ascii(image[row][col]);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the image
void free_image(int **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

// Function to load the PGM image
int **load_pgm_image(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read the PGM header
    char header[3];
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    // Get image dimensions and max brightness
    fscanf(file, "%d %d", width, height);
    int max_brightness;
    fscanf(file, "%d", &max_brightness);
    fgetc(file); // Read the newline character after header

    // Allocate memory for the image
    int **image = (int **)malloc(*height * sizeof(int *));
    for (int i = 0; i < *height; i++) {
        image[i] = (int *)malloc(*width * sizeof(int));
    }

    // Read the pixel data
    for (int row = 0; row < *height; row++) {
        for (int col = 0; col < *width; col++) {
            image[row][col] = fgetc(file);
        }
    }

    fclose(file);
    return image;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    int **image = load_pgm_image(argv[1], &width, &height);
    if (!image) {
        return EXIT_FAILURE;
    }

    // Print ASCII representation
    print_ascii_art(image, width, height);

    // Free allocated memory
    free_image(image, height);
    return EXIT_SUCCESS;
}