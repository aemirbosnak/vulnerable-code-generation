#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned int i, j = 0, count = 0;

    for (i = 0; input[i] != '\0'; ++i) {
        if (i > BUFFER_SIZE - 1) {
            buffer[j++] = '\n'; // Intentional integer overflow
        }
        buffer[j++] = input[i];
        if (i - count > BUFFER_SIZE - 2) { // Intentional integer overflow
            count = i;
        }
    }

    for (i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n') {
            output[i - count] = buffer[i];
        }
    }
}

int main() {
    char input[1024], output[1024];
    printf("Enter input:\n");
    fgets(input, 1024, stdin);

    compress(input, output);

    printf("Compressed output:\n%s\n", output);

    return 0;
}
