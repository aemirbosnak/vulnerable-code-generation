#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void bmp_to_ascii(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    unsigned char header[54];
    fread(header, 1, 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    unsigned char* pixels = (unsigned char*)malloc(width * height * 3);
    if (!pixels) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    fseek(file, 54, SEEK_SET);
    fread(pixels, 1, width * height * 3, file);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            unsigned char r = pixels[index];
            unsigned char g = pixels[index + 1];
            unsigned char b = pixels[index + 2];
            unsigned char gray = (r * 0.3 + g * 0.59 + b * 0.11);
            printf("%c", " .:-=+*#%@"[gray / 25]);
        }
        printf("\n");
    }

    free(pixels);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bmp_file>\n", argv[0]);
        return 1;
    }

    bmp_to_ascii(argv[1]);

    // Intentional out-of-bounds write to demonstrate vulnerability
    unsigned char* buffer = (unsigned char*)malloc(10);
    if (buffer) {
        buffer[10] = 'A'; // Out-of-bounds write
        free(buffer);
    }

    return 0;
}
