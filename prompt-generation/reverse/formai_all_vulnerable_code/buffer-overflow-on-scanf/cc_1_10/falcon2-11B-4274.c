//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int public_key;
} Key;

void encrypt(Key* key, char* plaintext) {
    printf("Encrypting message...\n");
    int encrypted_text[strlen(plaintext)];
    for (int i = 0; i < strlen(plaintext); i++) {
        encrypted_text[i] = (plaintext[i] + key->public_key) % 256;
    }
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%c", encrypted_text[i]);
    }
    printf("\n");
}

void decrypt(Key* key, char* ciphertext) {
    printf("Decrypting message...\n");
    int decrypted_text[strlen(ciphertext)];
    for (int i = 0; i < strlen(ciphertext); i++) {
        decrypted_text[i] = (ciphertext[i] - key->public_key) % 256;
    }
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%c", decrypted_text[i]);
    }
    printf("\n");
}

int main() {
    Key key;
    printf("Enter the private key: ");
    scanf("%d", &key.key);
    printf("Enter the public key: ");
    scanf("%d", &key.public_key);
    char plaintext[100];
    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    char ciphertext[100];
    encrypt(&key, plaintext);
    decrypt(&key, ciphertext);
    printf("The original message was: %s\n", plaintext);
    printf("The encrypted message is: %s\n", ciphertext);
    return 0;
}