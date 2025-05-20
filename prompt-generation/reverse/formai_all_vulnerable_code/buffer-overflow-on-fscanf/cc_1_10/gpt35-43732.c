//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct Image {
    int width;
    int height;
    Pixel* pixels;
} Image;

void flipImage(Image* image) {
    Pixel* temp = malloc(sizeof(Pixel) * image->width);
    int halfHeight = image->height / 2;
    for (int y = 0; y < halfHeight; y++) {
        int oppositeY = image->height - y - 1;
        memcpy(temp, &image->pixels[y * image->width], sizeof(Pixel) * image->width);
        memcpy(&image->pixels[y * image->width], &image->pixels[oppositeY * image->width], sizeof(Pixel) * image->width);
        memcpy(&image->pixels[oppositeY * image->width], temp, sizeof(Pixel) * image->width);
    }
    free(temp);
}

void adjustBrightness(Image* image, double brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        Pixel* p = &image->pixels[i];
        p->r = (unsigned char) (p->r * brightness);
        p->g = (unsigned char) (p->g * brightness);
        p->b = (unsigned char) (p->b * brightness);
    }
}

void adjustContrast(Image* image, double contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < image->width * image->height; i++) {
        Pixel* p = &image->pixels[i];
        p->r = (unsigned char) (factor * (p->r - 128) + 128);
        p->g = (unsigned char) (factor * (p->g - 128) + 128);
        p->b = (unsigned char) (factor * (p->b - 128) + 128);
    }
}

int main() {
    Image image;
    FILE* file = fopen("image.ppm", "rb");
    if (!file) {
        printf("Error: could not load image\n");
        return 1;
    }
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Error: invalid file format\n");
        fclose(file);
        return 1;
    }
    fscanf(file, "%d %d", &image.width, &image.height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    fgetc(file); // read newline character
    image.pixels = malloc(sizeof(Pixel) * image.width * image.height);
    fread(image.pixels, sizeof(Pixel), image.width * image.height, file);
    fclose(file);

    flipImage(&image);
    adjustBrightness(&image, 1.5);
    adjustContrast(&image, 50.0);

    // save modified image
    file = fopen("modified_image.ppm", "wb");
    if (!file) {
        printf("Error: could not save image\n");
        return 1;
    }

    fprintf(file, "P6\n%d %d\n%d\n", image.width, image.height, maxColor);
    fwrite(image.pixels, sizeof(Pixel), image.width * image.height, file);
    fclose(file);

    free(image.pixels);

    return 0;
}