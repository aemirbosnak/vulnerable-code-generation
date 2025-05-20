//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)  // Ensures no padding for the structures

// BMP File Header structure
typedef struct {
    unsigned short type;      // Magic identifier
    unsigned int size;       // File size in bytes
    unsigned short reserved1; // Reserved; must be zero
    unsigned short reserved2; // Reserved; must be zero
    unsigned int offset;     // Offset to image data
} BMPFileHeader;

// BMP Info Header structure
typedef struct {
    unsigned int size;        // Info header size
    int width;               // Width of the image
    int height;              // Height of image
    unsigned short planes;    // Number of color planes
    unsigned short bits_per_pixel; // Bits per pixel
    unsigned int compression; // Compression type
    unsigned int imagesize;   // Image size
    int x_pixels_per_meter;   // Pixels per meter
    int y_pixels_per_meter;   // Pixels per meter
    unsigned int total_colors; // Total colors
    unsigned int important_colors; // Important colors
} BMPInfoHeader;

// Function prototypes
void hideMessageInBMP(const char* bmpFile, const char* message, const char* outputFile);
void extractMessageFromBMP(const char* bmpFile);
int getBit(char byte, int bit);
char setBit(char byte, int bit, char value);

int main(int argc, char *argv[]) {
    if (argc != 4 && argc != 3) {
        printf("Usage: %s <bmp_file> <message> <output_file> OR %s <bmp_file> (to extract message)\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 4) {
        hideMessageInBMP(argv[1], argv[2], argv[3]);
        printf("Message hidden in '%s' as '%s'.\n", argv[1], argv[3]);
    } else {
        extractMessageFromBMP(argv[1]);
    }

    return 0;
}

void hideMessageInBMP(const char* bmpFile, const char* message, const char* outputFile) {
    FILE* input = fopen(bmpFile, "rb");
    if (!input) {
        perror("Error opening BMP file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    // Read BMP headers
    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);

    // Check if the BMP is 24-bit
    if (infoHeader.bits_per_pixel != 24) {
        printf("Only supports 24-bit BMP files!\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Find the size of the message
    size_t messageLength = strlen(message);
    size_t messageBits = messageLength * 8 + 1; // +1 for null-terminator

    // Calculate the number of pixels needed to encode the message
    size_t pixelCount = (infoHeader.width * infoHeader.height);
    if (messageBits > pixelCount * 3) {
        printf("Message is too long to hide in the image.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Create and open output file
    FILE* output = fopen(outputFile, "wb");
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, output);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output);

    unsigned char* pixelData = (unsigned char*)malloc(infoHeader.imagesize);
    fseek(input, fileHeader.offset, SEEK_SET);
    fread(pixelData, 1, infoHeader.imagesize, input);

    // Hide the message in the pixel data
    size_t currentBit = 0;
    for (size_t i = 0; currentBit < messageBits; i++) {
        for (int color = 0; color < 3; color++) {
            if (currentBit < messageBits) {
                pixelData[i * 3 + color] = setBit(pixelData[i * 3 + color], 0, getBit(message[currentBit / 8], currentBit % 8));
                currentBit++;
            }
        }
    }

    fwrite(pixelData, 1, infoHeader.imagesize, output);
    fclose(input);
    fclose(output);
    free(pixelData);
}

void extractMessageFromBMP(const char* bmpFile) {
    FILE* input = fopen(bmpFile, "rb");
    if (!input) {
        perror("Error opening BMP file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);

    if (infoHeader.bits_per_pixel != 24) {
        printf("Only supports 24-bit BMP files!\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    unsigned char* pixelData = (unsigned char*)malloc(infoHeader.imagesize);
    fseek(input, fileHeader.offset, SEEK_SET);
    fread(pixelData, 1, infoHeader.imagesize, input);

    size_t currentBit = 0;
    char message[256] = {0}; // Assuming the message will not exceed 255 characters
    for (size_t i = 0; currentBit < 8 * sizeof(message); i++) {
        for (int color = 0; color < 3; color++) {
            if (currentBit < 8 * sizeof(message)) {
                message[currentBit / 8] = setBit(message[currentBit / 8], currentBit % 8, getBit(pixelData[i * 3 + color], 0));
                currentBit++;
            }
        }
    }

    // Print the extracted message
    printf("Extracted message: %s\n", message);
    fclose(input);
    free(pixelData);
}

int getBit(char byte, int bit) {
    return (byte >> bit) & 0x01;
}

char setBit(char byte, int bit, char value) {
    if (value) {
        return byte | (1 << bit);
    } else {
        return byte & ~(1 << bit);
    }
}