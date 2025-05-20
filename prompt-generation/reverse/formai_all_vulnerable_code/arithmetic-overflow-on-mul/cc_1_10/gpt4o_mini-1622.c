//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: curious
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
} BMPFileHeader;

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
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;
#pragma pack(pop)

// Function to read the BMP file
void readBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, Pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    // Allocate memory for pixels
    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    *pixels = malloc(sizeof(Pixel) * width * height);
    
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(Pixel), width * height, file);
    
    fclose(file);
}

// Function to write the modified BMP file
void writeBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, Pixel *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), infoHeader->biWidth * infoHeader->biHeight, file);
    
    fclose(file);
}

// Function to embed a message into the image
void embedMessage(Pixel *pixels, const char *message, int size) {
    int messageBitIndex = 0;
    for (int i = 0; i < size; i++) {
        char ch = message[i];
        for (int j = 0; j < 8; j++) {
            int pixelIndex = messageBitIndex / 3;  // Each pixel has 3 components (RGB)
            int colorIndex = messageBitIndex % 3;  // 0 = Blue, 1 = Green, 2 = Red

            // Getting the bit to embed
            unsigned char bit = (ch >> (7 - j)) & 1;

            // Modifying the least significant bit
            if (bit == 1) {
                pixels[pixelIndex].red |= 1;  // Set the LSB of Red component
            } else {
                pixels[pixelIndex].red &= 0xFE;  // Clear the LSB of Red component
            }

            messageBitIndex++;
        }
    }
}

// Function to extract the message from the image
void extractMessage(Pixel *pixels, char *message, int size) {
    for (int i = 0; i < size; i++) {
        char ch = 0;
        for (int j = 0; j < 8; j++) {
            int pixelIndex = (i * 8 + j) / 3;
            int colorIndex = (i * 8 + j) % 3;

            // Getting the least significant bit
            unsigned char bit = (pixels[pixelIndex].red & 1);

            // Building the character
            ch |= (bit << (7 - j));
        }
        message[i] = ch;  // Set the extracted character
    }
}

// Main function
int main() {
    const char *inputFileName = "input.bmp";   // Change the input BMP file name as needed
    const char *outputFileName = "output.bmp"; // Output file name
    const char *secretMessage = "Hello!";       // Secret message to embed

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    Pixel *pixels;

    readBMP(inputFileName, &fileHeader, &infoHeader, &pixels);

    // Embed the secret message
    embedMessage(pixels, secretMessage, strlen(secretMessage));

    // Write the modified image to new file
    writeBMP(outputFileName, &fileHeader, &infoHeader, pixels);

    // Ready to extract message
    char extractedMessage[100] = {0}; // Assume the message won't be longer than 100 characters
    extractMessage(pixels, extractedMessage, strlen(secretMessage));
    printf("Extracted Message: %s\n", extractedMessage);

    // Clean up
    free(pixels);
    return 0;
}