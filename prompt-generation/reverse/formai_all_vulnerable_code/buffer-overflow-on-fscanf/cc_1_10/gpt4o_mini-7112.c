//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

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
        perror("Failed to open file");
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        free(img);
        return NULL;
    }

    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void convertToGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (unsigned char)((0.299 * img->pixels[i].r) + (0.587 * img->pixels[i].g) + (0.114 * img->pixels[i].b));
        img->pixels[i].r = img->pixels[i].g = img->pixels[i].b = gray;
    }
}

void flipVertically(Image *img) {
    int rowSize = img->width;
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < rowSize; x++) {
            int topIndex = (y * rowSize) + x;
            int bottomIndex = ((img->height - y - 1) * rowSize) + x;
            Pixel temp = img->pixels[topIndex];
            img->pixels[topIndex] = img->pixels[bottomIndex];
            img->pixels[bottomIndex] = temp;
        }
    }
}

void freeImage(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <operation: grayscale | flip>\n", argv[0]);
        return 1;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) {
        return 1;
    }

    if (strcmp(argv[3], "grayscale") == 0) {
        convertToGrayscale(img);
    } else if (strcmp(argv[3], "flip") == 0) {
        flipVertically(img);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[3]);
        freeImage(img);
        return 1;
    }

    savePPM(argv[2], img);
    freeImage(img);
    printf("Image processed successfully!\n");
    return 0;
}