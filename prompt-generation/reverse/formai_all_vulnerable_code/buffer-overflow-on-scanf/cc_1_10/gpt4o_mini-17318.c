//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header size
#define BMP_HEADER_SIZE 54

// Function to embed a message in the BMP file
void embedMessageInBMP(const char* bmpFilePath, const char* message) {
    FILE* bmpFile = fopen(bmpFilePath, "rb+");
    if (!bmpFile) {
        printf("Error opening the BMP file.\n");
        return;
    }

    // Move to the end of the message to find out its length
    size_t messageLength = strlen(message);
    size_t paddedLength = messageLength + 1; // +1 for the null terminator

    // Read BMP header to find the pixel data start
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, bmpFile);

    // Calculating the start position for pixel data
    long pixelStart = *(int*)&header[10];
    fseek(bmpFile, pixelStart, SEEK_SET);

    unsigned char ch;
    for (size_t i = 0; i < paddedLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Read a byte from the image
            fread(&ch, sizeof(unsigned char), 1, bmpFile);

            // Clear the least significant bit and replace it with the next bit of the message
            if (i < messageLength) {
                ch = (ch & 0xFE) | ((message[i] >> (7 - bit)) & 0x01);
            }

            // Write the modified byte back
            fseek(bmpFile, -1, SEEK_CUR);
            fwrite(&ch, sizeof(unsigned char), 1, bmpFile);
        }
    }

    // Close the BMP file
    fclose(bmpFile);
    printf("Message embedded successfully!\n");
}

// Function to extract the hidden message from the BMP file
void extractMessageFromBMP(const char* bmpFilePath) {
    FILE* bmpFile = fopen(bmpFilePath, "rb");
    if (!bmpFile) {
        printf("Error opening the BMP file.\n");
        return;
    }

    // Read BMP header to find the pixel data start
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, bmpFile);

    // Calculating the start position for pixel data
    long pixelStart = *(int*)&header[10];
    fseek(bmpFile, pixelStart, SEEK_SET);

    unsigned char ch;
    char message[256];
    int index = 0;

    // Reading the least significant bits to extract the message
    while (index < sizeof(message) - 1) {
        unsigned char byte = 0;
        for (int bit = 0; bit < 8; bit++) {
            fread(&ch, sizeof(unsigned char), 1, bmpFile);
            byte = (byte << 1) | (ch & 0x01);
        }
        
        if (byte == 0) {
            break; // Null terminator found, end of message
        }
        
        message[index++] = byte; // Store the character
    }
    message[index] = '\0'; // Null-terminate the message

    // Close the BMP file
    fclose(bmpFile);
    
    // Print the extracted message
    printf("Extracted Message: %s\n", message);
}

// Main Function
int main() {
    int choice;
    char bmpFilePath[100];
    char message[256];

    printf("Image Steganography Tool\n");
    printf("1. Embed Message\n");
    printf("2. Extract Message\n");
    printf("Choose an option (1/2): ");
    scanf("%d", &choice);
    printf("Enter the BMP file path: ");
    scanf("%s", bmpFilePath);

    switch (choice) {
        case 1:
            printf("Enter message to embed: ");
            scanf(" %[^\n]s", message); // Read a full line including spaces
            embedMessageInBMP(bmpFilePath, message);
            break;
        case 2:
            extractMessageFromBMP(bmpFilePath);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}