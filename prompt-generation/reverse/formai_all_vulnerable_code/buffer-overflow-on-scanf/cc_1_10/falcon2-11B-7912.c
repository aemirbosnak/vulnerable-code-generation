//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255
#define PIXEL_SIZE 3

void adjustBrightness(unsigned char *pixels, int pixval) {
    int i;
    for (i = 0; i < MAX_PIXEL; i++) {
        pixels[i] *= pixval;
    }
}

void flipImage(unsigned char *pixels, int hflip) {
    int i;
    for (i = 0; i < MAX_PIXEL; i++) {
        if (hflip) {
            pixels[i] = pixels[MAX_PIXEL - 1 - i];
        }
    }
}

unsigned char *getPixels(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int width = 0;
    int height = 0;

    unsigned char *pixels = (unsigned char *)malloc(MAX_PIXEL * MAX_PIXEL * PIXEL_SIZE);
    if (!pixels) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < MAX_PIXEL; y++) {
        for (int x = 0; x < MAX_PIXEL; x++) {
            fscanf(fp, "%d %d %d\n", &pixels[x * MAX_PIXEL + y * PIXEL_SIZE], &pixels[x * MAX_PIXEL + y * PIXEL_SIZE + 1], &pixels[x * MAX_PIXEL + y * PIXEL_SIZE + 2]);
        }
    }
    fclose(fp);
    return pixels;
}

void setPixels(unsigned char *pixels, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int width = 0;
    int height = 0;

    for (int y = 0; y < MAX_PIXEL; y++) {
        for (int x = 0; x < MAX_PIXEL; x++) {
            fprintf(fp, "%d %d %d\n", pixels[x * MAX_PIXEL + y * PIXEL_SIZE], pixels[x * MAX_PIXEL + y * PIXEL_SIZE + 1], pixels[x * MAX_PIXEL + y * PIXEL_SIZE + 2]);
        }
    }
    fclose(fp);
}

unsigned char *createImage(unsigned char *pixels, int width, int height) {
    unsigned char *image = (unsigned char *)malloc(width * height * PIXEL_SIZE);
    if (!image) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < width * height * PIXEL_SIZE; i++) {
        image[i] = pixels[i / PIXEL_SIZE];
    }
    return image;
}

void saveImage(unsigned char *image, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int width = 0;
    int height = 0;

    for (int y = 0; y < MAX_PIXEL; y++) {
        for (int x = 0; x < MAX_PIXEL; x++) {
            fprintf(fp, "%d %d %d\n", image[x * MAX_PIXEL + y * PIXEL_SIZE], image[x * MAX_PIXEL + y * PIXEL_SIZE + 1], image[x * MAX_PIXEL + y * PIXEL_SIZE + 2]);
        }
    }
    fclose(fp);
}

int main() {
    char filename[100];
    char pixval;

    printf("Enter image filename: ");
    scanf("%s", filename);
    printf("Enter pixel value (0 - 255): ");
    scanf("%c", &pixval);

    unsigned char *pixels = getPixels(filename);
    adjustBrightness(pixels, pixval);

    printf("Flip image horizontally? (y/n): ");
    char hflip = getchar();

    if (hflip == 'y') {
        flipImage(pixels, 1);
    }

    unsigned char *image = createImage(pixels, MAX_PIXEL, MAX_PIXEL);
    saveImage(image, "out.ppm");

    free(pixels);
    free(image);

    return 0;
}