//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
/*
 * C Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *createImage(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (unsigned char *)malloc(width * height * 3 * sizeof(unsigned char));
    return image;
}

void destroyImage(Image *image) {
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
    int index = (y * image->width + x) * 3;
    image->data[index] = red;
    image->data[index + 1] = green;
    image->data[index + 2] = blue;
}

void getPixel(Image *image, int x, int y, unsigned char *red, unsigned char *green, unsigned char *blue) {
    int index = (y * image->width + x) * 3;
    *red = image->data[index];
    *green = image->data[index + 1];
    *blue = image->data[index + 2];
}

void flipHorizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            unsigned char red2, green2, blue2;
            getPixel(image, image->width - x - 1, y, &red2, &green2, &blue2);
            setPixel(image, x, y, red2, green2, blue2);
            setPixel(image, image->width - x - 1, y, red, green, blue);
        }
    }
}

void flipVertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            unsigned char red2, green2, blue2;
            getPixel(image, x, image->height - y - 1, &red2, &green2, &blue2);
            setPixel(image, x, y, red2, green2, blue2);
            setPixel(image, x, image->height - y - 1, red, green, blue);
        }
    }
}

void changeBrightness(Image *image, int amount) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            setPixel(image, x, y, red + amount, green + amount, blue + amount);
        }
    }
}

void changeContrast(Image *image, float amount) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            setPixel(image, x, y, (unsigned char)(red * amount), (unsigned char)(green * amount), (unsigned char)(blue * amount));
        }
    }
}

int main() {
    Image *image = createImage(MAX_WIDTH, MAX_HEIGHT);

    // Flip horizontal
    flipHorizontal(image);

    // Flip vertical
    flipVertical(image);

    // Change brightness
    changeBrightness(image, 100);

    // Change contrast
    changeContrast(image, 2.0);

    // Display the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            printf("%c%c%c", red, green, blue);
        }
        printf("\n");
    }

    destroyImage(image);
    return 0;
}