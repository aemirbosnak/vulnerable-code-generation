//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIMENSION 512
#define WATERMARK_SIZE 64

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[MAX_DIMENSION][MAX_DIMENSION];
    int width;
    int height;
} Image;

void readImage(const char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    // Assuming a simple RGB format for demo purposes
    fread(&(img->width), sizeof(int), 1, file);
    fread(&(img->height), sizeof(int), 1, file);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void writeImage(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(&(img->width), sizeof(int), 1, file);
    fwrite(&(img->height), sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void embedWatermark(Image* img, const char* watermark) {
    int watermarkLen = strlen(watermark);
    int index = 0;

    for (int i = 0; i < img->height && index < watermarkLen; i += 8) {
        for (int j = 0; j < img->width && index < watermarkLen; j += 8) {
            // Embed one character of watermark in each pixel
            char ch = watermark[index];
            img->pixels[i][j].r = (img->pixels[i][j].r & 0xFE) | ((ch >> 7) & 0x01);
            img->pixels[i][j].g = (img->pixels[i][j].g & 0xFE) | ((ch >> 6) & 0x01);
            img->pixels[i][j].b = (img->pixels[i][j].b & 0xFE) | ((ch >> 5) & 0x01);
            index++;
        }
    }
}

void extractWatermark(Image* img, char* watermark) {
    int index = 0;

    for (int i = 0; i < img->height && index < WATERMARK_SIZE; i += 8) {
        for (int j = 0; j < img->width && index < WATERMARK_SIZE; j += 8) {
            // Extract one character of watermark from each pixel
            char ch = 0;
            ch |= (img->pixels[i][j].r & 0x01) << 7;
            ch |= (img->pixels[i][j].g & 0x01) << 6;
            ch |= (img->pixels[i][j].b & 0x01) << 5;
            watermark[index++] = ch;
        }
    }
    
    watermark[index] = '\0'; // Null-terminate extracted watermark
}

int main() {
    Image img;
    char watermark[WATERMARK_SIZE] = "Watermark12345";
    char extractedWatermark[WATERMARK_SIZE];

    // Read the input image (assumes it is a simple binary format)
    readImage("input_image.bin", &img);

    // Embed the watermark into the image
    embedWatermark(&img, watermark);

    // Write the watermarked image
    writeImage("watermarked_image.bin", &img);

    // Extract the watermark from the watermarked image
    extractWatermark(&img, extractedWatermark);

    // Display the extracted watermark
    printf("Extracted Watermark: %s\n", extractedWatermark);

    return 0;
}