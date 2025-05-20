//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image* createImage(int width, int height) {
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (int**) malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image->data[i] = (int*) malloc(width * sizeof(int));
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

void flipImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            int temp = image->data[i][j];
            image->data[i][j] = image->data[i][image->width - j - 1];
            image->data[i][image->width - j - 1] = temp;
        }
    }
}

void changeBrightness(Image *image, int delta) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[i][j];
            value += delta;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            image->data[i][j] = value;
        }
    }
}

void changeContrast(Image *image, int delta) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[i][j];
            value = (value * (256 - delta)) / 256;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            image->data[i][j] = value;
        }
    }
}

void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        fwrite(image->data[i], sizeof(int), image->width, fp);
    }
    fclose(fp);
}

int main() {
    Image *image = createImage(500, 500);
    int x, y, value;
    printf("Enter image data:\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            scanf("%d", &value);
            image->data[i][j] = value;
        }
    }
    printf("Enter x and y coordinates to flip around:\n");
    scanf("%d %d", &x, &y);
    flipImage(image);
    printf("Enter delta value for brightness change:\n");
    scanf("%d", &value);
    changeBrightness(image, value);
    printf("Enter delta value for contrast change:\n");
    scanf("%d", &value);
    changeContrast(image, value);
    char filename[100];
    printf("Enter filename to save image as:\n");
    scanf("%s", filename);
    saveImage(image, filename);
    destroyImage(image);
    return 0;
}