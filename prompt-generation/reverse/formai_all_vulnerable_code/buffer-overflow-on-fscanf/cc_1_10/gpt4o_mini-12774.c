//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ASCII_WIDTH 100
#define ASCII_HEIGHT 50
#define GRAY_SCALE 70

// Function to convert pixel value to ASCII character
char pixelToAscii(uint8_t pixel) {
    const char* ascii_chars = "@%#*+=-:. "; // Characters from darkest to lightest
    return ascii_chars[pixel * (strlen(ascii_chars) - 1) / GRAY_SCALE];
}

// Function to convert an image to ASCII art
void imageToAscii(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open image file");
        return;
    }

    // Read the image header (assuming PGM format here for simplicity)
    char format[3];
    int width, height, max_gray;
    fscanf(file, "%s", format);
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &max_gray);
    fgetc(file); // consume newline character

    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported image format. Please use PGM P5 format.\n");
        fclose(file);
        return;
    }
    
    uint8_t* image = (uint8_t*)malloc(width * height);
    if (image == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(image, sizeof(uint8_t), width * height, file);
    fclose(file);

    // Calculate aspect ratio for the ASCII output
    double aspect_ratio = (double)width / height;
    int ascii_width = ASCII_WIDTH;
    int ascii_height = (int)(ascii_width / aspect_ratio);

    // Generate ASCII art
    for (int y = 0; y < ascii_height; y++) {
        for (int x = 0; x < ascii_width; x++) {
            int src_x = (int)((double)x * width / ascii_width);
            int src_y = (int)((double)y * height / ascii_height);
            uint8_t pixel = image[src_y * width + src_x];
            putchar(pixelToAscii(pixel));
        }
        putchar('\n');
    }

    free(image);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    imageToAscii(argv[1]);

    return EXIT_SUCCESS;
}