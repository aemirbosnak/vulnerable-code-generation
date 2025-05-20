//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the maximum size of the image data
#define MAX_IMAGE_SIZE 1024 * 1024 * 3

// Define the maximum size of the secret message
#define MAX_SECRET_MESSAGE_SIZE 1024

// Define the bitmask for extracting the least significant bit of a byte
#define LSB_BITMASK 0x01

// Embed the secret message into the image data
int embed_secret_message(uint8_t *image_data, uint32_t image_size, uint8_t *secret_message, uint32_t secret_message_size) {
    // Check if the secret message is too large to be embedded in the image
    if (secret_message_size > (image_size - 1)) {
        return -1;
    }

    // Embed the secret message into the image data, one bit at a time
    for (uint32_t i = 0; i < secret_message_size; i++) {
        // Extract the least significant bit of the secret message
        uint8_t secret_message_bit = secret_message[i] & LSB_BITMASK;

        // Set the least significant bit of the image data to the secret message bit
        image_data[i + 1] = (image_data[i + 1] & ~LSB_BITMASK) | (secret_message_bit << 0);
    }

    return 0;
}

// Extract the secret message from the image data
int extract_secret_message(uint8_t *image_data, uint32_t image_size, uint8_t *secret_message, uint32_t secret_message_size) {
    // Extract the secret message from the image data, one bit at a time
    for (uint32_t i = 0; i < secret_message_size; i++) {
        // Extract the least significant bit of the image data
        uint8_t image_data_bit = image_data[i + 1] & LSB_BITMASK;

        // Set the least significant bit of the secret message to the image data bit
        secret_message[i] = (secret_message[i] & ~LSB_BITMASK) | (image_data_bit << 0);
    }

    return 0;
}

// Main function
int main() {
    // Load the image data from a file
    FILE *image_file = fopen("image.png", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Get the size of the image data
    fseek(image_file, 0, SEEK_END);
    uint32_t image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // Allocate memory for the image data
    uint8_t *image_data = malloc(image_size);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        fclose(image_file);
        return EXIT_FAILURE;
    }

    // Read the image data from the file
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // Get the secret message from the user
    printf("Enter the secret message: ");
    uint8_t secret_message[MAX_SECRET_MESSAGE_SIZE];
    scanf("%[^\n]", secret_message);

    // Get the size of the secret message
    uint32_t secret_message_size = strlen(secret_message);

    // Embed the secret message into the image data
    int embed_status = embed_secret_message(image_data, image_size, secret_message, secret_message_size);
    if (embed_status != 0) {
        perror("Error embedding secret message");
        free(image_data);
        return EXIT_FAILURE;
    }

    // Save the image data to a new file
    FILE *new_image_file = fopen("new_image.png", "wb");
    if (new_image_file == NULL) {
        perror("Error opening new image file");
        free(image_data);
        return EXIT_FAILURE;
    }

    // Write the image data to the new file
    fwrite(image_data, 1, image_size, new_image_file);
    fclose(new_image_file);

    // Free the memory allocated for the image data
    free(image_data);

    // Extract the secret message from the new image data
    uint8_t extracted_secret_message[MAX_SECRET_MESSAGE_SIZE];
    int extract_status = extract_secret_message(image_data, image_size, extracted_secret_message, secret_message_size);
    if (extract_status != 0) {
        perror("Error extracting secret message");
        return EXIT_FAILURE;
    }

    // Print the extracted secret message
    printf("Extracted secret message: %s\n", extracted_secret_message);

    return EXIT_SUCCESS;
}