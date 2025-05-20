//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input image\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output image\n");
        return 1;
    }

    // Read the input image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, input);

    // Write the output image header
    fwrite(header, sizeof(header), 1, output);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the input image data
    pixel *data = malloc(width * height * sizeof(pixel));
    fread(data, sizeof(pixel), width * height, input);

    // Encode the message in the image data
    int message_length = strlen(argv[3]);
    for (int i = 0; i < message_length; i++) {
        char c = argv[3][i];
        for (int j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            int index = i * 8 + j;
            data[index].r = (data[index].r & ~1) | bit;
        }
    }

    // Write the output image data
    fwrite(data, sizeof(pixel), width * height, output);

    // Free the allocated memory
    free(data);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}