//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define MAX_OUTPUT_SIZE 512

// Function to perform Run-Length Encoding (RLE)
void runLengthEncoding(const char *input, char *output) {
    int i, j = 0;
    int length = strlen(input);
    
    for (i = 0; i < length; i++) {
        // Count occurrences of the same character
        int count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Store the character and its count in output
        output[j++] = input[i];
        j += sprintf(output + j, "%d", count); // Append the count as a string
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to compress input data
void compressData() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];

    printf("Enter a string to compress (max %d characters): ", MAX_INPUT_SIZE - 1);
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Compress the input data using RLE
    runLengthEncoding(input, output);

    printf("Compressed output: %s\n", output);
}

// Function to decompress RLE output
void runLengthDecoding(const char *input, char *output) {
    int i, j = 0;
    int length = strlen(input);

    for (i = 0; i < length; i++) {
        char currentChar = input[i];
        i++;
        int count = 0;

        // Read the count
        while (i < length && isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        // Append the character 'count' times
        for (int k = 0; k < count; k++) {
            output[j++] = currentChar;
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to decompress compressed data
void decompressData() {
    char input[MAX_OUTPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    printf("Enter a compressed string to decompress (max %d characters): ", MAX_OUTPUT_SIZE - 1);
    fgets(input, MAX_OUTPUT_SIZE, stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Decompress the input data using RLE
    runLengthDecoding(input, output);

    printf("Decompressed output: %s\n", output);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nRun-Length Encoding Compression Program\n");
        printf("1. Compress data\n");
        printf("2. Decompress data\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline from scanf

        switch (choice) {
            case 1:
                compressData();
                break;
            case 2:
                decompressData();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}