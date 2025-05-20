//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void romeo_juliet_ascii_convert(FILE *image_file, FILE *output_file) {
    pixel *pixels;
    int i, j;
    char symbol[256];
    int red_range[3][3] = {{0, 31, 63}, {32, 63, 127}, {64, 127, 255}};

    fread(pixels, sizeof(pixel), WIDTH * HEIGHT, image_file);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int r_index = (pixels[i * WIDTH + j].r) / 32;
            int g_index = (pixels[i * WIDTH + j].g) / 32;
            int b_index = (pixels[i * WIDTH + j].b) / 32;

            sprintf(symbol, "%c", "Romeo"[r_index] + "Juliet"[g_index] + "Love"[b_index]);

            for (int k = 0; k < 3; k++) {
                if (r_index > k && r_index <= r_index + 2) {
                    symbol[k] = "^";
                } else if (g_index > k && g_index <= g_index + 2) {
                    symbol[k + 3] = "_";
                    symbol[k] = "|";
                } else if (b_index > k && b_index <= b_index + 2) {
                    symbol[k + 6] = "/";
                    symbol[k + 3] = "-";
                } else {
                    symbol[k] = ' ';
                }
            }

            fputs(symbol, output_file);
        }
        fputc('\n', output_file);
    }

    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.pgm> <output.txt>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (!image_file) {
        perror("Error opening image file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(image_file);
        return 1;
    }

    romeo_juliet_ascii_convert(image_file, output_file);

    fclose(image_file);
    fclose(output_file);

    return 0;
}