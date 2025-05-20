//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

void load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    fread(image, sizeof(pixel), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void convert_to_ascii_art() {
    char ascii_art[WIDTH][HEIGHT];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double brightness = (0.2126 * image[x][y].r) + (0.7152 * image[x][y].g) + (0.0722 * image[x][y].b);
            int ascii_index = (int)round(brightness / 255.0 * 63.0);

            ascii_art[x][y] = " .,-:;=!*#$@"[ascii_index];
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", ascii_art[x][y]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        exit(1);
    }

    load_image(argv[1]);
    convert_to_ascii_art();

    return 0;
}