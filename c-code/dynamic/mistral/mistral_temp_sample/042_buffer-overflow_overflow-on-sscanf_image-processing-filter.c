#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *filename, char *filter) {
    FILE *file;
    int width, height, r, g, b;
    char data[3 * 1024];

    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    fscanf(file, "%d %d\n", &width, &height);
    fread(data, 3 * width * height, 1, file);
    fclose(file);

    for (r = 0; r < height; ++r) {
        for (int c = 0; c < width * 3; ++c) {
            data[c] += atoi(filter + c) * (data[c] / 255);
        }
    }

    file = fopen("output.bmp", "w");
    fprintf(file, "BM\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "24bpp\n");
    fprintf(file, "0 0 0 %d\n", 54 + 3 * width * height);
    fwrite(data, 1, 54 + 3 * width * height, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: image_filter input.bmp filter.txt\n");
        return 1;
    }

    process_image(argv[1], argv[2]);
    return 0;
}
