//Falcon-180B DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100
#define BLOCK_SIZE 16
#define KEY_SIZE 16

void encrypt(char *message, int size, char *key) {
    int i;
    char block[BLOCK_SIZE];
    char ciphertext[MAX_SIZE];
    int j = 0;

    for (i = 0; i < size; i += BLOCK_SIZE) {
        strncpy(block, message + i, BLOCK_SIZE);
        block[BLOCK_SIZE-1] = '\0';
        int key_index = 0;
        for (int k = 0; k < BLOCK_SIZE; k++) {
            int temp = block[k] ^ key[key_index];
            ciphertext[j++] = temp;
            key_index++;
            if (key_index == KEY_SIZE) {
                key_index = 0;
            }
        }
    }
    ciphertext[j] = '\0';
    strcpy(message, ciphertext);
}

void decrypt(char *message, int size, char *key) {
    int i;
    char block[BLOCK_SIZE];
    char plaintext[MAX_SIZE];
    int j = 0;

    for (i = 0; i < size; i += BLOCK_SIZE) {
        strncpy(block, message + i, BLOCK_SIZE);
        block[BLOCK_SIZE-1] = '\0';
        int key_index = 0;
        for (int k = 0; k < BLOCK_SIZE; k++) {
            int temp = block[k] ^ key[key_index];
            plaintext[j++] = temp;
            key_index++;
            if (key_index == KEY_SIZE) {
                key_index = 0;
            }
        }
    }
    plaintext[j] = '\0';
    strcpy(message, plaintext);
}

int main() {
    char message[MAX_SIZE];
    char key[KEY_SIZE];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);

    encrypt(message, strlen(message), key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, strlen(encrypted_message), key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}