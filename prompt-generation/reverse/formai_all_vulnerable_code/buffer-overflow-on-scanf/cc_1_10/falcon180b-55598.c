//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32 // Maximum key size
#define MAX_TEXT_SIZE 1000 // Maximum text size
#define MAX_CIPHER_SIZE (MAX_TEXT_SIZE + 1) // Maximum cipher size

typedef struct {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char cipher[MAX_CIPHER_SIZE];
} Message;

void generate_key(char key[MAX_KEY_SIZE]) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt(char key[MAX_KEY_SIZE], char text[MAX_TEXT_SIZE], char cipher[MAX_CIPHER_SIZE]) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            cipher[i] = (char) ((int) text[i] + (int) key[i % strlen(key)] - 65);
        } else {
            cipher[i] = text[i];
        }
    }
    cipher[strlen(text)] = '\0';
}

void decrypt(char key[MAX_KEY_SIZE], char cipher[MAX_CIPHER_SIZE], char text[MAX_TEXT_SIZE]) {
    for (int i = 0; i < strlen(cipher); i++) {
        if (isalpha(cipher[i])) {
            text[i] = (char) ((int) cipher[i] - (int) key[i % strlen(key)] + 65);
        } else {
            text[i] = cipher[i];
        }
    }
    text[strlen(cipher)] = '\0';
}

int main() {
    Message message;
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char cipher[MAX_CIPHER_SIZE];

    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the text: ");
    scanf("%s", text);

    generate_key(key);
    encrypt(key, text, cipher);

    printf("Cipher: %s\n", cipher);
    printf("Enter the cipher: ");
    scanf("%s", cipher);

    decrypt(key, cipher, text);
    printf("Text: %s\n", text);

    return 0;
}