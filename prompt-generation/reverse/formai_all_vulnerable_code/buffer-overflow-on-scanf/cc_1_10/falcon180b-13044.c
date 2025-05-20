//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Function to compress the input string
void compress(char *input, char *output) {
    int i = 0, j = 0;
    int count = 1;

    // Copy the first character
    output[j++] = input[i++];

    // Loop through the rest of the string
    while (input[i]) {
        // Check if the current character is the same as the previous one
        if (input[i] == output[j - 1]) {
            count++;
        } else {
            // Write the count and the character to the output string
            output[j++] = count;
            output[j++] = input[i];
            count = 1;
        }
        i++;
    }

    // Write the last count and character to the output string
    output[j++] = count;
    output[j++] = input[i - 1];
    output[j] = '\0';
}

// Function to decompress the input string
void decompress(char *input, char *output) {
    int i = 0, j = 0;
    int count = 0;

    // Loop through the input string
    while (input[i]) {
        // Check if the current character is a count
        if (isdigit(input[i])) {
            count = input[i] - '0';
            i++;
        } else {
            // Write the character to the output string
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
}

int main() {
    char input[MAX_CHARS], output[MAX_CHARS * 2];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    char decompressed[MAX_CHARS * 2];
    decompress(output, decompressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}