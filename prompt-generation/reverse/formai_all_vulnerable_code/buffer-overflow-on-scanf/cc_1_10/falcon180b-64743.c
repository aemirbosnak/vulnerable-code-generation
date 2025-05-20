//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char *plaintext, char *ciphertext) {
    int i, j, k = 0;
    char key[strlen(KEY)];

    strcpy(key, KEY);

    for (i = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = (char) ((int) plaintext[i] + (int) key[k] - 65);
            } else {
                ciphertext[i] = (char) ((int) plaintext[i] + (int) key[k] - 97);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }

        k = (k + 1) % strlen(KEY);
    }

    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, j, k = 0;
    char key[strlen(KEY)];

    strcpy(key, KEY);

    for (i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[i] = (char) ((int) ciphertext[i] - (int) key[k] + 65);
            } else {
                plaintext[i] = (char) ((int) ciphertext[i] - (int) key[k] + 97);
            }
        } else {
            plaintext[i] = ciphertext[i];
        }

        k = (k + 1) % strlen(KEY);
    }

    plaintext[i] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    int choice;

    printf("Enter your message: ");
    scanf("%s", plaintext);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(plaintext, ciphertext);
            printf("Encrypted message: %s\n", ciphertext);
            break;

        case 2:
            decrypt(ciphertext, plaintext);
            printf("Decrypted message: %s\n", plaintext);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}