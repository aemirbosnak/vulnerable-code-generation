//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define HEADER_SIZE 54
#define FILE_SIZE_OFFSET 2
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define BITS_PER_PIXEL_OFFSET 28

// Function prototypes
void hide_message(char *image_path, char *message);
char *extract_message(char *image_path);

// Main function
int main() {
    // Hide message in image
    hide_message("image.bmp", "Hello, World!");

    // Extract message from image
    char *message = extract_message("image.bmp");

    printf("Extracted message: %s\n", message);

    free(message);
    return 0;
}

// Function to hide message in image
void hide_message(char *image_path, char *message) {
    // Read image file
    FILE *file = fopen(image_path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open %s\n", image_path);
        exit(1);
    }

    // Get file size
    fseek(file, FILE_SIZE_OFFSET, SEEK_SET);
    int file_size;
    fread(&file_size, sizeof(int), 1, file);

    // Get width
    fseek(file, WIDTH_OFFSET, SEEK_SET);
    int width;
    fread(&width, sizeof(int), 1, file);

    // Get height
    fseek(file, HEIGHT_OFFSET, SEEK_SET);
    int height;
    fread(&height, sizeof(int), 1, file);

    // Get bits per pixel
    fseek(file, BITS_PER_PIXEL_OFFSET, SEEK_SET);
    short bits_per_pixel;
    fread(&bits_per_pixel, sizeof(short), 1, file);

    // Allocate memory for image data
    fseek(file, HEADER_SIZE, SEEK_SET);
    unsigned char *image_data = (unsigned char *)malloc(file_size - HEADER_SIZE + 1);
    fread(image_data, file_size - HEADER_SIZE, 1, file);

    // Get message length
    int message_length = strlen(message);

    // Convert message length to binary
    char *binary_length = (char *)malloc(32 + 1);
    int binary_index = 31;
    for (int i = 0; i < 32; i++) {
        binary_length[binary_index--] = (message_length & 1) + '0';
        message_length >>= 1;
    }
    binary_length[32] = '\0';

    // Hide message length in image
    int data_index = 0;
    for (int i = 0; i < 32; i += 2) {
        image_data[data_index] &= ~3; // Set last two bits to 0
        image_data[data_index] |= (binary_length[i] - '0') << 1; // Set second-to-last bit to first bit of binary_length[i]
        image_data[data_index] |= (binary_length[i + 1] - '0'); // Set last bit to second bit of binary_length[i]
        data_index++;
    }

    // Hide message in image
    data_index = 32 / bits_per_pixel;
    int current_bit = 0;
    for (int i = 0; i < message_length; i++) {
        for (int j = 7; j >= 0; j--) {
            if (current_bit >= bits_per_pixel) {
                current_bit = 0;
                data_index++;
            }
            image_data[data_index] &= ~(1 << (current_bit % bits_per_pixel)); // Set current bit to 0
            image_data[data_index] |= ((message[i] >> j) & 1) << (current_bit % bits_per_pixel); // Set current bit to j-th bit of message[i]
            current_bit++;
        }
    }

    // Write image data back to file
    fseek(file, HEADER_SIZE, SEEK_SET);
    fwrite(image_data, file_size - HEADER_SIZE, 1, file);

    // Free memory
    free(image_data);
    free(binary_length);

    // Close file
    fclose(file);

    printf("Message hidden in %s\n", image_path);
}

// Function to extract message from image
char *extract_message(char *image_path) {
    // Read image file
    FILE *file = fopen(image_path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open %s\n", image_path);
        exit(1);
    }

    // Get file size
    fseek(file, FILE_SIZE_OFFSET, SEEK_SET);
    int file_size;
    fread(&file_size, sizeof(int), 1, file);

    // Get width
    fseek(file, WIDTH_OFFSET, SEEK_SET);
    int width;
    fread(&width, sizeof(int), 1, file);

    // Get height
    fseek(file, HEIGHT_OFFSET, SEEK_SET);
    int height;
    fread(&height, sizeof(int), 1, file);

    // Get bits per pixel
    fseek(file, BITS_PER_PIXEL_OFFSET, SEEK_SET);
    short bits_per_pixel;
    fread(&bits_per_pixel, sizeof(short), 1, file);

    // Allocate memory for image data
    fseek(file, HEADER_SIZE, SEEK_SET);
    unsigned char *image_data = (unsigned char *)malloc(file_size - HEADER_SIZE + 1);
    fread(image_data, file_size - HEADER_SIZE, 1, file);

    // Extract message length from image
    char binary_length[32 + 1];
    int data_index = 0;
    for (int i = 0; i < 32; i += 2) {
        binary_length[i] = (image_data[data_index] >> 1) & 1;
        binary_length[i + 1] = image_data[data_index] & 1;
        data_index++;
    }
    binary_length[32] = '\0';

    // Convert binary length to integer
    int message_length = 0;
    for (int i = 0; i < 32; i++) {
        message_length <<= 1;
        message_length += binary_length[i];
    }

    // Allocate memory for message
    char *message = (char *)malloc(message_length + 1);

    // Extract message from image
    int current_bit = 0;
    data_index = 32 / bits_per_pixel;
    for (int i = 0; i < message_length; i++) {
        message[i] = 0;
        for (int j = 7; j >= 0; j--) {
            if (current_bit >= bits_per_pixel) {
                current_bit = 0;
                data_index++;
            }
            message[i] |= ((image_data[data_index] >> (current_bit % bits_per_pixel)) & 1) << j; // Set j-th bit of message[i] to current bit
            current_bit++;
        }
    }
    message[message_length] = '\0';

    // Free memory
    free(image_data);

    // Close file
    fclose(file);

    return message;
}