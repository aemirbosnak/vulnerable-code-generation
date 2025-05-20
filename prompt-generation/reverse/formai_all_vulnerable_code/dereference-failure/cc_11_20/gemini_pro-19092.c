//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t pixels[MAX_WIDTH][MAX_HEIGHT];
} image_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output text>\n", argv[0]);
        return 1;
    }

    // Load the input image
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return 1;
    }

    image_t image;
    fread(&image.width, sizeof(int), 1, input);
    fread(&image.height, sizeof(int), 1, input);
    fread(image.pixels, sizeof(pixel_t), image.width * image.height, input);
    fclose(input);

    // Convert the image to ASCII art
    char *output = malloc(image.width * image.height * 2);
    if (output == NULL) {
        perror("malloc");
        return 1;
    }

    int index = 0;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            // Calculate the average color of the pixel
            int average = (image.pixels[x][y].red + image.pixels[x][y].green + image.pixels[x][y].blue) / 3;

            // Convert the average color to an ASCII character
            char character;
            if (average <= 32) {
                character = '@';
            } else if (average <= 64) {
                character = '#';
            } else if (average <= 96) {
                character = '$';
            } else if (average <= 128) {
                character = '%';
            } else if (average <= 160) {
                character = '*';
            } else if (average <= 192) {
                character = '+';
            } else if (average <= 224) {
                character = '=';
            } else {
                character = ' ';
            }

            // Write the ASCII character to the output string
            output[index++] = character;
            output[index++] = ' ';
        }

        // Add a newline character to the output string
        output[index++] = '\n';
    }

    // Write the output string to the output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("fopen");
        return 1;
    }

    fwrite(output, strlen(output), 1, output_file);
    fclose(output_file);

    free(output);

    return 0;
}