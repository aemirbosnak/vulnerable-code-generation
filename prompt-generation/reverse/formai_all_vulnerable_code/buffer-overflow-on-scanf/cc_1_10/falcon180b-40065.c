//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16

// Function to generate a random key
void generate_key(char *key) {
    srand(time(NULL));
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = (char) (rand() % 26 + 'A');
    }
    key[KEY_LENGTH] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'A' + key[j % KEY_LENGTH]) % 26 + 'A';
            j++;
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char *ciphertext, char *key) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = (ciphertext[i] - 'A' + 26 - key[j % KEY_LENGTH]) % 26 + 'A';
            j++;
        }
    }
}

int main() {
    char message[100], key[KEY_LENGTH + 1];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using the key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}