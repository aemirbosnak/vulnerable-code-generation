//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    int count = 1;

    // Iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // If the current character is the same as the previous character,
        // increment the count
        if (i > 0 && input[i] == input[i-1]) {
            count++;
        } else {
            // Otherwise, write the character and reset the count
            output[j] = input[i];
            j++;
            count = 1;
        }
    }

    // Write the count for the last character
    output[j] = count;
    j++;

    // Add a null terminator to the end of the compressed string
    output[j] = '\0';
}

// Function to decompress the compressed string
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    int count = 1;

    // Iterate through the compressed string
    for (i = 0; input[i]!= '\0'; i++) {
        // If the count is greater than 1, write the character
        // count times
        if (count > 1) {
            while (count > 0) {
                output[j] = input[i];
                j++;
                count--;
            }
        } else {
            // Otherwise, write the character and reset the count
            output[j] = input[i];
            j++;
            count = 1;
        }
    }

    // Add a null terminator to the end of the decompressed string
    output[j] = '\0';
}

int main() {
    char input[100], output[200];

    // Prompt the user for input
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