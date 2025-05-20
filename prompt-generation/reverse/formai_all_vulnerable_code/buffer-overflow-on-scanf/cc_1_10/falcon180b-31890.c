//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_PLAINTEXT_LEN 1024

void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i, j, n;
    char* table = malloc(MAX_KEY_LEN * sizeof(char));
    memset(table, 'A', MAX_KEY_LEN);
    for (i = 0; i < strlen(key); i++) {
        table[key[i] % MAX_KEY_LEN] = key[i];
    }
    n = strlen(plaintext);
    for (i = 0; i < n; i++) {
        if (isalpha(plaintext[i])) {
            j = (int) plaintext[i] - 'A';
            ciphertext[i] = table[j % MAX_KEY_LEN];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
}

void decrypt(char* key, char* ciphertext, char* plaintext) {
    int i, j, n;
    char* table = malloc(MAX_KEY_LEN * sizeof(char));
    memset(table, 'A', MAX_KEY_LEN);
    for (i = 0; i < strlen(key); i++) {
        table[key[i] % MAX_KEY_LEN] = key[i];
    }
    n = strlen(ciphertext);
    for (i = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            j = (int) ciphertext[i] - 'A';
            plaintext[i] = table[j % MAX_KEY_LEN];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[n] = '\0';
}

int main() {
    char key[MAX_KEY_LEN];
    char plaintext[MAX_PLAINTEXT_LEN];
    char ciphertext[MAX_PLAINTEXT_LEN];
    int i, n;
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    encrypt(key, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(key, ciphertext, plaintext);
    printf("Plaintext: %s\n", plaintext);
    return 0;
}