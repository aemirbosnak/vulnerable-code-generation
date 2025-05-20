//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 100
#define KEY_LENGTH 16

void generate_key(char* key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void shift_key(char* key, int shift) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = (key[i] - 'a' + shift) % 26 + 'a';
    }
}

void encrypt(char* message, char* key, char* result) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            result[i] = (message[i] - 'a' + (key[i % KEY_LENGTH] - 'a')) % 26 + 'a';
        } else {
            result[i] = message[i];
        }
    }
}

void decrypt(char* message, char* key, char* result) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            result[i] = (message[i] - (key[i % KEY_LENGTH] - 'a')) % 26 + 'a';
        } else {
            result[i] = message[i];
        }
    }
}

int main() {
    char message[LENGTH];
    char key[KEY_LENGTH];
    char result[LENGTH];

    printf("Enter message to be encrypted: ");
    fgets(message, LENGTH, stdin);

    generate_key(key);

    encrypt(message, key, result);

    printf("Encrypted message: %s\n", result);

    char choice;

    printf("Do you want to decrypt the message? (y/n) ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        decrypt(result, key, message);

        printf("Decrypted message: %s\n", message);
    }

    return 0;
}