//Falcon-180B DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* key, char* message) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (char)(c + (int)key[i % key_length] - 65);
            } else {
                c = (char)(c + (int)key[i % key_length] - 97);
            }
        }
        encrypted_message[i] = c;
    }
    encrypted_message[message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* key, char* encrypted_message) {
    int key_length = strlen(key);
    int encrypted_message_length = strlen(encrypted_message);
    char decrypted_message[encrypted_message_length + 1];

    for (int i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (char)(c - (int)key[i % key_length] + 65);
            } else {
                c = (char)(c - (int)key[i % key_length] + 97);
            }
        }
        decrypted_message[i] = c;
    }
    decrypted_message[encrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter encryption key: ");
    scanf("%s", key);

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message);
    decrypt(key, message);

    return 0;
}