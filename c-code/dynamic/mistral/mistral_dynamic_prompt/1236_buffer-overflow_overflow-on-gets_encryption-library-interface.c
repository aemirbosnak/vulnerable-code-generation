#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LEN 256

void encrypt(char *input, char *output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] + 3;
    }
    output[i] = '\0';
}

int main(int argc, char **argv) {
    char buffer[LEN];
    printf("Enter the message to encrypt: ");
    gets(buffer);

    char encrypted[LEN];
    encrypt(buffer, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}
