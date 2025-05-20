//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output ascii art>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        perror("Error opening input image");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output ASCII art");
        return 1;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);

    pixel *pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, sizeof(pixel), width * height, input);
    fclose(input);

    char *chars = " .,-~:;=*#%@";
    int num_chars = strlen(chars);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = (pixels[y * width + x].r + pixels[y * width + x].g + pixels[y * width + x].b) / 3;
            int char_index = (int)(brightness / 255.0 * (num_chars - 1));
            fprintf(output, "%c", chars[char_index]);
        }
        fprintf(output, "\n");
    }

    free(pixels);
    fclose(output);

    return 0;
}