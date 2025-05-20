//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Convert an image to ASCII art
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output text file>\n", argv[0]);
        return 1;
    }

    // Load the input image
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "Error opening input image file\n");
        return 1;
    }

    fseek(fp, 10, SEEK_SET);  // Skip the BMP header (14 bytes)
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    unsigned char *data = malloc(width * height * 3);
    fread(data, 1, width * height * 3, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char *ascii = malloc(width * height + 1);
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r = data[i * width * 3 + j * 3];
            int g = data[i * width * 3 + j * 3 + 1];
            int b = data[i * width * 3 + j * 3 + 2];
            double y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            int c = (int)(y / 255.0 * 76 + 32);
            ascii[i * width + j] = c;
        }
    }
    ascii[width * height] = '\0';

    // Write the ASCII art to a text file
    fp = fopen(argv[2], "w");
    if (!fp) {
        fprintf(stderr, "Error opening output text file\n");
        return 1;
    }

    fprintf(fp, "%s", ascii);
    fclose(fp);

    // Clean up
    free(data);
    free(ascii);

    return 0;
}