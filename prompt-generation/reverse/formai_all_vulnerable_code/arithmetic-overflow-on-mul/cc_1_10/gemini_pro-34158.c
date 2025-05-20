//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the secret message
#define MAX_MSG_LEN 1024

// Define the maximum size of the image
#define MAX_IMG_SIZE 1024 * 1024

// Read an image from a file
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header of the image
    unsigned char header[14];
    fread(header, 1, 14, fp);

    // Check if the image is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP image\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the width and height of the image
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    unsigned char *data = malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, 1, *width * *height * 3, fp);

    // Close the file
    fclose(fp);

    return data;
}

// Write an image to a file
void write_image(char *filename, unsigned char *data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header of the image
    unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    header[2] = (unsigned char)(width & 0xFF);
    header[3] = (unsigned char)((width >> 8) & 0xFF);
    header[4] = (unsigned char)(height & 0xFF);
    header[5] = (unsigned char)((height >> 8) & 0xFF);
    fwrite(header, 1, 14, fp);

    // Write the image data
    fwrite(data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);
}

// Embed a secret message in an image
void embed_message(unsigned char *data, int width, int height, char *msg) {
    int len = strlen(msg);
    if (len > MAX_MSG_LEN) {
        fprintf(stderr, "Error: message is too long\n");
        return;
    }

    // Embed the length of the message in the first pixel of the image
    data[0] = (unsigned char)(len & 0xFF);
    data[1] = (unsigned char)((len >> 8) & 0xFF);

    // Embed the message in the remaining pixels of the image
    int i, j, k;
    for (i = 0, k = 2; i < len; i++) {
        for (j = 0; j < 8; j++, k++) {
            // Get the bit from the message
            int bit = (msg[i] >> j) & 1;

            // Set the bit in the image data
            data[k] = (data[k] & 0xFE) | bit;
        }
    }
}

// Extract a secret message from an image
char *extract_message(unsigned char *data, int width, int height) {
    // Get the length of the message from the first pixel of the image
    int len = data[0] + (data[1] << 8);

    // Allocate memory for the message
    char *msg = malloc(len + 1);
    if (msg == NULL) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return NULL;
    }

    // Extract the message from the remaining pixels of the image
    int i, j, k;
    for (i = 0, k = 2; i < len; i++) {
        for (j = 0; j < 8; j++, k++) {
            // Get the bit from the image data
            int bit = data[k] & 1;

            // Set the bit in the message
            msg[i] |= (bit << j);
        }
    }

    // Terminate the message with a null character
    msg[len] = '\0';

    return msg;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message> <encode/decode>\n", argv[0]);
        return 1;
    }

    // Read the input image
    int width, height;
    unsigned char *data = read_image(argv[1], &width, &height);
    if (data == NULL) {
        return 1;
    }

    // Encode or decode the message
    if (strcmp(argv[4], "encode") == 0) {
        embed_message(data, width, height, argv[3]);
    } else if (strcmp(argv[4], "decode") == 0) {
        char *msg = extract_message(data, width, height);
        if (msg == NULL) {
            return 1;
        }
        printf("%s\n", msg);
        free(msg);
    } else {
        fprintf(stderr, "Error: invalid operation\n");
        return 1;
    }

    // Write the output image
    write_image(argv[2], data, width, height);

    // Free the memory allocated for the image data
    free(data);

    return 0;
}