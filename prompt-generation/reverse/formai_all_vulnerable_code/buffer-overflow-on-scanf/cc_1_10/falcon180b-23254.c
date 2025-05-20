//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generate_key(char* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int length = strlen(message);
    char encrypted_message[length + 1];
    encrypted_message[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            char c = toupper(message[i]);
            int k = toupper(key[i % strlen(key)]) - 'A';
            encrypted_message[i] = (c + k) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key) {
    int length = strlen(encrypted_message);
    char decrypted_message[length + 1];
    decrypted_message[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = toupper(encrypted_message[i]);
            int k = toupper(key[i % strlen(key)]) - 'A';
            decrypted_message[i] = (c - k + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[10];

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    generate_key(key, 10);

    printf("Encrypting message...\n");
    encrypt(message, key);

    printf("Decrypting message...\n");
    decrypt(message, key);

    return 0;
}