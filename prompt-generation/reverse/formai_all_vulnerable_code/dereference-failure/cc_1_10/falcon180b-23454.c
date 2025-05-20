//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
char* compress(char* input) {
    int i, j, count = 0;
    char* output = (char*)malloc(1000000 * sizeof(char)); // Allocate 1 MB of memory for output string
    output[0] = '\0'; // Initialize the output string with null character

    // Iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        count = 1; // Initialize the count to 1
        j = i + 1; // Start comparing from the next character

        // Compare the current character with the next characters
        while (j < strlen(input) && input[j] == input[i]) {
            count++; // Increment the count if characters are equal
            j++; // Move to the next character
        }

        // Append the count and the current character to the output string
        sprintf(&output[strlen(output)], "%d%c", count, input[i]);
    }

    return output;
}

// Function to decompress the compressed string
char* decompress(char* input) {
    int i, j, count = 0, k = 0;
    char* output = (char*)malloc(1000000 * sizeof(char)); // Allocate 1 MB of memory for output string
    output[0] = '\0'; // Initialize the output string with null character

    // Iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // If the current character is a digit, then it is the count
        if (isdigit(input[i])) {
            count = input[i] - '0'; // Convert the digit character to integer
            i++; // Move to the next character
        } else {
            // Append the current character to the output string
            output[k++] = input[i];
        }

        // Repeat the current character count times
        for (j = 0; j < count; j++) {
            output[k++] = input[i];
        }
    }

    return output;
}

int main() {
    char* input = "aaabbbbbcccdddaa";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    return 0;
}