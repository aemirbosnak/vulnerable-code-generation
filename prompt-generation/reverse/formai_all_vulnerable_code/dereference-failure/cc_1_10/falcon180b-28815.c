//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *data;
} Image;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char *data;
} SubImage;

void readImage(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(filesize);
    fread(image->data, 1, filesize, fp);
    fclose(fp);

    image->width = *(int *)image->data;
    image->height = *(int *)(image->data + 4);
}

void writeASCIIArt(const char *filename, SubImage *subimage) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        exit(1);
    }

    int x, y;
    for (y = subimage->y; y < subimage->y + subimage->height; y++) {
        for (x = subimage->x; x < subimage->x + subimage->width; x++) {
            char c = subimage->data[y * MAX_WIDTH + x] / 16;
            fprintf(fp, "%c", c);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    Image image;
    readImage("image.bin", &image);

    SubImage subimage;
    subimage.x = 0;
    subimage.y = 0;
    subimage.width = image.width;
    subimage.height = image.height;
    subimage.data = image.data;

    writeASCIIArt("ascii_art.txt", &subimage);

    free(image.data);
    return 0;
}