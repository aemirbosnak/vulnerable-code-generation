//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char *plaintext, int key) {
    int i;
    char *ciphertext = malloc(MAX_SIZE * sizeof(char));
    memset(ciphertext, '\0', MAX_SIZE);

    for (i = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = (char) (((int) plaintext[i] + key - 65) % 26 + 65);
            } else {
                ciphertext[i] = (char) (((int) plaintext[i] + key - 97) % 26 + 97);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("Encrypted text: %s\n", ciphertext);
    free(ciphertext);
}

void decrypt(char *ciphertext, int key) {
    int i;
    char *plaintext = malloc(MAX_SIZE * sizeof(char));
    memset(plaintext, '\0', MAX_SIZE);

    for (i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[i] = (char) (((int) ciphertext[i] - 65 - key) % 26 + 65);
            } else {
                plaintext[i] = (char) (((int) ciphertext[i] - 97 - key) % 26 + 97);
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    printf("Decrypted text: %s\n", plaintext);
    free(plaintext);
}

int main() {
    char *plaintext, *ciphertext;
    int key;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(plaintext, key);
    decrypt(plaintext, key);

    return 0;
}