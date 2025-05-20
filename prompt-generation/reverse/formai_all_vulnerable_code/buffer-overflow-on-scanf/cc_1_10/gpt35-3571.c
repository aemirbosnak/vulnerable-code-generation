//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main(void) {
    char message[256], key[256], choice;

    printf("Enter message to encrypt: ");
    fgets(message, 256, stdin);
    message[strcspn(message, "\r\n")] = 0;

    printf("Enter encryption key: ");
    fgets(key, 256, stdin);
    key[strcspn(key, "\r\n")] = 0;

    printf("Enter E to encrypt or D to decrypt: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'E':
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 'D':
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void encrypt(char *message, char *key) {
    int i, j = 0, len = strlen(key);

    for (i = 0; message[i] != '\0'; i++) {
        if (j == len) {
            j = 0;
        }
        
        message[i] = (message[i] + key[j]) % 128;
        j++;
    }
}

void decrypt(char *message, char *key) {
    int i, j = 0, len = strlen(key);

    for (i = 0; message[i] != '\0'; i++) {
        if (j == len) {
            j = 0;
        }
        
        message[i] = (message[i] - key[j] + 128) % 128;
        j++;
    }
}