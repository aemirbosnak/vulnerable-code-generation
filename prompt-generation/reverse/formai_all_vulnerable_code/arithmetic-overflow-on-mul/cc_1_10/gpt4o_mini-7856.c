//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function to read a BMP image file
Image* read_bmp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET);
    Pixel *data = malloc(width * height * sizeof(Pixel));
    fread(data, sizeof(Pixel), width * height, file);

    fclose(file);

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to write a BMP image file
void write_bmp(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    // BMP header
    uint16_t bfType = 0x4D42; // "BM"
    uint32_t bfSize = 54 + (image->width * image->height * sizeof(Pixel));
    uint32_t bfReserved = 0;
    uint32_t bfOffBits = 54;
    
    fwrite(&bfType, sizeof(bfType), 1, file);
    fwrite(&bfSize, sizeof(bfSize), 1, file);
    fwrite(&bfReserved, sizeof(bfReserved), 1, file);
    fwrite(&bfOffBits, sizeof(bfOffBits), 1, file);

    // DIB header
    uint32_t biSize = 40;
    uint32_t biWidth = image->width;
    uint32_t biHeight = image->height;
    uint16_t biPlanes = 1;
    uint16_t biBitCount = 24;
    uint32_t biCompression = 0;
    uint32_t biSizeImage = image->width * image->height * sizeof(Pixel);
    uint32_t biXPelsPerMeter = 0;
    uint32_t biYPelsPerMeter = 0;
    uint32_t biClrUsed = 0;
    uint32_t biClrImportant = 0;

    fwrite(&biSize, sizeof(biSize), 1, file);
    fwrite(&biWidth, sizeof(biWidth), 1, file);
    fwrite(&biHeight, sizeof(biHeight), 1, file);
    fwrite(&biPlanes, sizeof(biPlanes), 1, file);
    fwrite(&biBitCount, sizeof(biBitCount), 1, file);
    fwrite(&biCompression, sizeof(biCompression), 1, file);
    fwrite(&biSizeImage, sizeof(biSizeImage), 1, file);
    fwrite(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, file);
    fwrite(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, file);
    fwrite(&biClrUsed, sizeof(biClrUsed), 1, file);
    fwrite(&biClrImportant, sizeof(biClrImportant), 1, file);

    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to hide message in the least significant bit of the pixel
void encode_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int index = 0;
    for (int i = 0; i < image->width * image->height && index < message_length; i++) {
        if (index < message_length) {
            image->data[i].red = (image->data[i].red & 0xFE) | ((message[index] >> 7) & 0x01);
            index++;
        }
        if (index < message_length) {
            image->data[i].green = (image->data[i].green & 0xFE) | ((message[index] >> 7) & 0x01);
            index++;
        }
        if (index < message_length) {
            image->data[i].blue = (image->data[i].blue & 0xFE) | ((message[index] >> 7) & 0x01);
            index++;
        }
    }
}

// Function to decode the hidden message from the image
void decode_message(Image *image, char *output_message, int max_length) {
    int index = 0;
    for (int i = 0; i < image->width * image->height && index < max_length - 1; i += 3) {
        output_message[index] = 0;
        output_message[index] |= ((image->data[i].red & 0x01) << 7);
        output_message[index] |= ((image->data[i + 1].green & 0x01) << 6);
        output_message[index] |= ((image->data[i + 2].blue & 0x01) << 5);
        if (output_message[index] == '\0') break;
        index++;
    }
    output_message[index] = '\0'; // Null-terminate the string
}

int main() {
    const char *input_filename = "input.bmp";
    const char *output_filename = "output.bmp";
    const char *hidden_message = "Hello, Steganography!";

    Image *image = read_bmp(input_filename);
    if (!image) return 1;

    encode_message(image, hidden_message);
    write_bmp(output_filename, image);

    char decoded_message[256];
    decode_message(image, decoded_message, sizeof(decoded_message));

    printf("Decoded Message: %s\n", decoded_message);

    free(image->data);
    free(image);
    return 0;
}