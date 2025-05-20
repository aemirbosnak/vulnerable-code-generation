//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000000

// Function to compress the input data using Run Length Encoding (RLE)
void compress_rle(char* input_data, int input_size, char* output_data) {
    int i = 0; // Index for input data
    int j = 0; // Index for output data
    int count = 1; // Count of consecutive characters

    while (i < input_size) {
        if (i + count < input_size && input_data[i] == input_data[i + count]) {
            count++;
        } else {
            output_data[j++] = input_data[i];
            output_data[j++] = count;
            count = 1;
        }
        i++;
    }

    output_data[j++] = input_data[i - 1];
    output_data[j++] = count;

    output_data[j] = '\0'; // Null terminate the output string
}

// Function to decompress the compressed data using RLE
void decompress_rle(char* input_data, int input_size, char* output_data) {
    int i = 0; // Index for input data
    int j = 0; // Index for output data

    while (i < input_size) {
        int count = input_data[i++];

        while (count-- > 0 && i < input_size) {
            output_data[j++] = input_data[i++];
        }

        if (j >= MAX_BUFFER_SIZE) {
            printf("Error: Output buffer overflow\n");
            exit(1);
        }
    }

    output_data[j] = '\0'; // Null terminate the output string
}

int main() {
    char input_data[MAX_BUFFER_SIZE];
    char compressed_data[MAX_BUFFER_SIZE];
    char decompressed_data[MAX_BUFFER_SIZE];

    // Read input data from user
    printf("Enter input data: ");
    fgets(input_data, MAX_BUFFER_SIZE, stdin);

    // Compress the input data using RLE
    compress_rle(input_data, strlen(input_data), compressed_data);

    // Decompress the compressed data using RLE
    decompress_rle(compressed_data, strlen(compressed_data), decompressed_data);

    // Print the original and compressed/decompressed data
    printf("Original data: %s\n", input_data);
    printf("Compressed data: %s\n", compressed_data);
    printf("Decompressed data: %s\n", decompressed_data);

    return 0;
}