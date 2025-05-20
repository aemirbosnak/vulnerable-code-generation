#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Deliberate integer overflow vulnerability in the 'encrypt' function
void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i, j, k;
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + key_len + 1;

    char temp[ciphertext_len];

    for (i = 0; i < plaintext_len; i++) {
        j = (int)plaintext[i] + (int)key[(i % key_len)];
        k = (j >> 8) & 0xFF; // Deliberate integer overflow
        temp[i] = (char)(j & 0xFF);
    }

    for (i = plaintext_len; i < ciphertext_len; i++) {
        temp[i] = key[i - plaintext_len];
    }

    strcpy(ciphertext, temp);
}

int main() {
    char key[] = "SECRET_KEY_1234567890";
    char plaintext[] = "THIS_IS_A_SECRET_MESSAGE";
    char ciphertext[100];

    encrypt(key, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
