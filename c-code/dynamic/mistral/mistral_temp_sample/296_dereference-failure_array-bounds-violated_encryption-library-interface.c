#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ciphertext[i] = key[(plaintext[i] - 'A') % 26] ^ plaintext[i];
    }
    ciphertext[i] = '\0';
}

void decrypt(char* key, char* ciphertext, char* plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        plaintext[i] = key[(ciphertext[i] - 'A') + 13] ^ ciphertext[i];
    }
    plaintext[i] = '\0';
}

int main() {
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char plaintext[] = "THISISASIMPLEEXAMPLE";
    char ciphertext[51];
    char decrypted[51];

    encrypt(key, plaintext, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(key, ciphertext, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    char invalidKey[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'Z' }; // Note the duplicate 'Z'

    encrypt(invalidKey, plaintext, ciphertext);
    printf("Encrypted text with invalid key: %s\n", ciphertext);

    return 0;
}
