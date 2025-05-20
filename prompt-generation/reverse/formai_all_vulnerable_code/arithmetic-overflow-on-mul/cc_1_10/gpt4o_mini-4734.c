//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 256

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

typedef struct {
    char message[MAX_WATERMARK_SIZE];
    int message_length;
} Watermark;

// Function to read a BMP file
Image *read_bmp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror(" fopen ");
        return NULL;
    }

    // Skip BMP header
    fseek(file, 18, SEEK_SET);

    Image *img = malloc(sizeof(Image));
    fread(&(img->width), sizeof(int), 1, file);
    fread(&(img->height), sizeof(int), 1, file);
    
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    
    // Skip unused data
    fseek(file, 54, SEEK_SET);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fread(&img->pixels[i * img->width + j], sizeof(Pixel), 1, file);
        }
    }
    
    fclose(file);
    return img;
}

// Function to write a BMP file
void write_bmp(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror(" fopen ");
        return;
    }

    // Writing BMP header
    uint16_t bfType = 0x4D42; // 'BM'
    fwrite(&bfType, sizeof(uint16_t), 1, file);
    uint32_t bfSize = 54 + (img->width * img->height * sizeof(Pixel));
    fwrite(&bfSize, sizeof(uint32_t), 1, file);
    uint32_t bfReserved = 0;
    fwrite(&bfReserved, sizeof(uint32_t), 1, file);
    uint32_t bfOffBits = 54;
    fwrite(&bfOffBits, sizeof(uint32_t), 1, file);
    
    // Writing DIB header
    uint32_t biSize = 40;
    fwrite(&biSize, sizeof(uint32_t), 1, file);
    fwrite(&(img->width), sizeof(int), 1, file);
    fwrite(&(img->height), sizeof(int), 1, file);
    uint16_t biPlanes = 1;
    fwrite(&biPlanes, sizeof(uint16_t), 1, file);
    uint16_t biBitCount = 24;
    fwrite(&biBitCount, sizeof(uint16_t), 1, file);
    uint32_t biCompression = 0;
    fwrite(&biCompression, sizeof(uint32_t), 1, file);
    uint32_t biSizeImage = 0;
    fwrite(&biSizeImage, sizeof(uint32_t), 1, file);
    uint32_t biXPelsPerMeter = 0;
    fwrite(&biXPelsPerMeter, sizeof(uint32_t), 1, file);
    uint32_t biYPelsPerMeter = 0;
    fwrite(&biYPelsPerMeter, sizeof(uint32_t), 1, file);
    uint32_t biClrUsed = 0;
    fwrite(&biClrUsed, sizeof(uint32_t), 1, file);
    uint32_t biClrImportant = 0;
    fwrite(&biClrImportant, sizeof(uint32_t), 1, file);
    
    // Write pixel data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fwrite(&img->pixels[i * img->width + j], sizeof(Pixel), 1, file);
        }
    }
    
    fclose(file);
}

// Function to embed watermark into the image
void embed_watermark(Image *img, Watermark *wm) {
    for (int i = 0; i < wm->message_length; i++) {
        int pxIndex = (i * 8) % (img->width * img->height);
        Pixel *p = &img->pixels[pxIndex];

        // Embed each bit of watermark into the least significant bit of each color channel
        p->r = (p->r & ~1) | ((wm->message[i / 8] >> (7 - (i % 8))) & 1);
    }
}

// Function to extract watermark from the image
void extract_watermark(Image *img, Watermark *wm) {
    memset(wm->message, 0, sizeof(wm->message));
    
    for (int i = 0; i < (wm->message_length * 8); i++) {
        int pxIndex = (i * 8) % (img->width * img->height);
        Pixel *p = &img->pixels[pxIndex];

        // Extract each bit from the least significant bit of each color channel
        wm->message[i / 8] |= ((p->r & 1) << (7 - (i % 8)));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark_message>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    Image *image = read_bmp(argv[1]);
    if (!image) {
        exit(EXIT_FAILURE);
    }

    Watermark watermark;
    strncpy(watermark.message, argv[3], MAX_WATERMARK_SIZE);
    watermark.message_length = strlen(watermark.message);
    
    embed_watermark(image, &watermark);
    write_bmp(argv[2], image);
    
    Watermark extracted_watermark;
    extract_watermark(image, &extracted_watermark);
    printf("Extracted Watermark: %s\n", extracted_watermark.message);
    
    free(image->pixels);
    free(image);
    return EXIT_SUCCESS;
}