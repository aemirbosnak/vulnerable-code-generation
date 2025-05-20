//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    // iterate through the input string
    while (input[i]!= '\0') {
        // if the current character is the same as the previous one, increment the count
        if (input[i] == input[i-1]) {
            count++;
        } else {
            // write the character and its count to the output string
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
        i++;
    }

    // write the last character and its count to the output string
    output[j++] = input[i-1];
    output[j++] = count + '0';
    output[j] = '\0';
}

// function to decompress the input string using run-length encoding
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 0;

    // iterate through the input string
    while (input[i]!= '\0') {
        // if the current character is a digit, update the count
        if (input[i] >= '0' && input[i] <= '9') {
            count = input[i] - '0';
            i++;
        } else {
            // write the character count times to the output string
            while (count-- > 0) {
                output[j++] = input[i];
            }
            i++;
        }
    }

    output[j] = '\0';
}

int main() {
    char input[100], output[200];

    // get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // compress the input string
    compress(input, output);

    // print the compressed string
    printf("Compressed string: %s\n", output);

    // decompress the compressed string
    decompress(output, input);

    // print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}