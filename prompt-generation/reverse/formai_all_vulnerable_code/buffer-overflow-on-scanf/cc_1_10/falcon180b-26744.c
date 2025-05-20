//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int key;
    int rounds;
} block_cipher_t;

void generate_key(int *key) {
    srand(time(NULL));
    *key = rand() % 256;
}

void encrypt(unsigned char *plaintext, int plaintext_len, int key, int rounds) {
    int i, j;
    for (i = 0; i < plaintext_len; i++) {
        for (j = 0; j < rounds; j++) {
            plaintext[i] ^= key;
            key = (key + 3) % 256;
        }
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, int key, int rounds) {
    int i, j;
    for (i = 0; i < ciphertext_len; i++) {
        for (j = 0; j < rounds; j++) {
            ciphertext[i] ^= key;
            key = (key - 3) % 256;
        }
    }
}

int main() {
    block_cipher_t bc;
    int key, rounds;
    int plaintext_len, ciphertext_len;
    unsigned char plaintext[100], ciphertext[100];

    generate_key(&bc.key);
    printf("Key: %d\n", bc.key);

    printf("Enter the length of the plaintext (max 100): ");
    scanf("%d", &plaintext_len);

    if (plaintext_len > 100) {
        printf("Plaintext is too long.\n");
        exit(1);
    }

    printf("Enter the plaintext:\n");
    scanf("%s", plaintext);

    printf("Enter the number of rounds (1-100): ");
    scanf("%d", &rounds);

    if (rounds < 1 || rounds > 100) {
        printf("Invalid number of rounds.\n");
        exit(1);
    }

    encrypt(plaintext, plaintext_len, bc.key, rounds);

    printf("Ciphertext:\n");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02X ", ciphertext[i]);
    }

    printf("\n");

    return 0;
}