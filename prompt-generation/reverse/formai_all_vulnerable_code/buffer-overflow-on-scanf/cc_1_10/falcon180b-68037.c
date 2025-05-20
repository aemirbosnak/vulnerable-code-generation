//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define KEY_SIZE 13

// Function to encrypt message using Caesar cipher
void caesar_encrypt(char* message, int key, char* result) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int shift = (c - 'a' + key) % ALPHABET_SIZE;
            result[j++] = (shift + 'a');
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
}

// Function to decrypt message using Caesar cipher
void caesar_decrypt(char* message, int key, char* result) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int shift = (c - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE;
            result[j++] = (shift + 'a');
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
}

// Function to generate a random key of given size
void generate_key(char* key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        key[i] = 'a' + rand() % ALPHABET_SIZE;
    }
    key[size] = '\0';
}

int main() {
    char message[1000];
    char key[KEY_SIZE];
    char encrypted_message[1000];
    char decrypted_message[1000];

    // Get user input
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, KEY_SIZE);

    // Encrypt message using Caesar cipher
    caesar_encrypt(message, atoi(key), encrypted_message);

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message using Caesar cipher
    caesar_decrypt(encrypted_message, atoi(key), decrypted_message);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}