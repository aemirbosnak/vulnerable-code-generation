//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = ((plaintext[i] - 'A') + (key[i % KEY_SIZE] - 'A')) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = ((ciphertext[i] - 'A') - (key[i % KEY_SIZE] - 'A' + 26)) % 26 + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[100], key[KEY_SIZE], ciphertext[100];
    srand(time(NULL));
    generate_key(key);

    printf("Enter plaintext to encrypt: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}