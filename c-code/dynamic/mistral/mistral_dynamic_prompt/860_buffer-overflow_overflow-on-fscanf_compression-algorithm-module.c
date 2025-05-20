#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void compress(char *input) {
    char output[BUFFER_SIZE];
    char *ptr = output;

    while (*input) {
        *ptr++ = *input++;
        if (*ptr++ - *ptr == *ptr - *(ptr - 1) - 1)
            *(ptr - 1) = '*';
    }

    *ptr = '\0';
}

int main() {
    char input[1024];

    printf("Enter a string to compress:\n");
    fgets(input, sizeof(input), stdin);

    compress(input);
    printf("Compressed string: %s\n", input);

    // Intentionally create a buffer overflow by reading more characters than the buffer can hold
    fscanf(stdin, "%*[^\n]");

    return 0;
}
