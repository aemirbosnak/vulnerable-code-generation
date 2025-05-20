//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

void read_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }
    char magic[3];
    fgets(magic, 3, fp);
    if (!strcmp(magic, "P6")) {
        fscanf(fp, "%d %d\n255\n", &image->width, &image->height);
        image->data = malloc(image->width * image->height * sizeof(Pixel));
        fread(image->data, sizeof(Pixel), image->width * image->height, fp);
    }
    fclose(fp);
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (0.3 * image->data[i].r) + (0.59 * image->data[i].g) + (0.11 * image->data[i].b);
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void invert(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

int main() {
    Image image;
    read_image(&image, "input.ppm");
    printf("Loaded image with dimensions %d x %d\n", image.width, image.height);

    grayscale(&image);
    write_image(&image, "grayscale.ppm");
    printf("Converted image to grayscale and wrote to grayscale.ppm\n");

    invert(&image);
    write_image(&image, "inverted.ppm");
    printf("Inverted image and wrote to inverted.ppm\n");

    return 0;
}