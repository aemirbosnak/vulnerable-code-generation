#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input) {
    int i, j = 0;
    char output[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; ++i) {
        if (i == BUFFER_SIZE - 1 || input[i + 1] != input[i]) {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    printf("Compressed data: %s\n", output);
}

int main() {
    char input[BUFFER_SIZE];

    printf("Enter data to compress:\n");
    fgets(input, BUFFER_SIZE, stdin);

    compress(input);

    return 0;
}
