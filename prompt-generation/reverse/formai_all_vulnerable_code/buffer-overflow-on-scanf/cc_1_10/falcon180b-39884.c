//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 26
#define LETTERS "abcdefghijklmnopqrstuvwxyz"

char *key;
char *plaintext;
char ciphertext[500];

void encrypt(char *message) {
    int i, j, k, n;
    char *p;

    n = strlen(message);
    p = message;

    for (i = 0; i < n; i++) {
        if (isalpha(p[i])) {
            p[i] = tolower(p[i]);
            if (isalpha(p[i])) {
                j = p[i] - 'a';
                k = key[i % strlen(key)] - 'a';
                p[i] = LETTERS[j + k];
            }
        }
    }
}

void decrypt(char *message) {
    int i, j, k, n;
    char *p;

    n = strlen(message);
    p = message;

    for (i = 0; i < n; i++) {
        if (isalpha(p[i])) {
            p[i] = tolower(p[i]);
            if (isalpha(p[i])) {
                j = p[i] - 'a';
                k = key[i % strlen(key)] - 'a';
                p[i] = LETTERS[(j - k + 26) % SIZE];
            }
        }
    }
}

int main() {
    int choice, i;
    char ch;

    printf("Enter the message to be encrypted: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(plaintext);
            printf("Encrypted message: %s\n", ciphertext);
            break;
        case 2:
            decrypt(plaintext);
            printf("Decrypted message: %s\n", ciphertext);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}