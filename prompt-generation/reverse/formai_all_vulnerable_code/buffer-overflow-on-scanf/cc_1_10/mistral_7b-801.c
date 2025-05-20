//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#define _CRYPTIC_OBELISK_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

typedef struct {
    char symbol;
    int value;
} Code;

void CreateCodebook(Code codebook[27], char* str) {
    for (int i = 0; i < 26; i++) {
        codebook[i].symbol = (char)('A' + i);
        codebook[i].value = str[i] - 'A';
    }
    codebook[26].symbol = '\0';
    codebook[26].value = -1;
}

void EncodeMessage(Code codebook[27], char* msg, int* code) {
    for (int i = 0; i < strlen(msg); i++) {
        for (int j = 0; j < 26; j++) {
            if (msg[i] == codebook[j].symbol) {
                code[i] = codebook[j].value;
                break;
            }
        }
    }
}

void DecodeMessage(Code codebook[27], int* code, char* msg) {
    for (int i = 0; i < strlen(msg); i++) {
        for (int j = 0; j < 26; j++) {
            if (code[i] == codebook[j].value) {
                msg[i] = codebook[j].symbol;
                break;
            }
        }
    }
}

void GenerateRandomKey(int key[SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        key[i] = rand() % 26;
    }
}

void PerformEncryption(int key[SIZE], Code codebook[27], char* msg, char* encrypted) {
    int code[SIZE];
    EncodeMessage(codebook, msg, code);

    for (int i = 0; i < strlen(msg); i++) {
        encrypted[i] = msg[i] ^ key[i];
    }

    encrypted[strlen(msg)] = '\0';
}

int main() {
    char original_message[SIZE];
    char encrypted_message[SIZE];
    Code codebook[27];

    printf("Enter original message: ");
    scanf("%s", original_message);

    printf("Enter the cryptic key: ");
    int key[SIZE];
    GenerateRandomKey(key);

    CreateCodebook(codebook, "ALPHABET");

    PerformEncryption(key, codebook, original_message, encrypted_message);

    printf("Original message: %s\n", original_message);
    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[SIZE];
    DecodeMessage(codebook, key, encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}