//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported image format. Only P6 (PPM) supported.\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);

    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);
    fgetc(file); // Consume the newline character after the max color value

    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

void saveImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void applyGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (unsigned char)(0.299 * img->pixels[i].r + 0.587 * img->pixels[i].g + 0.114 * img->pixels[i].b);
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

void applyInvertColors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = 255 - img->pixels[i].r;
        img->pixels[i].g = 255 - img->pixels[i].g;
        img->pixels[i].b = 255 - img->pixels[i].b;
    }
}

void freeImage(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <filter>\n", argv[0]);
        fprintf(stderr, "Filters: grayscale | invert\n");
        return 1;
    }

    Image *img = loadImage(argv[1]);
    if (!img) {
        return 1;
    }

    if (strcmp(argv[3], "grayscale") == 0) {
        applyGrayscale(img);
    } else if (strcmp(argv[3], "invert") == 0) {
        applyInvertColors(img);
    } else {
        fprintf(stderr, "Error: Unknown filter %s. Available filters: grayscale, invert.\n", argv[3]);
        freeImage(img);
        return 1;
    }

    saveImage(argv[2], img);
    freeImage(img);
    printf("Image processing completed. Saved to %s\n", argv[2]);
    return 0;
}