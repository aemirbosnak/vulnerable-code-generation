//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000 // maximum size of input

// function to compress the input string using run-length encoding
void compress(char input[], int *compressed_size, char compressed[]) {
    int i, j, count = 1;
    compressed[0] = input[0]; // start with the first character
    for (i = 1; i < strlen(input); i++) {
        if (input[i] == input[i-1]) { // check if the current character is the same as the previous one
            count++; // increment the count of consecutive characters
        } else {
            count = 1; // reset the count
            compressed[*compressed_size] = input[i]; // add the current character to the compressed string
            (*compressed_size)++; // increase the size of the compressed string
            i--; // move back one character to start the next run
        }
    }
    compressed[*compressed_size] = input[i]; // add the last character to the compressed string
    (*compressed_size)++; // increase the size of the compressed string
}

// function to decompress the compressed string using run-length encoding
void decompress(char compressed[], int compressed_size, char decompressed[]) {
    int i, j, count = 0;
    decompressed[0] = compressed[0]; // start with the first character
    for (i = 1; i < compressed_size; i++) {
        if (compressed[i]!= compressed[i-1]) { // check if the current character is different from the previous one
            count = 1; // reset the count
        } else {
            count++; // increment the count of consecutive characters
        }
        for (j = 0; j < count; j++) {
            decompressed[i+j] = compressed[i]; // add the current character to the decompressed string
        }
    }
    decompressed[i] = '\0'; // add the null terminator to the end of the decompressed string
}

int main() {
    char input[MAX_SIZE], compressed[MAX_SIZE+1], decompressed[MAX_SIZE+1];
    int compressed_size, decompressed_size;
    printf("Enter the input string: ");
    scanf("%s", input);
    compress(input, &compressed_size, compressed);
    printf("Compressed string: %s\n", compressed);
    decompress(compressed, compressed_size, decompressed);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}