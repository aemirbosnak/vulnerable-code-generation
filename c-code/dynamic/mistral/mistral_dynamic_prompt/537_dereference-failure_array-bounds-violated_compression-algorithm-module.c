#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CHUNK_SIZE 256

void compress(char* input, char* output) {
    int i, j, k;
    char compressed[BUFFER_SIZE];

    for (i = j = 0; input[i] != '\0'; ++i) {
        if (i - k > CHUNK_SIZE) {
            compressed[j++] = input[k++];
            compressed[j++] = ' ';
            compressed[j++] = 'X';
        }
        compressed[j++] = input[i];
    }

    compressed[j++] = '\0';

    strcpy(output, compressed);
}

int main() {
    char input[BUFFER_SIZE] = "This is a test of the emergency compression system.";
    char output[BUFFER_SIZE];

    compress(input, output);

    printf("Compressed data: %s\n", output);

    // Accessing past the end of the output buffer
    printf("%c", output[BUFFER_SIZE]);

    return 0;
}
