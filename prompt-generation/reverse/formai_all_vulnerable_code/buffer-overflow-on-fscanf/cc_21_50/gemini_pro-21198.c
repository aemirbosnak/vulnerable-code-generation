//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char header[256];
    if (fscanf(fp, "%s", header) != 1) {
        printf("Error: could not read header from file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    if (strcmp(header, "P3") != 0) {
        printf("Error: file %s is not a valid PPM file\n", argv[1]);
        fclose(fp);
        return 1;
    }

    int width, height;
    if (fscanf(fp, "%d %d", &width, &height) != 2) {
        printf("Error: could not read width and height from file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image is too large (maximum size is %d x %d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(fp);
        return 1;
    }

    int maxval;
    if (fscanf(fp, "%d", &maxval) != 1) {
        printf("Error: could not read maxval from file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    if (maxval != 255) {
        printf("Error: file %s is not a 24-bit PPM file\n", argv[1]);
        fclose(fp);
        return 1;
    }

    unsigned char *pixels = malloc(3 * width * height);
    if (pixels == NULL) {
        printf("Error: could not allocate memory for pixels\n");
        fclose(fp);
        return 1;
    }

    if (fread(pixels, 1, 3 * width * height, fp) != 3 * width * height) {
        printf("Error: could not read pixels from file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // Create a 2D array of characters to store the ASCII art
    char **ascii_art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(width * sizeof(char));
    }

    // Convert the pixels to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = pixels[3 * (i * width + j) + 0];
            int g = pixels[3 * (i * width + j) + 1];
            int b = pixels[3 * (i * width + j) + 2];

            // Calculate the average brightness of the pixel
            int brightness = (r + g + b) / 3;

            // Map the brightness to an ASCII character
            char c;
            if (brightness < 32) {
                c = '#';
            } else if (brightness < 64) {
                c = '&';
            } else if (brightness < 96) {
                c = '@';
            } else if (brightness < 128) {
                c = '%';
            } else if (brightness < 160) {
                c = '*';
            } else if (brightness < 192) {
                c = '+';
            } else if (brightness < 224) {
                c = '=';
            } else {
                c = ' ';
            }

            ascii_art[i][j] = c;
        }
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);

    free(pixels);

    return 0;
}