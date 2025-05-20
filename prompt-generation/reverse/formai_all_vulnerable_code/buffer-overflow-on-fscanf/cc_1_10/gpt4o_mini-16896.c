//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define BLOCK_SIZE 8
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_SIZE 64

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[IMAGE_HEIGHT][IMAGE_WIDTH];
} Image;

typedef struct {
    uint8_t data[WATERMARK_SIZE][WATERMARK_SIZE];
} Watermark;

// Function prototypes
void loadImage(const char *filename, Image *img);
void saveImage(const char *filename, Image *img);
void applyWatermark(Image *img, Watermark *wm, int x_offset, int y_offset);
void extractWatermark(Image *img, Watermark *wm, int x_offset, int y_offset);
void createWatermark(Watermark *wm);

int main() {
    Image img;
    Watermark wm;

    loadImage("input.ppm", &img);
    createWatermark(&wm);
    
    applyWatermark(&img, &wm, 10, 10);
    saveImage("output.ppm", &img);

    Watermark extracted_wm;
    extractWatermark(&img, &extracted_wm, 10, 10);

    // Save extracted watermark for inspection
    FILE *fw = fopen("extracted_watermark.ppm", "wb");
    if (!fw) {
        fprintf(stderr, "Error saving extracted watermark.\n");
        return 1;
    }
    fprintf(fw, "P6\n%d %d\n255\n", WATERMARK_SIZE, WATERMARK_SIZE);
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            uint8_t color = extracted_wm.data[i][j] ? 255 : 0;
            fwrite(&color, 1, 1, fw);
            fwrite(&color, 1, 1, fw);
            fwrite(&color, 1, 1, fw);
        }
    }
    fclose(fw);

    printf("Watermark successfully embedded and extracted.\n");
    return 0;
}

void loadImage(const char *filename, Image *img) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Could not open image file.\n");
        exit(1);
    }
    // Simple PPM Header Reading
    char header[3];
    fscanf(f, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported image format. Only P6 PPM is supported.\n");
        fclose(f);
        exit(1);
    }
    int width, height, maxVal;
    fscanf(f, "%d %d %d", &width, &height, &maxVal);
    if (width != IMAGE_WIDTH || height != IMAGE_HEIGHT || maxVal != 255) {
        fprintf(stderr, "Image size or format does not match.\n");
        fclose(f);
        exit(1);
    }
    fgetc(f); // consume the newline after the header
    fread(img->pixels, sizeof(Pixel), IMAGE_HEIGHT * IMAGE_WIDTH, f);
    fclose(f);
}

void saveImage(const char *filename, Image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Could not save image file.\n");
        exit(1);
    }
    fprintf(f, "P6\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fwrite(img->pixels, sizeof(Pixel), IMAGE_HEIGHT * IMAGE_WIDTH, f);
    fclose(f);
}

void applyWatermark(Image *img, Watermark *wm, int x_offset, int y_offset) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            if (i + y_offset < IMAGE_HEIGHT && j + x_offset < IMAGE_WIDTH) {
                // Embedded watermark alters the blue channel slightly based on watermark bits
                img->pixels[i + y_offset][j + x_offset].b = 
                    (wm->data[i][j]) ? (img->pixels[i + y_offset][j + x_offset].b + 1) : 
                                        (img->pixels[i + y_offset][j + x_offset].b - 1);
            }
        }
    }
}

void extractWatermark(Image *img, Watermark *wm, int x_offset, int y_offset) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            if (i + y_offset < IMAGE_HEIGHT && j + x_offset < IMAGE_WIDTH) {
                // Extraction logic assumes the blue channel has been altered
                wm->data[i][j] = (img->pixels[i + y_offset][j + x_offset].b % 2) ? 1 : 0;
            }
        }
    }
}

void createWatermark(Watermark *wm) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            wm->data[i][j] = (i + j) % 2; // Create a simple checkered watermark
        }
    }
}