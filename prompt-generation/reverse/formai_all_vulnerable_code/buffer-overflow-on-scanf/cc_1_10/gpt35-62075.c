//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to encrypt plaintext
void encrypt(char* plaintext, char* key) {
    int n = strlen(plaintext);
    int keylen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == keylen) {
            j = 0;
        }
        plaintext[i] = (plaintext[i] + key[j]) % 256;
    }
}

// Function to decrypt ciphertext
void decrypt(char* ciphertext, char* key) {
    int n = strlen(ciphertext);
    int keylen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == keylen) {
            j = 0;
        }
        ciphertext[i] = (ciphertext[i] - key[j] + 256) % 256;
    }
}

int main() {
    char plaintext[MAX_LEN], ciphertext[MAX_LEN], key[MAX_LEN];
    int choice;

    while (1) {
        printf("Enter choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter plaintext to Encrypt: ");
            scanf(" %[^\n]", plaintext);
            printf("Enter key: ");
            scanf(" %[^\n]", key);

            encrypt(plaintext, key);

            printf("Encrypted text: %s\n", plaintext);
        }
        else if (choice == 2) {
            printf("Enter ciphertext to Decrypt: ");
            scanf(" %[^\n]", ciphertext);
            printf("Enter key: ");
            scanf(" %[^\n]", key);

            decrypt(ciphertext, key);

            printf("Decrypted text: %s\n", ciphertext);
        }
        else if (choice == 3) {
            printf("Exiting Program...\n");
            exit(0);
        }
        else {
            printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}