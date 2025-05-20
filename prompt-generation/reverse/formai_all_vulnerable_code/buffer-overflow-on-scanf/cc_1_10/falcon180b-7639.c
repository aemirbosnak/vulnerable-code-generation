//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 100000

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If the current character is the same as the previous one, increment the count
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Otherwise, write the count and the character to the output string
            output[j++] = count + '0';
            output[j++] = input[i];
            count = 1;
        }
        i++;
    }

    // Write the final count to the output string
    output[j++] = count + '0';
    output[j] = '\0';
}

// Function to decompress the input string using run-length encoding
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char count = input[i++];

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If the current character is a digit, it represents the count
        if (input[i] >= '0' && input[i] <= '9') {
            count = input[i++] - '0';
        } else {
            // Otherwise, write the character to the output string the specified number of times
            while (count-- > 0) {
                output[j++] = input[i];
            }
        }
    }

    output[j] = '\0';
}

int main() {
    char input[MAX_CHARS], output[MAX_CHARS];

    // Get the input string from the user
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}