//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + 'a') % 26 + 'a';
            } else {
                message[i] = (message[i] - 'a' + 'A') % 26 + 'A';
            }
        }
    }
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - 'a' + key[i % MAX_KEY_SIZE]) % 26 + 'a';
    }
}

void decrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + 'a') % 26 + 'a';
            } else {
                message[i] = (message[i] - 'a' + 'A') % 26 + 'A';
            }
        }
    }
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - key[i % MAX_KEY_SIZE] + 'a') % 26 + 'a';
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    int choice;
    int i;

    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        generate_key(key);
        printf("Key: %s\n", key);
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        printf("Enter the key: ");
        fgets(key, MAX_KEY_SIZE, stdin);
        key[strcspn(key, "\n")] = '\0';
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}