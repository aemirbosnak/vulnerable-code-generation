//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biImportantClr;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message(uint8_t *image_data, const char *message, size_t message_length) {
    size_t i;
    for (i = 0; i < message_length; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Clear the least significant bit and set it to the message bit
            image_data[i * 8 + bit] = (image_data[i * 8 + bit] & ~1) | ((message[i] >> (7 - bit)) & 1);
        }
    }
}

void extract_message(uint8_t *image_data, char *message, size_t message_length) {
    size_t i;
    for (i = 0; i < message_length; i++) {
        message[i] = 0;
        for (int bit = 0; bit < 8; bit++) {
            message[i] |= (image_data[i * 8 + bit] & 1) << (7 - bit);
        }
    }
}

void usage(const char *program_name) {
    printf("Usage: %s <embed/extract> <bitmap_file> <message_file>\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    const char *mode = argv[1];
    const char *bitmap_file = argv[2];
    const char *message_file = argv[3];

    BITMAPFILEHEADER bf_header;
    BITMAPINFOHEADER bi_header;

    // Open the bitmap file for reading
    FILE *bmp_file = fopen(bitmap_file, "rb");
    if (!bmp_file) {
        perror("Error opening bitmap file");
        return EXIT_FAILURE;
    }

    fread(&bf_header, sizeof(BITMAPFILEHEADER), 1, bmp_file);
    fread(&bi_header, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    // Check if the file is a BMP
    if (bf_header.bfType != 0x4D42) {
        printf("The file is not a valid BMP file.\n");
        fclose(bmp_file);
        return EXIT_FAILURE;
    }

    // Allocate memory for the image data
    size_t image_size = bi_header.biWidth * bi_header.biHeight * (bi_header.biBitCount / 8);
    uint8_t *image_data = (uint8_t *)malloc(image_size);
    fseek(bmp_file, bf_header.bfOffBits, SEEK_SET);
    fread(image_data, 1, image_size, bmp_file);
    fclose(bmp_file);

    if (strcmp(mode, "embed") == 0) {
        // Read the message from the file
        FILE *msg_file = fopen(message_file, "rb");
        if (!msg_file) {
            perror("Error opening message file");
            free(image_data);
            return EXIT_FAILURE;
        }

        fseek(msg_file, 0, SEEK_END);
        size_t message_length = ftell(msg_file);
        fseek(msg_file, 0, SEEK_SET);

        char *message = (char *)malloc(message_length);
        fread(message, 1, message_length, msg_file);
        fclose(msg_file);

        // Embed the message into the image data
        embed_message(image_data, message, message_length);

        // Write the modified image data back to a new file
        FILE *out_file = fopen("output.bmp", "wb");
        fwrite(&bf_header, sizeof(BITMAPFILEHEADER), 1, out_file);
        fwrite(&bi_header, sizeof(BITMAPINFOHEADER), 1, out_file);
        fwrite(image_data, 1, image_size, out_file);
        fclose(out_file);

        printf("Message embedded successfully into output.bmp\n");
        free(message);
    } else if (strcmp(mode, "extract") == 0) {
        // Determine the message length (as an example, we assume it's fixed to 256 bytes)
        size_t message_length = 256;
        char *message = (char *)malloc(message_length);
        extract_message(image_data, message, message_length);

        // Write the extracted message to a file
        FILE *out_msg_file = fopen("extracted_message.txt", "wb");
        fwrite(message, 1, message_length, out_msg_file);
        fclose(out_msg_file);

        printf("Message extracted successfully to extracted_message.txt\n");
        free(message);
    } else {
        usage(argv[0]);
    }

    free(image_data);
    return EXIT_SUCCESS;
}