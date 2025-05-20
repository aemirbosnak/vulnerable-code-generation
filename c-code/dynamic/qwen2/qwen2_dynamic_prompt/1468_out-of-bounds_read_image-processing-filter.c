#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(unsigned char *image, int width, int height) {
    unsigned char *filtered_image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!filtered_image) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = image[(y * width + x - 1) * 3];
            int g = image[(y * width + x) * 3];
            int b = image[(y * width + x + 1) * 3];

            filtered_image[(y * width + x) * 3] = (r + g + b) / 3;
        }
    }

    free(filtered_image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_image>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open input file");
        return 1;
    }

    fseek(file, 18, SEEK_SET); // Skip BMP header
    unsigned short width, height;
    fread(&width, sizeof(short), 1, file);
    fread(&height, sizeof(short), 1, file);

    fseek(file, 54, SEEK_SET); // Skip DIB header

    int row_size = ((width * 24 + 31) / 32) * 4;
    int padding = row_size - width * 3;

    unsigned char *image = (unsigned char *)malloc(height * row_size);
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    for (int y = 0; y < height; y++) {
        fread(image + y * row_size, 1, row_size, file);
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);

    apply_filter(image, width, height);

    free(image);

    return 0;
}
