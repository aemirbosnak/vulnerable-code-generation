//FormAI DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum size for the input string */
#define MAX_INPUT_SIZE 100

/* Define the maximum size for the compressed string */
#define MAX_OUTPUT_SIZE 50

/* This function compresses the input string using a unique algorithm */
void compress(char *input_string, char *compressed_string) {
    int i, j, count;
    char previous_char, current_char;

    /* Initialize variables */
    i = 0;
    j = 0;
    count = 1;
    previous_char = input_string[0];

    /* Traverse the input string */
    while (input_string[i] != '\0') {
        i++;
        current_char = input_string[i];

        /* If the current character is the same as the previous one, increment the count */
        if (current_char == previous_char) {
            count++;
        }
        /* Otherwise, add the previous character and its count to the compressed string */
        else {
            compressed_string[j++] = previous_char;
            compressed_string[j++] = count + '0';
            count = 1;
            previous_char = current_char;
        }
    }

    /* Add the last character and its count to the compressed string */
    compressed_string[j++] = previous_char;
    compressed_string[j++] = count + '0';
    compressed_string[j] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    char compressed[MAX_OUTPUT_SIZE];

    /* Prompt the user for input */
    printf("Enter a string to compress (up to %d characters):\n", MAX_INPUT_SIZE - 1);
    fgets(input, MAX_INPUT_SIZE, stdin);

    /* Remove the newline character from the input string */
    input[strlen(input) - 1] = '\0';

    /* Compress the input string */
    compress(input, compressed);

    /* Print the compressed string */
    printf("Compressed string: %s\n", compressed);

    return 0;
}