//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
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
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGBTRIPLE;
#pragma pack(pop)

void flipImage(RGBTRIPLE **pixels, int width, int height) {
    for(int i = 0; i < height / 2; i++) {
        for(int j = 0; j < width; j++) {
            RGBTRIPLE temp = pixels[i][j];
            pixels[i][j] = pixels[height - i - 1][j];
            pixels[height - i - 1][j] = temp;
        }
    }
}

void changeBrightness(RGBTRIPLE **pixels, int width, int height, int brightness) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixels[i][j].red = (pixels[i][j].red + brightness > 255) ? 255 : pixels[i][j].red + brightness < 0 ? 0 : pixels[i][j].red + brightness;
            pixels[i][j].green = (pixels[i][j].green + brightness > 255) ? 255 : pixels[i][j].green + brightness < 0 ? 0 : pixels[i][j].green + brightness;
            pixels[i][j].blue = (pixels[i][j].blue + brightness > 255) ? 255 : pixels[i][j].blue + brightness < 0 ? 0 : pixels[i][j].blue + brightness;
        }
    }
}

void adjustContrast(RGBTRIPLE **pixels, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixels[i][j].red = (int)(factor * (pixels[i][j].red - 128) + 128);
            pixels[i][j].green = (int)(factor * (pixels[i][j].green - 128) + 128);
            pixels[i][j].blue = (int)(factor * (pixels[i][j].blue - 128) + 128);
            
            // Clamp values between 0-255
            pixels[i][j].red = pixels[i][j].red > 255 ? 255 : pixels[i][j].red < 0 ? 0 : pixels[i][j].red;
            pixels[i][j].green = pixels[i][j].green > 255 ? 255 : pixels[i][j].green < 0 ? 0 : pixels[i][j].green;
            pixels[i][j].blue = pixels[i][j].blue > 255 ? 255 : pixels[i][j].blue < 0 ? 0 : pixels[i][j].blue;
        }
    }
}

void freePixels(RGBTRIPLE **pixels, int height) {
    for(int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
}

RGBTRIPLE **loadBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file!\n");
        fclose(file);
        exit(1);
    }

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;

    RGBTRIPLE **pixels = malloc(height * sizeof(RGBTRIPLE *));
    for(int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(RGBTRIPLE));
        fread(pixels[i], sizeof(RGBTRIPLE), width, file);
    }

    fclose(file);
    return pixels;
}

void saveBMP(const char *filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGBTRIPLE **pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file!\n");
        exit(1);
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    for(int i = 0; i < infoHeader.biHeight; i++) {
        fwrite(pixels[i], sizeof(RGBTRIPLE), infoHeader.biWidth, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGBTRIPLE **pixels = loadBMP(inputFilename, &fileHeader, &infoHeader);

    // Process the image
    flipImage(pixels, infoHeader.biWidth, infoHeader.biHeight);
    changeBrightness(pixels, infoHeader.biWidth, infoHeader.biHeight, brightness);
    adjustContrast(pixels, infoHeader.biWidth, infoHeader.biHeight, contrast);

    // Save the processed image
    saveBMP(outputFilename, fileHeader, infoHeader, pixels);
    freePixels(pixels, infoHeader.biHeight);
    
    printf("Image processing complete! Output saved to %s\n", outputFilename);
    return 0;
}