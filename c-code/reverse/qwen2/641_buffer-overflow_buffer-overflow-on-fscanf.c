#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void print_ascii_art(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char header[3];
    fread(header, 1, 3, file);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return;
    }

    int width, height, max_val;
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &max_val);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image too large\n");
        fclose(file);
        return;
    }

    unsigned char *image = malloc(width * height);
    if (!image) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(image, 1, width * height, file);
    fclose(file);

    const char *chars = "@%#*+=-:. ";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            double gray = (double)image[index] / max_val * (strlen(chars) - 1);
            putchar(chars[(int)gray]);
        }
        putchar('\n');
    }

    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    print_ascii_art(argv[1]);

    return 0;
}
