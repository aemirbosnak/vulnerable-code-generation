//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)  // Ensure no padding in the structures
typedef struct {
    unsigned short bfType;      // File type
    unsigned int bfSize;        // Size of the file
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;     // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;          // Size of this header
    int biWidth;                  // Width of bitmap in pixels
    int biHeight;                 // Height of bitmap in pixels
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;      // Image size
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Colors in color table
    unsigned int biClrImportant;   // Important color
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message(const char *image_path, const char *message, const char *output_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        fprintf(stderr, "Could not open image file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image);

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image);

    // Check if the image is a 24-bit BMP
    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP images are supported.\n");
        fclose(image);
        return;
    }

    size_t message_length = strlen(message);
    size_t total_bits = message_length * 8 + 1; // +1 for null terminator
    size_t pixel_count = bih.biWidth * bih.biHeight;

    if (total_bits > pixel_count * 3) {
        fprintf(stderr, "Message is too long to embed in this image.\n");
        fclose(image);
        return;
    }

    unsigned char *image_data = (unsigned char *)malloc(bfh.bfSize - bfh.bfOffBits);
    fseek(image, bfh.bfOffBits, SEEK_SET);
    fread(image_data, bfh.bfSize - bfh.bfOffBits, 1, image);
    fclose(image);

    // Embed the message into the image data
    size_t bit_index = 0;
    for (size_t i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (message[i] >> (7 - j)) & 1;
            size_t pixel_index = bit_index / 3;
            size_t color_index = bit_index % 3;

            if (bit) {
                image_data[pixel_index * 3 + color_index] |= 1;
            } else {
                image_data[pixel_index * 3 + color_index] &= ~1;
            }

            bit_index++;
        }
    }

    // Embed the null terminator
    for (int j = 0; j < 8; j++) {
        unsigned char bit = (0 >> (7 - j)) & 1;
        size_t pixel_index = bit_index / 3;
        size_t color_index = bit_index % 3;

        if (bit) {
            image_data[pixel_index * 3 + color_index] |= 1;
        } else {
            image_data[pixel_index * 3 + color_index] &= ~1;
        }

        bit_index++;
    }

    // Write the modified image data to a new file
    FILE *output_image = fopen(output_path, "wb");
    if (!output_image) {
        fprintf(stderr, "Could not open output image file.\n");
        free(image_data);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output_image);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output_image);
    fwrite(image_data, bfh.bfSize - bfh.bfOffBits, 1, output_image);
    
    free(image_data);
    fclose(output_image);
    printf("Message embedded successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.bmp> <message> <output_image.bmp>\n", argv[0]);
        return 1;
    }

    embed_message(argv[1], argv[2], argv[3]);
    return 0;
}