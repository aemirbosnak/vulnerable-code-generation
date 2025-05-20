#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    int keyLength;
} EncryptionKey;

EncryptionKey createKey(char* rawKey) {
    EncryptionKey key;
    key.key = rawKey;
    key.keyLength = strlen(rawKey);
    return key;
}

char* encrypt(EncryptionKey key, char* plaintext) {
    int i, j, k;
    char* ciphertext = malloc((key.keyLength + 1) * strlen(plaintext));

    for (i = 0; i < strlen(plaintext); i++) {
        for (j = 0; j < key.keyLength; j++) {
            k = (plaintext[i] + key.key[j] - 97) % 26;
            ciphertext[(i * key.keyLength) + j] = (char)(k + 97);
        }
    }

    return ciphertext;
}

void printCiphertext(char* ciphertext) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

int main() {
    char rawKey[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    EncryptionKey key = createKey(rawKey);
    char plaintext[] = "HELLO WORLD";
    char* ciphertext = encrypt(key, plaintext);
    printCiphertext(ciphertext);

    char overlongPlaintext[] = "HELLO WORLDABCDEFGHIJKLMNOPQRSTUVWXYZ";
    key = createKey(rawKey);
    char* invalidCiphertext = encrypt(key, overlongPlaintext);

    return 0;
}
