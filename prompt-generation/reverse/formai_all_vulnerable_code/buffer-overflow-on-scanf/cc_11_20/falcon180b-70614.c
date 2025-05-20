//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16

int main() {
    char key[KEY_LENGTH];
    char plaintext[100];
    char ciphertext[200];
    int i, j, len;

    // generate key
    srand(time(NULL));
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    len = strlen(plaintext);

    // encryption
    for (i = 0, j = 0; i < len; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[j++] = (char) (((int) plaintext[i] - 65 + (int) key[i % KEY_LENGTH]) % 26 + 65);
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[j++] = (char) (((int) plaintext[i] - 97 + (int) key[i % KEY_LENGTH]) % 26 + 97);
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';

    // decryption
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[j++] = (char) (((int) ciphertext[i] - 65 - (int) key[i % KEY_LENGTH]) % 26 + 65);
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[j++] = (char) (((int) ciphertext[i] - 97 - (int) key[i % KEY_LENGTH]) % 26 + 97);
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}