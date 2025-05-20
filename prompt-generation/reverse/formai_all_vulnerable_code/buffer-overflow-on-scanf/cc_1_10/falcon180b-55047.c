//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char encrypted_message[message_length];
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = ((message[i] + key[j % key_length]) % 26) + 'A';
            } else {
                encrypted_message[j] = ((message[i] + key[j % key_length]) % 26) + 'a';
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int encrypted_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;
    char decrypted_message[encrypted_length];
    for (i = 0, j = 0; i < encrypted_length; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = ((encrypted_message[i] - key[j % key_length]) % 26) + 'A';
            } else {
                decrypted_message[j] = ((encrypted_message[i] - key[j % key_length]) % 26) + 'a';
            }
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[KEY_LENGTH];
    int i;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key (must be %d characters): ", KEY_LENGTH);
    for (i = 0; i < KEY_LENGTH; i++) {
        scanf("%c", &key[i]);
    }
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}