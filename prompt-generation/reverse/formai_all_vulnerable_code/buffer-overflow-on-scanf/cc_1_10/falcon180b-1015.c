//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 16

void generateKey(int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 2;
    }
}

void printKey(int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d", key[i]);
    }
    printf("\n");
}

int encrypt(int key[SIZE], int plaintext[SIZE]) {
    int ciphertext[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }

    return 0;
}

int decrypt(int key[SIZE], int ciphertext[SIZE]) {
    int plaintext[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }

    return 0;
}

int main() {
    int key[SIZE], plaintext[SIZE], ciphertext[SIZE];
    int i;

    srand(time(NULL));
    generateKey(key);
    printKey(key);

    printf("Enter plaintext: ");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &plaintext[i]);
    }

    encrypt(key, plaintext);
    printf("Ciphertext: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", ciphertext[i]);
    }

    decrypt(key, ciphertext);
    printf("\nPlaintext: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", plaintext[i]);
    }

    return 0;
}