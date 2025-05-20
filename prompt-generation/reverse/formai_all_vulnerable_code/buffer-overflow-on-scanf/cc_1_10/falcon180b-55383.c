//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8
#define ROUNDS 10

void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_index = 0;
    char encrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (message[i] + key[key_index]) % 26 + 'A';
            } else {
                encrypted_message[i] = (message[i] + key[key_index]) % 26 + 'a';
            }
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_index = 0;
    char decrypted_message[encrypted_message_length];

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = (encrypted_message[i] - key[key_index] + 26) % 26 + 'A';
            } else {
                decrypted_message[i] = (encrypted_message[i] - key[key_index] + 26) % 26 + 'a';
            }
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    generate_key(key);

    printf("Encrypted message:\n");
    encrypt(message, key);

    printf("\nDecrypted message:\n");
    decrypt(message, key);

    return 0;
}