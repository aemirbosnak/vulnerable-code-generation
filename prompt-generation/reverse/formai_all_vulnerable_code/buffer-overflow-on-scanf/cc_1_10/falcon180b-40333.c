//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using a Caesar cipher
void encrypt_message(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 'A' + key) % 26 + 'A';
            } else {
                c = (c - 'a' + key) % 26 + 'a';
            }
            message[i] = c;
        }
    }
}

// Function to decrypt a message using a Caesar cipher
void decrypt_message(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 'A' - key + 26) % 26 + 'A';
            } else {
                c = (c - 'a' - key + 26) % 26 + 'a';
            }
            message[i] = c;
        }
    }
}

// Function to generate a random key between 1 and 25
int generate_key() {
    return rand() % 25 + 1;
}

int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    int key;

    // Get message from user
    printf("Enter a message to encrypt and decrypt: ");
    scanf("%s", message);

    // Generate a random key
    key = generate_key();

    // Encrypt the message using the key
    encrypt_message(message, key);
    strcpy(encrypted_message, message);

    // Decrypt the message using the key
    decrypt_message(encrypted_message, key);
    strcpy(decrypted_message, encrypted_message);

    // Print the encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}