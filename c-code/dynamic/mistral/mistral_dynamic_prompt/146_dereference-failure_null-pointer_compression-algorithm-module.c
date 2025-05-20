#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i;
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    char *ptr = buffer;

    for (i = 0; input[i] != '\0'; i++) {
        *ptr++ = input[i] + 1; // Encrypt each character by adding 1
        if (ptr - buffer >= BUFFER_SIZE) {
            *ptr = '\0';
            strcpy(output, buffer);
            strcpy(buffer, ptr);
            ptr = buffer;
        }
    }

    *ptr = '\0';
    strcpy(output, buffer);

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char *output = argv[2];

    compress(input, output);

    return 0;
}
