//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 8

void generate_key(unsigned char* key) {
    int i;
    for(i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* ciphertext) {
    int i, j;
    unsigned char temp;
    for(i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if(j == BLOCK_SIZE) {
            for(int k = 0; k < BLOCK_SIZE; k++) {
                temp = plaintext[i - BLOCK_SIZE + k];
                plaintext[i - BLOCK_SIZE + k] = plaintext[i];
                plaintext[i] = temp;
            }
            j = 0;
        }
        ciphertext[i] = plaintext[i] ^ key[j];
    }
}

void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* plaintext) {
    int i, j;
    unsigned char temp;
    for(i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if(j == BLOCK_SIZE) {
            for(int k = 0; k < BLOCK_SIZE; k++) {
                temp = ciphertext[i - BLOCK_SIZE + k];
                ciphertext[i - BLOCK_SIZE + k] = ciphertext[i];
                ciphertext[i] = temp;
            }
            j = 0;
        }
        plaintext[i] = ciphertext[i] ^ key[j];
    }
}

int main() {
    unsigned char plaintext[100], ciphertext[100], key[KEY_SIZE];
    int plaintext_len, ciphertext_len;
    generate_key(key);
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    plaintext_len = strlen(plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for(int i = 0; i < plaintext_len; i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);
    return 0;
}