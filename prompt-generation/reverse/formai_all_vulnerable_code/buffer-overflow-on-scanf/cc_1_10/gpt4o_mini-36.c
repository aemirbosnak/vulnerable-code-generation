//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;       // Magic number for BMP files
    uint32_t bfSize;       // Size of the file
    uint16_t bfReserved1;  // Reserved, must be zero
    uint16_t bfReserved2;  // Reserved, must be zero
    uint32_t bfOffBits;    // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header (in bytes)
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression method
    uint32_t biSizeImage;     // Size of the image data
    int32_t  biXPelsPerMeter;   // Horizontal resolution (pixels per meter)
    int32_t  biYPelsPerMeter;   // Vertical resolution (pixels per meter)
    uint32_t biClrUsed;        // Number of colors used
    uint32_t biClrImportant;   // Number of important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void embedMessage(const char* filename, const char* message) {
    FILE *bmpFile = fopen(filename, "rb+");
    if (!bmpFile) {
        printf("File could not be opened.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    fseek(bmpFile, bfh.bfOffBits, SEEK_SET);

    size_t messageLength = strlen(message);
    for (size_t i = 0; i < messageLength; i++) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, bmpFile); 

        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 5) & 0x01);

        fseek(bmpFile, -3, SEEK_CUR);
        fwrite(pixel, sizeof(uint8_t), 3, bmpFile);
    }

    fseek(bmpFile, SEEK_END, 0);
    fwrite("\0", sizeof(uint8_t), 1, bmpFile); // Add null terminator

    fclose(bmpFile);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char* filename) {
    FILE *bmpFile = fopen(filename, "rb");
    if (!bmpFile) {
        printf("File could not be opened.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    fseek(bmpFile, bfh.bfOffBits, SEEK_SET);
    
    char message[256] = {0};
    size_t messageIndex = 0;

    while (1) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, bmpFile);
        
        if(feof(bmpFile)) break;

        char character = 0;
        character |= (pixel[0] & 0x01) << 7;
        character |= (pixel[1] & 0x01) << 6;
        character |= (pixel[2] & 0x01) << 5;

        if (character == '\0') break; // Stop when null terminator encountered

        message[messageIndex++] = character;
    }

    fclose(bmpFile);
    printf("Extracted message: %s\n", message);
}

int main() {
    int choice;
    char filename[100];
    char message[256];

    printf("Image Steganography Tool\n");
    printf("1. Embed message\n");
    printf("2. Extract message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the filename (e.g., image.bmp): ");
    scanf("%s", filename);

    switch (choice) {
        case 1:
            printf("Enter the message to embed: ");
            scanf(" %[^\n]", message);
            embedMessage(filename, message);
            break;

        case 2:
            extractMessage(filename);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}