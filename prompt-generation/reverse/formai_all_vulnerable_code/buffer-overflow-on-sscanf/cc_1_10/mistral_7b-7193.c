//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define WIDTH 8
#define HEIGHT 8
#define MAX_COLOR 16
#define FILENAME_LENGTH 50

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

void read_palette(char *filename, Color palette[MAX_COLOR]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open palette file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) && i < MAX_COLOR) {
        Color color;

        sscanf(line, "%c%c%c %hhu %hhu %hhu", &color, &color, &color, &color.r, &color.g, &color.b);
        palette[i] = color;
        i++;
    }

    fclose(fp);
}

void generate_pixel_art(Color palette[MAX_COLOR], int **pixels) {
    int i, j, index;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            index = (i / 2) * WIDTH + j / 2;
            (*pixels)[i * WIDTH + j] = palette[index].r | (palette[index + 1].g << 5) | (palette[index + 2].b << 3);
        }
    }
}

void save_image(char *filename, int *pixels) {
    FILE *fp;
    int i;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "PIXEL\n%d %d\n255\n", WIDTH, HEIGHT);

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(fp, "%02x", pixels[i]);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    Color palette[MAX_COLOR];
    int *pixels;

    if (argc != 3) {
        printf("Usage: %s <palette.txt> <output.raw>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_palette(argv[1], palette);
    pixels = malloc(WIDTH * HEIGHT * sizeof(int));
    generate_pixel_art(palette, &pixels);
    save_image(argv[2], pixels);
    free(pixels);

    printf("Pixel art generated successfully.\n");
    return EXIT_SUCCESS;
}