#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;

    int width, height, max_val;
    fscanf(file, "%*s %d %d %d", &width, &height, &max_val);
    unsigned char *image = (unsigned char *)malloc(width * height);

    for (int i = 0; i < width * height; ++i) {
        fscanf(file, "%hhu", &image[i]);
    }

    free(image);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }
    process_image(argv[1]);
    return 0;
}
