//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt a message
void encrypt(char* message, char* key) {
    int message_size = strlen(message);
    int key_size = strlen(key);
    char encrypted_message[message_size];

    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c += 'a' - 'A';
            }
            encrypted_message[i] = (c - key[i % key_size] + 26) % 26 + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_size] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt a message
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_size = strlen(encrypted_message);
    int key_size = strlen(key);
    char decrypted_message[encrypted_message_size];

    for (int i = 0; i < encrypted_message_size; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = encrypted_message[i];
            if (isupper(c)) {
                c += 'A' - 'a';
            }
            decrypted_message[i] = (c - key[i % key_size] - 'a' + 26) % 26 + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_size] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[26];
    int key_size = 10;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key, key_size);

    encrypt(message, key);

    decrypt(message, key);

    return 0;
}