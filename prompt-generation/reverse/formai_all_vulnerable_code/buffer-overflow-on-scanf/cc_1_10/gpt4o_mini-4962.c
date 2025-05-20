//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;       // Magic number for file
    unsigned int size;        // Size of the file (in bytes)
    unsigned short reserved1;  // Reserved; must be zero
    unsigned short reserved2;  // Reserved; must be zero
    unsigned int offset;      // Offset to the pixel data
} BMPHeader;

typedef struct {
    unsigned int size;        // Size of this header (in bytes)
    int width;                // Width of the bitmap in pixels
    int height;               // Height of the bitmap in pixels
    unsigned short planes;     // Number of color planes being used
    unsigned short bitCount;   // Number of bits per pixel
    unsigned int compression;  // Compression method being used
    unsigned int sizeImage;    // Size of the image data in bytes
    int xPixelsPerMeter;      // Horizontal resolution of the image
    int yPixelsPerMeter;      // Vertical resolution of the image
    unsigned int colorsUsed;   // Number of colors in the palette
    unsigned int colorsImportant; // Number of important colors
} BMPInfoHeader;
#pragma pack(pop)

void hideTextInBMP(const char *imagePath, const char *message, const char *outputPath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(bmpHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, inputFile);

    if (bmpHeader.type != 0x4D42) { // BMP is 'BM' in ASCII
        printf("Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    // Begin hiding the message
    size_t messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.width * bmpInfoHeader.height * 3) / 8) {
        printf("Message is too long to hide in image.\n");
        fclose(inputFile);
        return;
    }

    // Go to pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    
    unsigned char *imageData = (unsigned char *)malloc(bmpInfoHeader.sizeImage);
    fread(imageData, 1, bmpInfoHeader.sizeImage, inputFile);
    fclose(inputFile);

    // Append a delimiter for the end of the hidden message
    strcat(message, "|");

    // Hide the message
    for (size_t i = 0; message[i] != '\0'; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            // Get the bit to hide
            unsigned char bitToHide = (message[i] >> bit) & 1;
            imageData[i * 8 + (7 - bit)] = (imageData[i * 8 + (7 - bit)] & 0xFE) | bitToHide;
        }
    }

    // Write to output file
    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        perror("Could not open output file");
        free(imageData);
        return;
    }

    fwrite(&bmpHeader, sizeof(bmpHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, outputFile);
    fwrite(imageData, 1, bmpInfoHeader.sizeImage, outputFile);

    fclose(outputFile);
    free(imageData);
    printf("Message hidden successfully!\n");
}

void revealTextInBMP(const char *imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(bmpHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, inputFile);

    fseek(inputFile, bmpHeader.offset, SEEK_SET);

    unsigned char *imageData = (unsigned char *)malloc(bmpInfoHeader.sizeImage);
    fread(imageData, 1, bmpInfoHeader.sizeImage, inputFile);
    fclose(inputFile);

    printf("Revealed message: ");
    int i = 0;
    char extractedChar;
    while (1) {
        extractedChar = 0; // Reset character
        for (int bit = 7; bit >= 0; bit--) {
            extractedChar |= ((imageData[i * 8 + (7 - bit)] & 1) << bit);
        }
        if (extractedChar == '|') { // Delimiter detected
            break;
        }
        putchar(extractedChar);
        i++;
    }
    putchar('\n');

    free(imageData);
}

int main() {
    int choice;
    char imagePath[100], message[256], outputPath[100];

    printf("Image Steganography Program\n");
    printf("1. Hide Message\n");
    printf("2. Reveal Message\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character

    switch (choice) {
        case 1:
            printf("Enter input BMP image path: ");
            fgets(imagePath, sizeof(imagePath), stdin);
            strtok(imagePath, "\n"); // Remove newline character
            printf("Enter message to hide: ");
            fgets(message, sizeof(message), stdin);
            strtok(message, "\n"); // Remove newline character
            printf("Enter output BMP image path: ");
            fgets(outputPath, sizeof(outputPath), stdin);
            strtok(outputPath, "\n"); // Remove newline character
            hideTextInBMP(imagePath, message, outputPath);
            break;

        case 2:
            printf("Enter BMP image path to reveal message: ");
            fgets(imagePath, sizeof(imagePath), stdin);
            strtok(imagePath, "\n"); // Remove newline character
            revealTextInBMP(imagePath);
            break;

        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}