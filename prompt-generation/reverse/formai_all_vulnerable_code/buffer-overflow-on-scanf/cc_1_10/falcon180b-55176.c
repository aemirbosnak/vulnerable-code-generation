//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

// Function to compress the given string
void compress(char input[], char output[]) {
    int i = 0, j = 0;
    char count[256] = {0};

    // Count the frequency of each character in the input string
    for (i = 0; input[i]!= '\0'; i++) {
        count[input[i]]++;
    }

    // Encode the characters and their frequencies in the output string
    for (i = 0; input[i]!= '\0'; i++) {
        while (count[input[i]] > 0) {
            output[j++] = input[i];
            count[input[i]]--;
        }
    }

    // Terminate the output string
    output[j] = '\0';
}

// Function to decompress the given string
void decompress(char input[], char output[]) {
    int i = 0, j = 0;
    char count[256] = {0};

    // Count the frequency of the first character in the input string
    count[input[0]]++;

    // Decode the characters and their frequencies in the output string
    while (input[i]!= '\0') {
        while (count[input[i]] > 0) {
            output[j++] = input[i];
            count[input[i]]--;
        }
        i++;
    }

    // Terminate the output string
    output[j] = '\0';
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    // Get the input string from the user
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}