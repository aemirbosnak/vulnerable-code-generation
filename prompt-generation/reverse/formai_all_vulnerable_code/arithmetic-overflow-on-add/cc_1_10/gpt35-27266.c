//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCALE_FACTOR 0.25

char ascii_chars[] = {'#', '&', '$', '*', '+', '-', ';', ':', ',', '.', ' '};
int ascii_chars_len = sizeof(ascii_chars) / sizeof(char);

int get_luminance(unsigned char r, unsigned char g, unsigned char b) {
    return (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
}

int get_ascii_char(int luminance) {
    int range = 255 / (ascii_chars_len - 1);
    int index = luminance / range;
    return ascii_chars[index];
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [filepath]\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    long filesize = ftell(fptr);
    rewind(fptr);

    unsigned char *buffer = (unsigned char *)malloc(sizeof(unsigned char) * filesize);
    size_t read_bytes = fread(buffer, 1, filesize, fptr);
    if (read_bytes != filesize) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    fclose(fptr);

    int width = *(int *)(buffer + 18);
    int height = *(int *)(buffer + 22);
    int bpp = *(buffer + 28);

    if (bpp != 24) {
        printf("Unsupported BPP: %d\n", bpp);
        exit(1);
    }

    printf("Image resolution: %dx%d\n", width, height);

    int bytes_per_pixel = bpp / 8;
    int row_size = ((width * bytes_per_pixel) + 3) & (~3);

    unsigned char *output = (unsigned char *)malloc(sizeof(unsigned char) * width * height * 2);
    memset(output, ' ', width * height * 2);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = ((height - 1 - y) * row_size) + (x * bytes_per_pixel);

            unsigned char r = *(buffer + index + 2);
            unsigned char g = *(buffer + index + 1);
            unsigned char b = *(buffer + index);

            int luminance = get_luminance(r, g, b);

            int ascii_index = get_ascii_char(luminance);

            *(output + (y * width) + x) = ascii_index;
        }
    }

    int scaled_width = (int)((float)width * SCALE_FACTOR);
    int scaled_height = (int)((float)height * SCALE_FACTOR);

    for (int y = 0; y < scaled_height; y++) {
        for (int x = 0; x < scaled_width; x++) {
            int index = (int)((float)y / SCALE_FACTOR) * width + (int)((float)x / SCALE_FACTOR);
            printf("%c", *(output + index));
        }
        printf("\n");
    }

    free(output);
    free(buffer);

    return 0;
}