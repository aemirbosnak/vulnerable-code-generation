//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_PLAIN_LENGTH 1000

void generate_key(char key[MAX_KEY_LENGTH]) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char plain[MAX_PLAIN_LENGTH], char key[MAX_KEY_LENGTH]) {
    int i;
    for (i = 0; i < strlen(plain); i++) {
        if (isalpha(plain[i])) {
            plain[i] = (plain[i] - 'a' + (int)key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

void decrypt(char cipher[MAX_PLAIN_LENGTH], char key[MAX_KEY_LENGTH]) {
    int i;
    for (i = 0; i < strlen(cipher); i++) {
        if (isalpha(cipher[i])) {
            cipher[i] = (cipher[i] - 'a' - (int)key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

int main() {
    char plain[MAX_PLAIN_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the plaintext: ");
    scanf("%s", plain);

    generate_key(key);

    encrypt(plain, key);
    printf("Ciphertext: %s\n", plain);

    decrypt(plain, key);
    printf("Plaintext: %s\n", plain);

    return 0;
}