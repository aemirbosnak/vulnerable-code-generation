#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define THRESHOLD 128

void compress(char *input, char *output) {
    int i, j = 0, count[256];
    memset(count, 0, sizeof(count));

    for (i = 0; input[i]; i++) {
        count[input[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i]) {
            output[j++] = (char)i;
            output[j++] = (char)count[i];
        }
    }

    for (i = j; input[i]; i++) {
        int prev = (char)output[j - 2];
        output[j++] = (char)(i - prev);
        if (i - THRESHOLD > THRESHOLD) {
            output[j++] = input[i];
        }
    }
}

int main() {
    char input[BUFFER_SIZE], output[BUFFER_SIZE * 2];
    printf("Enter text to compress:\n");
    fgets(input, BUFFER_SIZE, stdin);

    compress(input, output);

    printf("Compressed data:\n");
    fwrite(output, sizeof(char), sizeof(output), stdout);

    return 0;
}
