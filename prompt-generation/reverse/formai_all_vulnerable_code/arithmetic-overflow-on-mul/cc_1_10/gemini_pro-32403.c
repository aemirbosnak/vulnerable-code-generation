//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BMP_HEADER_SIZE 54

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Pixel;

Pixel get_pixel(unsigned char *image, int width, int height, int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        fprintf(stderr, "Error: Pixel (%d, %d) is out of bounds.\n", x, y);
        exit(1);
    }

    int offset = BMP_HEADER_SIZE + (y * width + x) * 3;
    return (Pixel) {image[offset], image[offset + 1], image[offset + 2]};
}

void set_pixel(unsigned char *image, int width, int height, int x, int y, Pixel pixel) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        fprintf(stderr, "Error: Pixel (%d, %d) is out of bounds.\n", x, y);
        exit(1);
    }

    int offset = BMP_HEADER_SIZE + (y * width + x) * 3;
    image[offset] = pixel.b;
    image[offset + 1] = pixel.g;
    image[offset + 2] = pixel.r;
}

unsigned char get_bit(unsigned char byte, int bit) {
    return (byte >> bit) & 1;
}

void set_bit(unsigned char *byte, int bit, unsigned char value) {
    if (value) {
        *byte |= (1 << bit);
    } else {
        *byte &= ~(1 << bit);
    }
}

void encode(unsigned char *image, int width, int height, unsigned char *message, int message_length) {
    int bit_index = 0;
    int pixel_index = 0;

    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char bit = get_bit(message[i], 7 - j);
            Pixel pixel = get_pixel(image, width, height, pixel_index % width, pixel_index / width);
            set_bit(&pixel.b, bit_index, bit);
            set_pixel(image, width, height, pixel_index % width, pixel_index / width, pixel);
            pixel_index++;
            bit_index++;
            if (bit_index == 8) {
                bit_index = 0;
            }
        }
    }
}

void decode(unsigned char *image, int width, int height, unsigned char *message, int message_length) {
    int bit_index = 0;
    int pixel_index = 0;

    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            Pixel pixel = get_pixel(image, width, height, pixel_index % width, pixel_index / width);
            unsigned char bit = get_bit(pixel.b, bit_index);
            message[i] |= (bit << (7 - j));
            pixel_index++;
            bit_index++;
            if (bit_index == 8) {
                bit_index = 0;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file %s.\n", argv[1]);
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file %s.\n", argv[2]);
        exit(1);
    }

    unsigned char *image = NULL;
    int width, height;

    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    image = malloc(width * height * 3);
    fread(image, 1, width * height * 3, input_file);
    fclose(input_file);

    int message_length = strlen(argv[3]);
    unsigned char *message = malloc(message_length);
    for (int i = 0; i < message_length; i++) {
        message[i] = argv[3][i];
    }

    encode(image, width, height, message, message_length);

    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    fwrite(image, 1, width * height * 3, output_file);
    fclose(output_file);

    free(image);
    free(message);

    return 0;
}