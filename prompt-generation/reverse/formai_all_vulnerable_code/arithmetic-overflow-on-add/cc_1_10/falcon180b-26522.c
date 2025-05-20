//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 50

typedef struct {
    int x;
    int y;
    char c;
    int r;
    int g;
    int b;
} Pixel;

Pixel* loadImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    int width = 0, height = 0, size = 0;
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&size, 4, 1, fp);

    Pixel* pixels = malloc(sizeof(Pixel) * width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixels[y * width + x].r, 1, 1, fp);
            fread(&pixels[y * width + x].g, 1, 1, fp);
            fread(&pixels[y * width + x].b, 1, 1, fp);
        }
    }

    fclose(fp);
    return pixels;
}

void printASCIIArt(Pixel* pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = pixels[y * width + x].c;
            int r = pixels[y * width + x].r;
            int g = pixels[y * width + x].g;
            int b = pixels[y * width + x].b;

            int avg = (r + g + b) / 3;

            if (avg < 128) {
                printf(" ");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <image>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    Pixel* pixels = loadImage(filename);
    printASCIIArt(pixels, WIDTH, HEIGHT);

    free(pixels);
    return 0;
}