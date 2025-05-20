//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* pixels;
} Image;

Image* loadPPM(const char* filename);
void savePPM(const char* filename, Image* img);
void embedWatermark(Image* img, const char* watermark);
char* extractWatermark(Image* img, int watermarkLength);
void freeImage(Image* img);

int main() {
    const char* inputFile = "input.ppm";
    const char* outputFile = "output.ppm";
    const char* watermark = "WATERMARK";

    // Load image
    Image* img = loadPPM(inputFile);
    if (!img) {
        fprintf(stderr, "Failed to load image %s\n", inputFile);
        return 1;
    }

    // Embed watermark
    embedWatermark(img, watermark);
    savePPM(outputFile, img);
    printf("Watermark embedded and saved to %s\n", outputFile);

    // Extract watermark
    char* extractedWatermark = extractWatermark(img, strlen(watermark));
    if (extractedWatermark) {
        printf("Extracted Watermark: %s\n", extractedWatermark);
        free(extractedWatermark);
    }

    // Clean up
    freeImage(img);
    return 0;
}

Image* loadPPM(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return NULL;

    char header[3];
    fscanf(fp, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(fp);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(fp, "%d", &maxval);
    fgetc(fp);  // Consume newline after maxval

    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void savePPM(const char* filename, Image* img) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) return;

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void embedWatermark(Image* img, const char* watermark) {
    int length = strlen(watermark);
    for (int i = 0; i < length; i++) {
        img->pixels[i].r = (img->pixels[i].r & 0xFE) | ((watermark[i] >> 7) & 0x01);
        img->pixels[i].g = (img->pixels[i].g & 0xFE) | ((watermark[i] >> 6) & 0x01);
        img->pixels[i].b = (img->pixels[i].b & 0xFE) | ((watermark[i] >> 5) & 0x01);
    }
}

char* extractWatermark(Image* img, int watermarkLength) {
    char* watermark = (char*)malloc(watermarkLength + 1);
    for (int i = 0; i < watermarkLength; i++) {
        watermark[i] = 0;
        watermark[i] |= (img->pixels[i].r & 0x01) << 7;
        watermark[i] |= (img->pixels[i].g & 0x01) << 6;
        watermark[i] |= (img->pixels[i].b & 0x01) << 5;
    }
    watermark[watermarkLength] = '\0';
    return watermark;
}

void freeImage(Image* img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}