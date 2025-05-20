//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generate_key(char key[SIZE]);
void encrypt(char message[SIZE], char key[SIZE]);
void decrypt(char ciphertext[SIZE], char key[SIZE]);

int main() {
    char message[SIZE];
    char ciphertext[SIZE];
    char key[SIZE];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    generate_key(key);

    printf("Key: %s\n", key);

    encrypt(message, key);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key);

    printf("Decrypted message: %s\n", ciphertext);

    return 0;
}

void generate_key(char key[SIZE]) {
    int i;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char message[SIZE], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + key[i % SIZE] - 'A') % 26;
            } else {
                message[i] = 'a' + (message[i] - 'a' + key[i % SIZE] - 'A') % 26;
            }
        }
    }
}

void decrypt(char ciphertext[SIZE], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                ciphertext[i] = 'A' + (ciphertext[i] - 'A' - key[i % SIZE] + 26) % 26;
            } else {
                ciphertext[i] = 'a' + (ciphertext[i] - 'a' - key[i % SIZE] + 26) % 26;
            }
        }
    }
}