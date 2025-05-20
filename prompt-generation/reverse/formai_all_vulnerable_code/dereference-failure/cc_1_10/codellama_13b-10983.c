//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: complex
// C Compression Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
void compress(char *input, char *output) {
    int i, j, k;
    char current_char;
    int current_count = 1;

    // Initialize the output buffer
    memset(output, 0, strlen(input) * 2 + 1);

    // Iterate through the input string
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        current_char = input[i];

        // Check if the current character is the same as the previous one
        if (input[i] == input[i - 1]) {
            // Increment the count
            current_count++;
        } else {
            // Output the current character and count
            output[j++] = current_char;
            output[j++] = current_count + '0';

            // Reset the count
            current_count = 1;
        }
    }

    // Output the last character and count
    output[j++] = current_char;
    output[j++] = current_count + '0';
}

// Function to decompress a string
void decompress(char *input, char *output) {
    int i, j, k;
    char current_char;
    int current_count = 0;

    // Initialize the output buffer
    memset(output, 0, strlen(input) / 2 + 1);

    // Iterate through the input string
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        current_char = input[i];

        // Check if the current character is a digit
        if (current_char >= '0' && current_char <= '9') {
            // Convert the digit to an integer
            current_count = current_char - '0';

            // Skip the next character
            i++;
        } else {
            // Output the current character the specified number of times
            for (k = 0; k < current_count; k++) {
                output[j++] = current_char;
            }
        }
    }
}

int main() {
    char input[] = "aaabbbcccddd";
    char output[256];

    // Compress the input string
    compress(input, output);
    printf("Compressed string: %s\n", output);

    // Decompress the output string
    decompress(output, input);
    printf("Decompressed string: %s\n", input);

    return 0;
}