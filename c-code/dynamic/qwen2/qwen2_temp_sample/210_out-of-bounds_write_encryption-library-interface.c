#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int len) {
    char key[] = "secret";
    int key_len = strlen(key);
    
    for (int i = 0; i < len; i++) {
        data[i] ^= key[i % key_len];
    }
}

void decrypt(char *data, int len) {
    encrypt(data, len); // Reusing the same function for decryption
}

int main() {
    char plaintext[] = "This is a secret message!";
    int len = strlen(plaintext);

    printf("Original: %s\n", plaintext);
    
    encrypt(plaintext, len + 10); // Deliberate out-of-bounds write
    
    printf("Encrypted: %s\n", plaintext);
    
    decrypt(plaintext, len + 10); // Deliberate out-of-bounds read
    
    printf("Decrypted: %s\n", plaintext);
    
    return 0;
}
