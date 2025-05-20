//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 1
#define ALPHABET_SIZE 26
#define SHIFT_MAX ALPHABET_SIZE - 1

void encrypt(char *plaintext, int key) {
    int i, j;
    char encrypted[strlen(plaintext)];
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            j = ((int)plaintext[i] - 'A' + key) % ALPHABET_SIZE;
            encrypted[i] = (char)('A' + j);
        } else {
            encrypted[i] = plaintext[i];
        }
    }
    encrypted[strlen(plaintext)] = '\0';
    printf("Encrypted text: %s\n", encrypted);
}

void decrypt(char *ciphertext, int key) {
    int i, j;
    char decrypted[strlen(ciphertext)];
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            j = ((int)ciphertext[i] - 'A' + ALPHABET_SIZE - key) % ALPHABET_SIZE;
            decrypted[i] = (char)('A' + j);
        } else {
            decrypted[i] = ciphertext[i];
        }
    }
    decrypted[strlen(ciphertext)] = '\0';
    printf("Decrypted text: %s\n", decrypted);
}

int main() {
    char plaintext[100], ciphertext[100];
    int key, shift;

    printf("Enter the message to be encrypted: ");
    scanf("%s", plaintext);

    printf("Enter the encryption key (shift): ");
    scanf("%d", &key);

    shift = key % ALPHABET_SIZE;
    if (shift == 0) {
        printf("Warning: The key is a multiple of the alphabet size. Please choose a different key.\n");
        return 1;
    }

    encrypt(plaintext, shift);

    strcpy(ciphertext, plaintext);
    decrypt(ciphertext, shift);

    return 0;
}