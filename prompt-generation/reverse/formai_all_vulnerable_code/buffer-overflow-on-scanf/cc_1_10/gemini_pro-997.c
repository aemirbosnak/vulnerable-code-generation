//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store the compressed data
typedef struct {
    unsigned char* data;  // Pointer to the compressed data
    size_t size;      // Size of the compressed data
} compressed_data;

// Define the compression algorithm
compressed_data* compress(const char* input) {
    size_t input_length = strlen(input);

    // Allocate memory for the compressed data
    compressed_data* compressed = malloc(sizeof(compressed_data));
    if (compressed == NULL) {
        return NULL;
    }
    compressed->data = malloc(input_length + 1);
    if (compressed->data == NULL) {
        free(compressed);
        return NULL;
    }

    // Initialize the compressed data
    compressed->size = 0;

    // Compress the input data
    unsigned char current_byte = input[0];
    unsigned char count = 1;
    for (size_t i = 1; i < input_length; i++) {
        if (input[i] == current_byte) {
            count++;
        } else {
            compressed->data[compressed->size++] = current_byte;
            compressed->data[compressed->size++] = count;
            current_byte = input[i];
            count = 1;
        }
    }
    compressed->data[compressed->size++] = current_byte;
    compressed->data[compressed->size++] = count;

    return compressed;
}

// Define the decompression algorithm
char* decompress(const compressed_data* compressed) {
    size_t decompressed_length = 0;

    // Calculate the decompressed length
    for (size_t i = 0; i < compressed->size; i += 2) {
        decompressed_length += compressed->data[i + 1];
    }

    // Allocate memory for the decompressed data
    char* decompressed = malloc(decompressed_length + 1);
    if (decompressed == NULL) {
        return NULL;
    }

    // Decompress the data
    size_t decompressed_index = 0;
    for (size_t i = 0; i < compressed->size; i += 2) {
        unsigned char byte = compressed->data[i];
        unsigned char count = compressed->data[i + 1];
        for (unsigned char j = 0; j < count; j++) {
            decompressed[decompressed_index++] = byte;
        }
    }
    decompressed[decompressed_length] = '\0';

    return decompressed;
}

// Define the main function
int main() {
    // Get the input string from the user
    char input[1024];
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compressed_data* compressed = compress(input);
    if (compressed == NULL) {
        printf("Error compressing the string.\n");
        return 1;
    }

    // Print the compressed data
    printf("Compressed data:\n");
    for (size_t i = 0; i < compressed->size; i++) {
        printf("%02x ", compressed->data[i]);
    }
    printf("\n");

    // Decompress the compressed data
    char* decompressed = decompress(compressed);
    if (decompressed == NULL) {
        printf("Error decompressing the data.\n");
        return 1;
    }

    // Print the decompressed data
    printf("Decompressed data: %s\n", decompressed);

    // Free the memory allocated for the compressed and decompressed data
    free(compressed->data);
    free(compressed);
    free(decompressed);

    return 0;
}