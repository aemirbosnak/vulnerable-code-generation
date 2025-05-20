#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void process_image(FILE *fp, int *data, int width, int height, int brightness, int contrast) {
    int i, j, pixel;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            fscanf(fp, "%d", &pixel);
            pixel = (pixel * contrast + brightness) / 10;
            if (pixel > 255) pixel = 255;
            if (pixel < 0) pixel = 0;
            data[(i * width + j)] = pixel;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int data[MAX_WIDTH * MAX_HEIGHT];
    int width, height, brightness, contrast;

    if (argc != 6) {
        printf("Usage: %s <pgm_file> <width> <height> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    if (fscanf(fp, "P5\n%d %d\n255\n", &width, &height) != 2) {
        fprintf(stderr, "Invalid PGM file format\n");
        fclose(fp);
        return 1;
    }

    brightness = atoi(argv[3]);
    contrast = atoi(argv[4]);

    process_image(fp, data, width, height, brightness, contrast);

    fclose(fp);

    return 0;
}
