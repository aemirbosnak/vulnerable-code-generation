//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_PIXEL_VALUE 256
#define ASCII_CHARS_SIZE 70

int main(int argc, char **argv) {
    // check that the input argument is provided
    if (argc < 2) {
        printf("Please provide a path to the image to convert to ASCII art.\n");
        return 1;
    }

    // open the image file
    FILE *image_file = fopen(argv[1], "r");
    if (image_file == NULL) {
        printf("Error: could not open the image file.\n");
        return 1;
    }

    // read the header of the image
    char format[3];
    int width, height, max_pixel_value;
    fscanf(image_file, "%s\n%d %d\n%d\n", format, &width, &height, &max_pixel_value);

    // check that the format is PGM
    if (strcmp(format, "P5") != 0) {
        printf("Error: unsupported image format.\n");
        return 1;
    }

    // read the pixels into an array
    unsigned char *pixels = malloc(width * height * sizeof(unsigned char));
    fread(pixels, sizeof(unsigned char), width * height, image_file);

    // close the image file
    fclose(image_file);

    // calculate the brightness of each pixel
    int brightness[width][height];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            brightness[x][y] = pixels[x + y * width];
        }
    }

    // create an ASCII art string using a set of characters with varying brightness
    char ascii_chars[ASCII_CHARS_SIZE] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    char ascii_art[WIDTH * HEIGHT];
    int ascii_index;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // calculate the average brightness of the surrounding pixels
            int total_brightness = 0;
            int count = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int pixel_x = x * width / WIDTH + i;
                    int pixel_y = y * height / HEIGHT + j;
                    if (pixel_x >= 0 && pixel_x < width && pixel_y >= 0 && pixel_y < height) {
                        total_brightness += brightness[pixel_x][pixel_y];
                        count++;
                    }
                }
            }
            int avg_brightness = total_brightness / count;

            // find the ASCII character that closest matches the average brightness
            ascii_index = (int) ((float) avg_brightness / (float) MAX_PIXEL_VALUE * (ASCII_CHARS_SIZE - 1));
            ascii_art[x + y * WIDTH] = ascii_chars[ascii_index];
        }
        ascii_art[(y + 1) * WIDTH - 1] = '\n';
    }
    ascii_art[WIDTH * HEIGHT - 1] = '\0';

    // print the ASCII art
    printf("%s", ascii_art);

    // free the memory
    free(pixels);

    return 0;
}