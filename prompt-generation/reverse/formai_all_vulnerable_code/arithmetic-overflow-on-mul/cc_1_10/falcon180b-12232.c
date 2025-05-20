//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct pixel {
    int x;
    int y;
    char c;
    int r;
    int g;
    int b;
} pixel;

pixel* read_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixel* pixels = calloc(width * height, sizeof(pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixels[y * width + x].r, sizeof(int), 1, fp);
            fread(&pixels[y * width + x].g, sizeof(int), 1, fp);
            fread(&pixels[y * width + x].b, sizeof(int), 1, fp);
        }
    }

    fclose(fp);

    return pixels;
}

void write_ascii(pixel* pixels, int width, int height, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = pixels[y * width + x].r;
            int g = pixels[y * width + x].g;
            int b = pixels[y * width + x].b;

            int avg = (r + g + b) / 3;

            if (avg < 128) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "█");
            }
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.png output.txt\n", argv[0]);
        return 1;
    }

    pixel* pixels = read_image(argv[1]);
    write_ascii(pixels, WIDTH, HEIGHT, argv[2]);

    return 0;
}