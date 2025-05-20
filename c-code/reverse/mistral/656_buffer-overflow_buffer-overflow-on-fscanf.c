#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void read_pgm(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE];
    char magic_number[3];
    int width, height, max_value;

    fscanf(file, "%s", magic_number);
    fscanf(file, "%d %d %d", &width, &height, &max_value);

    int pixels[width * height];
    char buffer[1]; // Intentionally small buffer for demonstrating buffer overflow

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fscanf(file, "%s", buffer); // Buffer overflow vulnerability
            pixels[y * width + x] = atoi(buffer);
        }
    }

    // Continue processing the image data...
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    read_pgm(argv[1]);

    return 0;
}
