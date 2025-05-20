//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 4096

typedef struct {
    int size;
    char *data;
} Image;

Image *read_image(char *filename) {
    FILE *fp;
    Image *img = NULL;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    img = (Image *)malloc(sizeof(Image) + (size_t)ftell(fp));
    if (img == NULL) {
        printf("Error: could not allocate memory for image\n");
        exit(1);
    }

    img->size = (int)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(img->data, 1, img->size, fp);

    fclose(fp);

    return img;
}

void write_image(Image *img, char *filename) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fwrite(img->data, 1, img->size, fp);

    fclose(fp);
}

void add_watermark(Image *img, char *filename) {
    FILE *fp;
    Image *watermark;

    watermark = read_image(filename);

    if (img->size!= watermark->size) {
        printf("Error: watermark image size does not match input image size\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < img->size; i++) {
        if (i % 3 == 0) {
            img->data[i] = (img->data[i] + watermark->data[i]) / 2;
        } else if (i % 3 == 1) {
            img->data[i] = (img->data[i] + watermark->data[i]) / 2;
        } else {
            img->data[i] = (img->data[i] + watermark->data[i]) / 2;
        }
    }

    write_image(img, "watermarked.bmp");

    free(watermark->data);
    free(watermark);
}

int main() {
    Image *img;

    img = read_image("image.bmp");
    add_watermark(img, "watermark.bmp");

    return 0;
}