//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compress data using a basic run-length encoding algorithm
void compress(const char *input, char *output) {
    int len = strlen(input);
    int count = 1;
    int outputIndex = 0;

    for (int i = 0; i < len; i++) {
        // If the next character is the same as the current one, increment the count
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            // Write the character and its count to the output
            outputIndex += snprintf(output + outputIndex, BUFFER_SIZE - outputIndex, "%d%c", count, input[i]);
            count = 1; // Reset count for the new character
        }
    }
}

// Function to decompress data compressed with the above function
void decompress(const char *input, char *output) {
    int outputIndex = 0;
    int count = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        // If we encounter a digit, we can have the count
        if (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0'); // Build the complete count
        } else {
            // Write the character count times to the output
            for (int j = 0; j < count; j++) {
                output[outputIndex++] = input[i];
            }
            count = 0; // Reset count for the next character
        }
    }
    output[outputIndex] = '\0'; // Null terminate the output
}

// Function to read input from a file
void readFile(const char *filename, char *buffer, size_t size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }
    fread(buffer, sizeof(char), size - 1, file);
    buffer[size - 1] = '\0'; // Null terminate
    fclose(file);
}

// Function to write output to a file
void writeFile(const char *filename, const char *buffer) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("File opening failed");
        return;
    }
    fprintf(file, "%s", buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char inputBuffer[BUFFER_SIZE];
    char outputBuffer[BUFFER_SIZE];
    char decompressedBuffer[BUFFER_SIZE];
    
    // Read input from the file
    readFile(argv[1], inputBuffer, BUFFER_SIZE);
    
    // Compress the input data
    compress(inputBuffer, outputBuffer);
    printf("Compressed data: %s\n", outputBuffer);
    
    // Write compressed data to output file
    writeFile(argv[2], outputBuffer);
    
    // Decompress the data to verify
    decompress(outputBuffer, decompressedBuffer);
    printf("Decompressed data: %s\n", decompressedBuffer);
    
    // Verify if the decompressed data matches the original data
    if (strcmp(inputBuffer, decompressedBuffer) == 0) {
        printf("Decompression successful: Original and decompressed data match.\n");
    } else {
        printf("Decompression failed: Original and decompressed data do not match.\n");
    }
    
    return EXIT_SUCCESS;
}