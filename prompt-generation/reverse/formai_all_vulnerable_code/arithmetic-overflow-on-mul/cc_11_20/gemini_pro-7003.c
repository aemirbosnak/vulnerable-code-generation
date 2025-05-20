//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_image = fopen(argv[1], "rb");
    if (input_image == NULL) {
        perror("Could not open input image");
        return EXIT_FAILURE;
    }

    FILE *output_image = fopen(argv[2], "wb");
    if (output_image == NULL) {
        perror("Could not open output image");
        fclose(input_image);
        return EXIT_FAILURE;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input_image);
    fread(&height, sizeof(int), 1, input_image);

    pixel **image = malloc(height * sizeof(pixel *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(pixel));
        fread(image[i], sizeof(pixel), width, input_image);
    }

    int message_length = strlen(argv[3]);
    if (message_length > width * height) {
        fprintf(stderr, "Message is too long\n");
        for (int i = 0; i < height; i++) {
            free(image[i]);
        }
        free(image);
        fclose(input_image);
        fclose(output_image);
        return EXIT_FAILURE;
    }

    int bit_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (bit_index < message_length) {
                unsigned char bit = (argv[3][bit_index / 8] >> (bit_index % 8)) & 1;
                image[i][j].r = (image[i][j].r & 0xfe) | bit;
                bit_index++;
            }
            if (bit_index < message_length) {
                unsigned char bit = (argv[3][bit_index / 8] >> (bit_index % 8)) & 1;
                image[i][j].g = (image[i][j].g & 0xfe) | bit;
                bit_index++;
            }
            if (bit_index < message_length) {
                unsigned char bit = (argv[3][bit_index / 8] >> (bit_index % 8)) & 1;
                image[i][j].b = (image[i][j].b & 0xfe) | bit;
                bit_index++;
            }
        }
    }

    fwrite(&width, sizeof(int), 1, output_image);
    fwrite(&height, sizeof(int), 1, output_image);
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(pixel), width, output_image);
        free(image[i]);
    }
    free(image);
    fclose(input_image);
    fclose(output_image);

    return EXIT_SUCCESS;
}