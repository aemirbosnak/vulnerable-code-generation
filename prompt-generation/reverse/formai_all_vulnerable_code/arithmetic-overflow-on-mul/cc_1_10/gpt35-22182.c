//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void readImage(char* filename, Pixel** image, int* width, int* height) {
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // extract width and height
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // allocate memory for image data
    int dataSize = *width * *height;
    *image = (Pixel*)malloc(dataSize * sizeof(Pixel));

    // read image data
    fseek(file, *(int*)&header[10], SEEK_SET);
    fread(*image, sizeof(Pixel), dataSize, file);

    fclose(file);
}

void writeImage(char* filename, Pixel* image, int width, int height) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // write BMP header
    unsigned char header[54] = {
        0x42, 0x4D, // "BM"
        0x36, 0x00, 0x0C, 0x00, // file size
        0x00, 0x00, // reserved
        0x00, 0x00, // reserved
        0x36, 0x00, 0x00, 0x00, // offset to image data
        0x28, 0x00, 0x00, 0x00, // size of info header
        0x00, 0x02, 0x00, 0x00, // width
        0x00, 0x02, 0x00, 0x00, // height
        0x01, 0x00, // number of color planes
        0x18, 0x00, // bits per pixel
        0x00, 0x00, 0x00, 0x00, // compression method (none)
        0x00, 0x00, 0x0C, 0x00, // size of image data
        0x13, 0x0B, 0x00, 0x00, // horz resolution
        0x13, 0x0B, 0x00, 0x00, // vert resolution
        0x00, 0x00, 0x00, 0x00, // number of colors in palette
        0x00, 0x00, 0x00, 0x00 // number of important colors
    };
    *(int*)&header[2] = 0x36 + width * height * 3; // file size
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    fwrite(header, sizeof(unsigned char), 54, file);

    // write image data
    fwrite(image, sizeof(Pixel), width * height, file);

    fclose(file);
}

void multiplyPixels(Pixel* image, int width, int height, unsigned char r, unsigned char g, unsigned char b) {
    for (int i = 0; i < width * height; i++) {
        image[i].r = image[i].r * r / 255;
        image[i].g = image[i].g * g / 255;
        image[i].b = image[i].b * b / 255;
    }
}

void addWatermark(Pixel* image, int width, int height, char* text) {
    int textLength = strlen(text);
    if (textLength > 255) {
        printf("Error: text too long\n");
        exit(1);
    }

    unsigned char len = (unsigned char)textLength;
    unsigned char hash = 0;
    for (int i = 0; i < textLength; i++) {
        hash = (hash + (unsigned char)text[i]) % 256;
    }

    // encode length and hash in first pixel
    image[0].r = (image[0].r & 0xFC) | ((len >> 6) & 0x3);
    image[0].g = (image[0].g & 0xFC) | ((len >> 4) & 0x3);
    image[0].b = (image[0].b & 0xFC) | ((len >> 2) & 0x3);
    image[1].r = (image[1].r & 0xFC) | ((len >> 0) & 0x3);
    image[1].g = (image[1].g & 0xFC) | ((hash >> 6) & 0x3);
    image[1].b = (image[1].b & 0xFC) | ((hash >> 4) & 0x3);
    image[2].r = (image[2].r & 0xFC) | ((hash >> 2) & 0x3);
    image[2].g = (image[2].g & 0xFC) | ((hash >> 0) & 0x3);

    // encode text in remaining pixels
    int bitIndex = 0;
    for (int i = 3; i < width * height; i++) {
        if (bitIndex < 8 * textLength) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (text[charIndex] >> (7 - charBitIndex)) & 0x1;
            image[i].r = (image[i].r & 0xFE) | ((bit >> 0) & 0x1);
            bitIndex++;
        }
        if (bitIndex < 8 * textLength) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (text[charIndex] >> (7 - charBitIndex)) & 0x1;
            image[i].g = (image[i].g & 0xFE) | ((bit >> 0) & 0x1);
            bitIndex++;
        }
        if (bitIndex < 8 * textLength) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (text[charIndex] >> (7 - charBitIndex)) & 0x1;
            image[i].b = (image[i].b & 0xFE) | ((bit >> 0) & 0x1);
            bitIndex++;
        }
    }
}

char* extractWatermark(Pixel* image, int width, int height) {
    unsigned char len = ((image[0].r & 0x3) << 6) | ((image[0].g & 0x3) << 4) | ((image[0].b & 0x3) << 2) | ((image[1].r & 0x3) << 0);
    unsigned char hash = ((image[1].g & 0x3) << 6) | ((image[1].b & 0x3) << 4) | ((image[2].r & 0x3) << 2) | ((image[2].g & 0x3) << 0);

    char* text = (char*)malloc(len + 1);
    int bitIndex = 0;
    for (int i = 3; i < width * height; i++) {
        if (bitIndex < 8 * len) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (image[i].r & 0x1) << (7 - charBitIndex);
            text[charIndex] = (text[charIndex] & ~(1 << (7 - charBitIndex))) | bit;
            bitIndex++;
        }
        if (bitIndex < 8 * len) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (image[i].g & 0x1) << (7 - charBitIndex);
            text[charIndex] = (text[charIndex] & ~(1 << (7 - charBitIndex))) | bit;
            bitIndex++;
        }
        if (bitIndex < 8 * len) {
            int charIndex = bitIndex / 8;
            int charBitIndex = bitIndex % 8;
            unsigned char bit = (image[i].b & 0x1) << (7 - charBitIndex);
            text[charIndex] = (text[charIndex] & ~(1 << (7 - charBitIndex))) | bit;
            bitIndex++;
        }
    }
    text[len] = '\0';

    unsigned char calculatedHash = 0;
    for (int i = 0; i < len; i++) {
        calculatedHash = (calculatedHash + (unsigned char)text[i]) % 256;
    }

    if (calculatedHash != hash) {
        printf("Error: hash does not match\n");
        exit(1);
    }

    return text;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s input.bmp output.bmp text\n", argv[0]);
        return 1;
    }

    char* inputFilename = argv[1];
    char* outputFilename = argv[2];
    char* text = argv[3];

    // read input image
    Pixel* image;
    int width, height;
    readImage(inputFilename, &image, &width, &height);

    // add watermark
    addWatermark(image, width, height, text);

    // multiply pixels to enhance watermark visibility
    multiplyPixels(image, width, height, 2, 2, 2);

    // write output image
    writeImage(outputFilename, image, width, height);

    // extract watermark and print to console
    char* extractedText = extractWatermark(image, width, height);
    printf("Extracted watermark: %s\n", extractedText);

    free(extractedText);
    free(image);

    return 0;
}