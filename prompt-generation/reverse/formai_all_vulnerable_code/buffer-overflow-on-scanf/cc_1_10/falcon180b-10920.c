//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "This is a secret key"
#define KEY_LEN strlen(KEY)

void encrypt(char* plaintext, char* ciphertext) {
    int i, j;
    char key[KEY_LEN];
    strcpy(key, KEY);

    for (i = 0, j = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = (plaintext[i] + key[i % KEY_LEN]) % 26 + 'A';
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* plaintext) {
    int i, j;
    char key[KEY_LEN];
    strcpy(key, KEY);

    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = (ciphertext[i] - key[i % KEY_LEN] + 26) % 26 + 'A';
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[100], ciphertext[200];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, plaintext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}