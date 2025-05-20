//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

char *encrypt(char *plaintext) {
    int i, j, n = strlen(plaintext);
    char *ciphertext = malloc(MAX_STRING_LENGTH * sizeof(char));
    memset(ciphertext, 0, MAX_STRING_LENGTH);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j++] = (char)(tolower(plaintext[i]) + 13);
            } else {
                ciphertext[j++] = (char)(toupper(plaintext[i]) - 13);
            }
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }

    return ciphertext;
}

char *decrypt(char *ciphertext) {
    int i, j, n = strlen(ciphertext);
    char *plaintext = malloc(MAX_STRING_LENGTH * sizeof(char));
    memset(plaintext, 0, MAX_STRING_LENGTH);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[j++] = (char)(toupper(ciphertext[i]) - 13);
            } else {
                plaintext[j++] = (char)(tolower(ciphertext[i]) - 13);
            }
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }

    return plaintext;
}

int main() {
    char *plaintext, *ciphertext, *decrypted;

    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);

    ciphertext = encrypt(plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypted = decrypt(ciphertext);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}