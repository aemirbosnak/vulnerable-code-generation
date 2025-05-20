//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <secret message>\n", argv[0]);
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

    // Read the input image header
    BYTE header[54];
    if (fread(header, 54, 1, input) != 1) {
        perror("fread");
        return EXIT_FAILURE;
    }

    // Write the output image header
    if (fwrite(header, 54, 1, output) != 1) {
        perror("fwrite");
        return EXIT_FAILURE;
    }

    // Read the input image data
    BYTE *data = malloc(header[18] * header[22]);
    if (data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (fread(data, header[18] * header[22], 1, input) != 1) {
        perror("fread");
        return EXIT_FAILURE;
    }

    // Encode the secret message in the input image data
    int messageLength = strlen(argv[3]);
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (argv[3][i] >> j) & 1;
            data[i * 8 + j] = (data[i * 8 + j] & 0xFE) | bit;
        }
    }

    // Write the output image data
    if (fwrite(data, header[18] * header[22], 1, output) != 1) {
        perror("fwrite");
        return EXIT_FAILURE;
    }

    // Free the allocated memory
    free(data);

    // Close the files
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}