//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define WATERMARK_ALPHA 0.5
#define WATERMARK_TEXT "Peaceful Programming"
#define WATERMARK_FONT "Arial"
#define WATERMARK_FONT_SIZE 36
#define WATERMARK_COLOR "white"

typedef struct {
    char *filename;
    unsigned char *data;
    int width;
    int height;
} Image;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Rect;

void load_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(filesize);
    if (image->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(1);
    }

    fread(image->data, filesize, 1, fp);
    fclose(fp);

    image->filename = strdup(filename);
    image->width = IMAGE_WIDTH;
    image->height = IMAGE_HEIGHT;
}

void display_image(Image *image) {
    printf("Displaying image %s...\n", image->filename);
}

void save_image(Image *image, const char *filename) {
    printf("Saving image %s...\n", filename);
}

void add_watermark(Image *image, const char *text, double alpha, int x, int y) {
    printf("Adding watermark '%s' with alpha %.2f at position (%d,%d)...\n", text, alpha, x, y);
}

void main() {
    Image image;
    load_image(&image, "input.png");

    display_image(&image);

    add_watermark(&image, WATERMARK_TEXT, WATERMARK_ALPHA, 10, 10);

    save_image(&image, "output.png");
}