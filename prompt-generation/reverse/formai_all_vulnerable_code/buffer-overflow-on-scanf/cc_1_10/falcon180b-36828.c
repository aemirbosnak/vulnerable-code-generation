//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

// Function to generate a random key
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the message using the key
void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypted_message[0] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = toupper(message[i]);
            int key_index = (int) (letter - 'A');
            char encrypted_letter = (char) (((key_index + (int) key[i % strlen(key)]) % 26) + 'A');
            strncat(encrypted_message, &encrypted_letter, 1);
        } else {
            strncat(encrypted_message, &message[i], 1);
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt_message(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypted_message[0] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = toupper(encrypted_message[i]);
            int key_index = (int) (letter - 'A');
            char decrypted_letter = (char) (((key_index - (int) key[i % strlen(key)]) % 26) + 'A');
            strncat(decrypted_message, &decrypted_letter, 1);
        } else {
            strncat(decrypted_message, &encrypted_message[i], 1);
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    srand(time(NULL));

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(message));

    encrypt_message(message, key);
    printf("\n");

    decrypt_message(message, key);

    return 0;
}