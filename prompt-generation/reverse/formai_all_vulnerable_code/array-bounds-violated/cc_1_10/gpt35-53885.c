//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 60

// Change these for different ASCII art styles
char ascii_chars[] = {'@', '#', '$', '%', 'X', '*', '+', '=', '-', ':', '.', ' '};
int num_ascii_chars = 12;

// Convert an RGB pixel to ASCII art char
char rgb_to_ascii(int r, int g, int b) {
    int brightness = (r + g + b) / 3;
    int char_index = (brightness * num_ascii_chars) / 255;
    return ascii_chars[char_index];
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ascii_image_converter [filename]\n");
        return 1;
    }

    char *filename = argv[1];

    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("Converting image to ASCII art...\n");

    // Read image header
    char header[54];
    fread(header, sizeof(char), 54, f);

    // Read image data
    unsigned char data[WIDTH * HEIGHT * 3];
    fread(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);

    fclose(f);

    // Print ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get RGB values for pixel
            int index = (y * WIDTH + x) * 3;
            int r = data[index + 2];
            int g = data[index + 1];
            int b = data[index];
            // Convert RGB values to ASCII char
            char ascii_char = rgb_to_ascii(r, g, b);
            // Output ASCII char
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    printf("Done!\n");

    return 0;
}