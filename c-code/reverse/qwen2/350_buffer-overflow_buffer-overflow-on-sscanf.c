#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

void bmp_to_ascii(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    unsigned char header[54];
    fread(header, 1, 54, file);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image size too large.\n");
        fclose(file);
        return;
    }

    unsigned char pixels[height][width * 3];
    fseek(file, 54, SEEK_SET);
    fread(pixels, 1, height * width * 3, file);
    fclose(file);

    const char *ascii_chars = "@%#*+=-:. ";
    int ascii_width = width / 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < ascii_width; x++) {
            int r = pixels[y][x * 3];
            int g = pixels[y][x * 3 + 1];
            int b = pixels[y][x * 3 + 2];
            int gray = (r + g + b) / 3;
            putchar(ascii_chars[gray * sizeof(ascii_chars) / 256]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    if (strlen(filename) < 9 || filename[strlen(filename) - 4] != '.' || filename[strlen(filename) - 3] != 'b' || filename[strlen(filename) - 2] != 'm' || filename[strlen(filename) - 1] != 'p') {
        fprintf(stderr, "Invalid file format. Expected .bmp\n");
        return 1;
    }

    bmp_to_ascii(filename);

    return 0;
}
