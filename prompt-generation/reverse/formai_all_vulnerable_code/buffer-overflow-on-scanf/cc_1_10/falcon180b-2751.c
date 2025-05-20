//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *key, char *message) {
    int i, j;
    char encrypted_message[strlen(message)];

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + (int)key[i % KEY_SIZE]) % 26 + 'A';
            } else {
                encrypted_message[j] = (message[i] + (int)key[i % KEY_SIZE]) % 26 + 'a';
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    strcpy(message, encrypted_message);
}

void decrypt(char *key, char *message) {
    int i, j;
    char decrypted_message[strlen(message)];

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[j] = ((int)message[i] - (int)key[i % KEY_SIZE]) % 26 + 'A';
            } else {
                decrypted_message[j] = ((int)message[i] - (int)key[i % KEY_SIZE]) % 26 + 'a';
            }
            j++;
        } else {
            decrypted_message[j] = message[i];
            j++;
        }
    }

    strcpy(message, decrypted_message);
}

int main() {
    char key[KEY_SIZE];
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];

    generate_key(key);

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(key, encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}