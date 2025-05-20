//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            c = (c - 'a' + (key[i % KEY_SIZE] - 'a')) % 26 + 'a';
        }
        ciphertext[i] = c;
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            c = (c - 'a' - (key[i % KEY_SIZE] - 'a') + 26) % 26 + 'a';
        }
        plaintext[i] = c;
    }
}

int main() {
    char key[KEY_SIZE];
    generate_key(key);

    printf("Key: %s\n", key);

    char plaintext[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    char ciphertext[100];
    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_text[100];
    decrypt(ciphertext, key, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}