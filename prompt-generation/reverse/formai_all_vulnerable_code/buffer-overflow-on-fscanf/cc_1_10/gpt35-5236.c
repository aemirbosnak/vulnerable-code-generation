//FormAI DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

void readFile(char* path, Pixel** image, int* width, int* height) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("File not found!");
        exit(1);
    }

    char magic[3];
    fscanf(file, "%s", magic);
    if (strcmp(magic, "P6") != 0) {
        printf("Invalid file format");
        exit(1);
    }

    fscanf(file, "%d %d", width, height);
    int maxVal;
    fscanf(file, "%d", &maxVal);

    *image = malloc((*width) * (*height) * sizeof(Pixel));
    fread(*image, sizeof(Pixel), (*width) * (*height), file);

    fclose(file);
}

void writeFile(char* path, Pixel* image, int width, int height) {
    FILE* file = fopen(path, "w");
    if (!file) {
        printf("Cannot create file");
        exit(1);
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    fwrite(image, sizeof(Pixel), width * height, file);

    fclose(file);
}

void invertColors(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = 255 - image[i].red;
        image[i].green = 255 - image[i].green;
        image[i].blue = 255 - image[i].blue;
    }
}

void grayscale(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char average = (image[i].red + image[i].green + image[i].blue) / 3;
        image[i].red = average;
        image[i].green = average;
        image[i].blue = average;
    }
}

void blur(Pixel* image, int width, int height) {
    Pixel* newImage = malloc(width * height * sizeof(Pixel));
    for (int i = 0; i < width * height; i++) {
        newImage[i].red = 0;
        newImage[i].green = 0;
        newImage[i].blue = 0;
    }

    int r, g, b, count;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            r = g = b = count = 0;
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int xPos = x + i;
                    int yPos = y + j;
                    if (xPos >= 0 && xPos < width && yPos >= 0 && yPos < height) {
                        r += image[yPos * width + xPos].red;
                        g += image[yPos * width + xPos].green;
                        b += image[yPos * width + xPos].blue;
                        count++;
                    }
                }
            }
            newImage[y * width + x].red = r / count;
            newImage[y * width + x].green = g / count;
            newImage[y * width + x].blue = b / count;
        }
    }

    memcpy(image, newImage, width * height * sizeof(Pixel));
    free(newImage);
}

int main() {
    int width, height;
    Pixel* image;

    readFile("image.ppm", &image, &width, &height);

    invertColors(image, width, height);
    writeFile("image_inverted.ppm", image, width, height);

    grayscale(image, width, height);
    writeFile("image_grayscale.ppm", image, width, height);

    blur(image, width, height);
    writeFile("image_blurred.ppm", image, width, height);

    free(image);

    return 0;
}