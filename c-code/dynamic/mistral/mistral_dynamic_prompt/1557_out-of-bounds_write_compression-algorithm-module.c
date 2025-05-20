#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    char buffer[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; i++) {
        if (i > BUFFER_SIZE - 1) {
            output[j++] = input[i];
        }

        if (i >= BUFFER_SIZE - 1 && input[i + 1] == input[i]) {
            buffer[j++] = '*';
            buffer[j++] = 'r';
            buffer[j++] = 'e';
            buffer[j++] = 'p';
            buffer[j++] = 'e';
            buffer[j++] = 't';
        } else {
            buffer[j++] = input[i];
        }
    }

    for (int k = 0; k < j; k++) {
        output[k] = buffer[k];
    }
}

int main() {
    char input[1024];
    char output[1024];

    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    compress(input, output);

    printf("Compressed: ");
    fputs(output, stdout);

    return 0;
}
