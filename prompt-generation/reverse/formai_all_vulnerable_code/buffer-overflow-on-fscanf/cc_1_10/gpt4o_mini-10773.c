//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// ASCII characters in decreasing order of brightness
const char ascii_chars[] = " .:-=+*%@#";

// Function to compute the brightness of a pixel
float pixel_brightness(uint8_t r, uint8_t g, uint8_t b) {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

// Function to read a PPM image
unsigned char* read_ppm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported PPM format.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume the newline character

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image size exceeds maximum limit (%dx%d).\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(file);
        return NULL;
    }

    unsigned char* image = (unsigned char*) malloc(3 * (*width) * (*height));
    fread(image, 3, (*width) * (*height), file);
    fclose(file);

    return image;
}

// Function to convert the image to ASCII art
void image_to_ascii(unsigned char* image, int width, int height) {
    FILE* output = stdout;  // Output to standard output
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pos = (y * width + x) * 3;
            uint8_t r = image[pos + 0];
            uint8_t g = image[pos + 1];
            uint8_t b = image[pos + 2];

            float brightness = pixel_brightness(r, g, b);
            int ascii_index = (int)(brightness / (255 / (strlen(ascii_chars) - 1)));
            fputc(ascii_chars[ascii_index], output);
        }
        fputc('\n', output); // Newline for the next row
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char* image = read_ppm(argv[1], &width, &height);
    if (!image) {
        return 1; // Error reading image
    }

    printf("Converting image '%s' to ASCII art...\n", argv[1]);
    image_to_ascii(image, width, height);
    
    free(image);
    return 0;
}