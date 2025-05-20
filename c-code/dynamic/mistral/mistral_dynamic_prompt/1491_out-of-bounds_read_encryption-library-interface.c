#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define ALPHABET_SIZE 26

char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
char key[MAX_KEY_LEN];

void encrypt(char *plaintext, int text_len, char *ciphertext) {
    for (int i = 0; i < text_len; i++) {
        int index = alphabet[plaintext[i] - 'a'];
        ciphertext[i] = alphabet[(index + key[i % MAX_KEY_LEN]) % ALPHABET_SIZE];
    }
}

int main() {
    printf("Enter plaintext:\n");
    char plaintext[1000];
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key:\n");
    fgets(key, sizeof(key), stdin);

    int plaintext_len = strlen(plaintext);
    char ciphertext[plaintext_len];
    encrypt(plaintext, plaintext_len, ciphertext);

    printf("Encrypted text:\n");
    printf("%s\n", ciphertext);

    return 0;
}
