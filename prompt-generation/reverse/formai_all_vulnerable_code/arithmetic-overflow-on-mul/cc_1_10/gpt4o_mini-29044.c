//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;      // 0x4d42
    unsigned int bfSize;       // File size in bytes
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;    // Offset to start of pixel array
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;       // Header size
    int biWidth;               // Width in pixels
    int biHeight;              // Height in pixels
    unsigned short biPlanes;    // Color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;  // Compression method
    unsigned int biSizeImage;    // Image size
    int biXPelsPerMeter;        // Pixels per meter in X
    int biYPelsPerMeter;        // Pixels per meter in Y
    unsigned int biClrUsed;     // Number of colors
    unsigned int biClrImportant; // Important colors
} BITMAPINFOHEADER;

void hideMessage(const char *imagePath, const char *message) {
    FILE *imageFile = fopen(imagePath, "rb+");
    if (!imageFile) {
        printf("Error opening image file.\n");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, imageFile);

    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);

    size_t messageLength = strlen(message);
    if (messageLength > ((infoHeader.biWidth * infoHeader.biHeight * infoHeader.biBitCount / 8) - 1)) {
        printf("Message is too long to hide in this image.\n");
        fclose(imageFile);
        return;
    }

    // Hide message in the least significant bits of the pixel data
    for (size_t i = 0; i < messageLength; i++) {
        unsigned char byte = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, imageFile);
            // Set the least significant bit to the message bit
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> (7 - j)) & 1);
            fwrite(pixel, sizeof(unsigned char), 3, imageFile);
        }
    }

    // Write a delimiter (0) after the message
    unsigned char delimiter = 0;
    for (int j = 0; j < 8; j++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, imageFile);
        pixel[0] = (pixel[0] & 0xFE) | ((delimiter >> (7 - j)) & 1);
        fwrite(pixel, sizeof(unsigned char), 3, imageFile);
    }

    fclose(imageFile);
    printf("Message hidden successfully.\n");
}

void revealMessage(const char *imagePath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        printf("Error opening image file.\n");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, imageFile);

    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    unsigned char byte;
    char message[256];
    memset(message, 0, sizeof(message));
    size_t msgIndex = 0;

    while (1) {
        byte = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, imageFile);
            byte = (byte << 1) | (pixel[0] & 1);
        }
        if (byte == 0) break; // Stop at the delimiter
        message[msgIndex++] = byte;
    }

    message[msgIndex] = '\0';
    fclose(imageFile);
    printf("Revealed message: %s\n", message);
}

int main() {
    int choice;
    char imagePath[256];
    char message[256];

    while (1) {
        printf("\nMultiplayer Steganography Menu:\n");
        printf("1. Hide a message in image\n");
        printf("2. Reveal message from image\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter path to image (BMP format): ");
            scanf("%s", imagePath);
            printf("Enter your message (max 255 characters): ");
            scanf(" %[^\n]", message);
            hideMessage(imagePath, message);

        } else if (choice == 2) {
            printf("Enter path to image (BMP format): ");
            scanf("%s", imagePath);
            revealMessage(imagePath);

        } else if (choice == 3) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}