//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

// Function to compress the input string using RLE compression algorithm
unsigned char* rleCompress(unsigned char* data, int inputSize, int* outputSize)
{
    // Initialize output buffer to twice the size of input buffer
    unsigned char* output = malloc(sizeof(unsigned char) * inputSize * 2);

    // Initialize start and end index of the current sequence with the first value in the buffer
    int count = 1;
    int currentIndex = 0;
    int outputIndex = 0;
    unsigned char currentChar = data[0];

    // Traverse the input buffer and compress the data using RLE algorithm
    while (currentIndex <= inputSize)
    {
        // Increment count if consecutive characters match
        if (data[currentIndex] == currentChar)
        {
            count++;
        }
        else // Write the current sequence to the output buffer and reset the count
        {
            output[outputIndex++] = count;
            output[outputIndex++] = currentChar;
            count = 1;
            currentChar = data[currentIndex];
        }
        
        currentIndex++;
    }

    // Set outputSize variable to the actual size of the compressed data
    *outputSize = outputIndex;

    // Return the compressed data
    return output;
}

// Function to decompress the input buffer using RLE compression algorithm
unsigned char* rleDecompress(unsigned char* data, int inputSize, int* outputSize)
{
    // Initialize output buffer to half the size of input buffer
    unsigned char* output = malloc(sizeof(unsigned char) * inputSize / 2);

    // Traverse the input buffer and decompress the data using RLE algorithm
    for (int i = 0, j = 0; i < inputSize; i += 2)
    {
        // Extract the count and character from input buffer
        int count = data[i];
        unsigned char currentChar = data[i + 1];

        // Write the current sequence of characters to the output buffer
        for (int k = 0; k < count; k++)
        {
            output[j++] = currentChar;
        }
    }

    // Set outputSize variable to the actual size of the decompressed data
    *outputSize = inputSize * 2;

    // Return the decompressed data
    return output;
}

int main()
{
    unsigned char inputBuffer[MAX_BUFFER_SIZE];
    unsigned char* compressedBuffer;
    unsigned char* decompressedBuffer;
    int inputSize;
    int compressedSize;
    int decompressedSize;

    // Read input string from user
    printf("Enter input string: ");
    scanf("%s", inputBuffer);
    inputSize = strlen(inputBuffer);

    // Compress the input string using RLE compression algorithm
    compressedBuffer = rleCompress(inputBuffer, inputSize, &compressedSize);

    // Decompress the compressed string using RLE compression algorithm
    decompressedBuffer = rleDecompress(compressedBuffer, compressedSize, &decompressedSize);

    // Print the original input string and decompressed string to verify if the compression is lossless
    printf("Original string: %s\n", inputBuffer);
    printf("Decompressed string: %s\n", decompressedBuffer);

    // Free the memory allocated to buffers
    free(compressedBuffer);
    free(decompressedBuffer);

    return 0;
}