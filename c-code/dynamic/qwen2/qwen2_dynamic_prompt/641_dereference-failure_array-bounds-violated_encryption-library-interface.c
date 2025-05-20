#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    while (*data) {
        *data = *data + key;
        data++;
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    int key = 3;

    printf("Plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, key);
    printf("Encrypted: %s\n", plaintext);

    // Intentionally create an array bounds violation
    char buffer[10];
    strcpy(buffer, plaintext); // This will overflow if plaintext is too long

    return 0;
}
