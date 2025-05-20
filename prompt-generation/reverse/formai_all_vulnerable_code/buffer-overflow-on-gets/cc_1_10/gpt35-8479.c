//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shape-shifting compression algorithm
void shape_shift_compress(char input[], char output[]) {
    int i, j, k, count, len;
    char prev;
    len = strlen(input);

    // Initialize output string to empty string
    output[0] = '\0';

    // Loop through input string
    for (i = 0; i < len; i += count) {
        prev = input[i]; // Record current character
        count = 0; // Reset count

        // Count the number of consecutive characters
        for (j = i; j < len; j++) {
            if (input[j] == prev) {
                count++;
            } else {
                break;
            }
        }

        // Convert count to a character and add to output string
        k = sprintf(output, "%d", count);
        output += k;

        // Add the current character to output string
        sprintf(output, "%c", prev);
        output++;
    }
}

int main() {
    char input[100], output[100];

    // Get input from user
    printf("Enter a string to compress: ");
    gets(input);

    // Compress input using shape-shifting algorithm
    shape_shift_compress(input, output);

    // Display compressed string
    printf("Compressed string: %s\n", output);

    return 0;
}