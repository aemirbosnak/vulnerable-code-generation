//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* message, char* key) {
    char encrypted[strlen(message)];
    int i, j;

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted[j++] = (message[i] + key[i % KEY_SIZE]) % 26 + 'a';
        } else {
            encrypted[j++] = message[i];
        }
    }

    encrypted[j] = '\0';
    strcpy(message, encrypted);
}

void decrypt(char* message, char* key) {
    char decrypted[strlen(message)];
    int i, j;

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            decrypted[j++] = (message[i] - key[i % KEY_SIZE] + 26) % 26 + 'a';
        } else {
            decrypted[j++] = message[i];
        }
    }

    decrypted[j] = '\0';
    strcpy(message, decrypted);
}

int main() {
    char message[100], key[KEY_SIZE];
    int choice;

    generate_key(key);

    printf("Enter a message to encrypt:\n");
    scanf("%s", message);

    printf("Encrypted Message: %s\n", message);

    printf("Enter 1 to decrypt the message or 0 to exit:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        decrypt(message, key);
        printf("Decrypted Message: %s\n", message);
    }

    return 0;
}