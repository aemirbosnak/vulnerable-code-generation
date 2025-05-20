#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; input[i]; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (output[j]) ++j;
        } else {
            output[j++] = input[i];
            if (j >= BUFFER_SIZE - 1) break;
        }
    }

    output[j] = '\0';
    printf("Compressed data: %s\n", output);
}

int main() {
    char buffer[1024];

    printf("Enter input data (up to 1023 characters):\n");
    fscanf(stdin, "%s", buffer);

    compress(buffer);

    return 0;
}
