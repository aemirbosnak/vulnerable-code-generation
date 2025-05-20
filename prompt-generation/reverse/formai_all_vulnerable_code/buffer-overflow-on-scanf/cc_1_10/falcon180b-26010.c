//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding (RLE)
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    while (input[i]!= '\0') {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            output[j] = input[i];
            output[j+1] = count;
            j += 2;
            count = 1;
        }
        i++;
    }

    output[j] = input[i-1];
    output[j+1] = count;
    j += 2;

    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char* input, char* output) {
    int i = 0, j = 0;

    while (input[i]!= '\0') {
        if (input[i]!= '\0') {
            int count = input[i+1];
            while (count-- > 0) {
                output[j] = input[i];
                j++;
            }
        } else {
            output[j] = input[i];
            j++;
        }
        i += 2;
    }

    output[j] = '\0';
}

int main() {
    char input[100], output[200];

    printf("Enter the input string: ");
    scanf("%s", input);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    char decompressed[200];
    decompress(output, decompressed);

    printf("Decompressed string: %s\n", decompressed);

    return 0;
}