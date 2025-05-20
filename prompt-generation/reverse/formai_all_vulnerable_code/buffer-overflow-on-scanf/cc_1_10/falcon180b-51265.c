//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define KEY_SIZE 16

void generate_key(char key[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char message[SIZE], char key[KEY_SIZE]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char letter = tolower(message[i]);
            int index = letter - 'a';
            message[i] = (char) (((int) letter + (int) key[index % KEY_SIZE]) % 26 + 'a');
        }
    }
}

void decrypt(char encrypted_message[SIZE], char key[KEY_SIZE]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = tolower(encrypted_message[i]);
            int index = letter - 'a';
            encrypted_message[i] = (char) (((int) letter - (int) key[index % KEY_SIZE] + 26) % 26 + 'a');
        }
    }
}

int main() {
    char message[SIZE];
    char encrypted_message[SIZE];
    char key[KEY_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}