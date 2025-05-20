#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char key[256];
    char iv[256];
} EncryptionKey;

void encrypt(EncryptionKey* key, char* plaintext, char* ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key->key[i % 256] ^ key->iv[i / 32];
    }
}

int main() {
    EncryptionKey myKey = {"mysecretkey", "myinitializationvector"};
    char plaintext[] = "This is a secret message";
    char ciphertext[strlen(plaintext) + 1];

    encrypt(&myKey, plaintext, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    // Intentionally accessing an out-of-bounds element in the key array
    printf("Key's 257th character: %c\n", myKey.key[257]);

    return 0;
}
