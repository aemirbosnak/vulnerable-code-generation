//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 15

typedef struct {
    unsigned char r, g, b;
} pixel;

void read_pgm(const char *filename, pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_value;

    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fgets(magic_number, sizeof(magic_number), file);
    sscanf(magic_number, "P5%n", &width);
    fgets(magic_number, sizeof(magic_number), file);
    sscanf(magic_number, "%d%d%n", &height, &max_value, &width);

    *pixels = malloc(width * height * sizeof(pixel));

    for (size_t i = 0; i < width * height; i++) {
        fread(&((*pixels)[i].r), sizeof(unsigned char), 1, file);
        fread(&((*pixels)[i].g), sizeof(unsigned char), 1, file);
        fread(&((*pixels)[i].b), sizeof(unsigned char), 1, file);
    }

    fclose(file);
}

void print_pixel(FILE *outfile, pixel pixel) {
    for (int intensity = 255; intensity >= 0; intensity -= 50) {
        for (int j = 0; j < intensity / 32; j++)
            putchar(' ');

        for (int i = 0; i < 3; i++) {
            int color = pixel.r > intensity ? '+' : pixel.g > intensity ? '.' : pixel.b > intensity ? ':' : ' ';
            putchar(color);
        }
    }
    putchar('\n');
}

void write_ascii(const char *filename, pixel *pixels) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
        print_pixel(file, pixels[i]);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.pgm output.asc\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel *pixels;
    read_pgm(argv[1], &pixels);

    write_ascii(argv[2], pixels);

    free(pixels);

    return EXIT_SUCCESS;
}