//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BLOCK_SIZE 16
#define MAX_VALUE 255
#define THRESHOLD 0.1

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y;
    int value;
} Block;

typedef struct {
    int size;
    int threshold;
} Watermark;

void read_image(char *filename, unsigned char **image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *image = (unsigned char *) malloc(filesize);
    fread(*image, filesize, 1, fp);
    fclose(fp);

    *width = WIDTH;
    *height = HEIGHT;
}

void apply_watermark(unsigned char *image, Watermark *watermark) {
    int i, j, k, l;
    int x, y, value;

    for (i = 0; i < HEIGHT; i += BLOCK_SIZE) {
        for (j = 0; j < WIDTH; j += BLOCK_SIZE) {
            int count = 0;
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    x = j + k;
                    y = i + l;
                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                        value = image[y * WIDTH + x];
                        if (value >= watermark->threshold * MAX_VALUE) {
                            count++;
                        }
                    }
                }
            }
            if (count >= watermark->size) {
                for (k = 0; k < BLOCK_SIZE; k++) {
                    for (l = 0; l < BLOCK_SIZE; l++) {
                        x = j + k;
                        y = i + l;
                        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                            image[y * WIDTH + x] += watermark->threshold * MAX_VALUE;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    unsigned char *image = NULL;
    int width, height;

    read_image("input.bmp", &image, &width, &height);

    Watermark watermark;
    watermark.size = 100;
    watermark.threshold = THRESHOLD;

    apply_watermark(image, &watermark);

    FILE *output = fopen("output.bmp", "wb");
    if (output == NULL) {
        printf("Error creating file %s\n", "output.bmp");
        exit(1);
    }

    fwrite(image, width * height, 1, output);
    fclose(output);

    free(image);

    return 0;
}