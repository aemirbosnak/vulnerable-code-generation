//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Align the structures
typedef struct {
    unsigned short bfType;
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BMPFILEHEADER;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BMPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

#pragma pack(pop)

void embedMessageInPixel(RGB *pixel, char bit) {
    pixel->red = (pixel->red & ~1) | (bit - '0');
}

char extractMessageFromPixel(RGB pixel) {
    return (pixel.red & 1) + '0';
}

void hideMessageInBMP(const char *bmpFilePath, const char *message) {
    FILE *bmpFile = fopen(bmpFilePath, "rb+");
    
    if (!bmpFile) {
        perror("Error opening BMP file");
        return;
    }

    BMPFILEHEADER bfHeader;
    BMPINFOHEADER biHeader;
    
    fread(&bfHeader, sizeof(BMPFILEHEADER), 1, bmpFile);
    fread(&biHeader, sizeof(BMPINFOHEADER), 1, bmpFile);

    long pixelArrayOffset = bfHeader.bfOffBits;
    fseek(bmpFile, pixelArrayOffset, SEEK_SET);

    // Prepare the message for embedding
    size_t messageLength = strlen(message);
    size_t totalBits = messageLength * 8;
    totalBits++; // To store the terminating null character

    for (size_t i = 0; i < totalBits; i++) {
        RGB pixel;
        fread(&pixel, sizeof(RGB), 1, bmpFile);
        
        // Determine the bit to embed
        char bitToEmbed = (i < messageLength * 8) ? ((message[i / 8] >> (i % 8)) & 1) + '0' : '0';
        embedMessageInPixel(&pixel, bitToEmbed);
        
        // Write the modified pixel back
        fseek(bmpFile, -sizeof(RGB), SEEK_CUR); // Move back one pixel
        fwrite(&pixel, sizeof(RGB), 1, bmpFile);
        fseek(bmpFile, sizeof(RGB), SEEK_CUR);   // Move to next pixel
    }

    fclose(bmpFile);
    printf("Message hidden in image successfully!\n");
}

void retrieveMessageFromBMP(const char *bmpFilePath) {
    FILE *bmpFile = fopen(bmpFilePath, "rb");
    
    if (!bmpFile) {
        perror("Error opening BMP file");
        return;
    }

    BMPFILEHEADER bfHeader;
    BMPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BMPFILEHEADER), 1, bmpFile);
    fread(&biHeader, sizeof(BMPINFOHEADER), 1, bmpFile);

    long pixelArrayOffset = bfHeader.bfOffBits;
    fseek(bmpFile, pixelArrayOffset, SEEK_SET);

    char message[256] = {0}; // Buffer to store retrieved message
    size_t messageLength = 0;

    while (messageLength < 256 * 8) {
        RGB pixel;
        fread(&pixel, sizeof(RGB), 1, bmpFile);

        // Extract bit from pixel
        char bit = extractMessageFromPixel(pixel);
        if (bit == '0' && messageLength % 8 == 0 && messageLength != 0) {
            break; // Stop if we encounter the null character
        }

        // Store the bits in the message buffer
        if (messageLength % 8 == 0 && messageLength > 0) {
            message[messageLength / 8] |= (bit - '0') << (messageLength % 8);
        }
        messageLength++;
    }

    printf("Retrieved Message: %s\n", message);
    fclose(bmpFile);
}

int main() {
    char message[256];
    char bmpFilePath[256];

    printf("Enter BMP file path: ");
    scanf("%s", bmpFilePath);
    
    printf("Enter message to hide: ");
    scanf(" %[^\n]", message);

    hideMessageInBMP(bmpFilePath, message);
    retrieveMessageFromBMP(bmpFilePath);

    return 0;
}