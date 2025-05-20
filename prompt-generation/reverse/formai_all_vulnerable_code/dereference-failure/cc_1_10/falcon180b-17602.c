//Falcon-180B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char key[], int key_size) {
    int i;
    for(i=0; i<key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char plaintext[], char key[], char ciphertext[], int plaintext_size) {
    int i, j, k;
    for(i=0, j=0; i<plaintext_size; i+=BLOCK_SIZE, j+=2) {
        char block[BLOCK_SIZE];
        strncpy(block, &plaintext[i], BLOCK_SIZE);
        int sum = 0;
        for(k=0; k<BLOCK_SIZE; k++) {
            sum += block[k] ^ key[j+k];
        }
        ciphertext[i] = sum;
    }
}

void decrypt(char ciphertext[], char key[], char plaintext[], int ciphertext_size) {
    int i, j, k;
    for(i=0, j=0; i<ciphertext_size; i+=2, j+=BLOCK_SIZE) {
        int sum = ciphertext[i];
        for(k=0; k<BLOCK_SIZE; k++) {
            plaintext[j+k] = sum ^ key[i+k];
        }
    }
}

int main() {
    char plaintext[] = "This is a secret message";
    int plaintext_size = strlen(plaintext);
    char key[KEY_SIZE];
    generate_key(key, KEY_SIZE);
    char ciphertext[plaintext_size];
    encrypt(plaintext, key, ciphertext, plaintext_size);
    printf("Ciphertext: %s\n", ciphertext);
    char plaintext_decrypted[plaintext_size];
    decrypt(ciphertext, key, plaintext_decrypted, plaintext_size);
    printf("Plaintext: %s\n", plaintext_decrypted);
    return 0;
}