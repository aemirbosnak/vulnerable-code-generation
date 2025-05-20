//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAP " .:-=+*%@#"
#define CHAR_MAP_SIZE 10

// Struct to hold image data
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load a PGM image
Image load_pgm(const char *filename) {
    Image img;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening image file\n");
        exit(1);
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Unsupported file format\n");
        exit(1);
    }

    fscanf(file, "%d %d", &img.width, &img.height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // Consume the newline character

    img.data = (unsigned char *)malloc(img.width * img.height);
    fread(img.data, sizeof(unsigned char), img.width * img.height, file);
    fclose(file);

    return img;
}

// Function to convert pixel value to an ASCII character
char pixel_to_ascii(unsigned char pixel) {
    return CHAR_MAP[(pixel * CHAR_MAP_SIZE) / 256]; // Scale to index of CHAR_MAP
}

// Function to print the ASCII art
void print_ascii_art(const Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char pixel_value = img->data[y * img->width + x];
            char ascii_char = pixel_to_ascii(pixel_value);
            putchar(ascii_char);
        }
        putchar('\n'); // New line after each row
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image img = load_pgm(argv[1]);
    print_ascii_art(&img);

    free(img.data); // Free allocated memory
    return EXIT_SUCCESS;
}