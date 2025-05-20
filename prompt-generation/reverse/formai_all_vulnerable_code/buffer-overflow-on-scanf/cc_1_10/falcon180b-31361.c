//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
void compress(char* input, char** output) {
    int i = 0;
    int j = 0;
    char currentChar = input[i];
    int count = 1;

    // Allocate memory for the output string
    char* temp = (char*)malloc(strlen(input) * 2 + 1);
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize the output string with the first character and its count
    *output = temp;
    temp[j++] = currentChar;
    temp[j++] = '1';

    // Encode the remaining characters using run-length encoding
    while (input[i]!= '\0') {
        if (input[i] == currentChar) {
            count++;
        } else {
            if (count > 1) {
                sprintf(&temp[j], "%d%c", count, currentChar);
                j += strlen(&temp[j]);
            }
            currentChar = input[i];
            count = 1;
        }
        i++;
    }

    // Encode the last character and its count
    if (count > 1) {
        sprintf(&temp[j], "%d%c", count, currentChar);
        j += strlen(&temp[j]);
    } else {
        temp[j++] = currentChar;
        temp[j++] = '1';
    }
    temp[j] = '\0';
}

int main() {
    char input[1000];
    char* output;

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, &output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Free the memory allocated for the output string
    free(output);

    return 0;
}