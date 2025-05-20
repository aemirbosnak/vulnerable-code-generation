//FormAI DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to compress the data using a unique compression algorithm
void compress(char *input, char *output) {
    int input_len = strlen(input);
    int output_len = 0;
    int i, j, k;

    // Perform the compression algorithm on the input
    for (i = 0; i < input_len; i++) {
        // Count how many times the current character appears
        int count = 1;
        for (j = i + 1; j < input_len; j++) {
            if (input[i] != input[j]) {
                break;
            }
            count++;
        }
        
        // Store the compressed data in the output
        if (count > 3) {
            // If the character appears more than 3 times, use a special delimiter
            output[output_len++] = '&';
            output[output_len++] = (char) (count + '0');
            output[output_len++] = input[i];
            i += count - 1;
        } else {
            // Otherwise, just append the character multiple times
            for (k = 0; k < count; k++) {
                output[output_len++] = input[i];
            }
        }
    }

    // Add the null terminator to the end of the output
    output[output_len] = '\0';
}

int main() {
    char input[100];
    char output[100];
    printf("Enter the input string to compress: ");
    scanf("%s", input);
    
    compress(input, output);
    
    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", output);
    return 0;
}