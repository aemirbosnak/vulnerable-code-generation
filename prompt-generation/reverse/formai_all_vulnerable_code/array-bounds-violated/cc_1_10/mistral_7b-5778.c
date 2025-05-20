//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 21
#define HEIGHT 11
#define BMP_SIZE (WIDTH * HEIGHT * 3)
#define ASCII_CHARS " .:+*#"

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

void bmp_to_ascii(FILE *bmp, FILE *ascii) {
    pixel *pixels = (pixel *)malloc(BMP_SIZE);
    fread(pixels, BMP_SIZE, 1, bmp);
    fseek(bmp, 2, SEEK_SET); // Go back to the header

    for (int y = HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH + x) * 3;
            int r = pixels[index].red;
            int g = pixels[index].green;
            int b = pixels[index].blue;

            char ascii_char = ASCII_CHARS[(r >> 5)];
            ascii_char += ASCII_CHARS[(g >> 5)];
            ascii_char += ASCII_CHARS[(b >> 5)];

            if (x < WIDTH - 1)
                fputc(ascii_char, ascii);
            else
                fputs("\n", ascii);

            ascii_char = ASCII_CHARS[(r & 0x1F)];
            ascii_char += ASCII_CHARS[(g & 0x1F)];
            ascii_char += ASCII_CHARS[(b & 0x1F)];

            fputc(ascii_char, ascii);
        }
    }

    free(pixels);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input.bmp> <output.asc>", argv[0]);
        return 1;
    }

    FILE *bmp = fopen(argv[1], "rb");
    FILE *ascii = fopen(argv[2], "w");

    if (!bmp || !ascii) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    bmp_to_ascii(bmp, ascii);
    fclose(bmp);
    fclose(ascii);

    return 0;
}