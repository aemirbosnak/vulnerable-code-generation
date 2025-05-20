//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the data to be hidden
unsigned char* read_data(FILE* content_file, long* size) {
    unsigned char* buffer = NULL;
    size_t result;

    // Read file size
    fseek(content_file, 0, SEEK_END);
    *size = ftell(content_file);
    rewind(content_file);

    // Allocate memory
    buffer = (unsigned char *) malloc(sizeof(unsigned char) * (*size));
    if (buffer == NULL) { 
        return NULL;
    }

    // Read content from file
    result = fread(buffer, 1, *size, content_file);
    if (result != *size) {
        free(buffer);
        return NULL;
    }

    return buffer;
}

// Function to hide the data in the image
void hide_data(char* image_filename, char* new_image_filename, unsigned char* data, long data_size) {
    FILE* image_file = NULL;
    FILE* new_image_file = NULL;

    // Open the image file
    image_file = fopen(image_filename, "rb");
    if (image_file == NULL) {
        return;
    }

    // Create the new image file
    new_image_file = fopen(new_image_filename, "wb");
    if (new_image_file == NULL) {
        fclose(image_file);
        return;
    }

    // Copy header from image file to new image file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    fwrite(header, sizeof(unsigned char), 54, new_image_file);

    // Write the data size to the image file
    int i;
    for (i = 0; i < 4; i++) {
        header[i + 54] = (unsigned char) (data_size >> (i * 8));
    }
    fwrite(header, sizeof(unsigned char), 4, new_image_file);

    // Write the data to the image file
    for (i = 0; i < data_size; i++) {
        fread(header, sizeof(unsigned char), 1, image_file);
        header[0] = (header[0] & 0xFE) | ((data[i] >> 7) & 0x01);
        header[1] = (header[1] & 0xFE) | ((data[i] >> 6) & 0x01);
        header[2] = (header[2] & 0xFE) | ((data[i] >> 5) & 0x01);
        header[3] = (header[3] & 0xFE) | ((data[i] >> 4) & 0x01);
        header[4] = (header[4] & 0xFE) | ((data[i] >> 3) & 0x01);
        header[5] = (header[5] & 0xFE) | ((data[i] >> 2) & 0x01);
        header[6] = (header[6] & 0xFE) | ((data[i] >> 1) & 0x01);
        header[7] = (header[7] & 0xFE) | (data[i] & 0x01);

        fwrite(header, sizeof(unsigned char), 1, new_image_file);
    }

    // Copy the remaining content from the image file to the new image file
    while (1) {
        int read_bytes = fread(header, sizeof(unsigned char), 1, image_file);
        if (read_bytes == 0) {
            break;
        }
        fwrite(header, sizeof(unsigned char), 1, new_image_file);
    }

    fclose(image_file);
    fclose(new_image_file);
}

// Function to retrieve the hidden data from the image
unsigned char* retrieve_data(char* image_filename, long* size) {
    FILE* image_file = NULL;
    unsigned char* buffer = NULL;

    // Open the image file
    image_file = fopen(image_filename, "rb");
    if (image_file == NULL) {
        return NULL;
    }

    // Read the data size from the image file
    unsigned char size_buffer[4];
    fread(size_buffer, sizeof(unsigned char), 4, image_file);
    *size = (size_buffer[0] & 0xFF) | ((size_buffer[1] << 8) & 0xFF00) | ((size_buffer[2] << 16) & 0xFF0000) | ((size_buffer[3] << 24) & 0xFF000000);

    // Allocate memory
    buffer = (unsigned char *) malloc(sizeof(unsigned char) * (*size));
    if (buffer == NULL) { 
        return NULL;
    }

    // Read the data from the image file
    int i;
    unsigned char byte = 0;
    for (i = 0; i < *size; i++) {
        int bit_index;
        for (bit_index = 0; bit_index < 8; bit_index++) {
            fread(&byte, sizeof(unsigned char), 1, image_file);
            buffer[i] |= ((byte & 0x01) << bit_index);
        }
    }

    fclose(image_file);

    return buffer;
}

int main() {
    char* image_filename = "input.bmp";
    char* new_image_filename = "output.bmp";
    char* data_filename = "secret.txt";

    // Read data from file
    FILE* content_file = fopen(data_filename, "rb");
    if (content_file == NULL) {
        return 1;
    }
    long data_size = 0;
    unsigned char* data_buffer = read_data(content_file, &data_size);
    fclose(content_file);

    // Hide data in image
    hide_data(image_filename, new_image_filename, data_buffer, data_size);

    // Retrieve data from image
    long retrieved_size = 0;
    unsigned char* retrieved_data = retrieve_data(new_image_filename, &retrieved_size);

    // Print retrieved data
    printf("Retrieved data: %s\n", retrieved_data);

    // Free resources
    free(data_buffer);
    free(retrieved_data);

    return 0;
}