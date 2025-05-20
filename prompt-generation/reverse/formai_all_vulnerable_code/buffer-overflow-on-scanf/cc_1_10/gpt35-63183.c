//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input, char *output) {

    int count = 1;
    char current = input[0];
    int i, j = 0;

    for (i = 1; input[i] != '\0'; i++) {

        // Check if the current character matches the previous one
        if (current == input[i]) {
            count++;
        } else {
            // If not, add the count and character to the output string
            output[j++] = current;
            output[j++] = '0' + count;
            current = input[i];
            count = 1;
        }
    }

    // Add the last character and count to the output string
    output[j++] = current;
    output[j++] = '0' + count;
    output[j] = '\0';
}

void decompress(char *input, char *output) {

    int i, j = 0;

    for (i = 0; input[i] != '\0'; i += 2) {
        int count = input[i+1] - '0';
        int k;
        for (k = 0; k < count; k++) {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
}

int main() {

    char input[100], output[200];

    printf("Enter a string to compress: ");
    scanf("%s", input);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    decompress(output, input);

    printf("Decompressed string: %s\n", input);

    return 0;
}