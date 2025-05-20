#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LENGTH 256

void encrypt(char* message, char* key, char* ciphertext) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        ciphertext[i] = message[i] ^ key[i % strlen(key)];
    }
    ciphertext[i] = '\0'; // Out of bounds write vulnerability
}

int main() {
    char message[LENGTH] = "Top secret message";
    char key[LENGTH] = "mySecretKey1234";
    char ciphertext[LENGTH];

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
