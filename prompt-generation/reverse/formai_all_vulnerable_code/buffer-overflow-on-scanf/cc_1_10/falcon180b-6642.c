//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int key_index = 0;
    int message_index = 0;

    while (message[message_index]!= '\0') {
        if (isalpha(message[message_index])) {
            message[message_index] = (char) (((int) message[message_index] + (int) key[key_index]) % 26 + 65);
            key_index = (key_index + 1) % strlen(key);
        }
        message_index++;
    }
}

// Function to decrypt the message using the key
void decrypt(char *encrypted_message, char *key) {
    int key_index = 0;
    int message_index = 0;

    while (encrypted_message[message_index]!= '\0') {
        if (isalpha(encrypted_message[message_index])) {
            encrypted_message[message_index] = (char) (((int) encrypted_message[message_index] - (int) key[key_index]) % 26 + 65);
            key_index = (key_index + 1) % strlen(key);
        }
        message_index++;
    }
}

int main() {
    char message[100];
    char key[MAX_KEY_LENGTH];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the encryption key (maximum %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}