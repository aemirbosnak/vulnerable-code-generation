//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void encode_message(uint8_t *image_data, const char *message, int width, int height) {
    int message_length = strlen(message);
    int data_size = width * height * 3; // Assuming 24-bit bitmap
    if (data_size < message_length * 8 + 32) {
        printf("Image too small to hold message.\n");
        return;
    }

    // Encode the message length in the first 32 bits (4 bytes)
    for (int i = 0; i < 32; i++) {
        image_data[i] = (image_data[i] & ~1) | ((message_length >> i) & 1);
    }

    // Encode the actual message
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            image_data[32 + i * 8 + j] = (image_data[32 + i * 8 + j] & ~1) | ((message[i] >> j) & 1);
        }
    }
}

void decode_message(uint8_t *image_data, char *message, int max_length) {
    int message_length = 0;

    // Decode the message length
    for (int i = 0; i < 32; i++) {
        message_length |= (image_data[i] & 1) << i;
    }

    if (message_length > max_length) {
        printf("Message length in image exceeds buffer size.\n");
        return;
    }

    // Decode the actual message
    for (int i = 0; i < message_length; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= (image_data[32 + i * 8 + j] & 1) << j;
        }
    }
    message[message_length] = '\0'; // Null-terminate the string
}

void read_bitmap(const char *filename, uint8_t **image_data, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fread(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fread(info_header, sizeof(BITMAPINFOHEADER), 1, file);

    int data_size = info_header->biWidth * info_header->biHeight * 3; // 24 bits
    *image_data = (uint8_t *)malloc(data_size);
    fseek(file, file_header->bfOffBits, SEEK_SET);
    fread(*image_data, data_size, 1, file);
    fclose(file);
}

void write_bitmap(const char *filename, uint8_t *image_data, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(info_header, sizeof(BITMAPINFOHEADER), 1, file);
    
    int data_size = info_header->biWidth * info_header->biHeight * 3; // 24 bits
    fseek(file, file_header->bfOffBits, SEEK_SET);
    fwrite(image_data, data_size, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_bitmap> <output_bitmap> <message_to_hide>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint8_t *image_data;
    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;
    
    read_bitmap(argv[1], &image_data, &file_header, &info_header);
    
    const char *message = argv[3];
    encode_message(image_data, message, info_header.biWidth, info_header.biHeight);
    
    write_bitmap(argv[2], image_data, &file_header, &info_header);
    printf("Message encoded and image written to %s\n", argv[2]);

    free(image_data);
    return EXIT_SUCCESS;
}