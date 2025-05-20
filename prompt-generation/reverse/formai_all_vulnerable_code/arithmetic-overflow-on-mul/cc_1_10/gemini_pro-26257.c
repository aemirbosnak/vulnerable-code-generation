//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTES_PER_PIXEL 3

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * BYTES_PER_PIXEL);

    // Read the image data
    fread(image->data, BYTES_PER_PIXEL, width * height, fp);

    fclose(fp);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image->data, BYTES_PER_PIXEL, image->width * image->height, fp);

    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);

    // Convert the message to binary
    uint8_t *binary_message = malloc(message_length * 8);
    for (int i = 0; i < message_length; i++) {
        for (int j = 7; j >= 0; j--) {
            binary_message[i * 8 + j] = message[i] & (1 << j);
        }
    }

    // Hide the binary message in the image
    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < BYTES_PER_PIXEL; j++) {
            image->data[i].b = (image->data[i].b & ~1) | binary_message[index];
            index++;
        }
    }

    free(binary_message);
}

char *extract_message(Image *image) {
    int message_length = 0;

    // Count the number of bits in the message
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < BYTES_PER_PIXEL; j++) {
            message_length += image->data[i].b & 1;
        }
    }

    // Convert the bits to a string
    char *message = malloc(message_length + 1);
    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < BYTES_PER_PIXEL; j++) {
            message[index] |= (image->data[i].b & 1) << (7 - j);
            index++;
        }
    }

    message[index] = '\0';

    return message;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    hide_message(image, argv[3]);
    save_image(argv[2], image);

    free(image->data);
    free(image);

    return 0;
}