//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    unsigned char data[MAX_WIDTH * MAX_HEIGHT];
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P5\n%d %d\n255\n", &image->width, &image->height);

    fread(image->data, 1, image->width * image->height, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);

    fwrite(image->data, 1, image->width * image->height, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.txt>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    int width = image->width;
    int height = image->height;

    int x = 0;
    int y = 0;
    while (y < height) {
        while (x < width) {
            unsigned char pixel = image->data[y * width + x];
            if (pixel == 255) {
                printf("1");
            } else {
                printf("0");
            }
            x++;
        }
        printf("\n");
        x = 0;
        y++;
    }

    free(image);

    return 0;
}