#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define COMPRESSION_FACTOR 3

void compress(char *input, char *output) {
    int inputIndex = 0;
    int outputIndex = 0;
    char prevChar;
    int repeatCount = 1;

    while (inputIndex < BUFFER_SIZE && input[inputIndex]) {
        if (input[inputIndex] != prevChar) {
            output[outputIndex++] = prevChar;
            if (repeatCount > COMPRESSION_FACTOR) {
                output[outputIndex++] = input[inputIndex];
                repeatCount = 1;
            } else {
                repeatCount++;
            }
        }
        prevChar = input[inputIndex++];
    }

    // Intentionally out-of-bounds write
    output[outputIndex++] = '\0';
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter a string to compress:\n");
    fgets(input, BUFFER_SIZE, stdin);

    char compressed[BUFFER_SIZE];
    compress(input, compressed);

    printf("Compressed string:\n%s\n", compressed);

    return 0;
}
