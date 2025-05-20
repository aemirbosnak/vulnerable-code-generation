//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to compress the input string using run-length encoding
void compress(char* input, int* output_size, char** output) {
    int i = 0;
    int j = 0;
    int count = 1;

    // Base case: input string is empty
    if (input[i] == '\0') {
        *output_size = 1;
        *output = malloc(2);
        output[0] = '0';
        output[1] = '\0';
        return;
    }

    // Recursive case: compress the input string
    while (input[i]!= '\0') {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            if (count > 1) {
                // Add the run-length encoded string to the output
                output[j] = '0' + count;
                j++;
            } else {
                // Add the single character to the output
                output[j] = input[i];
                j++;
            }
            count = 1;
        }
        i++;
    }

    // Add the last run-length encoded string to the output
    if (count > 1) {
        output[j] = '0' + count;
        j++;
    } else {
        output[j] = input[i];
        j++;
    }
    output[j] = '\0';

    // Set the output size and return the compressed string
    *output_size = j;
    return;
}

int main() {
    char input[100] = "aaabbbbbcc";
    int output_size;
    char* output;

    // Compress the input string
    compress(input, &output_size, &output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Free the memory allocated for the output string
    free(output);

    return 0;
}