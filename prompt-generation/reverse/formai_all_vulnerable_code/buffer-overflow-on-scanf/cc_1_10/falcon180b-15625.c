//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    output[j] = input[i];
    j++;
    while (i < strlen(input)) {
        if (input[i] == output[j - 1]) {
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

// Function to decompress the input string
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    while (input[i]!= '\0') {
        if (input[i]!= '~') {
            output[j] = input[i];
            j++;
        } else {
            i++;
            while (input[i]!= '~') {
                i++;
            }
            i++;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];
    printf("Enter the string to compress: ");
    scanf("%s", input);
    compress(input, output);
    printf("Compressed string: %s\n", output);
    printf("Enter the compressed string to decompress: ");
    scanf("%s", input);
    decompress(input, output);
    printf("Decompressed string: %s\n", output);
    return 0;
}