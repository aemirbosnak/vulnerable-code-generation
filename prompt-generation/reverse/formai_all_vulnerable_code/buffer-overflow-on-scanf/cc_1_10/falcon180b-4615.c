//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key of length key_length
void generate_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];
    encrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = toupper(message[i]);
            int k = toupper(key[i % strlen(key)]) - 'A';
            char e = 'A' + ((c - 'A' + k) % 26);
            encrypted_message[i] = e;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the encrypted message using the key
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    char decrypted_message[encrypted_message_length + 1];
    decrypted_message[encrypted_message_length] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = encrypted_message[i];
            int k = toupper(key[i % strlen(key)]) - 'A';
            char e = 'A' + ((c - 'A' - k + 26) % 26);
            decrypted_message[i] = e;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    generate_key(key, strlen(message));

    encrypt(message, key);

    decrypt(message, key);

    return 0;
}