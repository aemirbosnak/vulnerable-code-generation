//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: complex
/*
 * C Compression Algorithm Example Program
 *
 * This program implements a simple compression algorithm that replaces repeated
 * characters with a single character and a count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

int main(void) {
    char input[1000];
    char output[1000];
    int i, j;
    int count;
    char prev_char;
    char curr_char;

    // Get input from user
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Initialize output and count
    output[0] = input[0];
    count = 1;
    prev_char = input[0];

    // Iterate through input string
    for (i = 1; i < strlen(input); i++) {
        curr_char = input[i];

        // If current character is the same as previous character
        if (curr_char == prev_char) {
            // Increment count and continue
            count++;
            continue;
        }

        // If current character is different from previous character
        if (curr_char != prev_char) {
            // Add count to output
            output[j] = count + '0';
            j++;

            // Add current character to output
            output[j] = curr_char;
            j++;

            // Reset count and previous character
            count = 1;
            prev_char = curr_char;
        }
    }

    // Add final count to output
    output[j] = count + '0';
    j++;

    // Add null terminator to output
    output[j] = '\0';

    // Print compressed string
    printf("Compressed string: %s\n", output);

    return 0;
}