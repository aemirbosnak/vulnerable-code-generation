//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure proper alignment
typedef struct {
    unsigned char  bfType[2];       // Bitmap file type
    unsigned int   bfSize;          // Size of the file
    unsigned short bfReserved1;     // Reserved
    unsigned short bfReserved2;     // Reserved
    unsigned int   bfOffBits;       // Offset to bitmap data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int  biSize;          // Size of this header
    int           biWidth;         // Width of the image
    int           biHeight;        // Height of the image
    unsigned short biPlanes;        // Number of color planes
    unsigned short biBitCount;      // Number of bits per pixel
    unsigned int  biCompression;    // Compression type
    unsigned int  biSizeImage;      // Image size
    int           biXPelsPerMeter;  // Pixels per meter in X
    int           biYPelsPerMeter;  // Pixels per meter in Y
    unsigned int  biClrUsed;        // Number of colors in the color palette
    unsigned int  biClrImportant;    // Important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

// Function prototypes
void embedMessage(const char *inputImage, const char *outputImage, const char *message);
void decodeMessage(const char *inputImage);

int main() {
    char inputImage[256], outputImage[256], message[256];

    printf("Enter the input BMP image file: ");
    scanf("%255s", inputImage);
    
    printf("Enter the output BMP image file: ");
    scanf("%255s", outputImage);

    printf("Enter the message to hide: ");
    scanf(" %[^\n]", message); // Read line with spaces

    embedMessage(inputImage, outputImage, message);
    decodeMessage(outputImage); // Display the message embedded in the output image

    return 0;
}

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *input = fopen(inputImage, "rb");
    if (!input) {
        perror("Failed to open input image");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(bfh), 1, input);
    fread(&bih, sizeof(bih), 1, input);

    // Check if it's a 24-bit BMP
    if (bih.biBitCount != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(input);
        return;
    }

    // Prepare output file
    FILE *output = fopen(outputImage, "wb");
    if (!output) {
        perror("Failed to open output image");
        fclose(input);
        return;
    }

    fwrite(&bfh, sizeof(bfh), 1, output);
    fwrite(&bih, sizeof(bih), 1, output);

    // Embed message length (max length is 255 characters)
    int messageLength = strlen(message) + 1; // +1 for null terminator
    fseek(output, bfh.bfOffBits, SEEK_SET);
    fwrite(&messageLength, sizeof(messageLength), 1, output); // Write length

    // Embed message
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char byte = message[i];
            unsigned char bit = (byte >> (7 - j)) & 1;

            unsigned char pixel[3];

            fread(pixel, sizeof(pixel), 1, input);
            pixel[0] = (pixel[0] & ~1) | bit; // Modify LSB of blue
            fwrite(pixel, sizeof(pixel), 1, output);
        }
    }

    // Copy remaining pixels
    unsigned char buffer[3];
    while (fread(buffer, sizeof(buffer), 1, input) == 1) {
        fwrite(buffer, sizeof(buffer), 1, output);
    }

    fclose(input);
    fclose(output);
    printf("Message embedded successfully!\n");
}

void decodeMessage(const char *inputImage) {
    FILE *input = fopen(inputImage, "rb");
    if (!input) {
        perror("Failed to open input image");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(bfh), 1, input);
    fread(&bih, sizeof(bih), 1, input);

    fseek(input, bfh.bfOffBits, SEEK_SET);
    
    int messageLength;
    fread(&messageLength, sizeof(messageLength), 1, input);

    char *message = malloc(messageLength);
    if (!message) {
        perror("Failed to allocate memory for message");
        fclose(input);
        return;
    }

    // Decode message
    for (int i = 0; i < messageLength; i++) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(pixel), 1, input);
            unsigned char bit = pixel[0] & 1; // Get LSB of blue
            byte |= (bit << (7 - j)); // Set corresponding bit
        }
        message[i] = byte;
    }

    printf("Decoded message: %s\n", message);

    free(message);
    fclose(input);
}