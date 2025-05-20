//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1024

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int key_size = strlen(key);
    int message_size = strlen(message);
    int i = 0, j = 0;

    char encrypted_message[message_size];
    memset(encrypted_message, 0, message_size);

    while (i < message_size) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            int ascii_value = ch - 65;
            ascii_value = (ascii_value + key_size) % 26;
            encrypted_message[j++] = ch = ascii_value + 65;
        } else {
            encrypted_message[j++] = message[i++];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char* message, char* key) {
    int key_size = strlen(key);
    int message_size = strlen(message);
    int i = 0, j = 0;

    char decrypted_message[message_size];
    memset(decrypted_message, 0, message_size);

    while (i < message_size) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            int ascii_value = ch - 65;
            ascii_value = (26 - ascii_value + key_size) % 26;
            decrypted_message[j++] = ch = ascii_value + 65;
        } else {
            decrypted_message[j++] = message[i++];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}