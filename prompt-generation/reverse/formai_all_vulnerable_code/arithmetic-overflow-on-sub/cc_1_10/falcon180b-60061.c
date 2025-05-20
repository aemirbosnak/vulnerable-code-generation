//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = tolower(message[i]);
            int letter_index = letter - 'a';
            int key_index = letter_index + key_index;

            if (key_index >= 26) {
                key_index -= 26;
            }

            encrypted_message[j++] = (char) ('a' + key_index);
        } else {
            encrypted_message[j++] = message[i];
        }
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = tolower(encrypted_message[i]);
            int letter_index = letter - 'a';
            int key_index = letter_index - key_index;

            if (key_index < 0) {
                key_index += 26;
            }

            decrypted_message[j++] = (char) ('a' + key_index);
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}