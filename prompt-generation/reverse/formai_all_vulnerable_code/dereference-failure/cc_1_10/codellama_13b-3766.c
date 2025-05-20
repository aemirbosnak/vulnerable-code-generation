//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: calm
// Image Steganography Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BITS 8

// Struct for storing pixel data
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

// Function to encode a message in an image
void encode(pixel_t *pixels, int width, int height, char *message) {
    int message_length = strlen(message);
    int pixel_count = width * height;
    int bit_count = 0;

    // Iterate through each pixel and encode a bit from the message
    for (int i = 0; i < pixel_count; i++) {
        pixel_t *pixel = &pixels[i];
        if (bit_count < message_length) {
            // Get the next bit from the message
            char bit = message[bit_count];

            // Encode the bit in the pixel
            if (bit == '0') {
                pixel->r = 0;
                pixel->g = 0;
                pixel->b = 0;
            } else if (bit == '1') {
                pixel->r = 255;
                pixel->g = 255;
                pixel->b = 255;
            }

            // Increment the bit count
            bit_count++;
        }
    }
}

// Function to decode a message from an image
char *decode(pixel_t *pixels, int width, int height) {
    char *message = (char *)malloc(MAX_BITS);
    int pixel_count = width * height;
    int bit_count = 0;

    // Iterate through each pixel and decode a bit from the image
    for (int i = 0; i < pixel_count; i++) {
        pixel_t *pixel = &pixels[i];
        if (bit_count < MAX_BITS) {
            // Decode the bit from the pixel
            char bit;
            if (pixel->r == 0 && pixel->g == 0 && pixel->b == 0) {
                bit = '0';
            } else if (pixel->r == 255 && pixel->g == 255 && pixel->b == 255) {
                bit = '1';
            } else {
                break;
            }

            // Add the decoded bit to the message
            message[bit_count] = bit;

            // Increment the bit count
            bit_count++;
        }
    }

    // Add a null terminator to the message
    message[bit_count] = '\0';

    return message;
}

int main() {
    // Open the image file and read the pixel data
    FILE *file = fopen("image.bmp", "rb");
    fseek(file, 54, SEEK_SET);
    int width = 512;
    int height = 512;
    pixel_t *pixels = (pixel_t *)malloc(width * height * sizeof(pixel_t));
    fread(pixels, sizeof(pixel_t), width * height, file);
    fclose(file);

    // Encode a message in the image
    char message[] = "Hello, World!";
    encode(pixels, width, height, message);

    // Save the encoded image
    file = fopen("encoded.bmp", "wb");
    fwrite(pixels, sizeof(pixel_t), width * height, file);
    fclose(file);

    // Decode the message from the encoded image
    char *decoded = decode(pixels, width, height);
    printf("Decoded message: %s\n", decoded);

    return 0;
}