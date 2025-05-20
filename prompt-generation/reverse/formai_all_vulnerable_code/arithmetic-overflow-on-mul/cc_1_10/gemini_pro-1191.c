//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Type of a 24-bit color
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} rgb24;

// Get the least significant bit of a byte
unsigned char lsb(unsigned char byte) {
    return byte & 1;
}

// Set the least significant bit of a byte
void set_lsb(unsigned char *byte, unsigned char bit) {
    *byte = (*byte & ~1) | bit;
}

// Encode a message into a 24-bit color image
void encode(rgb24 *image, int width, int height, const char *message) {
    int message_length = strlen(message);
    int bit_index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (bit_index < message_length * 8) {
                set_lsb(&image[y * width + x].blue, lsb(message[bit_index / 8] >> (bit_index % 8)));
                bit_index++;
            }
            if (bit_index < message_length * 8) {
                set_lsb(&image[y * width + x].green, lsb(message[bit_index / 8] >> (bit_index % 8)));
                bit_index++;
            }
            if (bit_index < message_length * 8) {
                set_lsb(&image[y * width + x].red, lsb(message[bit_index / 8] >> (bit_index % 8)));
                bit_index++;
            }
        }
    }
}

// Decode a message from a 24-bit color image
char *decode(rgb24 *image, int width, int height) {
    int message_length = 0;
    int bit_index = 0;
    char *message = malloc(1);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (bit_index % 8 == 0) {
                message = realloc(message, message_length + 2);
                message[message_length++] = 0;
            }
            message[message_length - 1] |= lsb(image[y * width + x].blue) << (bit_index % 8);
            bit_index++;
            message[message_length - 1] |= lsb(image[y * width + x].green) << (bit_index % 8);
            bit_index++;
            message[message_length - 1] |= lsb(image[y * width + x].red) << (bit_index % 8);
            bit_index++;
        }
    }
    return message;
}

int main() {
    // Read the image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Read the image data
    rgb24 *image = malloc(width * height * sizeof(rgb24));
    fread(image, sizeof(rgb24), width * height, image_file);
    fclose(image_file);

    // Encode a message into the image
    const char *message = "Hello world!";
    encode(image, width, height, message);

    // Write the modified image to a file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Write the image dimensions
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);

    // Write the image data
    fwrite(image, sizeof(rgb24), width * height, output_file);
    fclose(output_file);

    // Decode the message from the image
    char *decoded_message = decode(image, width, height);

    // Print the decoded message
    printf("Decoded message: %s\n", decoded_message);

    // Free the allocated memory
    free(image);
    free(decoded_message);

    return 0;
}