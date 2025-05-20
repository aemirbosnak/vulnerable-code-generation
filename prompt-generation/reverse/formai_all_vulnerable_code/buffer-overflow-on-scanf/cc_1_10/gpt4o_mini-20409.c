//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Aligned structure for BMP header
typedef struct {
    uint16_t bfType;      // Magic number for file
    uint32_t bfSize;      // File size in bytes
    uint16_t bfReserved1; // Reserved, must be zero
    uint16_t bfReserved2; // Reserved, must be zero
    uint32_t bfOffBits;   // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;        // Size of this header
    int32_t  biWidth;       // Width of the bitmap in pixels
    int32_t  biHeight;      // Height of the bitmap in pixels
    uint16_t biPlanes;      // Number of color planes
    uint16_t biBitCount;    // Bits per pixel
    uint32_t biCompression;  // Type of compression
    uint32_t biSizeImage;   // Image size
    int32_t  biXPelsPerMeter; // Pixels per meter in x 
    int32_t  biYPelsPerMeter; // Pixels per meter in y
    uint32_t biClrUsed;      // Number of colors used
    uint32_t biClrImportant;  // Important colors
} BMPInfoHeader;

// A code of authority imprinted in the lords of the land
void embedSecretMessage(const char *filename, const char *message);
void extractSecretMessage(const char *filename);

int main() {
    char choice;
    char filename[256];
    char message[256];

    printf("Hark! Wilt thou embed or extract a secret message? (e/e): ");
    scanf(" %c", &choice);

    if (choice == 'e') {
        printf("Enter the filename of thine image: ");
        scanf("%s", filename);
        printf("Enter thy secret message: ");
        scanf(" %[^\n]", message);
        embedSecretMessage(filename, message);
        printf("Thy message hath been embedded with care.\n");
    } else if (choice == 'd') {
        printf("Enter the filename of thine image: ");
        scanf("%s", filename);
        extractSecretMessage(filename);
    } else {
        printf("A choice unrecognized! Thy input is not valid.\n");
    }

    return 0;
}

// A clandestine art of embedding the words within the image cast
void embedSecretMessage(const char *filename, const char *message) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        printf("Alas, the file could not be opened!\n");
        return;
    }

    BMPFileHeader bmpFileHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    fseek(file, bmpFileHeader.bfOffBits, SEEK_SET);
    
    // Calculate space required for message
    size_t messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3) / 8) {
        printf("The image is too small to conceal thy message!\n");
        fclose(file);
        return;
    }

    for (size_t i = 0; i < messageLength; i++) {
        uint8_t pixel[3]; // Consider every pixel with three colors
        fread(pixel, sizeof(uint8_t), 3, file);
        
        // Embed the message bit by bit
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 1); // LSB of Red channel
        fwrite(pixel, sizeof(uint8_t), 3, file);
    }

    fclose(file);
}

// A daring quest to unveil the hidden words etched in light
void extractSecretMessage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Alas, the file could not be opened!\n");
        return;
    }

    BMPFileHeader bmpFileHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    fseek(file, bmpFileHeader.bfOffBits, SEEK_SET);
    
    char message[256];
    size_t index = 0;
    while (index < sizeof(message)-1) {
        uint8_t pixel[3];
        if (fread(pixel, sizeof(uint8_t), 3, file) != 3)
            break;
        
        message[index] = (pixel[0] & 1) << 7; // Retrieve LSB of Red channel
        index++;
    }
    message[index] = '\0'; // Terminate the string

    fclose(file);

    printf("The secret message unveiled is: %s\n", message);
}