//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILENAME 100

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

typedef struct {
    uint16_t type;
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} BMPInfoHeader;

void encode_message(Pixel *pixels, const char *message, int width, int height) {
    int message_length = strlen(message);
    int total_pixels = width * height;

    if (message_length * 8 > total_pixels) {
        fprintf(stderr, "Message is too long to encode in the image.\n");
        exit(1);
    }

    for (int i = 0; i < message_length; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = i * 8 + bit;
            if (pixel_index >= total_pixels) return; // Prevent overflow

            uint8_t bit_to_encode = (message[i] >> (7 - bit)) & 1;
            pixels[pixel_index].red = (pixels[pixel_index].red & ~1) | bit_to_encode;
        }
    }
}

void decode_message(Pixel *pixels, int width, int height, char *message, int message_length) {
    for (int i = 0; i < message_length; i++) {
        message[i] = 0; // Initialize message char
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = i * 8 + bit;
            if (pixel_index >= (width * height)) return; // Prevent overflow

            uint8_t bit_value = pixels[pixel_index].red & 1;
            message[i] |= (bit_value << (7 - bit));
        }
    }
}

int read_bmp(const char *filename, Pixel **pixels, BMPHeader *bmp_header, BMPInfoHeader *bmp_info_header) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return -1;
    }

    fread(bmp_header, sizeof(BMPHeader), 1, file);
    fread(bmp_info_header, sizeof(BMPInfoHeader), 1, file);
    
    // Validate BMP file type
    if (bmp_header->type != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(file);
        return -1;
    }

    fseek(file, bmp_header->offset, SEEK_SET);
    int width = bmp_info_header->width;
    int height = bmp_info_header->height;
    *pixels = malloc(width * height * sizeof(Pixel));
    
    if (!*pixels) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return -1;
    }

    fread(*pixels, sizeof(Pixel), width * height, file);
    fclose(file);
    return width * height;
}

int write_bmp(const char *filename, Pixel *pixels, BMPHeader bmp_header, BMPInfoHeader bmp_info_header) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return -1;
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    fseek(file, bmp_header.offset, SEEK_SET);
    int width = bmp_info_header.width;
    int height = bmp_info_header.height;
    fwrite(pixels, sizeof(Pixel), width * height, file);

    fclose(file);
    return 0;
}

int main() {
    char input_filename[MAX_FILENAME];
    char output_filename[MAX_FILENAME];
    char message[256];
    Pixel *pixels = NULL;
    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    printf("Enter input BMP file name: ");
    scanf("%s", input_filename);
    printf("Enter output BMP file name: ");
    scanf("%s", output_filename);
    printf("Enter message to hide: ");
    scanf(" %[^\n]s", message); // Read string with spaces

    int total_pixels = read_bmp(input_filename, &pixels, &bmp_header, &bmp_info_header);
    if (total_pixels < 0) {
        return 1; // Error reading BMP
    }

    encode_message(pixels, message, bmp_info_header.width, bmp_info_header.height);
    write_bmp(output_filename, pixels, bmp_header, bmp_info_header);
    free(pixels);

    printf("Message encoded and saved to %s\n", output_filename);

    // Decode message for verification
    char decoded_message[256] = {0};
    decode_message(pixels, bmp_info_header.width, bmp_info_header.height, decoded_message, strlen(message));

    printf("Decoded Message: %s\n", decoded_message);
    return 0;
}