//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024
#define MAX_MESSAGE_LENGTH 1024

// Function to generate a random key
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = toupper(message[i]);
            int key_index = letter - 'A';
            encrypted_message[encrypted_message_length++] = key[key_index % strlen(key)];
        } else {
            encrypted_message[encrypted_message_length++] = message[i];
        }
    }
    encrypted_message[encrypted_message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using a key
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int decrypted_message_length = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = toupper(encrypted_message[i]);
            int key_index = letter - 'A';
            char decrypted_letter = 'A' + (key_index % strlen(key));
            decrypted_message[decrypted_message_length++] = decrypted_letter;
        } else {
            decrypted_message[decrypted_message_length++] = encrypted_message[i];
        }
    }
    decrypted_message[decrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(key));

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}