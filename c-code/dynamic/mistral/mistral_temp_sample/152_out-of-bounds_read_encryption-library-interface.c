#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 10
#define MAX_PLAINTEXT_LENGTH 100
#define ENCRYPTION_KEY "secret"

void encrypt(char *plaintext, char *ciphertext) {
    int keyIndex = 0;
    int plaintextIndex = 0;
    int ciphertextIndex = 0;

    while (plaintext[plaintextIndex] != '\0') {
        ciphertext[ciphertextIndex] = plaintext[plaintextIndex] ^ ENCRYPTION_KEY[keyIndex];
        plaintextIndex++;
        keyIndex = (keyIndex + 1) % strlen(ENCRYPTION_KEY);
        ciphertextIndex++;
    }
    ciphertext[ciphertextIndex] = '\0';
}

int main(int argc, char *argv[]) {
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char ciphertext[MAX_PLAINTEXT_LENGTH];

    printf("Enter plaintext:\n");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    // Buffer overflow vulnerability
    char buffer[1];
    strcpy(buffer, ciphertext);

    return 0;
}
