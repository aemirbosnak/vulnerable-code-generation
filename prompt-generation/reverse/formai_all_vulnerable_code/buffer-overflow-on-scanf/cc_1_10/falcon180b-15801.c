//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a character
int encode(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 27;
    } else if (c >= '0' && c <= '9') {
        return c - '0' + 55;
    } else {
        return 0;
    }
}

// Function to decode a character
char decode(int c) {
    if (c >= 1 && c <= 26) {
        return c + 'a' - 1;
    } else if (c >= 27 && c <= 52) {
        return c + 'A' - 27;
    } else if (c >= 53 && c <= 58) {
        return c + '0' - 55;
    } else {
        return 0;
    }
}

// Function to compress a string
void compress(char *input, char *output) {
    int i, j;
    for (i = 0, j = 0; input[i]; i++) {
        if (i == 0 || input[i]!= input[i-1]) {
            output[j++] = encode(input[i]);
        }
    }
    output[j] = '\0';
}

// Function to decompress a string
void decompress(char *input, char *output) {
    int i, j;
    for (i = 0, j = 0; input[i]; i++) {
        if (i == 0 || input[i]!= input[i-1]) {
            output[j++] = decode(input[i]);
        } else {
            output[j++] = output[j-1];
        }
    }
    output[j] = '\0';
}

int main() {
    char input[100], output[100];
    printf("Enter a string to compress: ");
    scanf("%s", input);
    compress(input, output);
    printf("Compressed string: %s\n", output);
    decompress(output, input);
    printf("Decompressed string: %s\n", input);
    return 0;
}