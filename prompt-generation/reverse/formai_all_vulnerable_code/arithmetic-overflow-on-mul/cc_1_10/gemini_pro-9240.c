//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read the image data from the file
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, 1, 54, file);

    // Get the width and height of the image
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(data, 1, *width * *height * 3, file);

    // Close the file
    fclose(file);

    return data;
}

// Write the image data to the file
void write_image(char *filename, unsigned char *data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header information
    unsigned char header[54];
    memcpy(header, data, 54);

    // Write the image data
    fwrite(data + 54, 1, width * height * 3, file);

    // Close the file
    fclose(file);
}

// Embed the message in the image data
void embed_message(unsigned char *data, int width, int height, char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    // Embed the message length in the first pixel
    data[0] = (data[0] & 0xF0) | (message_length & 0x0F);

    // Embed the message in the remaining pixels
    for (int i = 1; i < width * height * 3 && message_index < message_length; i++) {
        // Embed the next character in the least significant bit of the pixel
        data[i] = (data[i] & 0xFE) | ((message[message_index] >> (7 - (i % 3))) & 0x01);
        message_index++;
    }
}

// Extract the message from the image data
char *extract_message(unsigned char *data, int width, int height) {
    int message_length = data[0] & 0x0F;
    char *message = malloc(message_length + 1);
    int message_index = 0;

    // Extract the message from the remaining pixels
    for (int i = 1; i < width * height * 3 && message_index < message_length; i++) {
        // Extract the next character from the least significant bit of the pixel
        message[message_index] = (message[message_index] << 1) | (data[i] & 0x01);
        message_index++;
    }

    // Terminate the message with a null character
    message[message_length] = '\0';

    return message;
}

// Print the image data
void print_image_data(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        printf("%02X ", data[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

int main() {
    // Read the image data from the file
    int width, height;
    unsigned char *data = read_image("image.bmp", &width, &height);
    if (data == NULL) {
        return 1;
    }

    // Embed the message in the image data
    char *message = "Hello, world!";
    embed_message(data, width, height, message);

    // Write the image data to the file
    write_image("stego_image.bmp", data, width, height);

    // Free the image data
    free(data);

    // Read the image data from the stego image
    data = read_image("stego_image.bmp", &width, &height);
    if (data == NULL) {
        return 1;
    }

    // Extract the message from the image data
    char *extracted_message = extract_message(data, width, height);

    // Print the extracted message
    printf("Extracted message: %s\n", extracted_message);

    // Free the extracted message
    free(extracted_message);

    // Free the image data
    free(data);

    return 0;
}