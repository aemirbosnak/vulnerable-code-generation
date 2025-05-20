//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error loading image: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char header[54];
    fread(header, 1, 54, fp);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    Image img = {
       .width = width,
       .height = height,
       .data = malloc(size - 54)
    };

    fread(img.data, 1, size - 54, fp);

    fclose(fp);

    return img;
}

void saveImage(const char *filename, const Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error saving image: %s\n", filename);
        exit(1);
    }

    unsigned char header[54];
    memset(header, 0, 54);

    int width = img->width;
    int height = img->height;

    *(int *)&header[18] = width;
    *(int *)&header[22] = height;

    fwrite(header, 1, 54, fp);
    fwrite(img->data, 1, img->width * img->height * 3, fp);

    fclose(fp);
}

void printImage(const Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            printf("%d,%d,%d ", r, g, b);
        }
        printf("\n");
    }
}

int isInside(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void floodFill(Image *img, int x, int y, int color) {
    if (!isInside(x, y, img->width, img->height))
        return;

    if (img->data[y * img->width + x]!= color) {
        img->data[y * img->width + x] = color;
        floodFill(img, x - 1, y, color);
        floodFill(img, x + 1, y, color);
        floodFill(img, x, y - 1, color);
        floodFill(img, x, y + 1, color);
    }
}

int main() {
    Image img = loadImage("input.png");

    printImage(&img);

    floodFill(&img, 50, 50, 0xff0000);

    saveImage("output.png", &img);

    free(img.data);

    return 0;
}