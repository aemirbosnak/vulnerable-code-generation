//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_CODE 256
#define MAX_RUN_LENGTH 255

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i, j, count = 1;
    char* ptr = input;
    char* op = output;

    *op++ = *ptr++; // Copy the first character

    while (*ptr) {
        if (*ptr == *op - 1) {
            count++;
        } else {
            if (count > 1) {
                *op++ = count;
                *op++ = *ptr;
            } else {
                *op++ = *ptr;
            }
            count = 1;
        }
        ptr++;
    }

    if (count > 1) {
        *op++ = count;
        *op = '\0';
    } else {
        *op = '\0';
    }
}

// Function to decompress the input string using run-length encoding
void decompress(char* input, char* output) {
    int i, j, count;
    char* ptr = input;
    char* op = output;

    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') {
            count = *ptr - '0';
            ptr++;
        } else {
            count = 1;
        }

        while (count-- > 0 && *ptr) {
            *op++ = *ptr++;
        }
    }

    *op = '\0';
}

int main() {
    char input[1000];
    char compressed[1000];
    char decompressed[1000];

    printf("Enter a string to compress: ");
    scanf("%s", input);

    compress(input, compressed);

    printf("Compressed string: %s\n", compressed);

    decompress(compressed, decompressed);

    printf("Decompressed string: %s\n", decompressed);

    return 0;
}