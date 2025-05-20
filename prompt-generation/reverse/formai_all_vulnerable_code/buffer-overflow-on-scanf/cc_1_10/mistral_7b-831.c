//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_SIZE 13
#define BUFFER_SIZE 256

void monkey_encrypt(char* plaintext, char* ciphertext, char key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int shift = (isupper(plaintext[i]) ? 65 : 97);
            ciphertext[i] = (char)(((int)plaintext[i] + key - shift + 26) % 26 + shift);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void monkey_decrypt(char* ciphertext, char* plaintext, char key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            int shift = (isupper(ciphertext[i]) ? 65 : 97);
            plaintext[i] = (char)(((int)ciphertext[i] - key + 26) % 26 + shift);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[BUFFER_SIZE], ciphertext[BUFFER_SIZE];
    char key = 'R'; // Key must be a single letter
    printf("Enter the plaintext: ");
    fgets(plaintext, BUFFER_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Initialize ciphertext with same length as plaintext
    strcpy(ciphertext, plaintext);

    printf("Enter the key: ");
    scanf(" %c", &key);

    // Encrypt the plaintext using the key
    monkey_encrypt(plaintext, ciphertext, key);

    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the same key
    char decrypted[BUFFER_SIZE];
    monkey_decrypt(ciphertext, decrypted, key);

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}