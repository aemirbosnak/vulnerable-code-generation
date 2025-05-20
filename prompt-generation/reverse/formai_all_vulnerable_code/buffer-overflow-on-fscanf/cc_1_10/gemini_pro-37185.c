//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (!image) {
        return NULL;
    }
    image->width = width;
    image->height = height;
    return image;
}

void image_free(Image *image) {
    free(image);
}

int image_load(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }
    fscanf(file, "P3\n%d %d\n255\n", &image->width, &image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fscanf(file, "%hhu %hhu %hhu\n", &image->pixels[x][y].red, &image->pixels[x][y].green, &image->pixels[x][y].blue);
        }
    }
    fclose(file);
    return 0;
}

int image_save(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%hhu %hhu %hhu\n", image->pixels[x][y].red, image->pixels[x][y].green, image->pixels[x][y].blue);
        }
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }
    Image *image = image_new(0, 0);
    if (!image) {
        printf("Failed to allocate memory for image\n");
        return 1;
    }
    if (image_load(image, argv[1]) != 0) {
        printf("Failed to load image\n");
        image_free(image);
        return 1;
    }
    // Perform image editing operations here
    // ...
    if (image_save(image, "edited.ppm") != 0) {
        printf("Failed to save edited image\n");
        image_free(image);
        return 1;
    }
    image_free(image);
    return 0;
}