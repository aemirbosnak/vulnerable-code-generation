//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct compression_data {
    char symbol;
    int count;
} compression_data;

int main() {
    char input[MAX_SIZE];
    compression_data compressed[MAX_SIZE];
    int compressed_length = 0;
    int i, j;

    // Get input from user
    printf("Enter a string to compress: ");
    fgets(input, MAX_SIZE, stdin);

    // Compress the string
    for (i = 0; input[i] != '\0'; i++) {
        // If there is a repeat character, increase its count
        if (input[i] == input[i+1]) {
            compressed[compressed_length].symbol = input[i];
            compressed[compressed_length].count++;
        }
        // If the character is unique, create a new compression data element
        else {
            compressed[compressed_length].symbol = input[i];
            compressed[compressed_length].count = 1;
            compressed_length++;
        }
    }

    // Print out the compressed string
    printf("\nCompressed String:\n");
    for (i = 0; i < compressed_length; i++) {
        printf("%c%d", compressed[i].symbol, compressed[i].count);
    }

    // Decompress the string
    printf("\n\nDecompressed String:\n");
    for (i = 0; i < compressed_length; i++) {
        for (j = 0; j < compressed[i].count; j++) {
            printf("%c", compressed[i].symbol);
        }
    }

    return 0;
}