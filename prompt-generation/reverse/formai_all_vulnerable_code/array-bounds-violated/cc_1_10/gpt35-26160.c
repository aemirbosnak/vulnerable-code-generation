//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 50

void convert(unsigned char *img) {
    char ascii[WIDTH][HEIGHT];

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            int i = 3 * (y * WIDTH + x);
            int r = img[i];
            int g = img[i+1];
            int b = img[i+2];
            double luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            int value = (int)(luminance / 256 * 70);
            ascii[x][y] = value > 10 ? ' ' : ".-:=+*#%@"[9 - value];
        }
    }

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            putchar(ascii[x][y]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s [image file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");
    if(file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *img = malloc(size);
    if(img == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    fread(img, size, 1, file);
    fclose(file);

    convert(img);
    free(img);

    return 0;
}