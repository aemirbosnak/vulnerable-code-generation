//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_PIXEL_VALUE 255

struct Image {
    int width;
    int height;
    int maxPixelValue;
    unsigned char* pixels;
};

void writeImage(const char* filename, struct Image* img) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, img->maxPixelValue);
    fwrite(img->pixels, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
}

struct Image readImage(const char* filename) {
    struct Image img;
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(fp, "%s", format);
    if (strcmp(format, "P5") != 0) {
        printf("Error: file %s is not a PGM image\n", filename);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d %d", &img.width, &img.height, &img.maxPixelValue);
    img.pixels = (unsigned char*) malloc(img.height * img.width * sizeof(unsigned char));
    if (!img.pixels) {
        printf("Error: could not allocate memory for image pixels\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fread(img.pixels, sizeof(unsigned char), img.width * img.height, fp);
    fclose(fp);

    return img;
}

void invertColors(struct Image* img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->pixels[i] = MAX_PIXEL_VALUE - img->pixels[i];
    }
}

void grayscale(struct Image* img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        unsigned char pixel = img->pixels[i];
        img->pixels[i] = 0.30 * pixel + 0.59 * pixel + 0.11 * pixel;
    }
}

void threshold(struct Image* img, int threshold) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->pixels[i] = img->pixels[i] < threshold ? 0 : MAX_PIXEL_VALUE;
    }
}

void blur(struct Image* img, int radius) {
    int size = 2 * radius + 1;
    float kernel[size][size];
    float total = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel[i][j] = exp(-((i - radius) * (i - radius) + (j - radius) * (j - radius)) / (float)(2 * radius * radius));
            total += kernel[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel[i][j] /= total;
        }
    }

    unsigned char* pixelsCopy = malloc(img->height * img->width * sizeof(unsigned char));
    if (!pixelsCopy) {
        printf("Error: could not allocate memory for image pixels copy\n");
        exit(EXIT_FAILURE);
    }
    memcpy(pixelsCopy, img->pixels, img->height * img->width * sizeof(unsigned char));

    for (int i = 0; i < img->width; ++i) {
        for (int j = 0; j < img->height; ++j) {
            float pixelValue = 0;
            for (int k = 0; k < size; ++k) {
                for (int l = 0; l < size; ++l) {
                    int row = i + k - radius;
                    int col = j + l - radius;
                    if (row < 0 || row >= img->width || col < 0 || col >= img->height) {
                        continue;
                    }
                    pixelValue += pixelsCopy[row * img->height + col] * kernel[k][l];
                }
            }
            img->pixels[i * img->height + j] = pixelValue;
        }
    }

    free(pixelsCopy);
}

int main() {
    struct Image image = readImage("example.pgm");

    invertColors(&image);
    writeImage("invert_colors.pgm", &image);

    grayscale(&image);
    writeImage("grayscale.pgm", &image);

    threshold(&image, 128);
    writeImage("threshold.pgm", &image);

    blur(&image, 5);
    writeImage("blur.pgm", &image);
}