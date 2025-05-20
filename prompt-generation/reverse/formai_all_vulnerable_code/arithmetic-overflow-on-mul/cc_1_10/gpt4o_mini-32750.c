//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* data;
} Image;

void loadImage(const char* filename, Image* img) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    fseek(f, 18, SEEK_SET);
    fread(&img->width, sizeof(int), 1, f);
    fread(&img->height, sizeof(int), 1, f);
    fseek(f, 54, SEEK_SET);

    img->data = (Pixel*)malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->data, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void saveImage(const char* filename, Image* img) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error opening file for writing.\n");
        exit(1);
    }

    fwrite("BM", 2, 1, f);
    int filesize = 54 + sizeof(Pixel) * img->width * img->height;
    fwrite(&filesize, sizeof(int), 1, f);
    int reserved = 0;
    fwrite(&reserved, sizeof(int), 1, f);
    int offset = 54;
    fwrite(&offset, sizeof(int), 1, f);
    int headerSize = 40;
    fwrite(&headerSize, sizeof(int), 1, f);
    fwrite(&img->width, sizeof(int), 1, f);
    fwrite(&img->height, sizeof(int), 1, f);
    short planes = 1, bpp = 24;
    fwrite(&planes, sizeof(short), 1, f);
    fwrite(&bpp, sizeof(short), 1, f);
    int compression = 0;
    fwrite(&compression, sizeof(int), 1, f);
    int imgSize = 0;
    fwrite(&imgSize, sizeof(int), 1, f);
    int xPPM = 0, yPPM = 0;
    fwrite(&xPPM, sizeof(int), 1, f);
    fwrite(&yPPM, sizeof(int), 1, f);
    int clrUsed = 0, clrImportant = 0;
    fwrite(&clrUsed, sizeof(int), 1, f);
    fwrite(&clrImportant, sizeof(int), 1, f);
    
    fwrite(img->data, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void flipHorizontally(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjustBrightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : (img->data[i].r + value < 0) ? 0 : img->data[i].r + value;
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : (img->data[i].g + value < 0) ? 0 : img->data[i].g + value;
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : (img->data[i].b + value < 0) ? 0 : img->data[i].b + value;
    }
}

void adjustContrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 128 + factor * (img->data[i].r - 128);
        img->data[i].g = 128 + factor * (img->data[i].g - 128);
        img->data[i].b = 128 + factor * (img->data[i].b - 128);

        img->data[i].r = (img->data[i].r > 255) ? 255 : (img->data[i].r < 0) ? 0 : img->data[i].r;
        img->data[i].g = (img->data[i].g > 255) ? 255 : (img->data[i].g < 0) ? 0 : img->data[i].g;
        img->data[i].b = (img->data[i].b > 255) ? 255 : (img->data[i].b < 0) ? 0 : img->data[i].b;
    }
}

void freeImage(Image* img) {
    free(img->data);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image img;
    loadImage(argv[1], &img);

    flipHorizontally(&img);
    adjustBrightness(&img, brightness);
    adjustContrast(&img, contrast);

    saveImage(argv[2], &img);
    freeImage(&img);

    return 0;
}