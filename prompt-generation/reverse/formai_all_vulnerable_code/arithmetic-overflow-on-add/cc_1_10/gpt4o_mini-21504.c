//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;      // Signature
    unsigned int bfSize;       // Size of the file
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;     // Offset to pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;        // Size of the info header
    int biWidth;                // Width of the image
    int biHeight;               // Height of the image
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;  // Compression type
    unsigned int biSizeImage;    // Image size in bytes
    int biXPelsPerMeter;         // Horizontal resolution
    int biYPelsPerMeter;         // Vertical resolution
    unsigned int biClrUsed;      // Number of colors
    unsigned int biClrImportant;  // Important colors
} BMPInfoHeader;

void embedTextInImage(char *imagePath, char *message) {
    FILE *imageFile = fopen(imagePath, "r+b");
    if (!imageFile) {
        printf("Error opening file!\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    // Check if the file is a BMP
    if (bmpHeader.bfType != 0x4D42) {
        printf("Not a BMP file!\n");
        fclose(imageFile);
        return;
    }

    // Move to the end of the file to find the pixel data
    fseek(imageFile, bmpHeader.bfOffBits, SEEK_SET);

    // Prepare message for embedding
    int messageLength = strlen(message);
    message[messageLength] = '\0'; // Null terminate

    // Embed the length of the message at the start of the pixel data
    for (int i = 0; i < messageLength; i++) {
        unsigned char pixel;
        fread(&pixel, sizeof(unsigned char), 1, imageFile);
        pixel = (pixel & 0xFE) | ((message[i] >> 7) & 0x01); // LSB
        fseek(imageFile, -1, SEEK_CUR);
        fwrite(&pixel, sizeof(unsigned char), 1, imageFile);
    }

    // Embed the message characters into the image
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 6; bit >= 0; bit--) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, imageFile);
            pixel = (pixel & 0xFE) | ((message[i] >> bit) & 0x01); // LSB
            fseek(imageFile, -1, SEEK_CUR);
            fwrite(&pixel, sizeof(unsigned char), 1, imageFile);
        }
    }

    printf("Message embedded successfully!\n");
    fclose(imageFile);
}

void extractTextFromImage(char *imagePath, int messageLength) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        printf("Error opening file!\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    // Check if the file is a BMP
    if (bmpHeader.bfType != 0x4D42) {
        printf("Not a BMP file!\n");
        fclose(imageFile);
        return;
    }

    fseek(imageFile, bmpHeader.bfOffBits, SEEK_SET);
    char *message = malloc(messageLength + 1);
    memset(message, 0, messageLength + 1);

    // Extract message bits from LSB
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 6; bit >= 0; bit--) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, imageFile);
            message[i] |= ((pixel & 0x01) << bit); // Extract LSB
        }
    }

    message[messageLength] = '\0';
    printf("Extracted Message: %s\n", message);
    free(message);
    fclose(imageFile);
}

int main() {
    char choice;
    char imagePath[256];
    char message[256];

    printf("Welcome to the Curious BMP Steganography Program!\n");
    printf("Choose an option:\n");
    printf("1. Embed a message\n");
    printf("2. Extract a message\n");
    printf("Your choice: ");
    scanf(" %c", &choice);
    getchar(); // To consume the newline

    printf("Enter the BMP image path: ");
    fgets(imagePath, sizeof(imagePath), stdin);
    imagePath[strcspn(imagePath, "\n")] = 0; // Removing trailing newline

    switch (choice) {
        case '1':
            printf("Enter the message to embed: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Removing trailing newline
            embedTextInImage(imagePath, message);
            break;
        case '2':
            printf("Enter the message length: ");
            int msgLength;
            scanf("%d", &msgLength);
            extractTextFromImage(imagePath, msgLength);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}