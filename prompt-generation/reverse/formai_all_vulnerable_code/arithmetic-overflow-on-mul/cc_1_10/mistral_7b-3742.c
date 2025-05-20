//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 50
#define HEIGHT 10

typedef struct {
    unsigned char r, g, b;
} pixel_t;

void read_image(const char *filename, pixel_t **pixels) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    if (width * HEIGHT * 3 != sizeof(pixel_t) * WIDTH * HEIGHT) {
        fprintf(stderr, "Invalid image dimensions\n");
        exit(EXIT_FAILURE);
    }

    *pixels = malloc(WIDTH * HEIGHT * sizeof(pixel_t));
    fread(*pixels, sizeof(pixel_t), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void free_image(pixel_t *pixels) {
    free(pixels);
}

void print_ascii_art(const char *title, const pixel_t *pixels) {
    printf("\033[1m%s\033[0m\n", title);
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            pixel_t px = pixels[y * WIDTH + x];
            char ch = ' ';
            if (px.r > 128) ch = '*';
            if (px.g > 128) ch = (ch == ' ') ? ':' : ch;
            if (px.b > 128) ch = (ch == ' ') ? '.' : ch;
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel_t *pixels;
    read_image(argv[1], &pixels);

    char title[100];
    strcpy(title, "ASCII Art from ");
    strcat(title, argv[1]);

    print_ascii_art(title, pixels);
    free_image(pixels);

    return EXIT_SUCCESS;
}