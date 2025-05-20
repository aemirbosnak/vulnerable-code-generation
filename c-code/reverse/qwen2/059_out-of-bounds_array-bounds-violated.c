#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void bmp_to_ascii(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return;

    unsigned char header[54];
    fread(header, 1, 54, file);
    int width = *(int *)&header[18], height = *(int *)&header[22];

    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    const char *ascii_chars = "@%#*+=-:. ";
    int ascii_width = strlen(ascii_chars);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = data[(y * width + x) * 3];
            int g = data[(y * width + x) * 3 + 1];
            int b = data[(y * width + x) * 3 + 2];
            int gray = (r + g + b) / 3;
            int index = gray * ascii_width / 256;
            putchar(ascii_chars[index]);
        }
        putchar('\n');
    }

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bmp_file>\n", argv[0]);
        return 1;
    }
    bmp_to_ascii(argv[1]);
    return 0;
}
