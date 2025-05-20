//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
void compress(char* str) {
    int len = strlen(str);
    int count = 1;
    int prevChar = str[0];

    for (int i = 1; i < len; i++) {
        if (str[i]!= prevChar) {
            printf("%c", prevChar);
            count++;
            prevChar = str[i];
        }
    }
    printf("%c", prevChar);
}

// Function to decompress a string
void decompress(char* str) {
    int len = strlen(str);
    int count = 1;
    int prevChar = str[0];

    for (int i = 1; i < len; i++) {
        if (str[i] == prevChar) {
            count++;
        } else {
            printf("%c", prevChar);
            count = 1;
            prevChar = str[i];
        }
    }
    printf("%c", prevChar);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    compress(str);
    printf("\nCompressed string: %s\n", str);

    decompress(str);
    printf("\nDecompressed string: %s\n", str);

    return 0;
}