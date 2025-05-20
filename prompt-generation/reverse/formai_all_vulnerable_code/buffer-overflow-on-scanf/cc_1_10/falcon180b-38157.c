//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char *message, char *key);
void decrypt(char *ciphertext, char *key);

int main() {
    char message[1000];
    char key[KEY_SIZE];
    char choice;

    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter a key (%d characters): ", KEY_SIZE);
    fgets(key, KEY_SIZE, stdin);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case '2':
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void encrypt(char *message, char *key) {
    int i, j;
    char plaintext[1000];
    char ciphertext[1000];

    strcpy(plaintext, message);

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = toupper(plaintext[i] ^ key[i % KEY_SIZE]);
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }

    ciphertext[j] = '\0';
    strcpy(message, ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    char plaintext[1000];

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = toupper(ciphertext[i] ^ key[i % KEY_SIZE]);
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }

    plaintext[j] = '\0';
    strcpy(ciphertext, plaintext);
}