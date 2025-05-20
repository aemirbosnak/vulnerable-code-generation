//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
/*
 * C Image Steganography Example Program
 *
 * This program takes an image as input and hides a secret message within it.
 * The message is encoded using the Least Significant Bit (LSB) method.
 * The resulting image is then saved to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store an image
struct image {
    int width;
    int height;
    unsigned char* data;
};

// Function to encode a message in an image
void encode_message(struct image* img, char* message) {
    // Calculate the number of pixels required to store the message
    int num_pixels = strlen(message) * 8;

    // Ensure the image has enough pixels to store the message
    if (img->width * img->height < num_pixels) {
        printf("Image too small to store message\n");
        return;
    }

    // Iterate over the pixels in the image
    for (int i = 0; i < num_pixels; i++) {
        // Get the current pixel and its LSB
        unsigned char pixel = img->data[i];
        unsigned char lsb = pixel & 1;

        // Get the next bit from the message
        char bit = message[i / 8];
        bit = (bit >> (7 - (i % 8))) & 1;

        // Set the LSB of the pixel to the next bit from the message
        pixel = (pixel & 0xFE) | bit;

        // Update the image data
        img->data[i] = pixel;
    }
}

// Function to decode a message from an image
char* decode_message(struct image* img) {
    // Allocate memory for the message
    char* message = malloc(img->width * img->height);

    // Iterate over the pixels in the image
    for (int i = 0; i < img->width * img->height; i++) {
        // Get the current pixel and its LSB
        unsigned char pixel = img->data[i];
        unsigned char lsb = pixel & 1;

        // Set the next bit of the message to the LSB of the pixel
        char bit = lsb;
        bit = (bit << (7 - (i % 8))) | 0;

        // Update the message
        message[i / 8] = bit;
    }

    // Return the decoded message
    return message;
}

int main() {
    // Load the image
    struct image img;
    img.width = 256;
    img.height = 256;
    img.data = malloc(img.width * img.height);
    FILE* fp = fopen("image.ppm", "rb");
    fread(img.data, img.width * img.height, 1, fp);
    fclose(fp);

    // Encode the message in the image
    char* message = "Hello, World!";
    encode_message(&img, message);

    // Save the encoded image to a file
    FILE* fp2 = fopen("encoded_image.ppm", "wb");
    fwrite(img.data, img.width * img.height, 1, fp2);
    fclose(fp2);

    // Load the encoded image
    struct image encoded_img;
    encoded_img.width = 256;
    encoded_img.height = 256;
    encoded_img.data = malloc(encoded_img.width * encoded_img.height);
    FILE* fp3 = fopen("encoded_image.ppm", "rb");
    fread(encoded_img.data, encoded_img.width * encoded_img.height, 1, fp3);
    fclose(fp3);

    // Decode the message from the image
    char* decoded_message = decode_message(&encoded_img);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}