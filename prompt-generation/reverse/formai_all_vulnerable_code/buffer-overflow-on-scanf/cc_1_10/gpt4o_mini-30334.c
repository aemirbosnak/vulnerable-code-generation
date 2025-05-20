//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressRLE(const char *input, char *output) {
    int count;
    int i, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        // Count occurrences of each character
        count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store character and count in output
        output[j++] = input[i];
        if (count > 1) {
            j += sprintf(output + j, "%d", count);
        }
    }
    output[j] = '\0';  // Null terminate the output string
}

void decompressRLE(const char *input, char *output) {
    int i = 0, j = 0;
    while (input[i]) {
        char currentChar = input[i++];
        output[j++] = currentChar;

        if (input[i] >= '0' && input[i] <= '9') {
            // If the next character is a digit, capture the whole number
            int count = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                count = count * 10 + (input[i] - '0');
                i++;
            }

            // Repeat the character count times
            for (int k = 1; k < count; k++) {
                output[j++] = currentChar;
            }
        }
    }
    output[j] = '\0';  // Null terminate the output string
}

int main() {
    char option;
    char input[100];
    char output[200];

    printf("Run-Length Encoding (RLE) Compression Program\n");
    printf("-----------------------------------------------\n");
    printf("Choose an action:\n");
    printf("1. Compress a string\n");
    printf("2. Decompress a string\n");
    printf("Enter your choice (1/2): ");
    scanf(" %c", &option);
    getchar();  // Consume the newline character after scanf

    switch (option) {
        case '1':
            printf("Enter the string to compress: ");
            fgets(input, sizeof(input), stdin);
            // Remove the newline character at the end if it exists
            input[strcspn(input, "\n")] = 0;

            compressRLE(input, output);
            printf("Compressed output: %s\n", output);
            break;

        case '2':
            printf("Enter the string to decompress: ");
            fgets(input, sizeof(input), stdin);
            // Remove the newline character at the end if it exists
            input[strcspn(input, "\n")] = 0;

            decompressRLE(input, output);
            printf("Decompressed output: %s\n", output);
            break;

        default:
            printf("Invalid option. Please choose 1 or 2.\n");
            break;
    }

    return 0;
}