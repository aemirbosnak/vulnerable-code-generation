//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encode(char* input, char* output);
void decode(char* input, char* output);

int main() {
    char input[100], output[200];
    int choice;

    // Prompt user for input string
    printf("Enter a string: ");
    scanf("%s", input);

    // Prompt user for choice of operation
    printf("Choose operation:\n1. Encode\n2. Decode\n");
    scanf("%d", &choice);

    // Perform chosen operation
    switch (choice) {
        case 1:
            encode(input, output);
            printf("Encoded string: %s\n", output);
            break;
        case 2:
            decode(input, output);
            printf("Decoded string: %s\n", output);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function to encode input string
void encode(char* input, char* output) {
    int i, j, count = 0;

    // Initialize output string with first character of input string
    output[count++] = input[0];

    // Encode remaining characters
    for (i = 1; input[i]; i++) {
        int charCount = 0;

        // Count number of occurrences of current character
        for (j = 0; j < count; j++) {
            if (output[j] == input[i]) {
                charCount++;
            }
        }

        // Encode current character with its count
        if (charCount == 0) {
            output[count++] = input[i];
        } else {
            sprintf(&output[count], "%d%c", charCount, input[i]);
            count += strlen(&output[count]);
        }
    }

    // Add null terminator to output string
    output[count] = '\0';
}

// Function to decode input string
void decode(char* input, char* output) {
    int i, j, count = 0;

    // Initialize output string with first character of input string
    output[count++] = input[0];

    // Decode remaining characters
    for (i = 1; input[i]; i++) {
        if (isdigit(input[i])) {
            // Current character is a digit, decode it
            int charCount = input[i] - '0';

            // Decode current character with its count
            for (j = 0; j < charCount; j++) {
                output[count++] = input[i + 1];
            }

            i++;
        } else {
            // Current character is not a digit, copy it to output string
            output[count++] = input[i];
        }
    }

    // Add null terminator to output string
    output[count] = '\0';
}