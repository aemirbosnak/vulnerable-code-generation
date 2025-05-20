//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

Image *read_image(const char *filename) {
    // Read the image data from the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Check if the file is too large
    if (file_size > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: file is too large\n");
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    image->data = malloc(file_size);
    if (image->data == NULL) {
        perror("Error allocating memory");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the image data into the buffer
    fread(image->data, 1, file_size, file);
    fclose(file);

    // Get the image width and height
    int width, height;
    if (sscanf((char *) image->data, "P6\n%d %d\n255\n", &width, &height) != 2) {
        fprintf(stderr, "Error: invalid image format\n");
        free(image->data);
        free(image);
        return NULL;
    }

    image->width = width;
    image->height = height;

    return image;
}

void write_image(const Image *image, const char *filename) {
    // Open the file for writing
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the image header
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * 3, file);

    // Close the file
    fclose(file);
}

void watermark_image(Image *image, const char *message) {
    // Convert the message to a sequence of bits
    int message_length = strlen(message);
    uint8_t *message_bits = malloc(message_length * 8);
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            message_bits[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Embed the bits in the image data
    int bit_index = 0;
    for (int i = 0; i < image->width * image->height * 3; i++) {
        // Get the least significant bit of the pixel value
        uint8_t lsb = image->data[i] & 1;

        // Replace the LSB with the next bit of the message
        image->data[i] = (image->data[i] & ~1) | (message_bits[bit_index] & 1);

        // Increment the bit index
        bit_index++;

        // If we have reached the end of the message, stop embedding bits
        if (bit_index == message_length * 8) {
            break;
        }
    }

    free(message_bits);
}

char *extract_watermark(const Image *image) {
    // Extract the bits from the image data
    int message_length = 0;
    uint8_t *message_bits = malloc(MAX_IMAGE_SIZE * 8);
    for (int i = 0; i < image->width * image->height * 3; i++) {
        // Get the least significant bit of the pixel value
        message_bits[message_length++] = image->data[i] & 1;
    }

    // Convert the bits to a message
    char *message = malloc(message_length / 8 + 1);
    for (int i = 0; i < message_length / 8; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= (message_bits[i * 8 + j] << j);
        }
    }
    message[message_length / 8] = '\0';

    free(message_bits);

    return message;
}

int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <message> <output image>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Watermark the image
    watermark_image(image, argv[2]);

    // Write the output image
    write_image(image, argv[3]);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}