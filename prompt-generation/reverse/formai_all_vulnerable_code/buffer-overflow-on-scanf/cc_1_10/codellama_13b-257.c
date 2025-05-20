//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: automated
// C Compression Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input data
void compress(char* input, int length) {
    // Initialize variables
    char* output = malloc(length * sizeof(char));
    int i, j, count = 1;

    // Iterate over the input data
    for (i = 0; i < length; i++) {
        // Check if the current character is the same as the previous character
        if (input[i] == input[i - 1]) {
            // If it is, increment the count
            count++;
        } else {
            // If it is not, write the current character and its count to the output
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
    }

    // Write the final character and its count to the output
    output[j++] = input[i];
    output[j++] = count + '0';

    // Print the compressed data
    printf("Compressed data: ");
    for (i = 0; i < j; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    // Free the output array
    free(output);
}

// Function to decompress the input data
void decompress(char* input, int length) {
    // Initialize variables
    char* output = malloc(length * sizeof(char));
    int i, j, count = 1;

    // Iterate over the input data
    for (i = 0; i < length; i++) {
        // Check if the current character is a digit
        if (input[i] >= '0' && input[i] <= '9') {
            // If it is, read the count and repeat the previous character that many times
            count = input[i] - '0';
            for (j = 0; j < count; j++) {
                output[j] = input[i - 1];
            }
        } else {
            // If it is not, write the current character to the output
            output[j++] = input[i];
        }
    }

    // Print the decompressed data
    printf("Decompressed data: ");
    for (i = 0; i < j; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    // Free the output array
    free(output);
}

int main() {
    // Initialize variables
    char input[100];
    int length;

    // Get the input data
    printf("Enter the data to be compressed: ");
    scanf("%s", input);

    // Compress the input data
    length = strlen(input);
    compress(input, length);

    // Decompress the input data
    decompress(input, length);

    return 0;
}