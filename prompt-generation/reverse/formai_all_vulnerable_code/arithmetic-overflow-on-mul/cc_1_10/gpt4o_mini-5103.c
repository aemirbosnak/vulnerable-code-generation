//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: recursive
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
    unsigned int biCirImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;
#pragma pack(pop)

void encode_recursive(FILE *image, const char *message, size_t index, size_t message_length);
void decode_recursive(FILE *image, char *message, size_t index, size_t max_length);
void read_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, RGB **pixels);

int main() {
    const char *filename = "input.bmp";
    const char *secret_message = "Hello, World!";
    
    // Prepare BMP headers
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB *pixels;
    read_bmp(filename, &bfh, &bih, &pixels);
    
    // Encode the message
    FILE *image = fopen(filename, "r+b");
    if (!image) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    encode_recursive(image, secret_message, 0, strlen(secret_message));
    fclose(image);

    // To decode, use a new file pointer for reading
    image = fopen(filename, "rb");
    char decoded_message[256] = {0};
    decode_recursive(image, decoded_message, 0, sizeof(decoded_message) - 1);
    fclose(image);
    
    printf("Decoded Message: %s\n", decoded_message);
    
    // Free allocated memory
    free(pixels);
    return 0;
}

void encode_recursive(FILE *image, const char *message, size_t index, size_t message_length) {
    if (index >= message_length) return;

    unsigned char character = message[index];
    for (int bit = 0; bit < 8; bit++) {
        fseek(image, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + index * 8 + bit / 8, SEEK_SET);
        RGB pixel;
        fread(&pixel, sizeof(RGB), 1, image);
        pixel.red = (pixel.red & 0xFE) | ((character >> (7 - bit)) & 0x01);
        fseek(image, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + index * 8 + bit / 8, SEEK_SET);
        fwrite(&pixel, sizeof(RGB), 1, image);
    }
    encode_recursive(image, message, index + 1, message_length);
}

void decode_recursive(FILE *image, char *message, size_t index, size_t max_length) {
    if (index >= max_length) return;

    char character = 0;
    for (int bit = 0; bit < 8; bit++) {
        fseek(image, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + index * 8 + bit / 8, SEEK_SET);
        RGB pixel;
        fread(&pixel, sizeof(RGB), 1, image);
        character |= ((pixel.red & 1) << (7 - bit));
    }
    
    if (character == 0) return;  // Stop if null character is found
    message[index] = character;

    decode_recursive(image, message, index + 1, max_length);
}

void read_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, RGB **pixels) {
    FILE *image = fopen(filename, "rb");
    if (!image) {
        fprintf(stderr, "Error opening BMP file.\n");
        exit(1);
    }
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, image);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, image);
    
    int width = bih->biWidth;
    int height = bih->biHeight;
    *pixels = malloc(sizeof(RGB) * width * height);
    fseek(image, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), width * height, image);
    
    fclose(image);
}