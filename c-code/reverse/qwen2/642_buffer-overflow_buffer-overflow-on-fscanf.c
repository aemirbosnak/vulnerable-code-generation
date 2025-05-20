#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int width, height, max_val;
    fscanf(file, "%*s\n%d %d\n%d\n", &width, &height, &max_val);

    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(file, "%hhu ", &pixels[y][x]);
        }
    }

    fclose(file);

    const char *ascii_chars = "@%#*+=-:. ";
    int ascii_len = 11;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gray = pixels[y][x] * ascii_len / max_val;
            printf("%c", ascii_chars[gray]);
        }
        printf("\n");
    }

    return 0;
}
