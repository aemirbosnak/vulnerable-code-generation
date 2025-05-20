//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 16

// Function to encrypt the message using the given key
void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[strlen(message)];
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (j == KEY_LENGTH) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ key[j];
    }
    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the given key
void decrypt(char* encrypted_message, char* key) {
    int i, j;
    char decrypted_message[strlen(encrypted_message)];
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (j == KEY_LENGTH) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }
    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[KEY_LENGTH];
    printf("Enter message to be encrypted: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Generate a random key
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}