//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input image> <output image> <message> <write>\n", argv[0]);
        printf("Where <write> is 1 for writing into the image, and 0 for extracting the message.\n");
        return 1;
    }

    // Read the input image
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Error opening input image.\n");
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, in);
    fread(&height, sizeof(int), 1, in);

    // Read the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    fread(data, sizeof(pixel), width * height, in);
    fclose(in);

    // Convert the message to binary
    int len = strlen(argv[3]);
    unsigned char *binary = malloc(len * 8);
    for (int i = 0; i < len; i++) {
        unsigned char c = argv[3][i];
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = (c >> j) & 1;
        }
    }

    // Write the message into the image
    if (strcmp(argv[4], "1") == 0) {
        for (int i = 0; i < len * 8; i++) {
            int idx = i / 3;
            int bit = i % 3;
            if (binary[i]) {
                data[idx].r |= 1 << bit;
            } else {
                data[idx].r &= ~(1 << bit);
            }
        }
    }

    // Extract the message from the image
    else if (strcmp(argv[4], "0") == 0) {
        int idx = 0;
        for (int i = 0; i < len * 8; i++) {
            int bit = i % 3;
            if (data[idx].r & (1 << bit)) {
                binary[i] = 1;
            } else {
                binary[i] = 0;
            }
            if (bit == 2) {
                idx++;
            }
        }
    }

    // Convert the binary message back to text
    char *message = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        unsigned char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= binary[i * 8 + j] << j;
        }
        message[i] = c;
    }
    message[len] = '\0';

    // Write the output image
    FILE *out = fopen(argv[2], "wb");
    if (out == NULL) {
        printf("Error opening output image.\n");
        return 1;
    }

    // Write the image dimensions
    fwrite(&width, sizeof(int), 1, out);
    fwrite(&height, sizeof(int), 1, out);

    // Write the image data
    fwrite(data, sizeof(pixel), width * height, out);
    fclose(out);

    // Print the message
    if (strcmp(argv[4], "0") == 0) {
        printf("Message: %s\n", message);
    }

    // Free the allocated memory
    free(data);
    free(binary);
    free(message);

    return 0;
}