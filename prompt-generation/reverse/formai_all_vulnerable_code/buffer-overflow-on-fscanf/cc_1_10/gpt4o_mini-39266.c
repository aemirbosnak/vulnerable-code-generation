//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    // Read header
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Read the newline after maxval

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(Pixel));

    fread(img->pixels, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipImageVertically(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            int topIndex = y * img->width + x;
            int bottomIndex = (img->height - 1 - y) * img->width + x;
            // Swap pixels
            Pixel temp = img->pixels[topIndex];
            img->pixels[topIndex] = img->pixels[bottomIndex];
            img->pixels[bottomIndex] = temp;
        }
    }
}

void adjustBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)fmin(fmax(img->pixels[i].r + value, 0), 255);
        img->pixels[i].g = (unsigned char)fmin(fmax(img->pixels[i].g + value, 0), 255);
        img->pixels[i].b = (unsigned char)fmin(fmax(img->pixels[i].b + value, 0), 255);
    }
}

void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)fmin(fmax(((img->pixels[i].r - 128) * factor) + 128, 0), 255);
        img->pixels[i].g = (unsigned char)fmin(fmax(((img->pixels[i].g - 128) * factor) + 128, 0), 255);
        img->pixels[i].b = (unsigned char)fmin(fmax(((img->pixels[i].b - 128) * factor) + 128, 0), 255);
    }
}

void freeImage(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) {
        return 1;
    }

    flipImageVertically(img);
    adjustBrightness(img, 50);
    adjustContrast(img, 1.2f);

    savePPM(argv[2], img);

    freeImage(img);
    return 0;
}