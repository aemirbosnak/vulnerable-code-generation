//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 100

void encrypt(char key[], char message[], char encrypted_message[]);
void decrypt(char key[], char encrypted_message[], char decrypted_message[]);

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf("%s", message);

    encrypt(key, message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(key, encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

void encrypt(char key[], char message[], char encrypted_message[]) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        char message_char = message[i];
        char encrypted_char;

        if (isalpha(message_char)) {
            encrypted_char = (char) ((message_char + key_length - 65) % 26 + 65);
        } else {
            encrypted_char = message_char;
        }

        encrypted_message[encrypted_message_length++] = encrypted_char;
    }

    encrypted_message[encrypted_message_length] = '\0';
}

void decrypt(char key[], char encrypted_message[], char decrypted_message[]) {
    int key_length = strlen(key);
    int encrypted_message_length = strlen(encrypted_message);
    int decrypted_message_length = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        char encrypted_char = encrypted_message[i];
        char decrypted_char;

        if (isalpha(encrypted_char)) {
            decrypted_char = (char) ((encrypted_char - key_length - 65) % 26 + 65);
        } else {
            decrypted_char = encrypted_char;
        }

        decrypted_message[decrypted_message_length++] = decrypted_char;
    }

    decrypted_message[decrypted_message_length] = '\0';
}