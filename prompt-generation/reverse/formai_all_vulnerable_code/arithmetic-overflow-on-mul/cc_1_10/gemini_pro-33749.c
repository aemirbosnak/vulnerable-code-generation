//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(input, 10, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, input);
    fread(&height, 4, 1, input);

    pixel **image = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        image[i] = malloc(sizeof(pixel) * width);
    }

    fread(image[0], sizeof(pixel), width * height, input);

    int message_length = strlen(argv[3]);
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (argv[3][i] >> j) & 1;
            image[i / width][i % width].r &= ~(1 << j);
            image[i / width][i % width].r |= bit << j;
        }
    }

    fseek(output, 10, SEEK_SET);
    fwrite(&width, 4, 1, output);
    fwrite(&height, 4, 1, output);

    fwrite(image[0], sizeof(pixel), width * height, output);

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}