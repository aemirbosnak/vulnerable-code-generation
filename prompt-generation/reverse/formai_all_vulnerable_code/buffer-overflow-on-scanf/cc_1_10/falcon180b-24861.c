//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message, int message_size) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = ((message[i] - 'a' + key[i % strlen(key)]) % 26) + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_size] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message, int message_size) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = ((encrypted_message[i] - 'a' - key[i % strlen(key)]) % 26) + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[message_size] = '\0';
}

int main() {
    char message[1000];
    char key[100];
    char encrypted_message[1000];
    char decrypted_message[1000];
    int message_size;
    int key_size;

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message_size = strlen(message);

    printf("Enter the key to be used for encryption: ");
    scanf("%s", key);
    key_size = strlen(key);

    generate_key(key, key_size);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message, message_size);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}