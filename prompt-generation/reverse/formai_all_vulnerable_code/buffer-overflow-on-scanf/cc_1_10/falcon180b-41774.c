//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000
#define MAX_CODE_SIZE 1000000

// Function to compress the input string using Run Length Encoding
void compress(char* input, char* output) {
    int i = 0, j = 0, count = 1;
    while (input[i]!= '\0') {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[j++] = input[i++];
            output[j++] = count;
            count = 1;
        }
    }
    output[j++] = input[i++];
    output[j++] = count;
    output[j] = '\0';
}

// Function to decompress the compressed string using Run Length Encoding
void decompress(char* input, char* output) {
    int i = 0, j = 0, count = 0;
    while (input[i]!= '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + input[i] - '0';
        } else {
            while (count-- > 0) {
                output[j++] = input[i++];
            }
        }
    }
    output[j] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE], output[MAX_CODE_SIZE];

    // Read input string from user
    printf("Enter input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    char decompressed[MAX_INPUT_SIZE];
    decompress(output, decompressed);

    // Print decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}