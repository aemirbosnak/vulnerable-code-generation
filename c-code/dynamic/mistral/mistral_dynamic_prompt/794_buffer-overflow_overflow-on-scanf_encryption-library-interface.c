#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_SIZE 256

void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % MAX_KEY_SIZE];
    }
    ciphertext[i] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char plaintext[1024];
    char ciphertext[1024];

    printf("Enter encryption key (max length %d): ", MAX_KEY_SIZE);
    scanf("%s", key); // Buffer overflow vulnerability here

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
