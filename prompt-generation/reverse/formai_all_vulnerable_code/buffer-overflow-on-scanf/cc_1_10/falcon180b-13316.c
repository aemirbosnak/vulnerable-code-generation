//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define KEY_SIZE 10

struct {
    char plaintext[MAX_SIZE];
    char ciphertext[MAX_SIZE];
    char key[KEY_SIZE];
} message;

void generate_key() {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        message.key[i] = rand() % 26 + 'A';
    }
}

void encrypt() {
    int i, j;
    for (i = 0, j = 0; i < strlen(message.plaintext); i++) {
        if (isalpha(message.plaintext[i])) {
            if (isupper(message.plaintext[i])) {
                message.ciphertext[j] = message.key[i % KEY_SIZE] + 'A' - 'A' + 'a';
            } else {
                message.ciphertext[j] = message.key[i % KEY_SIZE] + 'a' - 'A' + 'a';
            }
            j++;
        } else {
            message.ciphertext[j] = message.plaintext[i];
            j++;
        }
    }
    message.ciphertext[j] = '\0';
}

void decrypt() {
    int i, j;
    for (i = 0, j = 0; i < strlen(message.ciphertext); i++) {
        if (isalpha(message.ciphertext[i])) {
            if (isupper(message.ciphertext[i])) {
                message.plaintext[j] = 'A' + 'a' - message.key[i % KEY_SIZE] - 'A';
            } else {
                message.plaintext[j] = 'a' + 'A' - message.key[i % KEY_SIZE] - 'a';
            }
            j++;
        } else {
            message.plaintext[j] = message.ciphertext[i];
            j++;
        }
    }
    message.plaintext[j] = '\0';
}

int main() {
    srand(time(NULL));
    generate_key();
    printf("Enter a message to encrypt: ");
    scanf("%s", message.plaintext);
    encrypt();
    printf("Encrypted message: %s\n", message.ciphertext);
    decrypt();
    printf("Decrypted message: %s\n", message.plaintext);
    return 0;
}