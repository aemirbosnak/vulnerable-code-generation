//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_CODE_LEN 10

// Function to compress the input string
void compress(char *input, char *output) {
    int i = 0, j = 0, k = 0;
    int word_count = 1;
    char word[MAX_WORD_LEN];
    char code[MAX_CODE_LEN];

    // Initialize the code table
    strcpy(code, "abcdefghijklmnopqrstuvwxyz");

    // Copy the first character to the output string
    output[k++] = input[i++];

    while (input[i]) {
        // Copy the current character to the word buffer
        strncat(word, &input[i], 1);

        // Check if the word is a prefix of any previously encountered word
        for (j = 0; j < strlen(word); j++) {
            if (word[j]!= code[j]) {
                break;
            }
        }

        // If the word is a prefix, update the code table and output the code
        if (j == strlen(word)) {
            strcat(code, &word[j]);
            output[k++] = '0' + word_count;
        } else {
            // Otherwise, output the character itself
            output[k++] = input[i++];
        }
    }

    // Add the last character to the code table
    strcat(code, "z");

    // Output the final code for the last character
    output[k++] = '0' + word_count;

    // Terminate the output string
    output[k] = '\0';
}

int main() {
    char input[MAX_WORD_LEN], output[MAX_CODE_LEN];

    // Get the input string from the user
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Output the compressed string
    printf("Compressed string: %s\n", output);

    return 0;
}