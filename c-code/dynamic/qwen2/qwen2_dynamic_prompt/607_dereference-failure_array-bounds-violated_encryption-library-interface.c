#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int length) {
    char key = 'A';
    for (int i = 0; i <= length; i++) { // Dereference failure here: array bounds violated
        data[i] = data[i] ^ key;
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    int length = sizeof(plaintext) / sizeof(plaintext[0]);

    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, length);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
