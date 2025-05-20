//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define MAX_COLORS 256

typedef unsigned char byte;
typedef struct {
    byte r, g, b;
} color;

typedef struct {
    int width, height;
    color pixels[MAX_WIDTH * MAX_HEIGHT];
} image;

image load_image(char *filename) {
    image img;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fscanf(f, "P6\n%d %d\n255\n", &img.width, &img.height);
    fread(img.pixels, sizeof(color), img.width * img.height, f);
    fclose(f);
    return img;
}

void save_image(char *filename, image img) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fprintf(f, "P6\n%d %d\n255\n", img.width, img.height);
    fwrite(img.pixels, sizeof(color), img.width * img.height, f);
    fclose(f);
}

image grayscale(image img) {
    image gray;
    gray.width = img.width;
    gray.height = img.height;
    for (int i = 0; i < img.width * img.height; i++) {
        gray.pixels[i].r = gray.pixels[i].g = gray.pixels[i].b = (img.pixels[i].r + img.pixels[i].g + img.pixels[i].b) / 3;
    }
    return gray;
}

image to_ascii(image img) {
    image ascii;
    ascii.width = img.width / 2;
    ascii.height = img.height / 2;
    for (int i = 0; i < img.width * img.height; i++) {
        int x = i % img.width;
        int y = i / img.width;
        ascii.pixels[i].r = ascii.pixels[i].g = ascii.pixels[i].b = img.pixels[x * 2 + y * 2].r;
    }
    return ascii;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }
    image img = load_image(argv[1]);
    image gray = grayscale(img);
    image ascii = to_ascii(gray);
    save_image(argv[2], ascii);
    return 0;
}