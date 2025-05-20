//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to perform Run-Length Encoding
char* compress(const char* input) {
    // Allocate a reasonable amount of memory for the compressed result
    char* compressed = malloc(BUFFER_SIZE);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int index = 0;
    
    // Loop through the input string
    for (int i = 0; input[i] != '\0'; i++) {
        // If the current character is the same as the last, increment count
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            // Store the character and count in the compressed string
            index += sprintf(&compressed[index], "%c%d", input[i], count);
            count = 1; // Reset the count
        }
    }
    
    return compressed; // Return the compressed string
}

// Function to display the results
void displayResults(const char* original, const char* compressed) {
    printf("Original String: %s\n", original);
    printf("Compressed String: %s\n", compressed);
    printf("Compression Ratio: %.2f%%\n", 
        ((float)(strlen(original) - strlen(compressed)) / strlen(original)) * 100);
}

int main() {
    char input[BUFFER_SIZE];

    printf("Welcome to the RLE Compression Program!\n");
    printf("Please enter a string to compress (up to %d characters):\n", BUFFER_SIZE - 1);
    
    // Read input from the user
    fgets(input, BUFFER_SIZE, stdin);
    
    // Remove the newline character from the end of the input if present
    input[strcspn(input, "\n")] = 0;

    // Perform the compression
    char* compressed = compress(input);
    
    // Display the results of the compression
    displayResults(input, compressed);

    // Free the allocated memory
    free(compressed);
    
    printf("Thank you for using the RLE Compression Program! Goodbye!\n");
    return 0;
}