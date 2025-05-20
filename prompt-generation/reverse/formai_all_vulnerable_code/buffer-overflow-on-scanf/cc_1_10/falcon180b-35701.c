//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* plaintext, char* ciphertext, int key) {
    int length = strlen(plaintext);
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j] = ((int) plaintext[i] + key - 65) % 26 + 65;
            } else {
                ciphertext[j] = ((int) plaintext[i] + key - 97) % 26 + 97;
            }
            j++;
        } else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }

    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* plaintext, int key) {
    int length = strlen(ciphertext);
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[j] = ((int) ciphertext[i] - key - 65) % 26 + 65;
            } else {
                plaintext[j] = ((int) ciphertext[i] - key - 97) % 26 + 97;
            }
            j++;
        } else {
            plaintext[j] = ciphertext[i];
            j++;
        }
    }

    plaintext[j] = '\0';
}

int main() {
    char plaintext[1000], ciphertext[1000];
    int key;

    printf("Enter the plaintext: ");
    scanf("%[^\n]", plaintext);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    encrypt(plaintext, ciphertext, key);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, plaintext, key);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}