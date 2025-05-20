//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input image file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output image file: %s\n", argv[2]);
        return 1;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);

    Pixel *pixels = malloc(width * height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * height, input_file);

    int message_length = strlen(argv[3]);
    for (int i = 0; i < message_length; i++) {
        char c = argv[3][i];
        for (int j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            int pixel_index = i * 8 + j;
            pixels[pixel_index].red &= ~1;
            pixels[pixel_index].red |= bit;
        }
    }

    fwrite(pixels, sizeof(Pixel), width * height, output_file);

    free(pixels);
    fclose(input_file);
    fclose(output_file);

    return 0;
}