//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0, count = 1;
    while (input[i]) {
        if (i > 0 && input[i] == input[i-1]) {
            count++;
        } else {
            output[j++] = input[i];
            count = 1;
        }
        i++;
    }
    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char* compressed, char* decompressed) {
    int i = 0, j = 0;
    while (compressed[i]) {
        if (compressed[i]!= '\0') {
            int count = compressed[i] - '0';
            while (count-- > 0) {
                decompressed[j++] = compressed[i];
            }
        } else {
            decompressed[j++] = compressed[i];
        }
        i++;
    }
    decompressed[j] = '\0';
}

int main() {
    char input[1000], compressed[1000], decompressed[1000];
    
    // Get user input
    printf("Enter a string to compress: ");
    scanf("%s", input);
    
    // Compress the input string
    compress(input, compressed);
    
    // Print the compressed string
    printf("Compressed string: %s\n", compressed);
    
    // Decompress the compressed string back to its original form
    decompress(compressed, decompressed);
    
    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);
    
    return 0;
}