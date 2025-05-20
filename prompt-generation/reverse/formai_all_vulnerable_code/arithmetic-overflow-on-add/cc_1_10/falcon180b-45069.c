//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding (RLE)
void compress(char* input, char* output) {
    int i, j, count = 1;

    // Iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // If current character is same as previous, increment count
        if (i > 0 && input[i] == input[i - 1]) {
            count++;
        } else {
            // Otherwise, write count and character to output and reset count
            output[j++] = count;
            output[j++] = input[i];
            count = 1;
        }
    }

    // Add end marker to indicate end of string
    output[j++] = 0;

    // Terminate output string
    output[j] = '\0';
}

// Function to decompress the input string using RLE
void decompress(char* input, char* output) {
    int i, j, count = 0;

    // Iterate through the input string
    for (i = 0; input[i]!= 0; i += 2) {
        // If current character is not end marker, write it multiple times
        if (input[i]!= 0) {
            for (j = 0; j < input[i]; j++) {
                output[count++] = input[i + 1];
            }
        } else {
            // Otherwise, move to next character
            i++;
        }
    }

    // Terminate output string
    output[count] = '\0';
}

int main() {
    char input[1000], output[1000];

    // Get input string from user
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress input string
    compress(input, output);

    // Print compressed string
    printf("Compressed string: %s\n", output);

    // Decompress compressed string back to original string
    decompress(output, input);

    // Print decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}