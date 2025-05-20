//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef unsigned char pixel_t;

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output text>\n", argv[0]);
        return 1;
    }

    // Read image
    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        perror("fopen");
        return 1;
    }
    fseek(image, 18, SEEK_SET);  // Skip header
    int width, height;
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image is too large (maximum size is %dx%d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(image);
        return 1;
    }
    pixel_t *pixels = malloc(width * height * sizeof(pixel_t));
    fread(pixels, sizeof(pixel_t), width * height, image);
    fclose(image);

    // Convert to ASCII art
    char *text = malloc((width + 1) * height * sizeof(char));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = pixels[y * width + x];
            char c = ' ';
            if (brightness < 32) c = '.';
            else if (brightness < 64) c = ',';
            else if (brightness < 96) c = '-';
            else if (brightness < 128) c = '=';
            else if (brightness < 160) c = '+';
            else if (brightness < 192) c = '*';
            else if (brightness < 224) c = '%';
            else if (brightness < 255) c = '#';
            text[y * (width + 1) + x] = c;
        }
        text[y * (width + 1) + width] = '\n';
    }

    // Write text to file
    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("fopen");
        free(pixels);
        free(text);
        return 1;
    }
    fwrite(text, sizeof(char), (width + 1) * height, output);
    fclose(output);

    // Free memory
    free(pixels);
    free(text);

    return 0;
}