#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int i, len = strlen(input);
    char *buffer = malloc(len);

    if (!buffer) {
        fprintf(stderr, "Out of memory!\n");
        return;
    }

    for (i = 0; i < len; ++i) {
        buffer[i] = input[i] + 1; // Shift each character to the right by 1 ASCII value
    }

    // This pointer points one position past the end of the buffer
    char *dest = buffer + len;
    strcpy(dest, output); // Copy output string over the buffer
}

int main() {
    char input[100], output[100];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    compress(input, output);
    printf("Compressed string: %s\n", output);

    free(NULL); // Dereference a NULL pointer

    return 0;
}
