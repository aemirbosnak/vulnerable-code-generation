//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a message using a key
void encrypt(char *message, char *key) {
    // Base case: message is empty
    if (strlen(message) == 0) {
        return;
    }

    // Recursive case: encrypt each character in the message
    char *encrypted_message = malloc(strlen(message) + 1);
    encrypted_message[0] = '\0';
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key[i % strlen(key)];
    }
    encrypted_message[strlen(message)] = '\0';
    printf("%s\n", encrypted_message);
}

// Decrypt an encrypted message using a key
void decrypt(char *encrypted_message, char *key) {
    // Base case: encrypted message is empty
    if (strlen(encrypted_message) == 0) {
        return;
    }

    // Recursive case: decrypt each character in the encrypted message
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);
    decrypted_message[0] = '\0';
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % strlen(key)];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
    printf("%s\n", decrypted_message);
}

int main() {
    char message[1000] = "Attack at dawn!";
    char key[1000] = "secret_key";

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}