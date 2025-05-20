//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1000
#define MAX_BLOCK_SIZE 1024
#define MAX_ROUNDS 1000

// Key Schedule
void key_schedule(char* key, int key_size, int* round_constants, int rounds) {
    int i, j, k;
    for (i = 0; i < rounds; i++) {
        j = i;
        k = 0;
        while (k < key_size) {
            round_constants[i] ^= key[j % key_size];
            j++;
            k++;
        }
    }
}

// Encryption
void encrypt(char* plaintext, int* round_constants, int rounds) {
    int i, j, k;
    char* ciphertext = malloc(strlen(plaintext) + 1);
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i];
        for (j = 0; j < rounds; j++) {
            ciphertext[i] ^= round_constants[j];
            k = ciphertext[i] % 26;
            if (k < 0) k += 26;
            ciphertext[i] = k + 'A';
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    free(ciphertext);
}

// Decryption
void decrypt(char* ciphertext, int* round_constants, int rounds) {
    int i, j, k;
    char* plaintext = malloc(strlen(ciphertext) + 1);
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i];
        for (j = 0; j < rounds; j++) {
            plaintext[i] ^= round_constants[j];
            k = plaintext[i] - 'A';
            if (k < 0) k += 26;
            plaintext[i] = k;
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
    printf("Plaintext: %s\n", plaintext);
    free(plaintext);
}

// Main
int main() {
    char* plaintext = "Hello World!";
    char* ciphertext;
    int key_size, rounds;

    printf("Enter key size (1-1000): ");
    scanf("%d", &key_size);

    printf("Enter number of rounds (1-1000): ");
    scanf("%d", &rounds);

    int round_constants[MAX_ROUNDS];
    key_schedule(plaintext, key_size, round_constants, rounds);

    encrypt(plaintext, round_constants, rounds);
    decrypt(ciphertext, round_constants, rounds);

    return 0;
}