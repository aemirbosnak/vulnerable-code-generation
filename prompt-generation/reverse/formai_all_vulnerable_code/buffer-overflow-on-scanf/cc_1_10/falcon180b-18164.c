//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generate_key(int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 256;
    }
}

int encrypt(int plaintext[SIZE], int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        plaintext[i] = (plaintext[i] + key[i]) % 256;
    }
    return 0;
}

int decrypt(int ciphertext[SIZE], int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        ciphertext[i] = (ciphertext[i] - key[i] + 256) % 256;
    }
    return 0;
}

int main() {
    int plaintext[SIZE], ciphertext[SIZE], key[SIZE];
    int i, choice;

    printf("Enter 1 for encryption, 2 for decryption: ");
    scanf("%d", &choice);

    srand(time(NULL));
    generate_key(key);

    if (choice == 1) {
        printf("Enter plaintext: ");
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &plaintext[i]);
        }
        encrypt(plaintext, key);
        printf("Ciphertext: ");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", ciphertext[i]);
        }
    } else if (choice == 2) {
        printf("Enter ciphertext: ");
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &ciphertext[i]);
        }
        decrypt(ciphertext, key);
        printf("Plaintext: ");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", plaintext[i]);
        }
    }

    return 0;
}