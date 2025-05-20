//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int width;
    int height;
    int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void readImage(Image *image) {
    int i, j;
    scanf("%d %d", &image->width, &image->height);
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            scanf("%d", &image->pixels[i][j]);
        }
    }
}

void writeImage(Image *image) {
    int i, j;
    printf("%d %d\n", image->width, image->height);
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%d ", image->pixels[i][j]);
        }
        printf("\n");
    }
}

void invert(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->pixels[i][j] = 255 - image->pixels[i][j];
        }
    }
}

void grayscale(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int gray = (image->pixels[i][j] & 0xff) * 0.3
                     + ((image->pixels[i][j] >> 8) & 0xff) * 0.59
                     + ((image->pixels[i][j] >> 16) & 0xff) * 0.11;
            image->pixels[i][j] = gray + (gray << 8) + (gray << 16);
        }
    }
}

void blur(Image *image) {
    int i, j;
    int kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}};
    for (i = 1; i < image->height - 1; i++) {
        for (j = 1; j < image->width - 1; j++) {
            int k, l;
            int sum = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    sum += kernel[k+1][l+1] * image->pixels[i+k][j+l];
                }
            }
            image->pixels[i][j] = sum / 16;
        }
    }
}

int main() {
    Image image;
    readImage(&image);
    invert(&image);
    writeImage(&image);
    return 0;
}