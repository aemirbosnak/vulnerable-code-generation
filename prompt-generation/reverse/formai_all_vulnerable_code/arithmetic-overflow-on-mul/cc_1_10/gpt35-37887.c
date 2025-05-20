//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct Image {
    char* pixels;
    int width;
    int height;
    int bpp; // Bits per pixel
} Image;

// Function to read the BMP file into an Image struct
Image read_bmp(char* filename) {
    Image img;

    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening BMP file '%s'\n", filename);
        exit(1);
    }

    // Read BMP header
    char header[54];
    fread(header, sizeof(char), 54, fp);

    // Parse BMP header
    img.width = *(int*)&header[18];
    img.height = *(int*)&header[22];
    img.bpp = *(short*)&header[28];

    // Allocate memory for pixels
    int row_size = ((img.width * img.bpp + 31) / 32) * 4;
    int pixel_data_size = row_size * img.height;
    img.pixels = (char*)malloc(pixel_data_size);
    if (!img.pixels) {
        fprintf(stderr, "Error allocating memory for pixels\n");
        exit(1);
    }

    // Read pixel data
    fseek(fp, *(int*)&header[10], SEEK_SET);
    fread(img.pixels, sizeof(char), pixel_data_size, fp);

    fclose(fp);

    return img;
}

// Function to write the Image struct to a BMP file
void write_bmp(Image img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    // Write BMP header
    char header[54] = {
        'B', 'M', // Magic number
        0, 0, 0, 0, // File size (will be filled later)
        0, 0, 0, 0, // Reserved
        54, 0, 0, 0, // Data offset
        40, 0, 0, 0, // Info header size
        0, 0, 0, 0, // Image width (will be filled later)
        0, 0, 0, 0, // Image height (will be filled later)
        1, 0, // Number of color planes
        img.bpp, 0, // Bits per pixel
        0, 0, 0, 0, // Compression method
        0, 0, 0, 0, // Image size (will be filled later)
        0, 0, 0, 0, // Horizontal resolution
        0, 0, 0, 0, // Vertical resolution
        0, 0, 0, 0, // Number of colors
        0, 0, 0, 0, // Important colors
    };
    *(int*)&header[2] = 54 + img.width * img.height * img.bpp / 8;
    *(int*)&header[18] = img.width;
    *(int*)&header[22] = img.height;
    *(int*)&header[34] = img.width * img.height * img.bpp / 8;
    fwrite(header, sizeof(char), 54, fp);

    // Write pixel data
    int row_size = ((img.width * img.bpp + 31) / 32) * 4;
    int pixel_data_size = row_size * img.height;
    fwrite(img.pixels, sizeof(char), pixel_data_size, fp);

    fclose(fp);
}

// Function to hide a message in the image
void hide_message(Image* img, char* message) {
    int message_len = strlen(message);
    int pixel_data_size = ((img->width * img->bpp + 31) / 32) * 4 * img->height;
    int unchanged_pixels;

    int i, j, k = 0;
    for (i = 0; i < pixel_data_size && k < message_len; i++) {
        // Skip padding bytes
        if ((i + 1) % ((img->width * img->bpp + 7) / 8) == 0) {
            continue;
        }

        // Get the current pixel value
        unsigned char pixel = img->pixels[i];

        if (k == 0) {
            // Store message length in first pixel
            unsigned char message_len_byte = message_len & 0xff;
            pixel = (pixel & 0xfe) | ((message_len_byte >> 7) & 0x01);
        } else if (k - 1 < message_len) {
            // Store message bytes in subsequent pixels
            unsigned char message_byte = message[k - 1];
            pixel = (pixel & 0xfe) | ((message_byte >> 7) & 0x01);
        }

        // Update the pixel in the image
        img->pixels[i] = pixel;

        // Keep track of the number of pixels that have not been changed
        if (img->pixels[i] == pixel) {
            unchanged_pixels++;
        } else {
            unchanged_pixels = 0;
        }

        // If we have run out of unchanged pixels, stop hiding the message
        if (unchanged_pixels > MAX_BUF_SIZE) {
            fprintf(stderr, "Error: not enough space to hide message\n");
            exit(1);
        }

        k++;
    }

    // If there are remaining bytes of the message that could not be hidden, show error
    if (k < message_len) {
        fprintf(stderr, "Error: not enough space to hide message\n");
        exit(1);
    }
}

// Function to retrieve a hidden message from the image
char* retrieve_message(Image img) {
    int pixel_data_size = ((img.width * img.bpp + 31) / 32) * 4 * img.height;
    int message_len = 0;

    // Extract message length from first pixel
    unsigned char message_len_byte = img.pixels[0] & 0x01;
    message_len += (message_len_byte << 7);

    int i, k = 0;
    char message_buf[MAX_BUF_SIZE];
    for (i = 0; i < pixel_data_size && k < message_len; i++) {
        // Skip padding bytes
        if ((i + 1) % ((img.width * img.bpp + 7) / 8) == 0) {
            continue;
        }

        // Get the current pixel value
        unsigned char pixel = img.pixels[i];

        if (k > 0) {
            // Extract next byte of message
            unsigned char message_byte = pixel & 0x01;
            message_buf[k - 1] = (message_buf[k - 1] << 1) | message_byte;
        }

        k++;
    }

    // If there are fewer than message_len bytes in the message, show error
    if (k - 1 < message_len) {
        fprintf(stderr, "Error: message was not found in the image\n");
        exit(1);
    }

    // Allocate memory for the message buffer
    char* message = (char*)malloc(message_len + 1);
    if (!message) {
        fprintf(stderr, "Error allocating memory for message\n");
        exit(1);
    }

    // Copy the message into the newly allocated buffer and null terminate it
    strncpy(message, message_buf, message_len);
    message[message_len] = '\0';

    return message;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <message>\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* message = argv[3];

    Image img = read_bmp(input_file);

    hide_message(&img, message);

    write_bmp(img, output_file);

    printf("Message hidden successfully in '%s'\n", output_file);

    Image new_img = read_bmp(output_file);

    char* retrieved_message = retrieve_message(new_img);

    printf("Retrieved message: '%s'\n", retrieved_message);

    return 0;
}