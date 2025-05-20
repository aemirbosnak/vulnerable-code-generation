//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_MESSAGE_LENGTH 10000

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - 'a';
            encrypted_message[i] = key[key_index % key_length] + letter_index;
            key_index++;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
    strcpy(message, encrypted_message);
}

void decrypt_message(char *message, char *key) {
    int message_length = strlen(message);
    char decrypted_message[message_length + 1];
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - 'a';
            decrypted_message[i] = 'a' + (letter_index - key[key_index % key_length]);
            key_index++;
        } else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[message_length] = '\0';
    strcpy(message, decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}