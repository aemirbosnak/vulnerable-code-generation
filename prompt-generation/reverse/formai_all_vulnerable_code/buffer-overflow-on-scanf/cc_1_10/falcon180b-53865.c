//Falcon-180B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key, int key_length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int i, j, key_index = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((int) message[i] + (int) key[key_index] - 65 % 26 + 65);
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

void decrypt(char* encrypted_message, char* key, char* message) {
    int i, j, key_index = 0;
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            message[i] = (char) ((int) encrypted_message[i] - (int) key[key_index] + 65 % 26 - 65);
            key_index = (key_index + 1) % strlen(key);
        } else {
            message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH], encrypted_message[MAX_MESSAGE_LENGTH];
    int message_length, key_length;

    printf("Enter message: ");
    scanf("%s", message);
    message_length = strlen(message);

    printf("Enter key length: ");
    scanf("%d", &key_length);

    generate_key(key, key_length);

    printf("Encrypted message: ");
    encrypt(message, key, encrypted_message);
    printf("%s\n", encrypted_message);

    printf("Enter key: ");
    scanf("%s", key);

    decrypt(encrypted_message, key, message);
    printf("Decrypted message: %s\n", message);

    return 0;
}