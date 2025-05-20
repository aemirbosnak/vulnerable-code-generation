//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *plaintext = "This is a secret message";
    char ciphertext[100];
    int key = 13;
    int i, j;
    char ch;

    // Encrypt the message
    for (i = 0; plaintext[i]!= '\0'; i++) {
        ch = tolower(plaintext[i]);
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ch + key;
            }
            else {
                ch = ch + key;
            }
            if (ch > 'z') {
                ch = ch - 26;
            }
            else if (ch < 'a') {
                ch = ch + 26;
            }
        }
        ciphertext[i] = ch;
    }
    ciphertext[i] = '\0';
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    for (i = 0; ciphertext[i]!= '\0'; i++) {
        ch = tolower(ciphertext[i]);
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ch - key;
            }
            else {
                ch = ch - key;
            }
            if (ch > 'z') {
                ch = ch - 26;
            }
            else if (ch < 'a') {
                ch = ch + 26;
            }
        }
        plaintext[i] = ch;
    }
    plaintext[i] = '\0';
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}