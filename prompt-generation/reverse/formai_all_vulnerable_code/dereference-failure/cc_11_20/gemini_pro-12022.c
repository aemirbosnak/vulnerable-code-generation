//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
    // Read the image data from a file
    FILE *fp = fopen("image.jpg", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    unsigned char *data = malloc(WIDTH * HEIGHT * 3);
    if (data == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    fread(data, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii = malloc(WIDTH * HEIGHT);
    if (ascii == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        // Calculate the average brightness of the pixel
        int r = data[i * 3 + 0];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];
        int brightness = (r + g + b) / 3;

        // Convert the brightness to an ASCII character
        char c;
        if (brightness < 32) {
            c = '@';
        } else if (brightness < 64) {
            c = '%';
        } else if (brightness < 96) {
            c = '#';
        } else if (brightness < 128) {
            c = '*';
        } else if (brightness < 160) {
            c = '+';
        } else if (brightness < 192) {
            c = '=';
        } else if (brightness < 224) {
            c = '-';
        } else {
            c = ' ';
        }

        // Store the ASCII character in the output array
        ascii[i] = c;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii[i * WIDTH + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(data);
    free(ascii);

    return EXIT_SUCCESS;
}