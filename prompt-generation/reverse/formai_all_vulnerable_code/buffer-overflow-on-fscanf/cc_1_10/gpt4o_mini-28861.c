//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

void freeImage(Image *img) {
    free(img->pixels);
    img->pixels = NULL;
}

Image* loadImage(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    char type[3];
    fscanf(file, "%s", type);
    if (strcmp(type, "P3") != 0) {
        printf("Unsupported file format: %s\n", type);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);

    img->pixels = (Pixel*)malloc(sizeof(Pixel) * img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(file, "%d %d %d", &img->pixels[i].r, &img->pixels[i].g, &img->pixels[i].b);
    }
    
    fclose(file);
    return img;
}

void saveImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "255\n");

    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(file, "%d %d %d\n", img->pixels[i].r, img->pixels[i].g, img->pixels[i].b);
    }

    fclose(file);
}

void applyGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        int gray = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = loadImage(argv[1]);
    if (!img) {
        return 1;
    }

    applyGrayscale(img);
    saveImage(argv[2], img);

    freeImage(img);
    free(img);
    printf("Image conversion complete. Grayscale image saved as %s\n", argv[2]);
    return 0;
}