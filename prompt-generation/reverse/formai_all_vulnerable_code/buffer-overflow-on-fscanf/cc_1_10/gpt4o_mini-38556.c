//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Function to read a PGM image file
uint8_t* read_pgm(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Error: Unsupported image format %s\n", format);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int max_gray;
    fscanf(file, "%d", &max_gray);
    fgetc(file); // Skip the single newline character

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions exceed limits (%d x %d)\n", 
                MAX_WIDTH, MAX_HEIGHT);
        fclose(file);
        return NULL;
    }

    size_t size = *width * *height;
    uint8_t *data = (uint8_t *)malloc(size);
    fread(data, sizeof(uint8_t), size, file);
    fclose(file);
    return data;
}

// Function to convert image data to ASCII
void image_to_ascii(const uint8_t *image, int width, int height) {
    const char *ascii_chars = "@%#*+=-:. "; // From dense to sparse
    int num_chars = strlen(ascii_chars);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gray_value = image[y * width + x];
            int idx = (gray_value * (num_chars - 1)) / 255; // Map gray value to ASCII index
            putchar(ascii_chars[idx]);
        }
        putchar('\n'); // New line after each row
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    uint8_t *image_data = read_pgm(argv[1], &width, &height);
    if (!image_data) {
        return EXIT_FAILURE;
    }

    image_to_ascii(image_data, width, height);
    free(image_data); // Cleanup
    return EXIT_SUCCESS;
}