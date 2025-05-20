//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensures that the structs are packed without padding
typedef struct {
    uint16_t bfType;       // File type
    uint32_t bfSize;       // Size of the file
    uint16_t bfReserved1;  // Reserved, must be zero
    uint16_t bfReserved2;  // Reserved, must be zero
    uint32_t bfOffBits;    // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of the info header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Must be 1
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the pixel data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;     // Blue value
    uint8_t green;    // Green value
    uint8_t red;      // Red value
} PIXEL;

#pragma pack(pop)

void flip_image(PIXEL **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            PIXEL temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void change_brightness(PIXEL **image, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int newRed = image[i][j].red + value;
            int newGreen = image[i][j].green + value;
            int newBlue = image[i][j].blue + value;

            image[i][j].red = (newRed < 0) ? 0 : (newRed > 255) ? 255 : newRed;
            image[i][j].green = (newGreen < 0) ? 0 : (newGreen > 255) ? 255 : newGreen;
            image[i][j].blue = (newBlue < 0) ? 0 : (newBlue > 255) ? 255 : newBlue;
        }
    }
}

void change_contrast(PIXEL **image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int newRed = (int)(factor * (image[i][j].red - 128) + 128);
            int newGreen = (int)(factor * (image[i][j].green - 128) + 128);
            int newBlue = (int)(factor * (image[i][j].blue - 128) + 128);

            image[i][j].red = (newRed < 0) ? 0 : (newRed > 255) ? 255 : newRed;
            image[i][j].green = (newGreen < 0) ? 0 : (newGreen > 255) ? 255 : newGreen;
            image[i][j].blue = (newBlue < 0) ? 0 : (newBlue > 255) ? 255 : newBlue;
        }
    }
}

PIXEL **read_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;

    PIXEL **image = (PIXEL **)malloc(height * sizeof(PIXEL *));
    for (int i = 0; i < height; i++) {
        image[i] = (PIXEL *)malloc(width * sizeof(PIXEL));
        fseek(file, fileHeader->bfOffBits + (height - i - 1) * width * sizeof(PIXEL), SEEK_SET);
        fread(image[i], sizeof(PIXEL), width, file);
    }

    fclose(file);
    return image;
}

void write_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, PIXEL **image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    for (int i = 0; i < infoHeader->biHeight; i++) {
        fwrite(image[i], sizeof(PIXEL), infoHeader->biWidth, file);
    }

    fclose(file);
}

void free_image(PIXEL **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

int main(void) {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";

    PIXEL **image = read_bmp(inputFile, &fileHeader, &infoHeader);
    if (!image) return 1;

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;

    // Flipping the image
    flip_image(image, width, height);
    // Change brightness
    change_brightness(image, width, height, 50);
    // Change contrast
    change_contrast(image, width, height, 1.2f);

    write_bmp(outputFile, &fileHeader, &infoHeader, image);
    free_image(image, height);

    printf("Image processing completed! Check 'output.bmp'.\n");

    return 0;
}