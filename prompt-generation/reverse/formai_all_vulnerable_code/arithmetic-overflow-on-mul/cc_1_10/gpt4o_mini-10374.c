//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE unsigned char
#define MAX_LEN 256

// Structure to hold RGB values of a pixel
typedef struct {
    BYTE r;
    BYTE g;
    BYTE b;
} Pixel;

// Function prototypes
void embedMessage(const char *inputImage, const char *outputImage, const char *message);
void decodeMessage(const char *inputImage);
void writeBMP(const char *filename, Pixel *pixels, int width, int height);
void readBMP(const char *filename, Pixel **pixels, int *width, int *height);
void encodeCharToLSB(BYTE *byte, char charToEncode);
char decodeCharFromLSB(BYTE byte);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }
    embedMessage(argv[1], argv[2], argv[3]);
    decodeMessage(argv[2]);
    return 0;
}

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    Pixel *pixels;
    int width, height;
    readBMP(inputImage, &pixels, &width, &height);

    int messageLength = strlen(message);
    int totalPixels = width * height;
    
    if (messageLength * 8 > totalPixels) {
        printf("Message is too long to embed in this image!\n");
        free(pixels);
        return;
    }

    for (int i = 0; i < messageLength; i++) {
        encodeCharToLSB((BYTE *)&pixels[i].r, message[i]);
    }

    writeBMP(outputImage, pixels, width, height);
    free(pixels);
    printf("Message embedded successfully!\n");
}

void decodeMessage(const char *inputImage) {
    Pixel *pixels;
    int width, height;
    readBMP(inputImage, &pixels, &width, &height);

    char message[MAX_LEN];
    int i;
    for (i = 0; i < MAX_LEN - 1; i++) {
        message[i] = decodeCharFromLSB((BYTE)pixels[i].r);
        if (message[i] == '\0') {
            break;
        }
    }
    message[i] = '\0';

    printf("Decoded message: %s\n", message);
    free(pixels);
}

void writeBMP(const char *filename, Pixel *pixels, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // BMP file header
    BYTE header[54] = {
        0x42, 0x4D,       // Signature
        0, 0, 0, 0,       // File size (to be filled)
        0, 0,             // Reserved1
        0, 0,             // Reserved2
        54, 0, 0, 0,      // Offset to pixel data
        40, 0, 0, 0,      // Info header size
        0, 0, 0, 0,       // Width (to be filled)
        0, 0, 0, 0,       // Height (to be filled)
        1, 0,             // Planes
        24, 0,            // Bits per pixel
        0, 0, 0, 0,       // Compression
        0, 0, 0, 0,       // Image size (can be 0 for uncompressed)
        0, 0, 0, 0,       // X pixels per meter
        0, 0, 0, 0,       // Y pixels per meter
        0, 0, 0, 0,       // Colors in color table
        0, 0, 0, 0        // Important color count
    };

    int filesize = 54 + (width * height * 3);
    header[2] = (BYTE)(filesize);
    header[3] = (BYTE)(filesize >> 8);
    header[4] = (BYTE)(filesize >> 16);
    header[5] = (BYTE)(filesize >> 24);
    header[18] = (BYTE)(width);
    header[19] = (BYTE)(width >> 8);
    header[20] = (BYTE)(width >> 16);
    header[21] = (BYTE)(width >> 24);
    header[22] = (BYTE)(height);
    header[23] = (BYTE)(height >> 8);
    header[24] = (BYTE)(height >> 16);
    header[25] = (BYTE)(height >> 24);
    
    fwrite(header, sizeof(BYTE), 54, fp);
    
    for (int i = 0; i < width * height; i++) {
        fwrite(&pixels[i].b, sizeof(BYTE), 1, fp);
        fwrite(&pixels[i].g, sizeof(BYTE), 1, fp);
        fwrite(&pixels[i].r, sizeof(BYTE), 1, fp);
    }

    fclose(fp);
}

void readBMP(const char *filename, Pixel **pixels, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    BYTE header[54];
    fread(header, sizeof(BYTE), 54, fp);

    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int size = (*width) * (*height);
    *pixels = (Pixel *)malloc(size * sizeof(Pixel));

    for (int i = 0; i < size; i++) {
        fread(&(*pixels)[i].b, sizeof(BYTE), 1, fp);
        fread(&(*pixels)[i].g, sizeof(BYTE), 1, fp);
        fread(&(*pixels)[i].r, sizeof(BYTE), 1, fp);
    }

    fclose(fp);
}

void encodeCharToLSB(BYTE *byte, char charToEncode) {
    *byte = (*byte & 0xFE) | (charToEncode & 0x01);
}

char decodeCharFromLSB(BYTE byte) {
    return (char)(byte & 0x01);
}