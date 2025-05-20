//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generateKey(int key[SIZE][SIZE]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            key[i][j] = rand() % 26 + 'A';
        }
    }
}

void encrypt(char message[100], int key[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[i % SIZE][message[i] - 'A'];
        }
    }
}

void decrypt(char message[100], int key[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[i % SIZE][message[i] - 'A'] + 'A';
        }
    }
}

int main() {
    int key[SIZE][SIZE];
    char message[100];

    printf("Enter your message: ");
    scanf("%s", message);

    generateKey(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}