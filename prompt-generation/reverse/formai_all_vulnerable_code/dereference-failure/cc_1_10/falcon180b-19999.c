//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to compress the input string
char* compress(char* input) {
    int i, j;
    char* output = malloc(strlen(input) * 2 + 1); // Allocate memory for the output string
    output[0] = '\0'; // Initialize the output string with a null character
    i = 0;
    while (input[i]) {
        j = i;
        while (input[i] == input[j]) { // Count the number of consecutive occurrences of the current character
            i++;
            j++;
        }
        sprintf(output + strlen(output), "%d%c", i - j, input[j]); // Add the count and the character to the output string
        i = j;
    }
    return output;
}

// Function to decompress the input string
char* decompress(char* input) {
    int i, j;
    char* output = malloc(strlen(input) * 2 + 1); // Allocate memory for the output string
    output[0] = '\0'; // Initialize the output string with a null character
    i = 0;
    while (input[i]) {
        if (input[i] >= '0' && input[i] <= '9') { // If the current character is a count
            j = i + 1;
            while (input[j] >= '0' && input[j] <= '9') { // Find the end of the count
                j++;
            }
            i = j;
            while (i < strlen(input)) { // Copy the count and the character to the output string
                output[strlen(output)] = input[i];
                i++;
            }
        } else { // If the current character is a character
            output[strlen(output)] = input[i]; // Copy the character to the output string
            i++;
        }
    }
    return output;
}

int main() {
    char* input = "aaabbbbbbbcccccccccddddeeeeeeeeeeeeeee";
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}