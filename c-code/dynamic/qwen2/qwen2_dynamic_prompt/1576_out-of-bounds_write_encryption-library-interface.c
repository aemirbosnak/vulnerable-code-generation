#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key) {
    int len = strlen(data);
    char temp[len + 1];
    strcpy(temp, data);

    for (int i = 0; i <= len; i++) { // Out of bounds write vulnerability
        temp[i] = data[i] ^ key;
    }

    strcpy(data, temp);
}

int main() {
    char plaintext[] = "Hello, World!";
    int key = 42;

    printf("Original: %s\n", plaintext);
    encrypt(plaintext, key);
    printf("Encrypted: %s\n", plaintext);

    return 0;
}
