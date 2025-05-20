//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct pixel {
    int x;
    int y;
    int value;
};

void read_qr_code(char *filename, struct pixel *pixels) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixels = (struct pixel *) malloc(width * height * sizeof(struct pixel));

    for (int i = 0; i < width * height; i++) {
        fread(&pixels[i].x, sizeof(int), 1, fp);
        fread(&pixels[i].y, sizeof(int), 1, fp);
        fread(&pixels[i].value, sizeof(int), 1, fp);
    }

    fclose(fp);
}

void print_pixels(struct pixel *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        printf("%d %d %d\n", pixels[i].x, pixels[i].y, pixels[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    struct pixel *pixels;

    read_qr_code(filename, pixels);
    print_pixels(pixels, MAX_SIZE, MAX_SIZE);

    free(pixels);

    return 0;
}