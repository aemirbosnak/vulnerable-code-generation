//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image* createImage(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image->data[i] = (int *)malloc(width * sizeof(int));
    }
    return image;
}

void destroyImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, int value) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->data[y][x] = value;
    }
}

int getPixel(Image *image, int x, int y) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return image->data[y][x];
    }
    return 0;
}

void printImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", getPixel(image, j, i));
        }
        printf("\n");
    }
}

int main() {
    int width, height, x, y, value;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    Image *image = createImage(width, height);

    printf("Enter the pixel values:\n");
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            scanf("%d", &value);
            setPixel(image, x, y, value);
        }
    }

    printf("The image is:\n");
    printImage(image);

    destroyImage(image);

    return 0;
}