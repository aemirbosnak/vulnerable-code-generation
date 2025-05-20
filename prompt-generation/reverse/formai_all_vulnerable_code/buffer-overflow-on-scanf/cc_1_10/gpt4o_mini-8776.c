//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

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
} DIBHeader;
#pragma pack(pop)

void encodeMessage(const char *message, const char *inputImage, const char *outputImage) {
    FILE *in = fopen(inputImage, "rb");
    FILE *out = fopen(outputImage, "wb");
    if (!in || !out) {
        perror("File opening failed");
        return;
    }
    
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&dibHeader, sizeof(DIBHeader), 1, in);
    
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, out);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, out);
    
    fseek(in, bmpHeader.bfOffBits, SEEK_SET);
    fseek(out, bmpHeader.bfOffBits, SEEK_SET);

    int messageLength = strlen(message);
    int bitIndex = 0;

    for (int i = 0; i < dibHeader.biWidth * dibHeader.biHeight * 3; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, in);

        // Modify the least significant bit of the blue channel
        if (bitIndex < messageLength * 8) {
            pixel[0] = (pixel[0] & 0xFE) | ((message[bitIndex / 8] >> (7 - (bitIndex % 8))) & 1);
            bitIndex++;
        }
        
        fwrite(pixel, sizeof(unsigned char), 3, out);
    }

    fclose(in);
    fclose(out);
    printf("Message encoded successfully!\n");
}

void decodeMessage(const char *inputImage) {
    FILE *in = fopen(inputImage, "rb");
    if (!in) {
        perror("File opening failed");
        return;
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&dibHeader, sizeof(DIBHeader), 1, in);
    
    fseek(in, bmpHeader.bfOffBits, SEEK_SET);

    char message[256] = {0};
    int bitIndex = 0;

    for (int i = 0; i < dibHeader.biWidth * dibHeader.biHeight * 3; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, in);

        if (bitIndex < 256 * 8) {
            message[bitIndex / 8] |= (pixel[0] & 1) << (7 - (bitIndex % 8));
            bitIndex++;
        }
    }

    printf("Decoded message: %s\n", message);
    fclose(in);
}

int main() {
    int choice;
    char message[256];
    char inputImage[100], outputImage[100];

    printf("Welcome to Multiplayer Image Steganography!\n");
    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Hide a message in an image\n");
        printf("2. Retrieve a hidden message from an image\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the message to hide: ");
            getchar(); // consume newline
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // remove newline character
            printf("Enter input image filename (BMP): ");
            scanf("%s", inputImage);
            printf("Enter output image filename (BMP): ");
            scanf("%s", outputImage);
            encodeMessage(message, inputImage, outputImage);
            break;

        case 2:
            printf("Enter the image filename (BMP) to retrieve a message: ");
            scanf("%s", inputImage);
            decodeMessage(inputImage);
            break;

        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}