//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main() {
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];
    int choice;

    while (true) {
        printf("Enter message to encrypt/decrypt (q to quit):\n");
        fgets(message, MAX_LENGTH, stdin);

        if (message[0] == 'q') {
            break;
        }

        printf("Enter key:\n");
        fgets(key, MAX_LENGTH, stdin);

        printf("Enter 1 to encrypt or 2 to decrypt:\n");
        scanf("%d", &choice);

        // remove newlines from message and key
        message[strcspn(message, "\n")] = '\0';
        key[strcspn(key, "\n")] = '\0';

        switch (choice) {
            case 1:
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case 2:
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // clear buffer
        while ((getchar()) != '\n');
    }

    return 0;
}

void encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    for (int i = 0; i < message_len; i++) {
        message[i] = message[i] ^ key[i % key_len];
    }
}

void decrypt(char* message, char* key) {
    encrypt(message, key); // decryption is just reapplying encryption
}