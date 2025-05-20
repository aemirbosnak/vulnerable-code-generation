//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 16

void generateKey(char key[KEY_SIZE]) {
    int i;
    for(i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void xor(char *text, char *key, int len) {
    int i;
    for(i = 0; i < len; i++) {
        text[i] ^= key[i % KEY_SIZE];
    }
}

void printHex(char *text, int len) {
    int i;
    for(i = 0; i < len; i++) {
        printf("%.2X ", text[i]);
    }
    printf("\n");
}

void encrypt(char *plainText, char *key) {
    int textLen = strlen(plainText), i, j, blockSize = BLOCK_SIZE;
    char textBlock[BLOCK_SIZE], encryptedBlock[BLOCK_SIZE];

    if(textLen % BLOCK_SIZE != 0) {
        textLen += BLOCK_SIZE - textLen % BLOCK_SIZE;
    }

    for(i = 0; i < textLen; i += blockSize) {
        memcpy(textBlock, plainText + i, blockSize);
        xor(textBlock, key, blockSize);
        memcpy(plainText + i, textBlock, blockSize);
    }
}

int main() {
    char plainText[100], key[KEY_SIZE], encryptedText[100];

    srand(time(NULL));
    generateKey(key);

    printf("Plain text: ");
    scanf("%s", plainText);

    encrypt(plainText, key);

    printf("Encrypted text: ");
    printHex(plainText, strlen(plainText));

    printf("Key: ");
    printHex(key, KEY_SIZE);

    return 0;
}