//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width, height;
    unsigned char **data;
} Image;

void load_pgm(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_value;
    unsigned char buffer[3];

    fgets(magic_number, sizeof(magic_number), fp);
    sscanf(magic_number, "P5%d%d", &image->width, &image->height);
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "255%d", &max_value);

    image->data = calloc(image->height, sizeof(unsigned char *));
    for (int y = 0; y < image->height; y++)
        image->data[y] = calloc(image->width, sizeof(unsigned char));

    for (int y = 0; y < image->height; y++)
        for (int x = 0; x < image->width; x++) {
            fread(buffer, 1, 3, fp);
            image->data[y][x] = buffer[2];
        }

    fclose(fp);
}

void save_ascii(const Image *image, const char *filename) {
    const int symbols[] = { ' ', '.', ':', '!', '*', 'o', 'x', '+', '-', '|' };
    FILE *fp = fopen(filename, "w");

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y][x] / 32;
            for (int symbol_index = 0; symbol_index < 10; symbol_index++) {
                if (value <= symbols[symbol_index + 1] - symbols[symbol_index]) {
                    fprintf(fp, "%c", symbols[symbol_index]);
                    break;
                }
            }
        }
        putc('\n', fp);
    }

    fclose(fp);
}

void free_image(Image *image) {
    for (int y = 0; y < image->height; y++)
        free(image->data[y]);
    free(image->data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.pgm output.asc\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image image;
    load_pgm(argv[1], &image);
    save_ascii(&image, argv[2]);
    free_image(&image);

    return EXIT_SUCCESS;
}