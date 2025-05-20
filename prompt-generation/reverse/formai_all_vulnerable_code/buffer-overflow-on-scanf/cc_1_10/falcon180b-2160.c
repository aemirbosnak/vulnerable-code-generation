//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_SIZE 64
#define MAX_BLOCK_SIZE 16

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    // Pad the message with spaces to make it a multiple of the block size
    for (i = message_length; i % MAX_BLOCK_SIZE!= 0; i++) {
        strcat(message, " ");
    }

    // Convert the message and key to uppercase
    for (i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]);
    }
    for (i = 0; i < key_length; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the message
    for (i = 0, j = 0; i < message_length; i += MAX_BLOCK_SIZE, j++) {
        char block[MAX_BLOCK_SIZE];
        strncpy(block, message + i, MAX_BLOCK_SIZE);
        block[MAX_BLOCK_SIZE - 1] = '\0';

        char encrypted_block[MAX_BLOCK_SIZE];
        int k = 0;
        for (int l = 0; l < MAX_BLOCK_SIZE; l++) {
            if (isalpha(block[l])) {
                encrypted_block[k++] = (char)(block[l] + key[j % key_length] - 65);
            } else {
                encrypted_block[k++] = block[l];
            }
        }
        strcat(encrypted_message, encrypted_block);
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;

    // Decrypt the message
    for (i = 0, j = 0; i < encrypted_length; i += MAX_BLOCK_SIZE, j++) {
        char block[MAX_BLOCK_SIZE];
        strncpy(block, encrypted_message + i, MAX_BLOCK_SIZE);
        block[MAX_BLOCK_SIZE - 1] = '\0';

        char decrypted_block[MAX_BLOCK_SIZE];
        int k = 0;
        for (int l = 0; l < MAX_BLOCK_SIZE; l++) {
            if (isalpha(block[l])) {
                decrypted_block[k++] = (char)(block[l] - key[j % key_length] + 65);
            } else {
                decrypted_block[k++] = block[l];
            }
        }
        strcat(decrypted_message, decrypted_block);
    }
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_KEY_SIZE];
    char decrypted_message[MAX_KEY_SIZE];

    // Get the message and key from the user
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}