//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensures no padding is added
typedef struct {
    unsigned short bfType;      // Bitmap file type
    unsigned int bfSize;        // Size of the file
    unsigned short bfReserved1; // Reserved, must be zero
    unsigned short bfReserved2; // Reserved, must be zero
    unsigned int bfOffBits;      // Offset to bitmap data
} BMPFileHeader;

typedef struct {
    unsigned int biSize;        // Size of this header
    int biWidth;                // Width of bitmap in pixels
    int biHeight;               // Height of bitmap in pixels
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;  // Compression type
    unsigned int biSizeImage;    // Size of image data
    int biXPelsPerMeter;         // Horizontal resolution
    int biYPelsPerMeter;         // Vertical resolution
    unsigned int biClrUsed;      // Number of colors
    unsigned int biClrImportant;  // Important colors
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

#pragma pack(pop)

void encodeMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inFile = fopen(inputImage, "rb");
    FILE *outFile = fopen(outputImage, "wb");
    if (!inFile || !outFile) {
        printf("Error: Unable to open file.\n");
        return;
    }

    BMPFileHeader bfh;
    BMPInfoHeader bih;
    fread(&bfh, sizeof(bfh), 1, inFile);
    fread(&bih, sizeof(bih), 1, inFile);

    if (bfh.bfType != 0x4D42) {  // Check for valid BMP file
        printf("Error: Not a valid BMP file.\n");
        fclose(inFile);
        fclose(outFile);
        return;
    }

    fwrite(&bfh, sizeof(bfh), 1, outFile);
    fwrite(&bih, sizeof(bih), 1, outFile);
    
    RGB pixel;
    size_t messageLen = strlen(message);
    size_t messageIndex = 0;
    size_t messageBitIndex = 0;

    for (int i = 0; i < bih.biHeight; ++i) {
        for (int j = 0; j < bih.biWidth; ++j) {
            fread(&pixel, sizeof(RGB), 1, inFile);
            
            // If there's still a message to encode
            if (messageIndex < messageLen) {
                // Get the current bit to hide
                unsigned char bitToHide = (message[messageIndex] >> (7 - messageBitIndex)) & 1;
                
                // Modify the blue channel's LSB
                pixel.blue = (pixel.blue & 0xFE) | bitToHide;

                // Move to the next bit
                messageBitIndex++;
                if (messageBitIndex >= 8) {
                    messageBitIndex = 0;
                    messageIndex++;
                }
            }

            fwrite(&pixel, sizeof(RGB), 1, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);
    printf("Message encoded successfully!\n");
}

void decodeMessage(const char *imageFile) {
    FILE *inFile = fopen(imageFile, "rb");
    if (!inFile) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    BMPFileHeader bfh;
    BMPInfoHeader bih;
    fread(&bfh, sizeof(bfh), 1, inFile);
    fread(&bih, sizeof(bih), 1, inFile);

    if (bfh.bfType != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(inFile);
        return;
    }

    RGB pixel;
    char message[256] = {0};
    size_t messageIndex = 0;
    size_t messageBitIndex = 0;

    for (int i = 0; i < bih.biHeight; ++i) {
        for (int j = 0; j < bih.biWidth; ++j) {
            fread(&pixel, sizeof(RGB), 1, inFile);
            // Read the LSB of blue channel
            unsigned char bit = pixel.blue & 1;

            // Set the current bit in the message
            message[messageIndex] |= (bit << (7 - messageBitIndex));
            messageBitIndex++;

            if (messageBitIndex >= 8) {
                messageBitIndex = 0;
                if (message[messageIndex] == '\0') {
                    // End of message detected
                    goto end;
                }
                messageIndex++;
            }
        }
    }
    
end:
    fclose(inFile);
    printf("Decoded message: %s\n", message);
}

int main() {
    int choice;
    char inputImage[256], outputImage[256], message[256];

    printf("Welcome to the Imaginary Image Steganography Program!\n");
    
    // Allow the user to encode or decode a message
    do {
        printf("What would you like to do?\n");
        printf("1. Encode a message\n");
        printf("2. Decode a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter input BMP image file name: ");
                fgets(inputImage, 256, stdin);
                strtok(inputImage, "\n"); // Remove newline

                printf("Enter output BMP image file name: ");
                fgets(outputImage, 256, stdin);
                strtok(outputImage, "\n"); // Remove newline

                printf("Enter the message to encode: ");
                fgets(message, 256, stdin);
                strtok(message, "\n"); // Remove newline

                encodeMessage(inputImage, outputImage, message);
                break;

            case 2:
                printf("Enter BMP image file name to decode: ");
                fgets(inputImage, 256, stdin);
                strtok(inputImage, "\n"); // Remove newline

                decodeMessage(inputImage);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}