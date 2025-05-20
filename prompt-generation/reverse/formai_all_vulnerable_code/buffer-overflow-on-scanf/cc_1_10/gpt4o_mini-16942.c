//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure that the structure is packed
typedef struct {
    unsigned short bfType;      // The file type; must be "BM"
    unsigned int bfSize;        // The size of the file in bytes
    unsigned short bfReserved1; // Reserved; must be 0
    unsigned short bfReserved2; // Reserved; must be 0
    unsigned int bfOffBits;     // Offset to start of Pixel Data
} BMPFileHeader;

typedef struct {
    unsigned int biSize;          // Size of this header
    int biWidth;                  // Width of the bitmap in pixels
    int biHeight;                 // Height of the bitmap in pixels
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Number of bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of the image data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color palette
    unsigned int biClrImportant;   // Number of important colors
} BMPInfoHeader;

#pragma pack(pop)

void hideMessage(const char *bmpFile, const char *message) {
    FILE *file = fopen(bmpFile, "rb+");
    if (!file) {
        printf("Error: Could not open file %s\n", bmpFile);
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Check if it's a BMP file
    if (fileHeader.bfType != 'MB') {
        printf("Error: Not a BMP file!\n");
        fclose(file);
        return;
    }

    // Move to the pixel data start
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    
    // Calculate the max space for the message (only the LSB of pixels)
    int messageLength = strlen(message);
    int pixelCount = infoHeader.biWidth * infoHeader.biHeight;

    if (messageLength * 8 > pixelCount) {
        printf("Error: Message too long for this image!\n");
        fclose(file);
        return;
    }

    // Write the message in the least significant bit of pixels
    for (int i = 0; i < messageLength; ++i) {
        unsigned char byte = message[i];
        for (int j = 0; j < 8; ++j) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);
            // Change the LSB
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> (7 - j)) & 0x01);
            fseek(file, -3, SEEK_CUR);
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);
    printf("Message hidden successfully!\n");
}

void revealMessage(const char *bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", bmpFile);
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    char message[256] = {0}; // To hold the extracted message
    int index = 0;

    for (int i = 0; index < 256; ++i) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, file);
        // Read the LSB
        message[index / 8] |= ((pixel[0] & 0x01) << (7 - (index % 8)));
        index++;
        if (message[index / 8] == '\0' && index % 8 == 0) {
            break; // Stop if we've reached the end of the message
        }
    }

    fclose(file);
    printf("Revealed message: %s\n", message);
}

int main() {
    int choice;
    char bmpFile[100];
    char message[256];

    printf("Welcome to the BMP Image Steganography Program! 🎉\n");
    printf("1. Hide a message in an image\n");
    printf("2. Reveal a message from an image\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); // To consume the leftover newline character

    switch (choice) {
        case 1:
            printf("Enter the BMP file name: ");
            fgets(bmpFile, 100, stdin);
            bmpFile[strcspn(bmpFile, "\n")] = 0; // Remove newline
            printf("Enter the message to hide: ");
            fgets(message, 256, stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline
            hideMessage(bmpFile, message);
            break;

        case 2:
            printf("Enter the BMP file name: ");
            fgets(bmpFile, 100, stdin);
            bmpFile[strcspn(bmpFile, "\n")] = 0; // Remove newline
            revealMessage(bmpFile);
            break;

        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            break;
    }

    return 0;
}