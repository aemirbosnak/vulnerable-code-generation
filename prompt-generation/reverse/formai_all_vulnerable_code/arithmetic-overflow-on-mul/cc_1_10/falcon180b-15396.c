//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1000000
#define MAX_WIDTH 1000000
#define MAX_HEIGHT 1000000

typedef struct {
    int width;
    int height;
    int *data;
} Image;

Image *loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int width, height, channels;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&channels, sizeof(int), 1, file);

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * channels * sizeof(int));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                fread(&image->data[y * width * channels + x * channels + c], sizeof(int), 1, file);
            }
        }
    }

    fclose(file);
    return image;
}

void saveImage(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->data, sizeof(int), image->width * image->height * 3, file);

    fclose(file);
}

void flipImage(Image *image) {
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            int index1 = y * width + x;
            int index2 = (height - y - 1) * width + x;

            int temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
    }
}

void changeBrightness(Image *image, int delta) {
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            int value = data[index];
            value += delta;

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }

            data[index] = value;
        }
    }
}

void changeContrast(Image *image, int delta) {
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            int value = data[index];
            value += delta;

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }

            data[index] = value;
        }
    }
}

int main() {
    Image *image = loadImage("input.jpg");

    flipImage(image);
    changeBrightness(image, 50);
    changeContrast(image, 20);

    saveImage("output.jpg", image);

    free(image->data);
    free(image);

    return 0;
}