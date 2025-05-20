//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP header structure
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;
#pragma pack(pop)

void encodeMessageInBMP(const char *imagePath, const char *message, const char *outputPath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Could not open input image");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Read BMP header
    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    if (bmpHeader.bfType != 0x4D42) { // Check for 'BM'
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(imageFile);
        return;
    }

    // Calculate the total number of pixels
    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;
    int pixelCount = width * height;
    unsigned char *pixels = (unsigned char *)malloc(pixelCount * 3); // 3 bytes per pixel for RGB
    fseek(imageFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixels, 3, pixelCount, imageFile);
    fclose(imageFile);

    // Prepare to encode the message
    int messageLength = strlen(message);
    int messageBytes = messageLength + 1; // +1 for null terminator
    if (messageBytes > pixelCount) {
        fprintf(stderr, "Message is too long to fit in the image.\n");
        free(pixels);
        return;
    }

    // Encode the message into the least significant bits
    for (int i = 0; i < messageBytes; i++) {
        for (int j = 0; j < 8; j++) {
            int pixelIndex = i * 8 + j;
            if (pixelIndex < pixelCount) {
                // Get the byte value of the message
                unsigned char bit = (message[i] >> (7 - j)) & 1;
                // Alter the LSB of the pixel (R channel only for simplicity)
                pixels[pixelIndex * 3] = (pixels[pixelIndex * 3] & ~1) | bit;
            }
        }
    }

    // Output the new image
    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        perror("Could not open output image");
        free(pixels);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixels, 3, pixelCount, outputFile);

    free(pixels);
    fclose(outputFile);
    printf("Message encoded successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input BMP> <message> <output BMP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *inputImagePath = argv[1];
    const char *message = argv[2];
    const char *outputImagePath = argv[3];

    encodeMessageInBMP(inputImagePath, message, outputImagePath);
    
    return 0;
}