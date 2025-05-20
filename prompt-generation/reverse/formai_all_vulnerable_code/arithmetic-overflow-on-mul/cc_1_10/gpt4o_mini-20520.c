//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void flip_image(Pixel *image, int width, int height);
void adjust_brightness(Pixel *image, int width, int height, int brightness);
void read_bmp(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, Pixel **image);
void write_bmp(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, Pixel *image);
void free_image(Pixel *image);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output_flipped.bmp> <output_brightened.bmp> <brightness_value>\n", argv[0]);
        return 1;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    Pixel *image = NULL;
    read_bmp(argv[1], &bmpHeader, &bmpInfoHeader, &image);

    // Flip the image
    flip_image(image, bmpInfoHeader.biWidth, bmpInfoHeader.biHeight);
    write_bmp(argv[2], &bmpHeader, &bmpInfoHeader, image);

    // Adjust brightness
    int brightness = atoi(argv[4]);
    adjust_brightness(image, bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, brightness);
    write_bmp(argv[3], &bmpHeader, &bmpInfoHeader, image);
    
    free_image(image);
    return 0;
}

void flip_image(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            Pixel temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - 1 - x)];
            image[y * width + (width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Pixel *image, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = (image[i].red + brightness < 255) ? 
                       (image[i].red + brightness > 0 ? image[i].red + brightness : 0) : 255;
        image[i].green = (image[i].green + brightness < 255) ? 
                         (image[i].green + brightness > 0 ? image[i].green + brightness : 0) : 255;
        image[i].blue = (image[i].blue + brightness < 255) ? 
                        (image[i].blue + brightness > 0 ? image[i].blue + brightness : 0) : 255;
    }
}

void read_bmp(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, Pixel **image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    fseek(file, bmpHeader->bfOffBits, SEEK_SET);
    int size = bmpInfoHeader->biWidth * bmpInfoHeader->biHeight;
    *image = (Pixel *)malloc(size * sizeof(Pixel));
    fread(*image, sizeof(Pixel), size, file);
    fclose(file);
}

void write_bmp(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, Pixel *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, bmpHeader->bfOffBits, SEEK_SET);
    int size = bmpInfoHeader->biWidth * bmpInfoHeader->biHeight;
    fwrite(image, sizeof(Pixel), size, file);
    fclose(file);
}

void free_image(Pixel *image) {
    if (image) {
        free(image);
    }
}