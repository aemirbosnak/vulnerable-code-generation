//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void generate_key(int key[SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(int plaintext[SIZE], int key[SIZE], int ciphertext[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
}

void decrypt(int ciphertext[SIZE], int key[SIZE], int plaintext[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
}

int main() {
    int plaintext[SIZE] = {0};
    int key[SIZE] = {0};
    int ciphertext[SIZE] = {0};

    generate_key(key);

    printf("Enter plaintext: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &plaintext[i]);
    }

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    decrypt(ciphertext, key, plaintext);

    printf("Plaintext: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", plaintext[i]);
    }
    printf("\n");

    return 0;
}