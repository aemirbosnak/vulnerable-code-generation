//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main() {
    char message[100];
    int key;
    int choice;

    printf("Enter message to encrypt/decrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption/decryption key: ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if(choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s", message);
    } else if(choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s", message);
    } else {
        printf("Invalid choice. Please choose either 1 or 2.");
    }

    return 0;
}

void encrypt(char message[], int key) {
    int len = strlen(message);

    for(int i = 0; i < len; i++) {
        char c = message[i];

        if(c >= 'a' && c <= 'z') {
            c = ((c - 'a') + key) % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + key) % 26 + 'A';
        }

        message[i] = c;
    }
}

void decrypt(char message[], int key) {
    int len = strlen(message);

    for(int i = 0; i < len; i++) {
        char c = message[i];

        if(c >= 'a' && c <= 'z') {
            c = ((c - 'a') - key + 26) % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = ((c - 'A') - key + 26) % 26 + 'A';
        }

        message[i] = c;
    }
}