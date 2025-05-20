//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding (RLE)
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If current character is same as previous character
        if (input[i] == input[i-1]) {
            count++; // Increment the count
        }
        else {
            // Add the compressed character and count to the output string
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
        i++;
    }

    // Add the last compressed character and count to the output string
    output[j++] = input[i-1];
    output[j++] = count + '0';
    output[j] = '\0';
}

// Function to decompress the input string using RLE
void decompress(char* input, char* output) {
    int i = 0, j = 0;

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If the current character is a compressed character
        if (input[i] >= '0' && input[i] <= '9') {
            int count = input[i] - '0';
            while (count > 0 && input[i+1]!= '\0') {
                output[j++] = input[i+1];
                count--;
                i++;
            }
        }
        else {
            // Add the decompressed character to the output string
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed String: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed String: %s\n", input);

    return 0;
}