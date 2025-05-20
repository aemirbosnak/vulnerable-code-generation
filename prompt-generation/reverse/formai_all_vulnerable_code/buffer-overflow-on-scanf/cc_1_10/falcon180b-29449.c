//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0, count = 1;
    char current_char = input[i];

    while (input[i]!= '\0') {
        if (input[i] == current_char) {
            count++;
        } else {
            output[j++] = current_char;
            output[j++] = (char)count;
            current_char = input[i];
            count = 1;
        }
        i++;
    }

    output[j++] = current_char;
    output[j++] = (char)count;
    output[j] = '\0';
}

// Function to decompress the compressed string using run-length encoding
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char current_char = input[i++];
    int count = (int)input[i++];

    while (count > 0) {
        for (int k = 0; k < count; k++) {
            output[j++] = current_char;
        }
        current_char = input[i++];
        count = (int)input[i++];
    }

    for (int k = 0; k < count; k++) {
        output[j++] = current_char;
    }
    output[j] = '\0';
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);
    printf("Decompressed string: %s\n", input);

    return 0;
}