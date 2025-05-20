//Falcon-180B DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 20
#define MAX_MSG_LEN 100

void encrypt(char* msg, char* key);
void decrypt(char* encrypted_msg, char* key);

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    char choice;

    printf("Enter a message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LEN, stdin);

    // Encrypt the message
    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    printf("Do you want to decrypt the message? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Decrypt the message
        decrypt(msg, key);
        printf("Decrypted message: %s\n", msg);
    }

    return 0;
}

void encrypt(char* msg, char* key) {
    int len = strlen(msg);
    int key_len = strlen(key);

    for (int i = 0; i < len; i++) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = msg[i] + (key[i % key_len] - 'a');
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = msg[i] + (key[i % key_len] - 'A');
        }
    }
}

void decrypt(char* encrypted_msg, char* key) {
    int len = strlen(encrypted_msg);
    int key_len = strlen(key);

    for (int i = 0; i < len; i++) {
        if (encrypted_msg[i] >= 'a' && encrypted_msg[i] <= 'z') {
            encrypted_msg[i] = encrypted_msg[i] - (key[i % key_len] - 'a');
        } else if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'Z') {
            encrypted_msg[i] = encrypted_msg[i] - (key[i % key_len] - 'A');
        }
    }
}