#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

void compress(char *input) {
    char output[BUFFER_SIZE];
    char *ptr = output;
    char c;

    while ((c = *input++) != '\0') {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        *ptr++ = c;
    }

    *ptr = '\0';
}

int main() {
    char buffer[BUFFER_SIZE];
    char* userInput;

    printf("Enter input: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    userInput = &buffer[0];

    compress(userInput);
    printf("Compressed data: %s\n", userInput);

    return 0;
}
