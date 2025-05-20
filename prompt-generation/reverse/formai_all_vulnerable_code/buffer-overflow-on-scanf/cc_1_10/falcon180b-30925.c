//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compress the input string using Run Length Encoding (RLE)
void compress(char input[], char output[]) {
    int i = 0, j = 0;
    char count = 1;

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If the current character is the same as the previous one, increment the count
        if (input[i] == input[i - 1]) {
            count++;
        }
        // Otherwise, write the current character and its count to the output string
        else {
            output[j++] = input[i];
            output[j++] = (char) count;
            count = 1;
        }
        i++;
    }

    // Add the last character and its count to the output string
    output[j++] = input[i - 1];
    output[j++] = (char) count;
    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char input[], char output[]) {
    int i = 0, j = 0;
    char count;

    // Iterate through the compressed string
    while (input[i]!= '\0') {
        // Read the current character and its count
        output[j++] = input[i++];
        count = input[i++];

        // Write the character 'count' times to the output string
        while (count-- > 0) {
            output[j++] = output[j - 1];
        }
    }

    output[j] = '\0';
}

int main() {
    char input[MAX_SIZE], output[MAX_SIZE];

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