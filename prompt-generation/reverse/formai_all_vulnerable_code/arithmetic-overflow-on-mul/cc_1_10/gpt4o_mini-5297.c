//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure the struct is packed to avoid padding issues

typedef struct {
    unsigned short bfType;      // Bitmap file type
    unsigned int bfSize;       // Size of the file in bytes
    unsigned short bfReserved1; // Reserved; actually should be 0
    unsigned short bfReserved2; // Reserved; actually should be 0
    unsigned int bfOffBits;     // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;          // Size of this header (40 bytes)
    int biWidth;                  // Width of the bitmap in pixels
    int biHeight;                 // Height of the bitmap in pixels
    unsigned short biPlanes;      // Number of color planes (must be 1)
    unsigned short biBitCount;     // Bits per pixel
    unsigned int biCompression;    // Type of compression
    unsigned int biSizeImage;      // Size of image data
    int biXPelsPerMeter;          // Pixels per meter in the X axis
    int biYPelsPerMeter;          // Pixels per meter in the Y axis
    unsigned int biClrUsed;       // Number of colors in the palette
    unsigned int biClrImportant;  // Important colors
} BITMAPINFOHEADER;

void encodeMessageInImage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        printf("Error opening input image file!\n");
        return;
    }

    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) {
        fclose(inputFile);
        printf("Error opening output image file!\n");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    // Read the BMP file header
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    // Read the BMP info header
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    size_t messageLength = strlen(message);
    unsigned char messageLengthWithTerminator = (unsigned char)(messageLength + 1);  // To include the null-terminator

    fputc(messageLengthWithTerminator, outputFile); // Write length of message at the beginning

    size_t pixelCount = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;

    unsigned char pixel[3]; // Assuming 24-bit BMP (3 bytes for RGB)
    size_t messageIndex = 0;

    for (size_t i = 0; i < pixelCount; i++) {
        fread(pixel, sizeof(unsigned char), 3, inputFile); // Read RGB values

        // Embed message into the least significant bits
        if (messageIndex < messageLength + 1) {
            pixel[0] = (pixel[0] & 0xFE) | ((message[messageIndex] >> 0) & 0x01);  // LSB of the first byte
            messageIndex++;
        }
        if (messageIndex < messageLength + 1) {
            pixel[1] = (pixel[1] & 0xFE) | ((message[messageIndex] >> 1) & 0x01);  // LSB of the second byte
            messageIndex++;
        }
        if (messageIndex < messageLength + 1) {
            pixel[2] = (pixel[2] & 0xFE) | ((message[messageIndex] >> 2) & 0x01);  // LSB of the third byte
            messageIndex++;
        }

        fwrite(pixel, sizeof(unsigned char), 3, outputFile); // Write modified pixel back
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Message encoded successfully in the image!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image.bmp> <output_image.bmp> <message>\n", argv[0]);
        return 1;
    }

    encodeMessageInImage(argv[1], argv[2], argv[3]);
    return 0;
}