//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header and info header structures
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function prototypes
void hideMessageInBMP(const char *bmpFilename, const char *messageFilename);
void extractMessageFromBMP(const char *bmpFilename, char *outputMessage, int maxLength);
unsigned char setLSB(unsigned char byte, unsigned char bit);
unsigned char getLSB(unsigned char byte);

int main() {
    const char *bmpFile = "input.bmp";
    const char *messageFile = "message.txt";
    
    // Hide a message in the BMP file
    hideMessageInBMP(bmpFile, messageFile);
    
    // Prepare to extract the message
    char outputMessage[256]; // Assuming the hidden message won't exceed 255 characters
    extractMessageFromBMP(bmpFile, outputMessage, sizeof(outputMessage));
    
    printf("Extracted Message: %s\n", outputMessage);
    
    return 0;
}

void hideMessageInBMP(const char *bmpFilename, const char *messageFilename) {
    FILE *bmpFile = fopen(bmpFilename, "rb+");
    FILE *messageFile = fopen(messageFilename, "r");
    
    if (bmpFile == NULL || messageFile == NULL) {
        fprintf(stderr, "Error opening files!\n");
        exit(1);
    }
    
    // Read and check the bitmap header
    BITMAPFILEHEADER bmpHeader;
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    
    if (bmpHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file!\n");
        fclose(bmpFile);
        fclose(messageFile);
        exit(1);
    }

    // Read the message to hide
    char message[255];
    fgets(message, sizeof(message), messageFile);
    size_t messageLength = strlen(message);
    if (message[messageLength - 1] == '\n') message[messageLength - 1] = '\0'; // Remove newline if present

    // Calculate where to start hiding the message
    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    
    // Ensure the message fits in the image
    if (messageLength * 8 > bmpHeader.bfSize - bmpHeader.bfOffBits) {
        fprintf(stderr, "Message too long to hide in this BMP file!\n");
        fclose(bmpFile);
        fclose(messageFile);
        exit(1);
    }

    // Encode message length at the start before pixels
    unsigned char messageLengthChar = (unsigned char)(messageLength);
    fwrite(&messageLengthChar, sizeof(unsigned char), 1, bmpFile);
    
    // Hide each character in the least significant bits of the pixels
    for (size_t i = 0; i < messageLength; i++) {
        unsigned char currentChar = message[i];
        
        for (int j = 0; j < 8; j++) {
            // Read a pixel
            unsigned char pixel[3]; // Assuming 24-bit (3 bytes - RGB)
            fread(pixel, sizeof(unsigned char), 3, bmpFile);

            // Set LSB of the blue component to the current bit of the character
            pixel[0] = setLSB(pixel[0], (currentChar >> (7 - j)) & 1);
            
            // Write the modified pixel back
            fseek(bmpFile, -3, SEEK_CUR);
            fwrite(pixel, sizeof(unsigned char), 3, bmpFile);
        }
    }

    fclose(bmpFile);
    fclose(messageFile);
}

void extractMessageFromBMP(const char *bmpFilename, char *outputMessage, int maxLength) {
    FILE *bmpFile = fopen(bmpFilename, "rb");
    if (bmpFile == NULL) {
        fprintf(stderr, "Error opening BMP file for reading!\n");
        exit(1);
    }

    // Read and check the bitmap header
    BITMAPFILEHEADER bmpHeader;
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);

    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    
    // Read the message length
    unsigned char messageLengthChar;
    fread(&messageLengthChar, sizeof(unsigned char), 1, bmpFile);
    size_t messageLength = (size_t)messageLengthChar;

    // Extract each character from pixels
    for (size_t i = 0; i < messageLength; i++) {
        unsigned char currentChar = 0;
        
        for (int j = 0; j < 8; j++) {
            // Read a pixel
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, bmpFile);
            
            // Get the LSB of the blue component
            currentChar |= (getLSB(pixel[0]) << (7 - j));
        }
        
        outputMessage[i] = currentChar; // Store the current character in the output
    }
    outputMessage[messageLength] = '\0'; // Null-terminate the string
    
    fclose(bmpFile);
}

unsigned char setLSB(unsigned char byte, unsigned char bit) {
    return (byte & 0xFE) | (bit & 0x01);
}

unsigned char getLSB(unsigned char byte) {
    return byte & 0x01;
}