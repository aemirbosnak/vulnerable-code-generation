//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02X", key[i]);
    }
    printf("\n");

    unsigned char plaintext[BLOCK_SIZE];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    unsigned char ciphertext[BLOCK_SIZE];
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    unsigned char decrypted_text[BLOCK_SIZE];
    decrypt(ciphertext, key, decrypted_text);
    printf("Decrypted text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", decrypted_text[i]);
    }
    printf("\n");

    return 0;
}