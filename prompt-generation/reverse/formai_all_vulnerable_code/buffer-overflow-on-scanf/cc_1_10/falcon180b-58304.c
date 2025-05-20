//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char* plaintext, char* key, char* ciphertext){
    int i, j, k;
    char state[KEY_SIZE]; // state initialization vector
    for(i=0; i<KEY_SIZE; i++){
        state[i] = key[i];
    }
    for(i=0, k=0; i<strlen(plaintext); i+=BLOCK_SIZE, k+=BLOCK_SIZE){
        char block[BLOCK_SIZE]; // XOR with state
        strncpy(block, plaintext+i, BLOCK_SIZE);
        for(j=0; j<BLOCK_SIZE; j++){
            block[j] ^= state[j];
        }
        strncat(ciphertext, block, BLOCK_SIZE);
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext){
    int i, j, k;
    char state[KEY_SIZE]; // state initialization vector
    for(i=0; i<KEY_SIZE; i++){
        state[i] = key[i];
    }
    for(i=0, k=0; i<strlen(ciphertext); i+=BLOCK_SIZE, k+=BLOCK_SIZE){
        char block[BLOCK_SIZE]; // XOR with state
        strncpy(block, ciphertext+i, BLOCK_SIZE);
        for(j=0; j<BLOCK_SIZE; j++){
            block[j] ^= state[j];
        }
        strncat(plaintext, block, BLOCK_SIZE);
    }
}

int main(){
    char plaintext[100], key[KEY_SIZE], ciphertext[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter key: ");
    scanf("%s", key);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}