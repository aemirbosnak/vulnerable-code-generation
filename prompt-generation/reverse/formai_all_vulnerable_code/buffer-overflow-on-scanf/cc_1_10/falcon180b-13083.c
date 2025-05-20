//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY 256
#define MAX_PLAINTEXT 1024

void generate_key(char* key, int key_len) {
    srand(time(NULL));
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_len - 1] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = plaintext[i] + key[i % strlen(key)];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = ciphertext[i] - key[i % strlen(key)];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char key[MAX_KEY];
    char plaintext[MAX_PLAINTEXT];
    char ciphertext[MAX_PLAINTEXT];

    printf("Enter a plaintext message: ");
    fgets(plaintext, MAX_PLAINTEXT, stdin);

    printf("Enter a key: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}