//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image *loadImage(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Failed to open file.\n");
        return NULL;
    }
    char format[3];
    fscanf(f, "%s", format);
    if (format[0] != 'P' || format[1] != '2') {
        printf("Error: Invalid file format.\n");
        return NULL;
    }
    int width, height, maxPixelValue;
    fscanf(f, "%d %d %d", &width, &height, &maxPixelValue);
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            fscanf(f, "%d", &img->data[i][j]);
        }
    }
    fclose(f);
    return img;
}

void saveImage(Image *img, char *filename) {
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P2\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VALUE);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(f, "%d ", img->data[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void freeImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

Image *flipImage(Image *img) {
    Image *flippedImg = (Image *)malloc(sizeof(Image));
    flippedImg->width = img->width;
    flippedImg->height = img->height;
    flippedImg->data = (int **)malloc(sizeof(int *) * flippedImg->height);
    for (int i = 0; i < flippedImg->height; i++) {
        flippedImg->data[i] = (int *)malloc(sizeof(int) * flippedImg->width);
        for (int j = 0; j < flippedImg->width; j++) {
            flippedImg->data[i][j] = img->data[flippedImg->height - i - 1][j];
        }
    }
    return flippedImg;
}

Image *adjustBrightness(Image *img, int brightness) {
    Image *brightenedImg = (Image *)malloc(sizeof(Image));
    brightenedImg->width = img->width;
    brightenedImg->height = img->height;
    brightenedImg->data = (int **)malloc(sizeof(int *) * brightenedImg->height);
    for (int i = 0; i < brightenedImg->height; i++) {
        brightenedImg->data[i] = (int *)malloc(sizeof(int) * brightenedImg->width);
        for (int j = 0; j < brightenedImg->width; j++) {
            brightenedImg->data[i][j] = img->data[i][j] + brightness;
            if (brightenedImg->data[i][j] > MAX_PIXEL_VALUE) {
                brightenedImg->data[i][j] = MAX_PIXEL_VALUE;
            }
            if (brightenedImg->data[i][j] < MIN_PIXEL_VALUE) {
                brightenedImg->data[i][j] = MIN_PIXEL_VALUE;
            }
        }
    }
    return brightenedImg;
}

Image *adjustContrast(Image *img, int contrast) {
    Image *contrastedImg = (Image *)malloc(sizeof(Image));
    contrastedImg->width = img->width;
    contrastedImg->height = img->height;
    contrastedImg->data = (int **)malloc(sizeof(int *) * contrastedImg->height);
    double pixelOffset = (double)(MAX_PIXEL_VALUE + MIN_PIXEL_VALUE) / 2;
    double factor = (double)(259 * (contrast + 255)) / (double)(255 * (259 - contrast));
    for (int i = 0; i < contrastedImg->height; i++) {
        contrastedImg->data[i] = (int *)malloc(sizeof(int) * contrastedImg->width);
        for (int j = 0; j < contrastedImg->width; j++) {
            contrastedImg->data[i][j] = (int)(factor * (img->data[i][j] - pixelOffset) + pixelOffset);
            if (contrastedImg->data[i][j] > MAX_PIXEL_VALUE) {
                contrastedImg->data[i][j] = MAX_PIXEL_VALUE;
            }
            if (contrastedImg->data[i][j] < MIN_PIXEL_VALUE) {
                contrastedImg->data[i][j] = MIN_PIXEL_VALUE;
            }
        }
    }
    return contrastedImg;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Error: Not enough arguments.\n");
        return 1;
    }
    char *operation = argv[1];
    Image *img = loadImage(argv[2]);
    if (img == NULL) {
        printf("Error: Failed to load image.\n");
        return 1;
    }
    Image *resultImg;
    if (strcmp(operation, "flip") == 0) {
        resultImg = flipImage(img);
    } else if (strcmp(operation, "brightness") == 0) {
        int brightness = atoi(argv[3]);
        resultImg = adjustBrightness(img, brightness);
    } else if (strcmp(operation, "contrast") == 0) {
        int contrast = atoi(argv[3]);
        resultImg = adjustContrast(img, contrast);
    } else {
        printf("Error: Invalid operation.\n");
        return 1;
    }
    saveImage(resultImg, "result.pgm");
    freeImage(img);
    freeImage(resultImg);
    return 0;
}