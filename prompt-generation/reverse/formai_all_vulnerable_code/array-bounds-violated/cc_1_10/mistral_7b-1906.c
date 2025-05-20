//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char **pixels;
} Image;

void read_pgm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_value;
    unsigned char buffer[3];

    fgets(magic_number, sizeof(magic_number), file);
    magic_number[strlen(magic_number) - 1] = '\0';

    if (strcmp(magic_number, "PGM") != 0) {
        printf("Invalid file format.\n");
        exit(1);
    }

    fscanf(file, "%d %d %d\n", &width, &height, &max_value);
    image->width = width;
    image->height = height;

    image->pixels = malloc(height * sizeof(unsigned char *));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(width * sizeof(unsigned char));
        fread(image->pixels[i], 1, width, file);
    }
}

void write_pgm(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "PGM\n%d %d %d\n255\n", image->width, image->height, 255);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%d ", image->pixels[y][x]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void print_image(const Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->pixels[y][x] < 128 ? '.' : '#');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.pgm output.asc\n", argv[0]);
        return 1;
    }

    Image image;
    read_pgm(argv[1], &image);
    print_image(&image);
    write_pgm(argv[2], &image);

    for (int y = 0; y < image.height; y++)
        free(image.pixels[y]);
    free(image.pixels);

    return 0;
}