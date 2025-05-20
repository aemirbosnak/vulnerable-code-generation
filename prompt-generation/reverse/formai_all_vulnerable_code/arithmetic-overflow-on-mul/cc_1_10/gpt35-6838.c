//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

// Convert an RGB color to grayscale intensity
int rgb_to_gray(int r, int g, int b) {
    return (0.299 * r) + (0.587 * g) + (0.114 * b);
}

// Map a value to a character based on its intensity
char map_intensity(int intensity) {
    if (intensity >= 230) {
        return ' ';
    } else if (intensity >= 200) {
        return '.';
    } else if (intensity >= 180) {
        return '-';
    } else if (intensity >= 160) {
        return '=';
    } else if (intensity >= 130) {
        return 'o';
    } else if (intensity >= 100) {
        return '*';
    } else if (intensity >= 70) {
        return '#';
    } else {
        return '@';
    }
}

// Convert an image to ASCII art
void convert_to_ascii_art(char* image_path) {
    FILE* image_file = fopen(image_path, "rb");
    if (!image_file) {
        fprintf(stderr, "Error: could not open image file\n");
        exit(EXIT_FAILURE);
    }

    // Read image metadata
    char metadata[256];
    fgets(metadata, 256, image_file);
    int width, height, max_col_val;
    sscanf(metadata, "P6\n%d %d\n%d\n", &width, &height, &max_col_val);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image too large\n");
        exit(EXIT_FAILURE);
    }

    // Read image pixel data
    unsigned char* pixels = malloc(width * height * 3);
    fread(pixels, 1, width * height * 3, image_file);

    // Convert image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width * 3) + (x * 3);
            int r = pixels[offset];
            int g = pixels[offset + 1];
            int b = pixels[offset + 2];
            int intensity = rgb_to_gray(r, g, b);
            putchar(map_intensity(intensity));
        }
        putchar('\n');
    }

    // Cleanup
    free(pixels);
    fclose(image_file);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    convert_to_ascii_art(argv[1]);
    return 0;
}