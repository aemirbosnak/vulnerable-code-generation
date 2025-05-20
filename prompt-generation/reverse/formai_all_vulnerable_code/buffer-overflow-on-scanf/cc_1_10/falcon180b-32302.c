//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    while (input[i]) {
        // Find the maximum number of consecutive occurrences of the current character
        int count = 1;
        while (input[i + count] == input[i] && input[i + count]!= '\0') {
            count++;
        }
        // Write the count and the character to the output string
        output[j++] = input[i];
        output[j++] = count + '0';
        i += count;
    }
    output[j] = '\0';
}

// Function to decompress the input string
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    while (input[i]) {
        // Read the count and the character from the input string
        int count = input[i] - '0';
        output[j++] = input[i + 1];
        i += 2;
        // Write the character count times to the output string
        while (count > 0) {
            output[j++] = input[i];
            count--;
            i++;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];
    printf("Enter the input string: ");
    scanf("%s", input);
    // Compress the input string
    compress(input, output);
    printf("Compressed string: %s\n", output);
    // Decompress the compressed string
    decompress(output, output);
    printf("Decompressed string: %s\n", output);
    return 0;
}