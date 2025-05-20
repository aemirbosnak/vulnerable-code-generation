//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

struct Block {
    char data[MAX_LENGTH];
    int length;
};

void encrypt(char* key, struct Block* plain_text, struct Block* cipher_text) {
    int i, j, k;
    char temp;

    for (i = 0, j = 0; i < strlen(key); i++, j++) {
        if (j >= MAX_LENGTH) {
            j = 0;
        }
        temp = key[i];
        cipher_text->data[j] = plain_text->data[j] ^ temp;
    }

    cipher_text->length = strlen(plain_text->data);
}

void decrypt(char* key, struct Block* cipher_text, struct Block* plain_text) {
    int i, j, k;
    char temp;

    for (i = 0, j = 0; i < strlen(key); i++, j++) {
        if (j >= MAX_LENGTH) {
            j = 0;
        }
        temp = key[i];
        plain_text->data[j] = cipher_text->data[j] ^ temp;
    }

    plain_text->length = strlen(cipher_text->data);
}

void generate_key(char* key) {
    int i;

    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

int main() {
    char plain_text[MAX_LENGTH];
    char cipher_text[MAX_LENGTH];
    struct Block plain_block, cipher_block;

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    plain_block.data[0] = '\0';
    strcat(plain_block.data, plain_text);
    plain_block.length = strlen(plain_text);

    generate_key(plain_block.data);
    encrypt(plain_block.data, &plain_block, &cipher_block);

    printf("Plain text: %s\n", plain_text);
    printf("Encrypted text: %s\n", cipher_block.data);

    generate_key(plain_text);
    decrypt(plain_text, &cipher_block, &plain_block);

    printf("Decrypted text: %s\n", plain_block.data);

    return 0;
}