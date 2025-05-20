//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  signature[2]; // BMP file signature
    unsigned int   fileSize;      // Size of the BMP file in bytes
    unsigned int   reserved;       // Reserved; must be zero
    unsigned int   dataOffset;     // Offset where the pixel data begins
    unsigned int   headerSize;     // Size of the header in bytes
    int            width;          // Width of the bitmap in pixels
    int            height;         // Height of the bitmap in pixels
    unsigned short planes;         // Number of color planes; must be 1
    unsigned short bitsPerPixel;   // Bits per pixel
    unsigned int   compression;     // Compression type
    unsigned int   imageSize;      // Size of the pixel data
    int            xPixelsPerMeter; // Horizontal resolution (pixels per meter)
    int            yPixelsPerMeter; // Vertical resolution (pixels per meter)
    unsigned int   colorsUsed;      // Number of colors in the color palette
    unsigned int   importantColors; // Important color count
} BMPHeader;

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Pixel;

void embedMessageInImage(const char *imagePath, const char *messagePath, const char *outputPath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        fprintf(stderr, "Couldn’t open the image file.\n");
        return;
    }
    
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, imageFile);
    
    if (header.signature[0] != 'B' || header.signature[1] != 'M') {
        fprintf(stderr, "This is not a BMP file!\n");
        fclose(imageFile);
        return;
    }
    
    unsigned long imageSize = header.width * header.height * sizeof(Pixel);
    Pixel *pixels = malloc(imageSize);
    fseek(imageFile, header.dataOffset, SEEK_SET);
    fread(pixels, sizeof(Pixel), header.width * header.height, imageFile);
    fclose(imageFile);

    FILE *msgFile = fopen(messagePath, "r");
    if (!msgFile) {
        fprintf(stderr, "Couldn’t open the message file.\n");
        free(pixels);
        return;
    }
    
    fseek(msgFile, 0, SEEK_END);
    long msgSize = ftell(msgFile);
    fseek(msgFile, 0, SEEK_SET);
    
    char *message = malloc(msgSize + 1);
    fread(message, 1, msgSize, msgFile);
    message[msgSize] = '\0';
    fclose(msgFile);
    
    strcat(message, "\0"); // Append end character
    size_t messageLength = strlen(message);

    // Check if image can hold the message
    if (imageSize < messageLength * 8) {
        fprintf(stderr, "Message too long to hide in this image.\n");
        free(pixels);
        free(message);
        return;
    }

    // Embed the message in the least significant bits
    int index = 0;
    for (size_t i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Get the current bit
            unsigned char currentBit = (message[i] >> (7 - bit)) & 0x01;
            // Modify the corresponding pixel's least significant bit
            pixels[index / 3].r = (pixels[index / 3].r & 0xFE) | currentBit;
            index++;
        }
    }
    
    // Save the modified image
    FILE *outputFile = fopen(outputPath, "wb");
    fwrite(&header, sizeof(BMPHeader), 1, outputFile);
    fseek(outputFile, header.dataOffset, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), header.width * header.height, outputFile);
    
    fclose(outputFile);
    printf("Message successfully hidden in the image!\n");

    free(pixels);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Welcome to the Curious World of Image Steganography!\n");
        printf("Usage: %s <input_image.bmp> <message_file.txt> <output_image.bmp>\n", argv[0]);
        return 1;
    }
    
    embedMessageInImage(argv[1], argv[2], argv[3]);
    
    return 0;
}