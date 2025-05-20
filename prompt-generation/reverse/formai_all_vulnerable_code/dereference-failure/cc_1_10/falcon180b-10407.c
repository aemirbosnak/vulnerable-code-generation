//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 16

void generate_key(char* key) {
    srand(time(NULL));
    for(int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_message_length = message_length + 1;

    for(int i = 0; i < message_length; i++) {
        int message_char_index = message[i] - 'A';
        int key_char_index = key[i % KEY_LENGTH] - 'A';

        encrypted_message[i] = (message_char_index + key_char_index) % 26 + 'A';
    }

    encrypted_message[encrypted_message_length - 1] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int decrypted_message_length = encrypted_message_length - 1;

    for(int i = 0; i < encrypted_message_length; i++) {
        int encrypted_message_char_index = encrypted_message[i] - 'A';
        int key_char_index = key[i % KEY_LENGTH] - 'A';

        int decrypted_message_char_index = (encrypted_message_char_index - key_char_index + 26) % 26;

        decrypted_message[i] = decrypted_message_char_index + 'A';
    }

    decrypted_message[decrypted_message_length] = '\0';
}

int main() {
    char key[KEY_LENGTH + 1];
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    generate_key(key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}