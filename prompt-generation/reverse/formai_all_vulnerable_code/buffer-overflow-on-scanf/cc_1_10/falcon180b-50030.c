//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[1000];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = (message[i] - 'A' + key[i % KEY_LENGTH] - 'A') % 26 + 'A';
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j;
    char decrypted_message[1000];
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j++] = (encrypted_message[i] - key[i % KEY_LENGTH] - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000], key[KEY_LENGTH + 1];
    generate_key(key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(message, key);
    return 0;
}