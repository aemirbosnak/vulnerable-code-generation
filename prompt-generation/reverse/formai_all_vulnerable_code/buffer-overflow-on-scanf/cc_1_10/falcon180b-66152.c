//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    while (input[i]) {
        // Count the number of consecutive occurrences of the current character
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Write the count and character to the output string
        output[j++] = count + '0';
        output[j++] = input[i++];
    }

    // Add a terminator to the output string
    output[j] = '\0';
}

// Function to decompress the input string
void decompress(char* input, char* output) {
    int i = 0, j = 0;

    while (input[i]) {
        // Read the count and character from the input string
        int count = input[i] - '0';
        char ch = input[i + 1];

        // Write the character to the output string the specified number of times
        while (count--) {
            output[j++] = ch;
        }

        i += 2;
    }

    // Add a terminator to the output string
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
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}