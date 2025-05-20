//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1024
#define WATERMARK_SIZE 512
#define SCALE_FACTOR 0.1

typedef struct {
    int x;
    int y;
    int value;
} Pixel;

void read_image(char *filename, Pixel *image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(image, sizeof(Pixel), MAX_PIXELS, fp);
    fclose(fp);

    *width = (int)sqrt(MAX_PIXELS);
    *height = (int)ceil((double)MAX_PIXELS / *width);
}

void print_image(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", image[y * width + x].value);
        }
        printf("\n");
    }
}

void add_watermark(Pixel *image, int width, int height, char *watermark_filename) {
    Pixel watermark[WATERMARK_SIZE * WATERMARK_SIZE];
    int watermark_width, watermark_height;

    read_image(watermark_filename, watermark, &watermark_width, &watermark_height);

    int offset_x = (width - watermark_width) / 2;
    int offset_y = (height - watermark_height) / 2;

    for (int y = 0; y < watermark_height; y++) {
        for (int x = 0; x < watermark_width; x++) {
            int index = y * watermark_width + x;
            int value = (int)round(watermark[index].value * SCALE_FACTOR);
            image[y * width + x + offset_x].value += value;
        }
    }
}

void save_image(char *filename, Pixel *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not create output file.\n");
        exit(1);
    }

    fwrite(image, sizeof(Pixel), MAX_PIXELS, fp);
    fclose(fp);
}

int main() {
    Pixel image[MAX_PIXELS];
    int width, height;

    read_image("input.bmp", image, &width, &height);
    add_watermark(image, width, height, "watermark.bmp");
    save_image("output.bmp", image, width, height);

    return 0;
}