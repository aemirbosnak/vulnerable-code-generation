//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void flipImage(Pixel* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            Pixel temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

void changeBrightness(Pixel* image, int width, int height, int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j].r += brightness;
            image[i * width + j].g += brightness;
            image[i * width + j].b += brightness;
        }
    }
}

void changeContrast(Pixel* image, int width, int height, float contrast) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j].r = (image[i * width + j].r - 127) * contrast + 127;
            image[i * width + j].g = (image[i * width + j].g - 127) * contrast + 127;
            image[i * width + j].b = (image[i * width + j].b - 127) * contrast + 127;
        }
    }
}

int main() {
    Pixel image[MAX_WIDTH * MAX_HEIGHT];
    int width, height, brightness, contrast;
    char filename[100];

    printf("Enter image filename: ");
    scanf("%s", filename);
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);
    printf("Enter brightness value: ");
    scanf("%d", &brightness);
    printf("Enter contrast value: ");
    scanf("%f", &contrast);

    // Load image from file
    FILE* file = fopen(filename, "rb");
    fread(image, sizeof(Pixel), width * height, file);
    fclose(file);

    // Flip image
    flipImage(image, width, height);

    // Change brightness
    changeBrightness(image, width, height, brightness);

    // Change contrast
    changeContrast(image, width, height, contrast);

    // Save image to file
    file = fopen(filename, "wb");
    fwrite(image, sizeof(Pixel), width * height, file);
    fclose(file);

    return 0;
}