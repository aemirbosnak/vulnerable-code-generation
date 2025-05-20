//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_-+=[]{}\\|;:,.<>?/~`"

int get_pixel(int x, int y, unsigned char *data, int width, int height) {
    if (x < 0 || y < 0 || x >= width || y >= height) {
        return 0;
    }
    return data[(y * width + x) * 3];
}

void ascii_art(int width, int height, unsigned char *data) {
    int x, y, value;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            value = get_pixel(x, y, data, width, height);
            printf("%c", CHAR_SET[value]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char header[3];
    int width, height, bpp;
    unsigned char *data;

    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    fread(header, 1, 3, fp);
    if (memcmp(header, "BMP", 3)!= 0) {
        printf("Error: invalid BMP file\n");
        fclose(fp);
        return 1;
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&bpp, 4, 1, fp);

    if (bpp!= 24) {
        printf("Error: unsupported BPP\n");
        fclose(fp);
        return 1;
    }

    data = malloc(width * height * 3);
    fread(data, width * height * 3, 1, fp);
    fclose(fp);

    ascii_art(width, height, data);

    free(data);

    return 0;
}