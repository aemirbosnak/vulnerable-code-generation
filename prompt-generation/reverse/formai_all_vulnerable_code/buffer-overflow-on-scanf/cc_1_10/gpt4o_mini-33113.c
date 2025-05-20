//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMPRESSED_SIZE 2048

// Function to perform run-length encoding on the input data
void runLengthEncode(const char *input, char *output) {
    int count;
    int i, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Write character and its count to output
        output[j++] = input[i];
        output[j++] = count + '0'; // Convert count to character
    }
    output[j] = '\0'; // Null terminate the output string
}

// Function to check if the compression was beneficial
int isCompressionBeneficial(const char *original, const char *compressed) {
    return strlen(compressed) < strlen(original);
}

// Function to compress the input using run-length encoding
void compress(const char *input, char *output) {
    runLengthEncode(input, output);
    if (!isCompressionBeneficial(input, output)) {
        strcpy(output, input); // If not beneficial, output original
    }
}

int main() {
    char input[MAX_BUFFER_SIZE];
    char compressed[MAX_COMPRESSED_SIZE];
    char choice;

    printf("Welcome to the Run-Length Encoding Compression Utility!\n");
    
    do {
        printf("Enter a string to compress (max %d characters): ", MAX_BUFFER_SIZE - 1);
        fgets(input, MAX_BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        compress(input, compressed);

        printf("Original String: %s\n", input);
        printf("Compressed String: %s\n", compressed);

        printf("Do you want to compress another string? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline after choice input
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the utility!\n");
    return 0;
}