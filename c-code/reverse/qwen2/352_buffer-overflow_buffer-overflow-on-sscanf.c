#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    unsigned short width, height;
    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(unsigned short), 1, file);
    fread(&height, sizeof(unsigned short), 1, file);

    fseek(file, 54, SEEK_SET);
    unsigned char pixel_data[height][width];
    for (unsigned int y = 0; y < height; ++y) {
        fread(pixel_data[y], sizeof(unsigned char), width, file);
    }

    const char *ascii_chars = "@%#*+=-:. ";
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            unsigned char gray = (pixel_data[y][x] * 3) / 8;
            printf("%c", ascii_chars[gray]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
