//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
typedef struct {
    unsigned char magic[2];
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int dataOffset;
} BMPHeader;

typedef struct {
    unsigned int headerSize;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

void flipImageHorizontally(const char *inputFile, const char *outputFile) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    if (bmpHeader.magic[0] != 'B' || bmpHeader.magic[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    Pixel *pixels = malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fseek(file, bmpHeader.dataOffset, SEEK_SET);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, file);
    fclose(file);

    for (int i = 0; i < bmpInfoHeader.height; i++) {
        for (int j = 0; j < bmpInfoHeader.width / 2; j++) {
            Pixel temp = pixels[i * bmpInfoHeader.width + j];
            pixels[i * bmpInfoHeader.width + j] = pixels[i * bmpInfoHeader.width + (bmpInfoHeader.width - 1 - j)];
            pixels[i * bmpInfoHeader.width + (bmpInfoHeader.width - 1 - j)] = temp;
        }
    }

    file = fopen(outputFile, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, bmpHeader.dataOffset, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, file);
    fclose(file);
    free(pixels);
}

void adjustBrightnessContrast(const char *inputFile, const char *outputFile, float brightness, float contrast) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Error opening input file");
        return;
    }
    
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    if (bmpHeader.magic[0] != 'B' || bmpHeader.magic[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    Pixel *pixels = malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fseek(file, bmpHeader.dataOffset, SEEK_SET);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, file);
    fclose(file);

    for (int i = 0; i < bmpInfoHeader.height; i++) {
        for (int j = 0; j < bmpInfoHeader.width; j++) {
            Pixel *p = &pixels[i * bmpInfoHeader.width + j];
            p->red = fmin(fmax((p->red - 128) * contrast + 128 + brightness, 0), 255);
            p->green = fmin(fmax((p->green - 128) * contrast + 128 + brightness, 0), 255);
            p->blue = fmin(fmax((p->blue - 128) * contrast + 128 + brightness, 0), 255);
        }
    }

    file = fopen(outputFile, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, bmpHeader.dataOffset, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, file);
    fclose(file);
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.bmp> <output_flipped.bmp> <output_brightness_contrast.bmp> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFlippedFile = argv[2];
    const char *outputBrightnessContrastFile = argv[3];
    float brightness = atof(argv[4]);
    float contrast = atof(argv[5]);

    flipImageHorizontally(inputFile, outputFlippedFile);
    printf("Image flipped and saved to: %s\n", outputFlippedFile);

    adjustBrightnessContrast(inputFile, outputBrightnessContrastFile, brightness, contrast);
    printf("Brightness and contrast adjusted and saved to: %s\n", outputBrightnessContrastFile);

    return EXIT_SUCCESS;
}