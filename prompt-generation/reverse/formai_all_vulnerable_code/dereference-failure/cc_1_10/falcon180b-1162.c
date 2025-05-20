//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WATERMARK_SIZE 64
#define WATERMARK_VALUE 0x7F
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_COMPONENTS 4
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT * MAX_COMPONENTS)

typedef struct {
    int width;
    int height;
    int components;
    int pixels;
    char *data;
} Image;

typedef struct {
    int x;
    int y;
    int c;
} Pixel;

void read_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error reading image file.\n");
        exit(1);
    }
    fseek(fp, 18, SEEK_SET);
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->components = fgetc(fp) & 0xff;
    image->pixels = image->width * image->height * image->components;
    image->data = malloc(image->pixels * sizeof(char));
    if (image->data == NULL) {
        printf("Error allocating memory for image data.\n");
        exit(1);
    }
    fread(image->data, sizeof(char), image->pixels, fp);
    fclose(fp);
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error writing image file.\n");
        exit(1);
    }
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fputc(image->components & 0xff, fp);
    fwrite(image->data, sizeof(char), image->pixels, fp);
    fclose(fp);
}

void add_watermark(Image *image, int x, int y, int c, int value) {
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (i >= y && i < y + WATERMARK_SIZE && j >= x && j < x + WATERMARK_SIZE) {
                for (k = 0; k < image->components; k++) {
                    int index = (i - y) * image->width * image->components + (j - x) * image->components + k;
                    image->data[index] = value;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    Image input, output;
    Pixel watermark;
    int i, j, k;
    srand(time(NULL));
    watermark.x = rand() % (MAX_WIDTH - WATERMARK_SIZE);
    watermark.y = rand() % (MAX_HEIGHT - WATERMARK_SIZE);
    watermark.c = rand() % MAX_COMPONENTS;
    watermark.x += WATERMARK_SIZE / 2;
    watermark.y += WATERMARK_SIZE / 2;
    read_image(&input, argv[1]);
    add_watermark(&input, watermark.x, watermark.y, watermark.c, WATERMARK_VALUE);
    write_image(&input, argv[2]);
    return 0;
}