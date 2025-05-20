//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[MAX_KEY_SIZE-1] = '\0';
}

void encrypt(char *key, char *message, char *ciphertext) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 'a' + key[i % MAX_KEY_SIZE]) % 26 + 'a';
        }
        ciphertext[i] = c;
    }
    ciphertext[strlen(message)] = '\0';
}

void decrypt(char *key, char *ciphertext, char *message) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            int k = (c - 'a' - key[i % MAX_KEY_SIZE]) % 26 + 26;
            if (k < 0) {
                k += 26;
            }
            c = (char) k;
        }
        message[i] = c;
    }
    message[strlen(ciphertext)] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char ciphertext[MAX_MESSAGE_SIZE];

    generate_key(key);

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(key, ciphertext, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}