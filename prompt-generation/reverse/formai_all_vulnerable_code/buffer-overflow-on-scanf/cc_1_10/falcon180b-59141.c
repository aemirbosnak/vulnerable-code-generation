//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0, count = 1;
    while (input[i]) {
        if (input[i] == output[j]) {
            count++;
        } else {
            output[j++] = input[i];
            output[j++] = count;
            count = 1;
        }
        i++;
    }
    output[j++] = input[i];
    output[j++] = count;
    output[j] = '\0';
}

// Function to decompress the input string using run-length encoding
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    while (input[i]) {
        if (input[i] >= '0' && input[i] <= '9') {
            int count = input[i] - '0';
            while (count--) {
                output[j++] = input[i + 1];
            }
            i += 2;
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];

    // Get input string from user
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