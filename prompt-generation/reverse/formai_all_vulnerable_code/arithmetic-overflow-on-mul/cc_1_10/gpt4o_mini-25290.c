//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(push, 1) // Ensure packing is 1 byte for struct alignment
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t b;
    uint8_t g;
    uint8_t r;
} RGB;

#pragma pack(pop)

void flipImageVertically(RGB *image, int width, int height) {
    for (int row = 0; row < height / 2; row++) {
        for (int col = 0; col < width; col++) {
            RGB temp = image[row * width + col];
            image[row * width + col] = image[(height - row - 1) * width + col];
            image[(height - row - 1) * width + col] = temp;
        }
    }
}

void adjustBrightness(RGB *image, int width, int height, int value) {
    for (int i = 0; i < width * height; i++) {
        image[i].r = (uint8_t) fmin(fmax(image[i].r + value, 0), 255);
        image[i].g = (uint8_t) fmin(fmax(image[i].g + value, 0), 255);
        image[i].b = (uint8_t) fmin(fmax(image[i].b + value, 0), 255);
    }
}

void adjustContrast(RGB *image, int width, int height, float factor) {
    for (int i = 0; i < width * height; i++) {
        image[i].r = (uint8_t) fmin(fmax((factor * (image[i].r - 128) + 128), 0), 255);
        image[i].g = (uint8_t) fmin(fmax((factor * (image[i].g - 128) + 128), 0), 255);
        image[i].b = (uint8_t) fmin(fmax((factor * (image[i].b - 128) + 128), 0), 255);
    }
}

void saveBMP(const char *filename, BMPHeader bmpHeader, BMPInfoHeader bmpInfoHeader, RGB *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save the image");
        exit(EXIT_FAILURE);
    }
    fwrite(&bmpHeader, sizeof(bmpHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, file);
    fwrite(image, sizeof(RGB), bmpInfoHeader.width * bmpInfoHeader.height, file);
    fclose(file);
}

RGB *loadBMP(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open the image");
        exit(EXIT_FAILURE);
    }
    
    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    if (bmpHeader->type != 0x4D42) { // 'BM' in hexadecimal
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    RGB *image = malloc(bmpInfoHeader->width * bmpInfoHeader->height * sizeof(RGB));
    if (!image) {
        perror("Unable to allocate memory for image");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fseek(file, bmpHeader->offset, SEEK_SET);
    fread(image, sizeof(RGB), bmpInfoHeader->width * bmpInfoHeader->height, file);
    fclose(file);
    
    return image;
}

int main() {
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    RGB *image = loadBMP("input.bmp", &bmpHeader, &bmpInfoHeader);

    printf("Image Loaded: Width = %d, Height = %d\n", bmpInfoHeader.width, bmpInfoHeader.height);
    
    // Flip the image vertically
    flipImageVertically(image, bmpInfoHeader.width, bmpInfoHeader.height);
    saveBMP("flipped.bmp", bmpHeader, bmpInfoHeader, image);
    printf("Flipped image saved as flipped.bmp\n");

    // Adjust brightness
    adjustBrightness(image, bmpInfoHeader.width, bmpInfoHeader.height, 30);
    saveBMP("bright.bmp", bmpHeader, bmpInfoHeader, image);
    printf("Brightness adjusted image saved as bright.bmp\n");

    // Adjust contrast
    adjustContrast(image, bmpInfoHeader.width, bmpInfoHeader.height, 1.5);
    saveBMP("contrast.bmp", bmpHeader, bmpInfoHeader, image);
    printf("Contrast adjusted image saved as contrast.bmp\n");

    free(image);
    return 0;
}