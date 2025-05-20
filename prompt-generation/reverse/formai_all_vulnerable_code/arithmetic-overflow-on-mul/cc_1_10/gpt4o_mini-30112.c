//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024
#define IMAGE_FILE_HEADER_SIZE 54

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

typedef struct {
    int width;
    int height;
    RGB *pixels;
} Image;

// Function to read BMP file
Image* read_bmp(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open image file: %s\n", filename);
        return NULL;
    }

    // Read BMP file header
    unsigned char bmp_header[IMAGE_FILE_HEADER_SIZE];
    fread(bmp_header, sizeof(unsigned char), IMAGE_FILE_HEADER_SIZE, file);

    // Extract width and height from header
    int width = *(int*)&bmp_header[18];
    int height = *(int*)&bmp_header[22];

    // Allocate space for pixels
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (RGB*)malloc(width * height * sizeof(RGB));

    // Move file pointer to the beginning of the pixel data
    fseek(file, 54, SEEK_SET);
    fread(image->pixels, sizeof(RGB), width * height, file);
    fclose(file);

    return image;
}

// Function to write BMP file
void write_bmp(const char* filename, Image* image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to create image file: %s\n", filename);
        return;
    }

    // Write BMP file header
    unsigned char bmp_header[IMAGE_FILE_HEADER_SIZE] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 
        54, 0, 0, 0, 40, 0, 0, 0,
        image->width & 0xFF, (image->width >> 8) & 0xFF, (image->width >> 16) & 0xFF, (image->width >> 24) & 0xFF,
        image->height & 0xFF, (image->height >> 8) & 0xFF, (image->height >> 16) & 0xFF, (image->height >> 24) & 0xFF,
        1, 0, 24, 0 
    };

    // Calculate file size
    int filesize = IMAGE_FILE_HEADER_SIZE + 3 * image->width * image->height;
    bmp_header[2] = filesize & 0xFF;
    bmp_header[3] = (filesize >> 8) & 0xFF;
    bmp_header[4] = (filesize >> 16) & 0xFF;
    bmp_header[5] = (filesize >> 24) & 0xFF;

    fwrite(bmp_header, sizeof(unsigned char), IMAGE_FILE_HEADER_SIZE, file);
    fwrite(image->pixels, sizeof(RGB), image->width * image->height, file);
    fclose(file);
}

// Function to encode message into the image
void encode_message(Image* image, const char* message) {
    int msg_length = strlen(message);
    // Generate a mask to hide the message
    for (int i = 0; i < msg_length; i++) {
        // Simple LSB method
        int pixel_index = i;
        image->pixels[pixel_index].red &= 0xFE;  // Clear LSB
        image->pixels[pixel_index].red |= (message[i] & 0x01); // Store LSB of message
    }
}

// Function to decode the message from the image
void decode_message(Image* image) {
    char decoded_message[MAX_SIZE] = {0};
    for (int i = 0; i < MAX_SIZE; i++) {
        decoded_message[i] = (image->pixels[i].red & 0x01); // Get LSB
        if (decoded_message[i] == '\0') {
            break;
        }
    }
    printf("Decoded Message: %s\n", decoded_message);
}

// Main Function in Cyberpunk Style
int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.bmp> <output_image.bmp> <message>\n", argv[0]);
        return 1;
    }

    printf("Initializing Steganographic Protocol...\n");

    const char* input_image = argv[1];
    const char* output_image = argv[2];
    const char* secret_message = argv[3];

    // Read the image file
    Image* image = read_bmp(input_image);
    if (!image) {
        return 1;
    }

    printf("Image loaded successfully, dimensions: %dx%d.\n", image->width, image->height);

    // Encode message
    printf("Encoding message into pixels...\n");
    encode_message(image, secret_message);

    // Write the modified image file
    write_bmp(output_image, image);

    printf("Encoded message saved into %s.\n", output_image);

    // Decode message
    printf("Decoding message from the art...\n");
    decode_message(image);

    // Clean up
    free(image->pixels);
    free(image);
    printf("Steganographic Protocol Completed. The city sleeps...\n");

    return 0;
}