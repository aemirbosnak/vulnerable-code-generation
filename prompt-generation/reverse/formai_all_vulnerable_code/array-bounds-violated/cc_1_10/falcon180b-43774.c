//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define BASE_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define ENCRYPTION_KEY "mysecretkey"

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int key_length;
    int message_length;
    int i;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Check key length
    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key length must be less than or equal to %d\n", MAX_KEY_LENGTH);
        return 1;
    }

    // Check message length
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: Message length must be less than or equal to %d\n", MAX_MESSAGE_LENGTH);
        return 1;
    }

    // Encrypt message
    for (i = 0; i < message_length; i++) {
        char message_char = tolower(message[i]);
        char key_char = tolower(key[i % key_length]);
        int alphabet_index = message_char - 'a';
        int key_index = key_char - 'a';
        encrypted_message[i] = BASE_ALPHABET[alphabet_index + key_index];
    }
    encrypted_message[message_length] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}