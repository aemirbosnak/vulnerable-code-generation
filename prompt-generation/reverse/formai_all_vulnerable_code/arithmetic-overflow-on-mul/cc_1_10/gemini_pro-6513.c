//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH  1024
#define MAX_HEIGHT 768

// Define the maximum number of bits to embed in the image
#define MAX_BITS 10000

// Create a structure to represent the image
typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

// Create a function to embed a message in an image
void embed_message(Image *image, char *message) {
    // Convert the message to a bitstream
    int bitstream_length = strlen(message) * 8;
    uint8_t *bitstream = malloc(bitstream_length);
    for (int i = 0; i < strlen(message); i++) {
        for (int j = 7; j >= 0; j--) {
            bitstream[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Embed the bitstream in the image
    int bitstream_index = 0;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the pixel value
            uint8_t pixel = image->data[y * image->width + x];

            // Embed the bit in the pixel
            image->data[y * image->width + x] = (pixel & 0xFE) | bitstream[bitstream_index++];

            // Check if we have embedded all the bits
            if (bitstream_index >= bitstream_length) {
                break;
            }
        }

        // Check if we have embedded all the bits
        if (bitstream_index >= bitstream_length) {
            break;
        }
    }

    // Free the bitstream
    free(bitstream);
}

// Create a function to extract the message from an image
char *extract_message(Image *image) {
    // Create a buffer to store the message
    int message_length = MAX_BITS / 8;
    char *message = malloc(message_length + 1);
    memset(message, 0, message_length + 1);

    // Extract the bitstream from the image
    int bitstream_index = 0;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the pixel value
            uint8_t pixel = image->data[y * image->width + x];

            // Extract the bit from the pixel
            uint8_t bit = pixel & 1;

            // Store the bit in the bitstream
            message[bitstream_index / 8] |= bit << (7 - bitstream_index % 8);

            // Increment the bitstream index
            bitstream_index++;

            // Check if we have extracted all the bits
            if (bitstream_index >= MAX_BITS) {
                break;
            }
        }

        // Check if we have extracted all the bits
        if (bitstream_index >= MAX_BITS) {
            break;
        }
    }

    // Null-terminate the message
    message[message_length] = '\0';

    // Return the message
    return message;
}

// Create a function to load an image from a file
Image *load_image(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the image header
    uint8_t header[14];
    fread(header, 1, 14, file);

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(file);
        return NULL;
    }

    // Get the image width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height);

    // Read the image data
    fread(image->data, 1, width * height, file);

    // Close the file
    fclose(file);

    // Return the image
    return image;
}

// Create a function to save an image to a file
void save_image(Image *image, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write the image header
    uint8_t header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = sizeof(header) + image->width * image->height;
    *(int *)&header[10] = sizeof(header);
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(int *)&header[26] = 1;
    *(int *)&header[28] = 8;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = 0;
    *(int *)&header[38] = 0;
    fwrite(header, 1, 14, file);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, file);

    // Close the file
    fclose(file);
}

// Create a function to print the usage information
void usage() {
    printf("Usage: watermark <input_image> <output_image> <message>\n");
}

// Create the main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        usage();
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading input image\n");
        return 1;
    }

    // Embed the message in the image
    embed_message(image, argv[3]);

    // Save the output image
    save_image(image, argv[2]);

    // Free the image
    free(image->data);
    free(image);

    return 0;
}