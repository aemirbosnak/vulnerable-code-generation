//Falcon-180B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char key[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char plaintext[128], char key[KEY_SIZE]) {
    int i = 0, j = 0;
    char ciphertext[128] = {0};

    while (plaintext[i]!= '\0') {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j] = (((plaintext[i] - 'A' + key[i % KEY_SIZE]) % 26) + 'A');
            } else {
                ciphertext[j] = (((plaintext[i] - 'a' + key[i % KEY_SIZE]) % 26) + 'a');
            }
        } else {
            ciphertext[j] = plaintext[i];
        }
        i++;
        j++;
    }
    strcpy(plaintext, ciphertext);
}

void decrypt(char ciphertext[128], char key[KEY_SIZE]) {
    int i = 0, j = 0;
    char plaintext[128] = {0};

    while (ciphertext[i]!= '\0') {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[j] = (((ciphertext[i] - 'A' - key[i % KEY_SIZE] + 26) % 26) + 'A');
            } else {
                plaintext[j] = (((ciphertext[i] - 'a' - key[i % KEY_SIZE] + 26) % 26) + 'a');
            }
        } else {
            plaintext[j] = ciphertext[i];
        }
        i++;
        j++;
    }
    strcpy(ciphertext, plaintext);
}

int main() {
    char plaintext[128];
    char key[KEY_SIZE];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    generate_key(key);
    encrypt(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    decrypt(plaintext, key);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}