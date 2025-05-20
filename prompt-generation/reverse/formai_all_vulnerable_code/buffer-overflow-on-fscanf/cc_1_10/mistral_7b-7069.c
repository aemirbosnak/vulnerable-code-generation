//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define PALETTE_SIZE 16

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color palette[PALETTE_SIZE];
unsigned char *pixels;

void load_palette(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening palette file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < PALETTE_SIZE; i++) {
        fscanf(fp, "%hhu %hhu %hhu", &palette[i].r, &palette[i].g, &palette[i].b);
    }

    fclose(fp);
}

void generate_pixel_art(const char *output_filename) {
    int fd;
    struct stat st;

    fd = open(output_filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    fstat(fd, &st);
    pixels = mmap(NULL, WIDTH * HEIGHT, PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (pixels == MAP_FAILED) {
        perror("Error mapping file to memory");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color_index = rand() % PALETTE_SIZE;
            pixels[y * WIDTH + x] = palette[color_index].r;
        }
    }

    msync(pixels, WIDTH * HEIGHT, MS_ASYNC);
    close(fd);

    printf("Pixel art generated: %s\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <palette.pal> <output.png>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_palette(argv[1]);
    generate_pixel_art(argv[2]);

    return EXIT_SUCCESS;
}