//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensures the structures are packed tightly
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

typedef struct {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
} RGB;

#pragma pack(pop)

void encodeMessage(const char *message, const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Unable to open input file");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Unable to open output file");
        fclose(inputFile);
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    RGB *pixelData = (RGB*) malloc(bmpInfoHeader.biSizeImage);
    fread(pixelData, bmpInfoHeader.biSizeImage, 1, inputFile);

    int messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.biSizeImage / 8)) {
        printf("Message too long to be encoded in this image.\n");
        free(pixelData);
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Append a delimiter to the message
    unsigned char delimiter = '\0';
    char *fullMessage = (char*) malloc(messageLength + 1);
    strcpy(fullMessage, message);
    fullMessage[messageLength] = delimiter;

    for (int i = 0; i < messageLength + 1; i++) {
        // Use least significant bit of each pixel to represent the message
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = (i * 8 + bit);
            if (pixelIndex < bmpInfoHeader.biSizeImage / sizeof(RGB)) {
                if (fullMessage[i] & (1 << bit)) {
                    pixelData[pixelIndex].rgbRed |= 1; // Set LSB of Red channel
                } else {
                    pixelData[pixelIndex].rgbRed &= ~1; // Clear LSB of Red channel
                }
            }
        }
    }

    fwrite(pixelData, bmpInfoHeader.biSizeImage, 1, outputFile);
    
    free(fullMessage);
    free(pixelData);
    fclose(inputFile);
    fclose(outputFile);

    printf("Message encoded successfully.\n");
}

void decodeMessage(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Unable to open input file");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    RGB *pixelData = (RGB*) malloc(bmpInfoHeader.biSizeImage);
    fread(pixelData, bmpInfoHeader.biSizeImage, 1, inputFile);

    char message[1024] = {0}; // Store the message here
    int messageLength = 0;

    for (int i = 0; messageLength < sizeof(message) - 1; i++) {
        // Read LSB from the red channel of each pixel to recover the message
        if (i < bmpInfoHeader.biSizeImage / sizeof(RGB)) {
            unsigned char bit = (pixelData[i].rgbRed & 1); // Get the LSB
            message[messageLength / 8] |= (bit << (messageLength % 8));
            messageLength++;

            // Check for delimiter
            if (message[messageLength / 8 - 1] == '\0') {
                break;
            }
        }
    }

    printf("Decoded message: %s\n", message);

    free(pixelData);
    fclose(inputFile);
}

int main() {
    int choice;
    char inputFile[100], outputFile[100], message[1024];

    printf("Choose operation:\n1. Encode Message\n2. Decode Message\n");
    scanf("%d", &choice);
    getchar(); // consume the newline after the number

    if (choice == 1) {
        printf("Enter input BMP file name: ");
        fgets(inputFile, sizeof(inputFile), stdin);
        strtok(inputFile, "\n"); // Remove newline character
        printf("Enter message to encode: ");
        fgets(message, sizeof(message), stdin);
        strtok(message, "\n"); // Remove newline character
        printf("Enter output BMP file name: ");
        fgets(outputFile, sizeof(outputFile), stdin);
        strtok(outputFile, "\n"); // Remove newline character
        encodeMessage(message, inputFile, outputFile);
    } else if (choice == 2) {
        printf("Enter input BMP file name: ");
        fgets(inputFile, sizeof(inputFile), stdin);
        strtok(inputFile, "\n"); // Remove newline character
        decodeMessage(inputFile);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}