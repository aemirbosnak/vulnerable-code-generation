//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the string using Run-Length Encoding
char* rleCompress(const char* str) {
    int n = strlen(str);
    if (n == 0) return "";

    char* compressed = malloc(2 * n + 1); // Maximum size could be twice the original
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            index += sprintf(&compressed[index], "%c%d", str[i - 1], count);
            count = 1; // Reset count
        }
    }

    compressed[index] = '\0'; // Null-terminate the string
    return compressed;
}

// Function to decompress a run-length encoded string
char* rleDecompress(const char* compressed) {
    int n = strlen(compressed);
    char* decompressed = malloc(2 * n + 1); // Maximum size could be twice the compressed
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        char currentChar = compressed[i];
        i++;
        int count = 0;

        // Collect the numeric part
        while (i < n && compressed[i] >= '0' && compressed[i] <= '9') {
            count = count * 10 + (compressed[i] - '0');
            i++;
        }
        i--; // Adjust for the increment in the loop

        // Decode the character based on the count
        for (int j = 0; j < count; j++) {
            decompressed[index++] = currentChar;
        }
    }
    decompressed[index] = '\0'; // Null-terminate the string
    return decompressed;
}

int main() {
    char input[100];
    printf("Welcome to the RLE Compressor!\n");
    printf("Enter a string to compress (max 99 characters): ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char* compressed = rleCompress(input);
    printf("Compressed: %s\n", compressed);

    char* decompressed = rleDecompress(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    printf("Thank you for using the RLE Compressor!\n");
    return 0;
}