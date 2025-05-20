//Falcon-180B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        char message_char = message[i];
        if (isalpha(message_char)) {
            message_char = tolower(message_char);
            int key_index = message_char - 'a';
            if (key_index < 0) {
                key_index += 26;
            }
            encrypted_message[encrypted_message_length++] = key[key_index % key_length];
        } else {
            encrypted_message[encrypted_message_length++] = message_char;
        }
    }
    encrypted_message[encrypted_message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int key_length = strlen(key);
    int encrypted_message_length = strlen(encrypted_message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int decrypted_message_length = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        char encrypted_message_char = encrypted_message[i];
        if (isalpha(encrypted_message_char)) {
            int key_index = tolower(encrypted_message_char) - 'a';
            if (key_index < 0) {
                key_index += 26;
            }
            decrypted_message[decrypted_message_length++] = key[key_index % key_length];
        } else {
            decrypted_message[decrypted_message_length++] = encrypted_message_char;
        }
    }
    decrypted_message[decrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}