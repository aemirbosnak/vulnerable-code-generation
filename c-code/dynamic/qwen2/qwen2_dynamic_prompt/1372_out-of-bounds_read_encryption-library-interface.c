#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void encrypt(const char *input, char *output) {
    int len = strlen(input);
    if (len > BUFFER_SIZE) {
        printf("Input too large\n");
        return;
    }
    for (int i = 0; i <= len; i++) { // Out of bounds read vulnerability
        output[i] = input[i] + 3;
    }
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);

    encrypt(input, output);

    printf("Encrypted string: %s\n", output);

    return 0;
}
