//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define KEY_SIZE 3

void encrypt(char *plaintext, char key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i]))
                plaintext[i] = (char)(((int)plaintext[i] + key - 65) % 26 + 65);
            else
                plaintext[i] = (char)(((int)plaintext[i] + key - 97) % 26 + 97);
        }
    }
}

void decrypt(char *ciphertext, char key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i]))
                ciphertext[i] = (char)(((int)ciphertext[i] - key + 26) % 26 + 65);
            else
                ciphertext[i] = (char)(((int)ciphertext[i] - key + 26) % 26 + 97);
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0'; // remove newline character

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    encrypt(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    int len = strlen(plaintext);

    // allocate memory for ciphertext
    ciphertext[len] = '\0';
    ciphertext[len - 1] = '\0'; // leave space for newline character

    // decrypt the encrypted text
    decrypt(plaintext, key);

    printf("Decrypted text: %s\n", plaintext);

    // encrypt the decrypted text to check if the key is correct
    encrypt(plaintext, key);

    strcat(ciphertext, plaintext); // concatenate encrypted text and decrypted text

    if (strcmp(plaintext, ciphertext) == 0)
        printf("Key is correct.\n");
    else
        printf("Key is incorrect.\n");

    return 0;
}