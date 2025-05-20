//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    while (input[i]!= '\0') {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[j] = input[i];
            j++;
            output[j] = count;
            j++;
            count = 1;
        }
        i++;
    }

    output[j] = input[i];
    j++;
    output[j] = count;
    j++;
    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    int count = 0;

    while (input[i]!= '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            count = input[i] - '0';
            i++;
        } else {
            while (count > 0) {
                output[j] = input[i];
                j++;
                count--;
            }
        }
    }

    output[j] = '\0';
}

int main() {
    char input[1000], compressed[1000], decompressed[1000];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, compressed);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string
    decompress(compressed, decompressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}