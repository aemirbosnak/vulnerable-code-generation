//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char message[MAX_MESSAGE_LENGTH];
    int message_length;
} EncryptedMessage;

EncryptedMessage generate_encrypted_message(char* message, char* key) {
    int message_length = strlen(message);
    EncryptedMessage encrypted_message;
    encrypted_message.key_length = strlen(key);
    encrypted_message.message_length = message_length;
    strcpy(encrypted_message.key, key);
    strcpy(encrypted_message.message, message);

    int i, j;
    for (i = 0, j = 0; i < message_length; i++) {
        char current_char = toupper(message[i]);
        if (isalpha(current_char)) {
            encrypted_message.message[j] = current_char ^ key[j % encrypted_message.key_length];
            j++;
        } else {
            encrypted_message.message[j] = message[i];
            j++;
        }
    }

    return encrypted_message;
}

EncryptedMessage decrypt_message(EncryptedMessage encrypted_message) {
    int message_length = encrypted_message.message_length;
    EncryptedMessage decrypted_message;
    decrypted_message.key_length = encrypted_message.key_length;
    decrypted_message.message_length = message_length;
    strcpy(decrypted_message.key, encrypted_message.key);

    int i, j;
    for (i = 0, j = 0; i < message_length; i++) {
        char current_char = encrypted_message.message[i];
        if (isalpha(current_char)) {
            decrypted_message.message[j] = current_char ^ encrypted_message.key[j % encrypted_message.key_length];
            j++;
        } else {
            decrypted_message.message[j] = current_char;
            j++;
        }
    }

    return decrypted_message;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);

    printf("Enter encryption key: ");
    scanf("%[^\n]", key);

    EncryptedMessage encrypted_message = generate_encrypted_message(message, key);

    printf("Encrypted message: %s\n", encrypted_message.message);

    EncryptedMessage decrypted_message = decrypt_message(encrypted_message);

    printf("Decrypted message: %s\n", decrypted_message.message);

    return 0;
}