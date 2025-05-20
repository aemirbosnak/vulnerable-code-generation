//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
/* 
  The following program converts a given image to ASCII art.
  It uses the concept of Claude Shannon's Information Theory and 
  calculates the average information per pixel to determine 
  the ASCII character that should be used to represent it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768
#define MAX_PIXEL 256

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

char ascii_chars[MAX_PIXEL] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void read_image(char *filename, Pixel **pixels, int *height, int *width) {
    FILE *fp = fopen(filename, "rb");
    char format[3];
    int max_pixel;

    fscanf(fp, "%s\n%d %d\n%d\n", format, width, height, &max_pixel);

    if (strcmp(format, "P6") != 0 || *width > MAX_WIDTH || *height > MAX_HEIGHT || max_pixel > MAX_PIXEL) {
        printf("***ERROR: Invalid Image Format***\n");
        exit(EXIT_FAILURE);
    }

    *pixels = (Pixel *) malloc((*height) * (*width) * sizeof(Pixel));
    fread(*pixels, sizeof(Pixel), (*height) * (*width), fp);
    fclose(fp);
}

void write_image(char *filename, char **ascii, int height) {
    FILE *fp = fopen(filename, "w");

    for (int i = 0; i < height; i++) {
        fprintf(fp, "%s\n", ascii[i]);
    }

    fclose(fp);
}

char calculate_ascii_char(Pixel pixel) {
    int average_brightness = (int) ((pixel.r + pixel.g + pixel.b) / 3.0);
    int index = (int) round((average_brightness * 9.0) / 255.0);

    return ascii_chars[index];
}

void convert_to_ascii(Pixel *pixels, char **ascii, int height, int width) {
    int total_brightness = 0;
    int count = 0;

    for (int i = 0; i < height; i++) {
      ascii[i] = (char *) malloc((width + 1) * sizeof(char));

      for (int j = 0; j < width; j++) {
            char ascii_char = calculate_ascii_char(pixels[i * (width + 1) + j]);

            ascii[i][j] = ascii_char;
            total_brightness += (int) ((pixels[i * (width + 1) + j].r + pixels[i * (width + 1) + j].g + pixels[i * (width + 1) + j].b) / 3.0);
            count++;
        }

        ascii[i][width] = '\0';
    }

    int average_brightness = (int) ((total_brightness * 1.0) / count);
    int index = (int) round((average_brightness * 9.0) / 255.0);

    printf("Average brightness of the image: %d\n", average_brightness);
    printf("ASCII character for average brightness (\"%c\"): %d\n", ascii_chars[index], index);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_text_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Pixel *pixels;
    int height, width;

    read_image(argv[1], &pixels, &height, &width);

    char **ascii = (char **) malloc(height * sizeof(char *));

    convert_to_ascii(pixels, ascii, height, width);
    write_image(argv[2], ascii, height);

    free(pixels);
    free(ascii);

    return 0;
}