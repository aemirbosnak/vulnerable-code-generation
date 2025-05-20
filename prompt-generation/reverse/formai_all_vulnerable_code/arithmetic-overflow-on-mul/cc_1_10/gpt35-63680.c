//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

typedef struct {
    char magic[2];
    int size;
    short int reserved1, reserved2;
    int offset;
} BMPHeader;

typedef struct {
    int size;
    int width, height;
    short int planes;
    short int bit_count;
    int compression;
    int image_size;
    int x_pix_per_m;
    int y_pix_per_m;
    int colors_used;
    int colors_important;
} BMPInfo;

void encode(char *message, char *image_path, char *output_path) {
    FILE *image_file = fopen(image_path, "rb");
    FILE *output_file = fopen(output_path, "wb");
    if (!image_file || !output_file) {
        printf("Failed to open files.\n");
        return;
    }

    BMPHeader header;
    BMPInfo info;
    fread(&header, sizeof(BMPHeader), 1, image_file);
    fread(&info, sizeof(BMPInfo), 1, image_file);

    // Skip over color table
    fseek(image_file, header.offset - sizeof(BMPHeader) - sizeof(BMPInfo), SEEK_CUR);

    // Write header and info to output file
    fwrite(&header, sizeof(BMPHeader), 1, output_file);
    fwrite(&info, sizeof(BMPInfo), 1, output_file);

    // Convert message to binary and get length
    int message_length = strlen(message);
    char binary_message[message_length * 8];
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] & (1 << j)) ? '1' : '0';
        }
    }

    char chunk[CHUNK_SIZE];
    int chunk_pos = 0, bit_pos = 0;
    while (fread(chunk, 1, CHUNK_SIZE, image_file) > 0) {
        for (int i = 0; i < CHUNK_SIZE; i++) {
            if (chunk_pos >= message_length * 8) {
                // End of message has been reached, write the rest of the image bytes
                fwrite(chunk + i, 1, CHUNK_SIZE - i, output_file);
                break;
            }
            if (bit_pos == 8) {
                // Reached end of current message bit, move to next character
                bit_pos = 0;
                chunk_pos++;
            }
            char bit = binary_message[chunk_pos * 8 + bit_pos];
            chunk[i] = (chunk[i] & ~1) | (bit - '0');
            bit_pos++;
        }
        fwrite(chunk, 1, CHUNK_SIZE, output_file);
    }

    fclose(image_file);
    fclose(output_file);
}

char* decode(char *image_path) {
    FILE *image_file = fopen(image_path, "rb");
    if (!image_file) {
        printf("Failed to open file.\n");
        return NULL;
    }

    BMPHeader header;
    BMPInfo info;
    fread(&header, sizeof(BMPHeader), 1, image_file);
    fread(&info, sizeof(BMPInfo), 1, image_file);

    // Skip over color table
    fseek(image_file, header.offset - sizeof(BMPHeader) - sizeof(BMPInfo), SEEK_CUR);

    char chunk[CHUNK_SIZE];
    int chunk_pos = 0, bit_pos = 0;
    int message_length = info.width * info.height * info.bit_count / 8;
    char *binary_message = malloc(message_length * 8 + 1);
    for (int i = 0; i < message_length * 8; i++) {
        binary_message[i] = '0';
    }
    binary_message[message_length * 8] = '\0';

    while (fread(chunk, 1, CHUNK_SIZE, image_file) > 0) {
        for (int i = 0; i < CHUNK_SIZE; i++) {
            if (chunk_pos >= message_length * 8) {
                // End of message has been reached
                fclose(image_file);
                return binary_message;
            }
            if (bit_pos == 8) {
                // Reached end of current message bit, move to next character
                bit_pos = 0;
                chunk_pos++;
            }
            binary_message[chunk_pos * 8 + bit_pos] = (chunk[i] & 1) ? '1' : '0';
            bit_pos++;
        }
    }

    fclose(image_file);
    return binary_message;
}

int main() {
    char *message = "This is a secret message!";
    char *image_path = "input.bmp";
    char *output_path = "output.bmp";

    encode(message, image_path, output_path);
    char *decoded_message = decode(output_path);

    printf("Decoded message: %s\n", decoded_message);

    free(decoded_message);
    return 0;
}