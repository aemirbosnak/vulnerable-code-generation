//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 26
#define K 3
#define M (N * K)

void key_schedule(char *key, int *k);
void encrypt(char *message, int *k);
void decrypt(char *ciphertext, int *k);

int main() {
    char message[1000], key[1000];
    int k[M];

    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    key_schedule(key, k);
    encrypt(message, k);
    decrypt(message, k);

    return 0;
}

void key_schedule(char *key, int *k) {
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (isalpha(key[i])) {
            k[i] = tolower(key[i]) - 'a';
        } else {
            k[i] = 0;
        }
    }
    for (int i = N; i < M; i++) {
        k[i] = k[i - N];
    }
}

void encrypt(char *message, int *k) {
    int m = strlen(message);
    char ciphertext[m + 1];
    int j = 0;

    for (int i = 0; i < m; i++) {
        if (isalpha(message[i])) {
            ciphertext[i] = (char) ((message[i] + k[j]) % 26 + 'a');
            j = (j + 1) % M;
        } else {
            ciphertext[i] = message[i];
        }
    }
    ciphertext[m] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char *ciphertext, int *k) {
    int m = strlen(ciphertext);
    char message[m + 1];
    int j = 0;

    for (int i = 0; i < m; i++) {
        if (isalpha(ciphertext[i])) {
            message[i] = (char) ((ciphertext[i] - k[j]) % 26 + 'a');
            j = (j + 1) % M;
        } else {
            message[i] = ciphertext[i];
        }
    }
    message[m] = '\0';

    printf("Decrypted message: %s\n", message);
}