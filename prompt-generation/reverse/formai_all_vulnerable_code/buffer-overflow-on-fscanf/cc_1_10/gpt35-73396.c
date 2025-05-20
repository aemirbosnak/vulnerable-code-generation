//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

void readImage(Image *image) {
    FILE *file = fopen("image.ppm", "r");
    fscanf(file, "P3\n%d %d\n255\n", &image->width, &image->height);
    image->pixels = (Pixel*) malloc(image->width * image->height * sizeof(Pixel));
    for (int i = 0; i < image->width * image->height; ++i) {
        fscanf(file, "%hhu %hhu %hhu", &image->pixels[i].red, &image->pixels[i].green, &image->pixels[i].blue);
    }
    fclose(file);
}

void writeImage(Image *image) {
    FILE *file = fopen("output.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->width * image->height; ++i) {
        fprintf(file, "%hhu %hhu %hhu\t", image->pixels[i].red, image->pixels[i].green, image->pixels[i].blue);
        if ((i+1) % image->width == 0) fprintf(file, "\n");
    }
    fclose(file);
}

void flip(Image *image) {
    Pixel temp;
    for (int i = 0; i < image->height / 2; ++i) {
        for (int j = 0; j < image->width; ++j) {
            temp = image->pixels[i*image->width + j];
            image->pixels[i*image->width + j] = image->pixels[(image->height-i-1)*image->width + j];
            image->pixels[(image->height-i-1)*image->width + j] = temp;
        }
    }
}

void brightnessContrast(Image *image, int brightness, float contrast) {
    for (int i = 0; i < image->width * image->height; ++i) {
        image->pixels[i].red = (unsigned char) (image->pixels[i].red * contrast + brightness);
        image->pixels[i].green = (unsigned char) (image->pixels[i].green * contrast + brightness);
        image->pixels[i].blue = (unsigned char) (image->pixels[i].blue * contrast + brightness);
    }
}

int main() {
    Image image;
    readImage(&image);
    flip(&image);
    brightnessContrast(&image, 50, 1.5);
    writeImage(&image);
    free(image.pixels);
    return 0;
}