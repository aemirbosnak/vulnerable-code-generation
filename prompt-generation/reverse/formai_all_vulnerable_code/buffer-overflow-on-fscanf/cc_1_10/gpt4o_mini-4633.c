//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    // Check the image format
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        return NULL;
    }

    // Read image dimensions
    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);

    // Allocate memory for pixel data
    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void saveImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void applyGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadImage(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    applyGrayscale(img);
    saveImage(argv[2], img);
    freeImage(img);

    printf("Image processed and saved as %s\n", argv[2]);
    return EXIT_SUCCESS;
}