//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

#define SIZE 26
#define KEY 5

void encrypt(char plaintext[], char ciphertext[]) {
    int i, j;
    char keyword[SIZE] = "abcdefghijklmnopqrstuvwxyz";
    int keyword_length = strlen(keyword);

    for (i = 0; plaintext[i]!= '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            int index = 0;
            while (index < keyword_length) {
                if (plaintext[i] == keyword[index]) {
                    ciphertext[i] = keyword[(index + KEY) % keyword_length];
                    break;
                }
                ++index;
            }
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char ciphertext[], char plaintext[]) {
    int i, j;
    char keyword[SIZE] = "abcdefghijklmnopqrstuvwxyz";
    int keyword_length = strlen(keyword);

    for (i = 0; ciphertext[i]!= '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            int index = 0;
            while (index < keyword_length) {
                if (ciphertext[i] == keyword[index]) {
                    plaintext[i] = keyword[(index - KEY + keyword_length) % keyword_length];
                    break;
                }
                ++index;
            }
        }
        else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, plaintext);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}