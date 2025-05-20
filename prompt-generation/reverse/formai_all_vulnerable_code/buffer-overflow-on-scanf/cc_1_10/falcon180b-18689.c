//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 1;

    // Iterate through the input string
    for(i=0; input[i]!='\0'; i++) {
        // If the current character is same as previous character
        if(i>0 && input[i]==input[i-1]) {
            // Increment the count
            count++;
        }
        // If the count becomes greater than 1 or the characters are different
        else {
            // Append the character and its count to the output string
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
    }

    // Append the last character and its count to the output string
    output[j++] = input[i];
    output[j++] = count + '0';
    output[j] = '\0';
}

// Function to decompress the compressed string back to its original form
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char count = 0;

    // Iterate through the input string
    while(input[i]!='\0') {
        // If the current character is a digit
        if(input[i] >= '0' && input[i] <= '9') {
            // Increment the count
            count = count*10 + (input[i] - '0');
        }
        // If the current character is an alphabet
        else {
            // Append the character to the output string multiple times based on the count
            while(count-- > 0) {
                output[j++] = input[i];
            }
            count = 0;
        }
        i++;
    }

    // Append the last character to the output string if the count is not zero
    while(count-- > 0) {
        output[j++] = input[i];
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[2000];

    // Get the input string from user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string back to its original form
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}