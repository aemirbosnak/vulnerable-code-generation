//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE* in_image = fopen(argv[1], "rb");
    if (!in_image) {
        fprintf(stderr, "Could not open input image %s\n", argv[1]);
        return 1;
    }

    FILE* out_image = fopen(argv[2], "wb");
    if (!out_image) {
        fprintf(stderr, "Could not create output image %s\n", argv[2]);
        fclose(in_image);
        return 1;
    }

    FILE* cover_image = fopen(argv[1], "rb");
    if (!cover_image) {
        fprintf(stderr, "Could not open cover image %s\n", argv[1]);
        fclose(in_image);
        fclose(out_image);
        return 1;
    }

    unsigned char* cover_image_data = (unsigned char*)malloc(sizeof(unsigned char) * (fread(NULL, 1, 0, cover_image)));
    if (!cover_image_data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(in_image);
        fclose(out_image);
        return 1;
    }

    int num_pixels = 0;
    for (int i = 0; i < 4000; i++) {
        if (fread(&num_pixels, sizeof(int), 1, in_image) == 1) {
            break;
        }
    }

    int num_bytes = num_pixels * 3;
    unsigned char* message = (unsigned char*)malloc(sizeof(unsigned char) * num_bytes);
    if (!message) {
        fprintf(stderr, "Memory allocation failed\n");
        free(cover_image_data);
        fclose(in_image);
        fclose(out_image);
        return 1;
    }

    fread(message, sizeof(unsigned char), num_bytes, in_image);
    fclose(in_image);

    unsigned char* cover_image_data_out = (unsigned char*)malloc(sizeof(unsigned char) * num_bytes);
    if (!cover_image_data_out) {
        fprintf(stderr, "Memory allocation failed\n");
        free(message);
        free(cover_image_data);
        fclose(out_image);
        return 1;
    }

    for (int i = 0; i < num_pixels; i++) {
        int index = i * 3;
        unsigned char pixel = cover_image_data[index];
        unsigned char message_byte = message[i * 3 + 0];
        unsigned char message_byte2 = message[i * 3 + 1];
        unsigned char message_byte3 = message[i * 3 + 2];

        if (message_byte == 0) {
            cover_image_data_out[index] = pixel | (message_byte2 << 1) | (message_byte3 << 2);
        } else if (message_byte == 1) {
            cover_image_data_out[index] = pixel | (message_byte2 << 2) | (message_byte3 << 1);
        } else if (message_byte == 2) {
            cover_image_data_out[index] = pixel | (message_byte2 << 3) | (message_byte3 << 2);
        } else if (message_byte == 3) {
            cover_image_data_out[index] = pixel | (message_byte2 << 3) | (message_byte3 << 1);
        } else if (message_byte == 4) {
            cover_image_data_out[index] = pixel | (message_byte2 << 1) | (message_byte3 << 3);
        } else if (message_byte == 5) {
            cover_image_data_out[index] = pixel | (message_byte2 << 2) | (message_byte3 << 3);
        } else if (message_byte == 6) {
            cover_image_data_out[index] = pixel | (message_byte2 << 3) | (message_byte3 << 3);
        }
    }

    fwrite(cover_image_data_out, sizeof(unsigned char), num_bytes, out_image);
    fclose(out_image);
    free(cover_image_data);
    free(message);

    return 0;
}