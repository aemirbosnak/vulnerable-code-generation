//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char* key) {
    const char alphanumeric[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int key_length = rand() % MAX_KEY_LENGTH + 1;
    for (int i = 0; i < key_length; i++) {
        key[i] = alphanumeric[rand() % strlen(alphanumeric)];
    }
    key[key_length] = '\0';
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key[key_index];
        key_index++;
        if (key_index == key_length) {
            key_index = 0;
        }
    }
}

// Function to decrypt a message using a key
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < encrypted_message_length; i++) {
        encrypted_message[i] = encrypted_message[i] ^ key[key_index];
        key_index++;
        if (key_index == key_length) {
            key_index = 0;
        }
    }
}

int main() {
    srand(time(0));
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    char key[MAX_KEY_LENGTH];
    generate_key(key);
    printf("Key: %s\n", key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}