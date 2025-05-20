#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key) {
    int len = strlen(data);
    char temp[len + 1];
    memcpy(temp, data, len);
    temp[len] = '\0';

    for (int i = 0; i <= len; i++) { // Out of bounds write vulnerability
        data[i] = temp[i] ^ key;
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    int key = 42;

    printf("Plaintext: %s\n", plaintext);

    encrypt(plaintext, key);

    printf("Encrypted: %s\n", plaintext);

    return 0;
}
