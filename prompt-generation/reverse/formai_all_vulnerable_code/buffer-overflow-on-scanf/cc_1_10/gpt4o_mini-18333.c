//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct bmp_header {
    uint16_t bfType;      // Magic number for the BMP file
    uint32_t bfSize;      // Size of the BMP file in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to start of pixel data
} BMPHeader;

typedef struct bmp_info_header {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the pixel data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors
    uint32_t biClrImportant;   // Important colors
} BMPInfoHeader;
#pragma pack(pop)

void hide_message_in_bmp(const char *input_file, const char *output_file, const char *message) {
    FILE *bmp_file = fopen(input_file, "rb");
    if (!bmp_file) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return;
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, bmp_file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, bmp_file);

    // Calculate the size required for the message
    size_t message_length = strlen(message);
    size_t total_length = message_length + 1; // +1 for null terminator
    fseek(bmp_file, bmp_header.bfOffBits, SEEK_SET);

    // Check if the BMP has enough pixels
    size_t image_size = bmp_info_header.biWidth * bmp_info_header.biHeight * (bmp_info_header.biBitCount / 8);
    if (total_length * 8 > image_size) {
        fprintf(stderr, "Error: Message is too long to fit in the BMP image.\n");
        fclose(bmp_file);
        return;
    }

    // Create a new BMP file with the modified pixels
    FILE *output_file_ptr = fopen(output_file, "wb");
    fwrite(&bmp_header, sizeof(BMPHeader), 1, output_file_ptr);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, output_file_ptr);
    fwrite(bmp_file + bmp_header.bfOffBits, 1, image_size, output_file_ptr);

    // Hide the message in the BMP pixels
    for (size_t i = 0; i < total_length; i++) {
        uint8_t byte = (uint8_t) message[i];
        for (int j = 0; j < 8; j++) {
            uint8_t pixel;
            fread(&pixel, sizeof(uint8_t), 1, bmp_file);
            // Clear the least significant bit
            pixel &= 0xFE;
            // Set the least significant bit to the message bit
            pixel |= (byte >> (7 - j)) & 0x01;
            fwrite(&pixel, sizeof(uint8_t), 1, output_file_ptr);
        }
    }

    fclose(bmp_file);
    fclose(output_file_ptr);
    fprintf(stdout, "Success: Message hidden in BMP image!\n");
}

void extract_message_from_bmp(const char *input_file) {
    FILE *bmp_file = fopen(input_file, "rb");
    if (!bmp_file) {
        fprintf(stderr, "Error: Could not open BMP file.\n");
        return;
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, bmp_file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, bmp_file);

    fseek(bmp_file, bmp_header.bfOffBits, SEEK_SET);

    char extracted_message[256]; // Assuming max message length is 255
    size_t i = 0;
  
    while (1) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            uint8_t pixel;
            fread(&pixel, sizeof(uint8_t), 1, bmp_file);
            byte |= (pixel & 0x01) << (7 - j);
        }
        if (byte == '\0') break; // Stop if null terminator is found
        extracted_message[i++] = byte;
    }
    extracted_message[i] = '\0'; // Null terminate the string

    fclose(bmp_file);
    printf("Extracted Message: %s\n", extracted_message);
}

int main() {
    int choice;
    char input_file[100];
    char output_file[100];
    char message[256];

    printf("Welcome to the BMP Image Steganography Program!\n");
    printf("1. Hide a message in a BMP image\n");
    printf("2. Extract a message from a BMP image\n");
    printf("Please enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    switch (choice) {
        case 1:
            printf("Enter the input BMP file name: ");
            fgets(input_file, sizeof(input_file), stdin);
            strtok(input_file, "\n"); // Remove newline character

            printf("Enter the output BMP file name: ");
            fgets(output_file, sizeof(output_file), stdin);
            strtok(output_file, "\n");

            printf("Enter the message to hide: ");
            fgets(message, sizeof(message), stdin);
            strtok(message, "\n"); // Remove newline character

            hide_message_in_bmp(input_file, output_file, message);
            break;

        case 2:
            printf("Enter the input BMP file name to extract the message from: ");
            fgets(input_file, sizeof(input_file), stdin);
            strtok(input_file, "\n");

            extract_message_from_bmp(input_file);
            break;

        default:
            printf("Invalid choice. Please restart the program.\n");
            break;
    }

    return 0;
}